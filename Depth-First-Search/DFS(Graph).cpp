#include<iostream>
#include<list>
using namespace std;

class Graph {
    int v; // Number of vertices
    list<int> *adj; // adjacency list
    void Traverse(int v, bool visited[]);
    public:
        Graph(int v); // Constructor
        void addEdge(int v, int w); // Add an edge to graph
        void DFS(int v);
};

Graph::Graph(int v) {
    this->v = v;
    adj = new list<int>[v];
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);
}

void Graph::DFS(int v) {
    // Mark all the vertices as not visited
    bool *visited = new bool[v];
    for (int s = 0; s < v; s++)
        visited[s] = false;
   
    // Call the recursive helper function to print DFS traversal
    Traverse(v, visited);
}

void Graph::Traverse(int v, bool visited[]) {
    // Mark the current node as visited and print it
    visited[v] = true;
    cout << v << " ";
   
    // Recur for all the vertices adjacent to this vertex
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i]) {
            Traverse(*i, visited);
    }
}

int main() {
    // Create a sample graph
    Graph g(7);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(0, 3);
    g.addEdge(1, 4);
    g.addEdge(1, 5);
    g.addEdge(2, 6);
    g.addEdge(5, 3);
   
    g.DFS(0);
   
    return 0;
}
