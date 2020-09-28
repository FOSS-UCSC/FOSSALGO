#include<stdio.h>
#define max 50

int front = -1;
int rear = -1;
int arr[max], a, i;

void display(){
  if(rear == -1){
    printf("Queue is empty");
   }else{
    for(i=front; i<= rear; i++){
      printf("%d", arr[i]);
    }
   }
}

void enQueue(a){
  if(rear == max-1){
    printf("Queue is full");
  }else{
    if(front == -1){
      front = 0;
    }
    rear = rear+1;
    arr[rear] = a;
  }
}

void deQueue(){
    if(front == -1){
        printf("Queue is empty");
    }else{
        return( arr[front]);
        front = front+1;
    }    
    if(front > rear){
      front = -1;
      rear = -1;
    }
}git

int main(){
    enQueue(10);
    enQueue(25);
    display();	
    deQueue();
    display();	
	enQueue(17);
    enQueue(15);
    deQueue();
	display();
}