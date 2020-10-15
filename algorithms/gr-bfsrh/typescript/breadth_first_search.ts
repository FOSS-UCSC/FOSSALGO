class Graph {
    v: number;  //number of vertices
    adjacencies: Array<Array<number>>;   //Adjacency Lists

    constructor(value: number) {
        this.v = value;
        this.adjacencies = [];
        this.adjacencies[0] = [];
    }

    addNode(node: number) {
        this.adjacencies[node] = [];
    }

    addEdge(node1: number, node2: number) {
        this.adjacencies[node1].push(node2);
    }

    // === Breadth First Search ===
    breadthFirstSearch(cb?: Function) {
        const visitedNodes: Array<number> = [];
        let nodesToProcess: Array<number> = [0];

        while (nodesToProcess.length) {
            const node = nodesToProcess.shift();

            // process the node if there is a callback
            if (cb) {
                const result = cb(node, visitedNodes, nodesToProcess);
                if (result === true) {
                    break;
                }
            }

            if (!(visitedNodes.indexOf(node) > -1)) {
                nodesToProcess = nodesToProcess.concat(this.adjacencies[node]);
                visitedNodes.push(node);
            }
        }
        return visitedNodes;
    }

}


const main = function () {
    const graph = new Graph(4);

    graph.addNode(0);
    graph.addNode(1);
    graph.addNode(2);
    graph.addNode(3);

    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 2);
    graph.addEdge(2, 0);
    graph.addEdge(2, 3);
    graph.addEdge(3, 3);

    var result = graph.breadthFirstSearch();
}

main();
