#include<stdio.h>
#include<stdlib.h>
struct linkListNode{
	int data;
	struct linkListNode *next;
};
typedef struct linkListNode *node;

node head=NULL;
node start=NULL;

node createNode(){
	node newNode;
	newNode = (node)malloc(sizeof(struct linkListNode));
	return newNode;
}

addNode(int data){
	node myNode=createNode();
	myNode->data=data;
	myNode->next=NULL;
	if(head==NULL)
		start=myNode;
	else
		head->next=myNode;
	head=myNode;
}

deleteNode(int data){
	node temp=start;
	node pre=start;
	while(temp->data!=data){
		pre=temp;
		temp=temp->next;
	}
	if(temp==start)
		start=start->next;
	else
		pre->next=temp->next;
	free(temp);
}

int main(){
	addNode(0);
	addNode(1);
	addNode(2);
	addNode(3);
	addNode(4);
	
	

	//traverce
	node tem=start;
	while(tem!=NULL){
		printf("%d ",tem->data);
		tem=tem->next;
	}
		
	return 0;
}
