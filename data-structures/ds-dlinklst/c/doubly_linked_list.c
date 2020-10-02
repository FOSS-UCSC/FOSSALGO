#include <stdio.h>
#include <stdlib.h>

struct linkedListNode{
	int data;
	struct linkedListNode *prev,*next;
};

typedef struct linkedListNode *node;

node start=NULL;

node createNode(){
	node temp=malloc(8); // sizeof(node) is generate an issue
	temp->data=0;
	temp->prev=temp->next=NULL;
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
	start->prev=temp;
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
	temp->prev=ptr;
}

void insertNodeBefore(int val,int before){
	node temp=createNode();
	temp->data=val;
	if(start==NULL){
		start=temp;
		return;
	}
	node ptr=start;
	while(ptr->data!=before){
		ptr=ptr->next;
	}
	if(ptr==start){
		temp->next=ptr;
		ptr->prev=temp;
		start=temp;
		return;
	}
	temp->prev=ptr->prev;
	ptr->prev->next=temp;
	temp->next=ptr;
	ptr->prev=temp;
}

void insertNodeAfter(int val,int after){
	node temp=createNode();
	temp->data=val;
	if(start==NULL){
		start=temp;
		return;
	}
	node ptr=start;
	while(ptr->data!=after){
		ptr=ptr->next;
	}
	temp->next=ptr->next;
	temp->prev=ptr;
	ptr->next=temp;
}

void deleteNodeBeginning(){
	if(start!=NULL){
		start=start->next;
		start->prev=NULL;
	}
}

void deleteNodeEnd(){
	node ptr=start;
	while(ptr->next!=NULL){
		ptr=ptr->next;
	}
	ptr->prev->next=NULL;
}

void deleteNodeBefore(int before){
	node ptr=start;
	while(ptr->next->data!=before){
		ptr=ptr->next;
	}
	if(ptr==start){
		start=ptr->next;
		start->prev=NULL;
		return;
	}
	ptr->prev->next=ptr->next;
	ptr->next->prev=ptr->prev;
}

void deleteNodeAfter(int after){
	node ptr=start;
	while(ptr->data!=after){
		ptr=ptr->next;
	}
	ptr->next->next->prev=ptr;
	ptr->next=ptr->next->next;
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
