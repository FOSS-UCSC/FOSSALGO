#include<stdio.h>
#define max 50

int front = -1;
int rear = -1;
int arr[max], a, i;

void display(){
  if(rear == -1){
    printf("\n\tQueue is empty\n");
   }else{
    for(i=front; i<= rear; i++){
      printf("|%d\n",arr[i]);
    }
   }
}

void enQueue(a){
  if(rear == max-1){
    printf("\n\tQueue is full\n");
  }else{
    if(front == -1){
      front = 0;
    }
    rear = rear+1;
    arr[rear] = a;
    printf("\n\tEnqueued\n");
  }
}

void deQueue(){
    if(front == -1){
        printf("\n\tQueue is empty\n");
    }else{
    	printf("\n\tDequeued\n");
        return( arr[front++]);
        //front = front+1;
    }    
    if(front > rear){
      front = -1;
      rear = -1;
    }
}

int main(){
	int n,value;
		
		
		while(1){
	 	printf("\n1:Enqueue");
		printf("\n2:Dequeue");
		printf("\n3:Display");
		printf("\n4:Exit\n");
	 	scanf("%d",&n);
	 	
	 	switch(n){
	 		case 1:
	 			scanf("%d",&value);
			 	enQueue(value);
	 			break;
	 			
	 		case 2:deQueue();
	 			break;
	 			
	 		case 3:display();
	 			break;
	 			
	 			
	 		default:printf("\nInvalid");
		 }
	 }
}