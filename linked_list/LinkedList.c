#include <stdio.h>
#include <stdlib.h>

struct linkedListNode{
	int data;
	struct linkedListNode *next;
};

typedef struct linkedListNode *node;

node start=NULL;

node createNode(){
	node temp=malloc(sizeof(node));
	temp->data=0;
	temp->next=NULL;
	return temp;
}

void insertNodeBeginning(int val){
	node temp=createNode();
	temp->data=val;
	if(start==NULL){
		start=temp;
		return;
	}
	temp->next=start;
	start=temp;
}

void insertNodeEnd(int val){
	node temp=createNode();
	temp->data=val;
	if(start==NULL){
		start=temp;
		return;
	}
	node ptr=start;
	while(ptr->next!=NULL){
		ptr=ptr->next;
	}
	ptr->next=temp;
}

void insertNodeBefore(int val,int before){
	node temp=createNode();
	temp->data=val;
	if(start==NULL){
		start=temp;
		return;
	}
	node ptr=start;
	node preptr=ptr;
	while(ptr->data!=before){
		preptr=ptr;
		ptr=ptr->next;
	}
	if(preptr==ptr){
		temp->next=ptr;
		start=temp;
		return;
	}
	temp->next=ptr;
	preptr->next=temp;
	
}

void insertNodeAfter(int val,int after){
	node temp=createNode();
	temp->data=val;
	if(start==NULL){
		start=temp;
		return;
	}
	node ptr=start;
	node preptr=ptr;
	while(preptr->data!=after){
		preptr=ptr;
		ptr=ptr->next;
	}
	preptr->next=temp;
	temp->next=ptr;
}

void deleteNodeBeginning(){
	if(start!=NULL){
		start=start->next;
	}
}

void deleteNodeEnd(){
	node ptr=start;
	node preptr=ptr;
	while(ptr->next!=NULL){
		preptr=ptr;
		ptr=ptr->next;
	}
	preptr->next=NULL;
}

void deleteNodeBefore(int before){
	node ptr=start;
	node preptr=ptr;
	while(ptr->next->data!=before){
		preptr=ptr;
		ptr=ptr->next;
	}
	if(preptr==ptr){
		start=ptr->next;
		return;
	}
	preptr->next=ptr->next;
}

void deleteNodeAfter(int after){
	node ptr=start;
	node preptr=ptr;
	while(preptr->data!=after){
		preptr=ptr;
		ptr=ptr->next;
	}
	preptr->next=ptr->next;
}

void print(){
	node ptr=start;
	while(ptr!=NULL){
		printf("%d ",ptr->data);
		ptr=ptr->next;
	}
	printf("\n");
}

int main(){
	insertNodeBeginning(10);
	print();
	insertNodeBeginning(20);
	print();
	insertNodeEnd(40);
	print();
	insertNodeBefore(50,10);
	print();
	insertNodeAfter(60,50);
	print();
	insertNodeAfter(70,40);
	print();
	insertNodeBefore(80,20);
	print();
	insertNodeAfter(90,10);
	print();
	deleteNodeBeginning();
	print();
	deleteNodeEnd();
	print();
	deleteNodeBefore(50);
	print();
	deleteNodeAfter(10);
	print();
	return 0;
}
