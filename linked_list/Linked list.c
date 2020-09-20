#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *link;
};

struct node *root=NULL;

void insertion(){
	struct node *tmp;
	tmp=(struct node*)malloc(sizeof(struct node));
	printf("Enter data:");
	scanf("%d",&tmp->data);
	tmp->link=NULL;
	if(root==NULL){
		root=tmp;
	}
	else{
		struct node *p;
		p=root;
		while(p->link!=NULL){
			p=p->link;
		}
		p->link=tmp;
	}
}
void display(){
	struct node *tmp;
	if(root==NULL){
		printf("No linked list:");
	}
	else{
		tmp=root;
		while(tmp!=NULL){
			printf("%d-->",tmp->data);
			tmp=tmp->link;
		}
	}
}

void addNodeAt1(){
	struct node *tmp;
	tmp=(struct node*)malloc(sizeof(struct node));
	printf("Enter data:");
	scanf("%d",&tmp->data);
	tmp->link=NULL;
	if(root==NULL){
		root=tmp;
	}
	else{
		tmp->link=root;
		root=tmp;
	}
}

int main(){
	int n,i;
	printf("Enter number of node:");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		insertion();
		
//	}
	display();
/*	printf("\n");
	addNodeAt1();
	printf("\n");
	display();*/
}
}












