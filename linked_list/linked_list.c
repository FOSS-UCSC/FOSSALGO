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

int main(){
	
	return 0;
}
