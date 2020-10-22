
//created question as object
  const graph = {
    start: { A: 5, D: 8 },
    A: { B: 9, C: 3 },
    D: { C: 4, E: 6 },
    C: { B: 5, E: 2 },
    B: { en d:  },
    E: { end: 4 },
    end: {}
  };

  function shortestCostNode (costs, processed)  {
    return Object.keys(costs).reduce((lowest, node) => {
      if (lowest === null || costs[node] < costs[lowest]) {
        if (!processed.includes(node)) {
          lowest = node;
        }
      }
      return lowest;
    }, null);
  }

  // this function returns the minimum cost and path to reach end
  function shortestPath(graph) {

    // track lowest cost to reach each node
    const costs = Object.assign({end: Infinity}, graph.start);
    const parents = {end: null};
    for (let child in graph.start) {
      if((graph.start).hasOwnProperty(child)){
        parents[child] = 'start';
      }
    }

    // track nodes that have already been processed
    const processed = [];
    let node = shortestCostNode(costs, processed);

    while (node) {
      let cost = costs[node];
      let children = graph[node];
      for (const [key, child] of Object.entries(children)) {
      let newCost = cost + children[key];
        if (!costs[key] || costs[key] > newCost) {
          costs[key] = newCost;
          parents[key] = node;
        }
      }
      processed.push(node);
      node = shortestCostNode(costs, processed);
    }

    const optimalPath = ["end"];
    let parent = parents.end;
    while (parent) {
      optimalPath.unshift(parent);
      parent = parents[parent];
    }

    const result = {
      distance: costs.end,
      path: optimalPath
    };

    return result;
  }
