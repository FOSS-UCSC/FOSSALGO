public class BST {
	Node root;
	int count;
	
	public BST(){
		root = null;
		this.count = 0;
	}
	
	public void insert(int data){
		if (this.root == null) {
			this.root = new Node(data);
		}else{
			this._insert(data, this.root);
		}
		count++;
	}
	
	public void _insert(int data, Node current){
		if (data<current.data) {
			if (current.left == null) {
				current.left = new Node(data);
			}else{
				this._insert(data, current.left);
			}
		}else{
			if (current.right == null) {
				current.right = new Node(data);
			}else{
				this._insert(data, current.right);
			}
		}
	}
	
	public void inorder(){		
			this._inorder(this.root);
	}
	
	public void _inorder(Node root){
		if (root == null){
			System.out.print("Tree is empty!");
		}else{
			System.out.print(root.data);
			if (root.left != null){
				this._inorder(root.left);
			}
			if (root.right != null){
				this._inorder(root.right);
			}
		}
	}
}

class Node{
	int data;
	Node left;
	Node right;

	public Node(int data){
		this.data = data;
		this.left = null;
		this.right = null;
	}
}