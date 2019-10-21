//implement a linear queue
#include<stdio.h>
#define max 5
int enqueue() , dequeue(), front(), size(), isEmpty(), isFull();

int que[max];
int c,f=-1,r=-1,en;
int main(){
		printf("1-enqueue\n2-dequeue\n3-peek\n4-size\n5-isEmpty\n6-isFull\n\n");

	while(1){
		printf("enter your choice: ");
		scanf("%d",&c);
		switch(c){
			case 1:
				printf("enter number to enqueue: ");
				scanf("%d",&en);
				enqueue(en);
				break;
			case 2:
				dequeue();
				break;
			case 3:
				printf("front value: %d\n",front());
				break;
			case 4:
				printf("size is : %d\n",size());
				break;
			case 5:
				if(isEmpty()){
					printf("queue is not empty\n");
				}
				else{
					printf("queue is empty\n");
				}
				break;
			case 6:
				if(isFull()){
					printf("queue is not full\n");
				}
				else{
					printf("queue is full\n");
				}
				
				break;			
		}
	}
}
int dequeue(){
	if(isEmpty()){
		printf("dequeued value : %d\n",que[f]);
		f++;
	}
	else{
		printf("queue is empty\n");
	}
}
int size(){
	if(r==-1){
		return 0;
	}
	else{
		return r-f+1;
	}
}
int isFull(){
	if (r==max-1){
		return 0;
	}
	else{
		return 1;
	}
}
int isEmpty(){
	if (f==-1 || f>r){
		return 0;
	}
	else{
		return 1;
	}
}

int enqueue(int en){
	if(isFull()){
		if(r==-1){
			f=0;
		}
		r++;
		que[r]=en;
//		printf("%d",r);
	}
	else{
		printf("que is full\n");
	}	
}
int front(){
	return que[f];
}
