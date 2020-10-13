// C++ program to perform Depth First Search traversal on a Graph
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// data structure to store graph edges
struct Edge {
	int src, dest;
};

// class to represent a graph object
class Graph
{
public:
	// construct a vector of vectors to represent an adjacency list
	vector<vector<int>> adjList;

	// Graph Constructor
	Graph(vector<Edge> const &edges, int N)
	{
		// resize the vector to N elements of type vector<int>
		adjList.resize(N);

		// add edges to the undirected graph
		for (auto &edge: edges)
		{
			adjList[edge.src].push_back(edge.dest);
			adjList[edge.dest].push_back(edge.src);
		}
	}
};

// Perform DFS on graph g starting from vertex v
void DFS(Graph const &graph, int v, vector<bool> &discovered)
{
	// 1)create a stack used to do iterative DFS
	stack<int> stack;

	// 2)push the source node into stack
	stack.push(v);

	// 3)loop till stack is empty
	while (!stack.empty())
	{
		v = stack.top();
		stack.pop();

		if (discovered[v])
			continue;

		discovered[v] = true;
		cout << v << " ";

		for (auto it = graph.adjList[v].rbegin();
				  it != graph.adjList[v].rend(); ++it)
		{
			int u = *it;
			if (!discovered[u])
				stack.push(u);
		}
	}
}

// Driver program to test above function 
int main()
{
	
	vector<Edge> edges = {
		
		// Notice that node 0 is unconnected node
		{1, 2}, {1, 7}, {1, 8}, {2, 3}, {2, 6}, {3, 4},
		{3, 5}, {8, 9}, {8, 12}, {9, 10}, {9, 11}
		
	};

	// Number of nodes in the graph (0-12)
	int N = 13;

	// create a graph from given edges
	Graph graph(edges, N);

	// stores vertex is discovered or not
	vector<bool> discovered(N);

	// Do DFS traversal from all undiscovered nodes to
	// cover all unconnected components of graph
	for (int i = 0; i < N; i++)
		if (discovered[i] == false)
			DFS(graph, i, discovered);

	return 0;
}
