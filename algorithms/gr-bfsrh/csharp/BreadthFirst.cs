using System.Collections.Generic;

namespace Algorithms
{
    //Based on https://www.geeksforgeeks.org/shortest-distance-two-cells-matrix-grid/
    //Binary-first search
    protected class BreadthFirst
    {
        private const int BLOCKED = 1;
        private const int START = 2;
        private const int END = 3;

        private static int MinDistance(int[][] grid)
        {
            Node source = new Node(0, 0, 0);

            var n = grid.Length;
            var m = grid[0].Length;

            // To keep track of visited QItems. Marking 
            // blocked cells as visited. 
            bool[][] visited = TrackVisited(grid, source, n, m);

            // applying BFS on matrix cells starting from source 
            Queue<Node> q = new Queue<Node>();
            q.Enqueue(source);
            visited[source.X][source.Y] = true;
            while (q.Count > 0)
            {
                var p = q.Dequeue();

                if (grid[p.X][p.Y] == END)
                {
                    return p.DistanceFromSource;
                }

                AddNeighbors(n, m, visited, q, p);
            }
            return -1;
        }

        private static bool[][] TrackVisited(int[][] grid, Node source, int n, int m)
        {
            bool[][] visited = new bool[n][];
            for (int i = 0; i < n; i++)
            {
                visited[i] = new bool[m];
                for (int j = 0; j < m; j++)
                {
                    visited[i][j] = grid[i][j] == BLOCKED;

                    // Finding source 
                    if (grid[i][j] == START)
                    {
                        source.X = i;
                        source.Y = j;
                    }
                }
            }

            return visited;
        }

        private static void AddNeighbors(int n, int m, bool[][] visited, Queue<Node> q, Node p)
        {
            // moving up 
            if (p.X - 1 >= 0 && visited[p.X - 1][p.Y] == false)
            {
                q.Enqueue(new Node(p.X - 1, p.Y, p.DistanceFromSource + 1));
                visited[p.X - 1][p.Y] = true;
            }

            // moving down 
            if (p.X + 1 < n && visited[p.X + 1][p.Y] == false)
            {
                q.Enqueue(new Node(p.X + 1, p.Y, p.DistanceFromSource + 1));
                visited[p.X + 1][p.Y] = true;
            }

            // moving left 
            if (p.Y - 1 >= 0 && visited[p.X][p.Y - 1] == false)
            {
                q.Enqueue(new Node(p.X, p.Y - 1, p.DistanceFromSource + 1));
                visited[p.X][p.Y - 1] = true;
            }

            // moving right 
            if (p.Y + 1 < m && visited[p.X][p.Y + 1] == false)
            {
                q.Enqueue(new Node(p.X, p.Y + 1, p.DistanceFromSource + 1));
                visited[p.X][p.Y + 1] = true;
            }
        }
    }
}
