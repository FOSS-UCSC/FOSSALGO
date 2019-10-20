#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *left;
	struct node *right;
};
struct node * insert(struct node *temp,int x);
struct node * out(struct node *temp1);
int main(){
	int val;
	struct node *root =NULL;
	printf("enter value to insert into BST, \nenter 200 to print the BST inorder traversal\n\n\n");
	while(1){
		scanf("%d",&val);
		if(val==200){
			out(root);
			continue;
		}
		if(root==NULL){
			root = insert(root,val);
		}
		else{
		
			insert(root,val);
		}
	
		
	}
return 0;
}
struct node * insert(struct node *temp,int x){
	
	if (temp==NULL){
		temp = (struct node*)malloc(sizeof(struct node));
		temp->data=x;
		temp->left=NULL;
		temp->right=NULL;
		return temp;
		
	}
	else{
		if(temp->data<x){
			temp->right= insert(temp->right,x);
		}
		else{
			temp->left= insert(temp->left,x);
		}
	}
}
struct node * out(struct node *temp1){
	if(temp1==NULL){
	
		return;
	}
	else{
		out(temp1->left);
		printf("%d ",temp1->data);
		out(temp1->right);
	}	
}
