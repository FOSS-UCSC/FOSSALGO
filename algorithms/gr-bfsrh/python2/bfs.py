from collections import deque
#graph: List[List[int]]
#s: start vertex
def bfs(graph, s):
    visited = set()
    queue = deque()

    visited.add(s)
    queue.appendleft(s)

    while queue:
        current_vertex = queue.pop()
        print(current_vertex)
        for v in graph[current_vertex]:
          if v not in visited:
             visited.add(v)
             queue.appendleft(v)
#Testing Function Call
bfs([[1,2,3],[8,6,8],[2,9,3],[2,5,7],[5,4,1],[0,8,7]], 4)
