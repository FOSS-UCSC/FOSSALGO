
const dfs = (graph, startNode) => {
    // Create an array / fake "stack" for storing next visiting nodes
    let stack = [startNode];
    let visited = [];

    while (stack.length) {
        // Take first node from stack to visit
        node = stack.shift();

        // Check whether the node is not visited 
        if (visited.indexOf(node) === -1) {
            visited.push(node);
            console.log(`visited ${node}`);
            
            // Find direct-connected node and put to stack if it's not visited
            graph.edges.filter(edge => edge.start == node && !visited.includes(edge.end)).forEach(item => {
                stack = [item.end].concat(stack);
            });
        }
    }
}

function main() {
    let graph = {
        nodes: ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'],
        edges: [
            { start: 'A', end: 'B' },
            { start: 'A', end: 'C' },
            { start: 'B', end: 'D' },
            { start: 'B', end: 'E' },
            { start: 'D', end: 'E' },
            { start: 'D', end: 'F' },
            { start: 'E', end: 'H' },
            { start: 'F', end: 'G' }
        ]
    }
    dfs(graph, 'A');
}

main();