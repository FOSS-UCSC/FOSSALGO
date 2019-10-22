#include <iostream>
using namespace std;

#define max 10
int array[max], val, i;
int front = -1;
int rear = -1;
void enQueue(int);
void deQueue();
void deQueue();

void enQueue(val){
  if(rear == max-1)
    cout << "Queue is full";
  else{
    if(front == -1){
      front = 0;
    }
    rear = rear+1;
    array[rear] = val;
  }
}

void deQueue(){
  if(front == -1)
    cout <<"Queue is empty!";
  else{
    return( array[front]);
    front = front+1;
    if(front > rear){
      front = -1;
      rear = -1;
    }
  }
}

void display(){
  if(rear == -1)
    cout << "Queue is empty");
   else{
    for(i=front; i<= rear; i++){
      printf("%d" array[i]);
    }
   }
}

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
