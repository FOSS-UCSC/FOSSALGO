import java.util.Deque;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Map;
import java.util.Set;

public class BreadthFirstSearch {
	
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
		
		graph.bfs(nodeA);
	}
	
	static class Graph {

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
		 * <strong>Breadth First Search (BFS)</strong> algorithm traverses a graph in a
		 * breadthward motion and uses a queue to remember to get the next vertex to
		 * start a search, when a dead end occurs in any iteration..
		 * 
		 * @param rootNode the node that algorithm start to traverse
		 */
		public void bfs(Node rootNode) {
			// If start node not existed in the graph, then return
			if (adjacencyMap.get(rootNode) == null) {
				return;
			}

			Deque<Node> queue = new LinkedList<>();

			// Put start node to the end of queue
			queue.add(rootNode);

			while (!queue.isEmpty()) {
				final Node node = queue.poll();
				if (!node.isVisited()) {
					// If the node not visit yet, visit it
					node.visit();

					// Push adjacency nodes of current visiting node to the end of queue
					Set<Node> adjacencyNodes = adjacencyMap.get(node);
					if (adjacencyNodes != null && !adjacencyNodes.isEmpty()) {
						adjacencyNodes.stream().filter(item -> !item.isVisited())
								.forEach(item -> queue.add(item));
					}
				}
			}
		}
	}
	
	static class Node {

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

}
