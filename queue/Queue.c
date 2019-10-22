#include <stdio.h>
#define max 10
int queue[max], val,val2, i;
int front = -1;
int rear = -1;
void enQueue(val);
int deQueue();
void display();

void enQueue(val)
{
  if(rear == max-1)
  {
  	printf("\nQueue is full");
  }
    
  else if(front==-1 && rear == -1)
  {
  	front = rear = 0;
  }
  
  else
  {
  	rear = rear+1;
    queue[rear] = val;
  }
}

int deQueue()
{
  if(front == -1|| front>rear)
  {
  	printf("\nQueue is empty!");
  	return -1;
  }
    
  else
  {
    val2=queue[front];
    front = front+1;
    if(front > rear)
	{
      front = -1;
      rear = -1;
    }
    return val2;
  }
}

void display()
{
  if(front==-1 || front>rear)
  {
  	printf("\nQueue is empty");
  }
    
  else
  {
  	printf("\n");	
    for(i=front; i<= rear; i++)
    {
	  printf("%d ",queue[i]);
    }
    
  }
}

int main()
{
	
  	
  for (i=0;i<10;i++)
  {
    enQueue(i+5);
  }
  deQueue();
  deQueue();
  display();	
	enQueue(35);
	display();
	
}
