#include<stdio.h>
#include<stdlib.h>

struct linkListNode{
	int data;
	struct linkListNode *next;
};
typedef struct linkListNode *node;

node head=NULL;
node start=NULL;

node createNode();
void addNode(int);
void deleteNode(int);

node createNode(){
	node newNode;
	newNode=(node)malloc(sizeof(node));
	return newNode;
}

void addNode(int data){
	node myNode=createNode();
	myNode->data=data;
	myNode->next=NULL;
	if(head==NULL)
		start=myNode;
	else
		head->next=myNode;
	head=myNode;
}

void deleteNode(int data){
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
	
	return 0;
}
