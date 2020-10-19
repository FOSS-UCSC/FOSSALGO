
//created question as object
const question = {
    start: {A: 5, D: 8},
    A: {B: 9, C: 3},
    D: {C: 4, E: 6},
    C: {B: 5, E: 2},
    B: {end: 7},
    E: {end: 4},
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
      if((graph.start).hasOwnProperty(child)) {
          parents[child] = "start";
      }
  }

    // track nodes that have already been processed
    const processed = [];

    let node = shortestCostNode(costs, processed);

    while (node) {
      let cost = costs[node];
      let children = graph[node];
      for (let n in children) {
        if(children.hasOwnProperty(n)){
          let newCost = cost + children[n];
          if (!costs[n]) {
            costs[n] = newCost;
            parents[n] = node;
          }
          if (costs[n] > newCost) {
            costs[n] = newCost;
            parents[n] = node;
          }
        }
      }
      processed.push(node);
      node = shortestCostNode(costs, processed);
    }

    let optimalPath = ["end"];
    let parent = parents.end;
    while (parent) {
      optimalPath.push(parent);
      parent = parents[parent];
    }
    optimalPath.reverse();

    const result = {
      distance: costs.end,
      path: optimalPath
    };

    return result;
  }
