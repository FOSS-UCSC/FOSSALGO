#include <stdio.h>
#define max 10

int array[max], val, i;
int front = -1;
int rear = -1;

void enQueue(val){
  if(rear == max-1)
    printf("Queue is full");
  else{
    if(front == -1){
      front = 0;
    }
    rear = rear+1;
    array[rear] = val;
    printf("Inserted value is %d", val);
  }
}

void deQueue(){
  if(front == -1)
    printf("Queue is empty!");
  else{
    printf("deleted value is %d", array[front]);
    front = front+1;
    if(front > rear){
      front = -1;
      rear = -1;
    }
  }
}

void display(){
  if(rear == -1)
    printf("Queue is empty");
   else{
    for(i=front; i<= rear; i++){
      printf("%d", array[i]);
    }
   }
}

int main(){
  enQueue(4);
  enQueue(8);
  enQueue(0);
  enQueue(25);
  enQueue(48);
  deQueue();
  deQueue();
  display();	
	enQueue(35);
	display();
	
return 0;
}
