package main

import (
	"fmt"
	"log"
)

func newGraph() graph {
	return graph{
		adjacency: make(map[string][]string),
	}
}

type graph struct {
	adjacency map[string][]string
}

func (g *graph) addVertex(vertex string) {
	if _, ok := g.adjacency[vertex]; ok {
		log.Fatalf("Vertex '%v' already exists\n", vertex)
	}

	g.adjacency[vertex] = []string{}
}

func (g *graph) addEdge(src, dst string) {
	if _, ok := g.adjacency[src]; !ok {
		log.Fatalf("Vertex '%v' does not exist\n", src)
	}
	if _, ok := g.adjacency[dst]; !ok {
		log.Fatalf("Vertex '%v' does not exist\n", dst)
	}
	if g.containsEdge(src, dst) {
		log.Fatalf("Edge from '%v' to '%v' already exists\n", src, dst)
	}

	g.adjacency[src] = append(g.adjacency[src], dst)
}

func (g *graph) containsEdge(src, dst string) bool {
	for _, edge := range g.adjacency[src] {
		if edge == dst {
			return true
		}
	}

	return false
}

func (g graph) newVisitedArray() map[string]bool {
	visited := make(map[string]bool, len(g.adjacency))
	for vertex := range g.adjacency {
		visited[vertex] = false
	}

	return visited
}

func (g graph) DFS(start string) {
	visited := g.newVisitedArray()
	log.Println("DFS:")
	g.recursiveDFS(start, visited)
}

func (g graph) recursiveDFS(src string, visited map[string]bool) {
	fmt.Println(src)
	visited[src] = true
	for _, dst := range g.adjacency[src] {
		if !visited[dst] {
			g.recursiveDFS(dst, visited)
		}
	}
}

func main() {
	g := newGraph()
	g.addVertex("1")
	g.addVertex("2")
	g.addVertex("3")
	g.addVertex("4")
	g.addVertex("5")

	g.addEdge("1", "2")
	g.addEdge("1", "3")
	g.addEdge("2", "4")
	g.addEdge("3", "4")
	g.addEdge("4", "5")

	g.DFS("1")
}
