// Building binary tree and tree traversal
#include<iostream>
using namespace std;

struct node{
	int val;
	
	node *left;
	node *right;
};

void printArr(int arr[], int length);
void addNode(node **root, int data);

void preorderTraversal(node *root);
void inorderTraversal(node *root);
void postorderTraversal(node *root);

int main(){
	int arr[] = {4,2,5,8,7,6,9,1,3,4,5,4,2};
	int length = sizeof(arr)/sizeof(arr[1]);
	
	cout<<"Real List : ";
	printArr(arr, length);
	
	node *head = NULL;
	
	for(int i=0; i<length; i++){
		addNode(&head, arr[i]);
	}
	
	cout<<"Preorder Traversal  : ";
	preorderTraversal(head);
	cout<<endl;
	
	cout<<"Inorder Traversal   : ";
	inorderTraversal(head);
	cout<<endl;
	
	cout<<"Postorder Traversal : ";
	postorderTraversal(head);
	cout<<endl;
	
	
}

void printArr(int arr[], int length){
	for(int i=0; i<length; i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

void addNode(node **root, int data){
	if(*root==NULL){
		node *temp = new node;
		temp->val = data;
		temp->left = NULL;
		temp->right = NULL;
		*root = temp;
	}else{
		if((*root)->val>data){
			addNode((&(*root)->left), data);
		}else{
			addNode((&(*root)->right), data);
		}
	}
}

void preorderTraversal(node *root){
	if(root!=NULL){
		cout<<root->val<<" ";
		preorderTraversal(root->left);
		preorderTraversal(root->right);
	}
}

void inorderTraversal(node *root){
	if(root!=NULL){
		inorderTraversal(root->left);
		cout<<root->val<<" ";
		inorderTraversal(root->right);
	}
}

void postorderTraversal(node *root){
	if(root!=NULL){
		postorderTraversal(root->left);
		postorderTraversal(root->right);
		cout<<root->val<<" ";
	}
}
