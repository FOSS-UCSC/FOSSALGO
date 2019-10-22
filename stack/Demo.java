
package demo;

class Node{
	int data;
	Node next;
	Node(int data){
		this.data=data;
	}
}
class Stack{
	private Node top;
	public void push(int data){
		Node n1=new Node(data);
		n1.next=top;
		top=n1;
	}
	public void printStack(){
		System.out.print("[");
		Node t=top;
		while(t!=null){
			System.out.print(t.data+", ");
			t=t.next;
		}
		System.out.println(top==null ? "empty]" : "\b\b]");
	}
	public void pop(){
		if(top==null){
			System.out.println("Stack is empty...");
		}else{
			top=top.next;
		}
	}
}
class Demo{
	public static void main(String args[]){
		Stack s1=new Stack();
		s1.push(100);
		s1.push(200);
		s1.push(300);
		s1.push(400);
		s1.push(500);
		s1.printStack();//[500, 400, 300, 200, 100]
		
		s1.pop();
		s1.printStack();//[400, 300, 200, 100]
	}
}
