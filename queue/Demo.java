package demo;



class Node{
	int data;
	Node next;
	Node(int data){
		this.data=data;
	}
}
class Queue{
	private Node front;
	public void enQueue(int data){
		Node n1=new Node(data);
		if(isEmpty()){
			front=n1;
		}else{
			Node t=front;
			while(t.next!=null){
				t=t.next;
			}
			t.next=n1;
		}
	}
	public void printQueue(){
		System.out.print("[");
		Node t=front;
		while(t!=null){
			System.out.print(t.data+", ");
			t=t.next;
		}
		System.out.println(front==null ? "empty]" : "\b\b]");
	}
	public void deQueue(){
		if(!isEmpty()){
			front=front.next; 
		}
	}
	public int size(){
		int count=0;
		Node t=front;
		while(t!=null){
			t=t.next;
			count++;
		}
		return count;
	}
	public void clear(){
		front=null;
	}
	public boolean isEmpty(){
		return front==null;
	}
}
class Demo{
	public static void main(String args[]){
		Queue q1=new Queue();
		q1.enQueue(100);
		q1.enQueue(200);
		q1.enQueue(300);
		q1.enQueue(400);
		q1.enQueue(500);
		
		q1.printQueue(); //[100, 200, 300, 400, 500]
		System.out.println("Size of the Queue : "+q1.size());
		
		q1.deQueue();
		q1.printQueue(); //[200, 300, 400, 500]
		System.out.println("Size of the Queue : "+q1.size());//4
		
		q1.clear();	
		q1.printQueue(); //[empty]
		System.out.println("Size of the Queue : "+q1.size());//0
	}
}
