public class BST {
    private Node root;
    public int count;

    public BST() {
        root = null;
        this.count = 0;
    }

    public void insert(int data) {
        if (this.root == null) {
            this.root = new Node(data);
        } else {
            this.insertDate(data, this.root);
        }
        count++;
    }

    public void insertDate(int data, Node current) {
        if (data < current.data) {
            if (current.left == null) {
                current.left = new Node(data);
            } else {
                this.insertDate(data, current.left);
            }
        } else {
            if (current.right == null) {
                current.right = new Node(data);
            } else {
                this.insertDate(data, current.right);
            }
        }
    }

    public void inorder() {
        this.inorderNode(this.root);
    }

    public void inorderNode(Node root) {
        if (root == null) {
            System.out.print("Tree is empty!");
        } else {
            System.out.print(root.data);
            if (root.left != null) {
                this.inorderNode(root.left);
            }
            if (root.right != null) {
                this.inorderNode(root.right);
            }
        }
    }
}

class Node {
    private int data;
    private Node left;
    private Node right;

    public Node(int data) {
        this.data = data;
        this.left = null;
        this.right = null;
    }
}
