from collections import deque

# graph: List[List[int]]
# s: start vertex
def bfs(graph, s):
    # set is used to mark visited vertices
    visited = set()

    # create a queue for BFS 
    queue = deque()

    # Mark the start vertex as visited and enqueue it
    visited.add(s)
    queue.appendleft(s)

    while queue:
        current_vertex = queue.pop()
        print(current_vertex)

        # Get all adjacent vertices of current_vertex 
        # If a adjacent has not been visited, then mark it 
        # visited and enqueue it
        for v in graph[current_vertex]:
          if graph[current_vertex] == None:
            return
            if v not in visited:
                visited.add(v)
                queue.appendleft(v)
                
# Testing Function Call
bfs([[1,2,3],[8,6,8],[2,9,3],[2,5,7],[5,4,1],[0,8,7]], 4)
