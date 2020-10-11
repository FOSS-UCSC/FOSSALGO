def breadth_first_search(graph, node):
  if node not in graph: return

  queue = [node]
  visited = [node]

  while len(queue) > 0:
    node = queue.pop(0)
    print(node, end = " ")

    for neighbor in graph[node]:
      if neighbor not in visited:
        visited.append(neighbor)
        queue.append(neighbor)


#key is node, list is neighbors
sample_graph = {
  0: [1, 2, 3, 5],
  1: [2, 3, 5],
  2: [4, 5],
  3: [4],
  4: [5],
  5: []
}

breadth_first_search(sample_graph, 0)