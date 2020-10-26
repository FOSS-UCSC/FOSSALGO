import java.util.Deque;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Map;
import java.util.Set;

public class DepthFirstSearch {

	public static void main(String[] args) {

		Node nodeA = new Node("A");
		Node nodeB = new Node("B");
		Node nodeC = new Node("C");
		Node nodeD = new Node("D");
		Node nodeE = new Node("E");
		Node nodeF = new Node("F");
		Node nodeG = new Node("G");
		Node nodeH = new Node("H");

		Graph graph = new Graph();
		graph.addNode(nodeA, nodeB, nodeC);
		graph.addNode(nodeB, nodeD, nodeE);
		graph.addNode(nodeC);
		graph.addNode(nodeD, nodeE, nodeF);
		graph.addNode(nodeE, nodeH);
		graph.addNode(nodeF, nodeG);
		graph.addNode(nodeG);
		graph.addNode(nodeH);
		
		graph.dfs(nodeA);
	}

}

class Graph {

	private Map<Node, Set<Node>> adjacencyMap;

	public Graph() {
		this.adjacencyMap = new HashMap<>();
	}

	/**
	 * Add a node into the graph. Optionally add its adjacency node if needed.
	 * @param node given node will override if same node existed in the graph.
	 * @param adjacencies
	 */
	public void addNode(Node node, Node... adjacencies) {
		Set<Node> adjacencyNodes = new HashSet<>();
		for (Node adjacency : adjacencies) {
			adjacencyNodes.add(adjacency);
		}
		adjacencyMap.put(node, adjacencyNodes);
	}

	/**
	 * <strong>Depth First Search (DFS)</strong> algorithm traverses a graph in a
	 * depthward motion and uses a stack to remember to get the next vertex to start
	 * a search, when a dead end occurs in any iteration.
	 * 
	 * @param rootNode the node that algorithm start to traverse
	 */
	public void dfs(Node rootNode) {
		// If start node not existed in the graph, then return
		if (adjacencyMap.get(rootNode) == null) {
			return;
		}

		Deque<Node> stack = new LinkedList<>();

		// Put start node to the stack
		stack.push(rootNode);

		while (!stack.isEmpty()) {
			final Node node = stack.pop();
			if (!node.isVisited()) {
				// If the node not visit yet, visit it
				node.visit();

				// Push adjacency nodes of current visiting node to stack
				Set<Node> adjacencyNodes = adjacencyMap.get(node);
				if (adjacencyNodes != null && !adjacencyNodes.isEmpty()) {
					adjacencyNodes.stream().filter(item -> !item.isVisited())
							.forEach(item -> stack.push(item));
				}
			}
		}
	}

}

class Node {

	private String label;
	private boolean visited;

	public Node(String label) {
		this.label = label;
		this.visited = false;
	}

	public String label() {
		return label;
	}

	public boolean isVisited() {
		return visited;
	}

	public void visit() {
		visited = true;
		System.out.println("I visited node " + this.label);
	}

}