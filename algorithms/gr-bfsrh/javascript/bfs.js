function doBFS(graph, root) {
  let nodesLength = {}; // obj with distances to the root node

  for (let i = 0; i < graph.length; i++) {
    nodesLength[i] = Infinity; // init all nodes in graph and set dist to INF
  }
  nodesLength[root] = 0;

  let queue = [root];
  let current;

  while (queue.length !== 0) {
    current = queue.shift();

    let currentConnected = graph[current];
    let neighborIdx = [];
    let idx = currentConnected.indexOf(1);

    while (idx !== -1) {
      neighborIdx.push(idx);
      idx = currentConnected.indexOf(1, idx + 1);
    }

    for (let j = 0; j < neighborIdx.length; j++) {
      if (nodesLength[neighborIdx[j]] === Infinity) {
        nodesLength[neighborIdx[j]] = nodesLength[current] + 1;
        queue.push(neighborIdx[j]);
      }
    }
  }
  return nodesLength;
}

