const bfs = (graph, root, targetNode) => {

  buildPath = (parents, targetNode) => {
    let result = [targetNode];
    while (parents[targetNode] !== null) {
      targetNode = parents[targetNode];
      result.push(targetNode);
    }
    return result.reverse();
  };

  let parents = [];
  let queue = [];
  let visited = [];
  let current;

  queue.push(root);
  parents[root] = null;
  visited[root] = true; // mark first node as visited

  while(queue.length !== -1) {
    current = queue.shift();

    if (current === targetNode) {
      return buildPath(parents, targetNode);
    }

    for (let i = 0; i < graph.length; i++) {
      if (i !== current && graph[current][i] && !visited[i]) {
        parents[i] = current;
        visited[i] = true;
        queue.push(i);
      }
    }
  }
  return null;
};

// Test Example
const graph = [[1, 1, 0, 0, 1, 0],
             [1, 0, 1, 0, 1, 0],
             [0, 1, 0, 1, 0, 0],
             [0, 0, 1, 0, 1, 1],
             [1, 1, 0, 1, 0, 0],
             [0, 0, 0, 1, 0, 0]];

const shortestPath = bfs(graph, 1, 5); // [1, 2, 3, 5]
