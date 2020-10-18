/*
* Dijkstra's single source shortest path algorithm in JavaScript.
 */
 const dijkstraAlgorithm = function (graph, start) {

    //the distances from the start node to all other nodes
    var distance = [];
    //Initial distance is "Infinity"
    for (var i = 0; i < graph.length; i++) distance[i] = Number.MAX_VALUE;
    //The distance from the start node to itself is 0
    distance[start] = 0;

    //it contains whether a node was already visited
    var visited = [];

    //While there are nodes left to visit
    while (true) {
        //find the node with the currently shortest distance from the start node
        var shortestDistance = Number.MAX_VALUE;
        var shortestIndex = -1;
        for (var i = 0; i < graph.length; i++) {
            if (distance[i] < shortestDistance && !visited[i]) {
                shortestDistance = distance[i];
                shortestIndex = i;
            }
        }

        console.log("Visiting node " + shortestDistance + " with current distance " + shortestDistance);

        if (shortestIndex === -1) {
            // There was no node not yet visited
            return distance;
        }

        //for all neighboring nodes....
        for (var i = 0; i < graph[shortestIndex].length; i++) {
            //...if the path over this edge is shorter...
            if (graph[shortestIndex][i] !== 0 && distance[i] > distance[shortestIndex] + graph[shortestIndex][i]) {
                //...Save this path as new shortest path.
                distance[i] = distance[shortestIndex] + graph[shortestIndex][i];
                console.log("Updating distance of node " + i + " to " + distance[i]);
            }
        }
        // Lastly we finished with this node.
        visited[shortestIndex] = true;
        console.log("Visited nodes: " + visited);
        console.log("Currently lowest distance: " + distance);

    }
};

module.exports = {dijkstraAlgorithm};
