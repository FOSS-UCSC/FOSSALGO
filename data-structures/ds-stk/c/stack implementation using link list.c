#include<stdio.h>
#include<stdlib.h>
struct linkListNode{
	int data;
	struct linkListNode *next;
};
typedef struct linkListNode *node;

node start=NULL;

node createNode(){
	node newNode;
	newNode=(node)malloc(sizeof(node));
	return newNode;
}

push(int data){
	node myNode=createNode();
	myNode->data=data;
	myNode->next=start;
	start=myNode;
	
}

pop(){
	if(start!=NULL){
		node temp=start;
		start=start->next;
		free(temp);
	}else{
		printf("Underflow error.");
	}
}

int main(){
	push(2);
	push(1);
	push(3);
	push(5);
	push(4);
	pop();
	pop();
	
	//traverce
	node tem=start;
	while(tem!=NULL){
		printf("%d ",tem->data);
		tem=tem->next;
	}
		
	return 0;
}
