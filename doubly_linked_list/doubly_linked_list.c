#include<stdio.h>
#include<stdlib.h>

//create linklist node  structure using struct
struct linkListNode{
	struct linkListNode *previous;
	int data;
	struct linkListNode *next;
};
typedef struct linkListNode *node;

node head=NULL;
node start=NULL;

addNode(int);
deleteNode(int);
node createNode();

//code for create node
node createNode(){
	node newNode;
	newNode=(node)malloc(sizeof(node));
	return newNode;
}

//code for add a node into the list
addNode(int data){
	node myNode=createNode();
	myNode->previous=head;
	myNode->data=data;
	myNode->next=NULL;
	if(head==NULL)
		start=myNode;
	else
		head->next=myNode;
	head=myNode;
}

//code for delete a given node
//it may be 1st or last or any
deleteNode(int data){
	node temp=start;
	while(temp->data!=data){
		temp=temp->next;
	}
	if(temp==start){
		start=start->next;	
		start->previous=NULL;
	}else if(temp->next==NULL){
		temp->previous->next=NULL;
	}else{
		temp->previous->next=temp->next;
		temp->next->previous=temp->previous;
	}
	free(temp);
} 
int main(){
	//call hear above function..
	//addNode(int) this function for create and add a node to linklist..
	//deleteNode(int) this function for delate any given node...
	return 0;
}
