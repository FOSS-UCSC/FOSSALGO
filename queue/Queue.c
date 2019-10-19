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
  }
}
