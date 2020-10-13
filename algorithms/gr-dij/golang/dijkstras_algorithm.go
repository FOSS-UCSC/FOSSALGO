package main

import (
	"fmt"
	"sort"
	"strconv"
)

// Graph defines the structure for our graph
type Graph struct {
	Edges []*Edge
	Nodes map[*Node]bool
}

// Edge defines a struct used to build Edges
type Edge struct {
	Parent *Node
	Child  *Node
	Cost   int
}

// Node defines a struct used to build a Node
type Node struct {
	Name string
}

// Infinity defines a value of infinity
const Infinity = int(^uint(0) >> 1)

// AddEdge adds an Edge to the Graph
func (g *Graph) AddEdge(parent, child *Node, cost int) {
	edge := &Edge{
		Parent: parent,
		Child:  child,
		Cost:   cost,
	}

	g.Edges = append(g.Edges, edge)
	g.AddNode(parent)
	g.AddNode(child)
}

// AddNode adds a Node to the Graph list of Nodes, if the the node wasn't already added
func (g *Graph) AddNode(node *Node) {
	if g.Nodes == nil {
		g.Nodes = make(map[*Node]bool)
	}

	_, ok := g.Nodes[node]
	if !ok {
		g.Nodes[node] = true
	}
}

// String returns a string representation of the Graph
func (g *Graph) String() string {
	var s string

	s += "Edges:\n"
	for _, edge := range g.Edges {
		s += edge.Parent.Name + " -> " + edge.Child.Name + " = " + strconv.Itoa(edge.Cost)
		s += "\n"
	}
	s += "\n"

	s += "Nodes: "
	i := 0
	for node := range g.Nodes {
		if i == len(g.Nodes)-1 {
			s += node.Name
		} else {
			s += node.Name + ", "
		}
		i++
	}
	s += "\n"

	return s
}

// Dijkstra implements Dijkstra's algorithm
func (g *Graph) Dijkstra(startNode *Node) (costTable map[*Node]int) {

	costTable = g.NewCostTable(startNode)

	// An empty list of "visited" Nodes. Everytime the algorithm runs on a Node, we add it here
	var visited []*Node

	for len(visited) != len(g.Nodes) {

		node := getClosestNonVisitedNode(costTable, visited)

		visited = append(visited, node)

		nodeEdges := g.GetNodeEdges(node)

		for _, edge := range nodeEdges {

			distanceToNeighbor := costTable[node] + edge.Cost

			if distanceToNeighbor < costTable[edge.Child] {

				costTable[edge.Child] = distanceToNeighbor
			}
		}
	}

	return costTable
}

// NewCostTable returns an initialized cost table for the Dijkstra algorithm work with
func (g *Graph) NewCostTable(startNode *Node) map[*Node]int {
	costTable := make(map[*Node]int)
	costTable[startNode] = 0

	for node := range g.Nodes {
		if node != startNode {
			costTable[node] = Infinity
		}
	}

	return costTable
}

// GetNodeEdges returns all the Edges that start with the specified Node
func (g *Graph) GetNodeEdges(node *Node) (edges []*Edge) {
	for _, edge := range g.Edges {
		if edge.Parent == node {
			edges = append(edges, edge)
		}
	}

	return edges
}

// getClosestNonVisitedNode returns the closest Node (with the lower cost) from the costTable
func getClosestNonVisitedNode(costTable map[*Node]int, visited []*Node) *Node {
	type CostTableToSort struct {
		Node *Node
		Cost int
	}
	var sorted []CostTableToSort

	for node, cost := range costTable {
		var isVisited bool
		for _, visitedNode := range visited {
			if node == visitedNode {
				isVisited = true
			}
		}

		if !isVisited {
			sorted = append(sorted, CostTableToSort{node, cost})
		}
	}

	sort.Slice(sorted, func(i, j int) bool {
		return sorted[i].Cost < sorted[j].Cost
	})

	return sorted[0].Node
}

func main() {
	start := &Node{Name: "start"}
	finish := &Node{Name: "finish"}
	a := &Node{Name: "a"}
	b := &Node{Name: "b"}
	c := &Node{Name: "c"}
	d := &Node{Name: "d"}

	g := Graph{}
	g.AddEdge(start, a, 5)
	g.AddEdge(start, b, 2)
	g.AddEdge(b, a, 8)
	g.AddEdge(b, c, 7)
	g.AddEdge(a, c, 4)
	g.AddEdge(a, d, 2)
	g.AddEdge(c, d, 3)
	g.AddEdge(c, finish, 6)
	g.AddEdge(d, finish, 1)
	costTable := g.Dijkstra(start)
	for node, cost := range costTable {
		fmt.Printf("Distance from %s to %s = %d\n", a.Name, node.Name, cost)
	}
}
