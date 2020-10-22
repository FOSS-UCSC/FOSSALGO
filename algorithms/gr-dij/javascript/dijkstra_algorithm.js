
//created question as object
  const graph = {
    start: { A: 5, D: 8 },
    A: { B: 9, C: 3 },
    D: { C: 4, E: 6 },
    C: { B: 5, E: 2 },
    B: { end: 7 },
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

  function parentChild(graph){
    const parentobj = { end:null };
    for (let child in graph.start) {
      if(graph.start.hasOwnProperty(child)){
        parentobj[child] = "start";
      }
    }
    return parentobj;
  }

  function optimalarray(parents){
   const optimalPath = ["end"];
   let parent = parents.end;
   while (parent) {
     optimalPath.unshift(parent);
     parent = parents[parent];
   }
   return optimalPath;
 }

  // this function returns the minimum cost and path to reach end
  function shortestPath(graph) {

    // track lowest cost to reach each node
    const costs = Object.assign({end: Infinity}, graph.start);
    let parents = parentChild(graph);

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

    let optimalPaths= optimalarray(parents);

    // Shortest distance and path from start to end

    const result = {
      distance: costs.end,
      path: optimalPaths
    };

    return result;
  }
