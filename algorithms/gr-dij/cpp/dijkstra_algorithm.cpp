//C++ program for Dijkstra's shortest path algorithm.
#include <limits.h> 
#include <stdio.h> 

// Function to find the vertex with minimum distance value, 
int minDistance(int dist[], bool sptSet[]) 
{ 
	int min = INT_MAX, min_index; 

	for (int v = 0; v < 9; v++) 
		if (sptSet[v] == false && dist[v] <= min) 
			min = dist[v], min_index = v; 

	return min_index; 
} 

// Function to print the constructed distance array 
void printSolution(int dist[]) 
{ 
	printf("Vertex \t\t Distance from Source\n"); 
	for (int i = 0; i < 9; i++) 
		printf("%d \t\t %d\n", i, dist[i]); 
} 

// Function that implements Dijkstra's shortest path algorithm
void dijkstra(int graph[9][9], int src) 
{ 
	int dist[9]; 

	bool sptSet[9]; 

	// Initialize all distances as INFINITE and stpSet[] as false 
	for (int i = 0; i < 9; i++) 
		dist[i] = INT_MAX, sptSet[i] = false; 

	// Distance of source vertex from itself is always 0 
	dist[src] = 0; 

	// Find shortest path for all vertices 
	for (int count = 0; count < 9 - 1; count++) { 
	
		int u = minDistance(dist, sptSet); 

		
		sptSet[u] = true; 

	
		for (int v = 0; v < 9; v++) 

			// Update dist[v] only if is not in sptSet, there is an edge from 
			// u to v, and total weight of path from src to v through u is 
			// smaller than current value of dist[v] 
			if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX 
				&& dist[u] + graph[u][v] < dist[v]) 
				dist[v] = dist[u] + graph[u][v]; 
	} 

	
	printSolution(dist); 
} 

// Driver program to test above function 
int main() 
{ 
	
	int graph[9][9] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 }, 
						{ 4, 0, 8, 0, 0, 0, 0, 11, 0 }, 
						{ 0, 8, 0, 7, 0, 4, 0, 0, 2 }, 
						{ 0, 0, 7, 0, 9, 14, 0, 0, 0 }, 
						{ 0, 0, 0, 9, 0, 10, 0, 0, 0 }, 
						{ 0, 0, 4, 14, 10, 0, 2, 0, 0 }, 
						{ 0, 0, 0, 0, 0, 2, 0, 1, 6 }, 
						{ 8, 11, 0, 0, 0, 0, 1, 0, 7 }, 
						{ 0, 0, 2, 0, 0, 0, 6, 7, 0 } }; 

	dijkstra(graph, 0); 

	return 0; 
} 

