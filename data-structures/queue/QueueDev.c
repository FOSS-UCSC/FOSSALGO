#include <stdio.h>
#define max 10
int array[max], val, i;
int front = -1;
int rear = -1;

void enQueue(val){
  if((front==0 && rear == max-1)||(front==rear+1))
    printf("\nQueue is full\n");
  else{
    if((front == -1)&&(rear==-1)){
      front = 0;
    }
    rear = (rear+1) % 10;
    array[rear] = val;
  }
}

void deQueue(){
  if(front == -1)
    printf("\nQueue is empty! \n");
  else{
    
    if(front == rear){
      front = -1;
      rear = -1;
    }
    else{
    	front = (front+1) % max;
	}
  }
}

void display(){
  if(rear == -1)
    printf("\nQueue is empty \n");
   else{
   	if(front<rear){
   		for(i=front; i<= rear; i=(i+1)){
      printf("%d " , array[i]);
	   }}
	else{
    for(i=front; i< max; i=(i+1)){
      printf("%d " , array[i]);
    }
    for(i=0; i<= rear; i=(i+1)){
      printf("%d " , array[i]);
   }}
}}
//This was not a circular queue, i made this as a circular queue. becouse when we try to enqueue 35 it says queue is full, but there is still spaces. so we make it as a circular queue

int main(){
  for (i=0;i<10;i++){
    enQueue(i+5);
  }
	deQueue();
	deQueue();
	display();	
	enQueue(35);
	display();
	
}

