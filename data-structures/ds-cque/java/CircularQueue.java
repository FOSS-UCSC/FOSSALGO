public class CircularQueue
{
  private int SIZE = 5;
  private int front;
  private int rear;
  private int items[] = new int[SIZE];

    CircularQueue ()
  {
    front = -1;
    rear = -1;
  }

  // Check if the queue is full
  private boolean isFull ()
  {
    if (front == 0 && rear == SIZE - 1)
      {
	return true;
      }
    return front == rear + 1;
  }

  // Check if the queue is empty
  private boolean isEmpty ()
  {
    return front == -1;
  }

  // Adding an element
  private void enQueue (int element)
  {
    if (isFull ())
      {
	System.out.println ("Queue is full");
      }
    else
      {
	if (front == -1)
	  front = 0;
	rear = (rear + 1) % SIZE;
	items[rear] = element;
	System.out.println ("Inserted " + element);
      }
  }

  // Removing an element
  private int deQueue ()
  {
    int element;
    if (isEmpty ())
      {
	System.out.println ("Queue is empty");
	return (-1);
      }
    else
      {
	element = items[front];
	if (front == rear)
	  {
	    front = -1;
	    rear = -1;
	  }
	else
	  {
	    front = (front + 1) % SIZE;
	  }
	return (element);
      }
  }

  private void display ()
  {
    int i;
    if (isEmpty ())
      {
	System.out.println ("Empty Queue");
      }
    else
      {
	System.out.println ("Front -> " + front);
	System.out.println ("Items -> ");
	for (i = front; i != rear; i = (i + 1) % SIZE)
	  System.out.print (items[i] + " ");
	System.out.println (items[i]);
	System.out.println ("Rear -> " + rear);
      }
  }

  public static void main (String[]args)
  {

    CircularQueue q = new CircularQueue ();
    q.deQueue ();

    q.enQueue (1);
    q.enQueue (2);
    q.enQueue (3);
    q.enQueue (4);
    q.enQueue (5);
    q.enQueue (6);

    q.display ();

    int elem = q.deQueue ();

    if (elem != -1)
      {
	System.out.println ("Deleted Element is " + elem);
      }
    q.display ();

    q.enQueue (7);

    q.display ();

    q.enQueue (8);
  }

}
