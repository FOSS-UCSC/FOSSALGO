// A C# program for Dijkstra's  shortest path algorithm. 
using System; 

public static class Dijkstra { 

	static int V = 9; 

	static int minDistance(int[] dist, bool[] sptSet) 
	{ 
		// Initialize min value 
		int min = int.MaxValue, min_index = -1; 

		for (int v = 0; v < V; v++) 
		{
			if (sptSet[v] == false && dist[v] <= min) 
			{ 
				min = dist[v]; 
				min_index = v; 
			} 
		}

		return min_index; 
	} 


	// Funtion that implements Dijkstra's shortest path algorithm 
	static void Dodijkstra(int[, ] graph, int src) 
	{ 
		int[] dist = new int[V];  

		
		bool[] sptSet = new bool[V]; 

	
		for (int i = 0; i < V; i++) 
		{ 
			dist[i] = int.MaxValue; 
			sptSet[i] = false; 
		} 

		
		dist[src] = 0; 

		// Find shortest path for all vertices 
		for (int count = 0; count < V - 1; count++) 
		{ 
			
			int u = minDistance(dist, sptSet); 

			// Mark the picked vertex as processed 
			sptSet[u] = true; 

			// Update dist value of the adjacent 
			// vertices of the picked vertex. 
			for (int v = 0; v < V; v++) 
			{

		
				if (!sptSet[v] && graph[u, v] != 0 && dist[u] != int.MaxValue && dist[u] + graph[u, v] < dist[v]) {
					dist[v] = dist[u] + graph[u, v]; 
				}
			}
		} 

		// print the constructed distance array 
		for (int i = 0; i < V; i++) 
		{
			//Console.Write(dist[i]);  
		}
	} 

	// Driver Code to test above function
	public static void Main() 
	{ 

		int[, ] graph = new int[, ] { { 0, 4, 0, 0, 0, 0, 0, 8, 0 }, 
									{ 4, 0, 8, 0, 0, 0, 0, 11, 0 }, 
									{ 0, 8, 0, 7, 0, 4, 0, 0, 2 }, 
									{ 0, 0, 7, 0, 9, 14, 0, 0, 0 }, 
									{ 0, 0, 0, 9, 0, 10, 0, 0, 0 }, 
									{ 0, 0, 4, 14, 10, 0, 2, 0, 0 }, 
									{ 0, 0, 0, 0, 0, 2, 0, 1, 6 }, 
									{ 8, 11, 0, 0, 0, 0, 1, 0, 7 }, 
									{ 0, 0, 2, 0, 0, 0, 6, 7, 0 } }; 
		
		Dodijkstra(graph, 0); 
	} 
} 
