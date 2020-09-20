//trees
#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node* right;
	struct node * left;
};
	
	
struct node * root =NULL;
struct node * ptr1,*ptr2;

void insert(int val){
	struct node * new_node,*parent;
	new_node=(struct node*)malloc(sizeof(struct node));
	new_node->data=val;
	new_node->left=NULL;
	new_node->right=NULL;
	parent=root;
	if(root== NULL){
		root=new_node;
	
	
	
	}else{
		struct node * ptr;
		ptr=root;	
		while(ptr){
			parent=ptr;
			
			if(ptr->data < new_node->data){
				ptr=ptr->right;
				
			}else{
				ptr=ptr->left;
			}
			
		}
		
		if(parent->data < new_node->data){
			parent->right=new_node;
		}else{
				parent->left=new_node;
		}
		 
		
	}
}	

void preorder(struct node * ptr){
//	struct node *ptr;
	//ptr=root;
	if(ptr != NULL){
		printf("%d ",ptr->data);
		preorder(ptr->left);
		preorder(ptr->right);
	}
	
}
void inorder(struct node*ptr){ 
	
	if(ptr!=NULL){
		inorder(ptr->left);
		printf("%d ",ptr->data);
		inorder(ptr->right);
	}
}

void postorder(struct node* ptr){
	
	if(ptr!=NULL){
		postorder(ptr->left);
		postorder(ptr->right);
		printf("%d ",ptr->data);
		
	}
	
}
void smallest(struct node* ptr){
	
	if(ptr==NULL || ptr->left ==NULL){
		printf("\n The smallest node = %d",ptr->data);
	}else{
		smallest(ptr->left);
	}
	
}
void largest(struct node*ptr){
	if(ptr==NULL || ptr->right==NULL){
		printf("\nThe Largest Node is = %d",ptr->data);
		ptr1=ptr;
		
	}else{
		ptr2=ptr;
		largest(ptr->right);
	}
}
void search(struct node *ptr,int val){
	
	if(ptr==NULL){
		printf("The Not  found");
	}else if(ptr->data==val){
		printf("The found %d",ptr->data);
	}else if(val>ptr->data){
		search(ptr->right,val);
	}else if(val< ptr->data){
		search(ptr->left,val);
	}
		
	
}
void deleteele(struct node*ptr,int val){
	struct node * parent,*curr;
while(ptr->data!=val){
		parent=ptr;
	if(ptr->data>val){
		ptr=ptr->left;
	}else{
		ptr=ptr->right;
	}
		
}
printf("\n parent node= %d",parent->data);
printf("\n Delete node= %d",ptr->data);

//deletion of nodes
 //1 type
 if(ptr->left ==NULL && ptr->right==NULL){
 	if(parent->left==ptr){
 		parent->left=NULL;
 		
	 }else{
	 	parent->right=NULL;
	 }
	//type 2
	free(ptr);
 }else if((ptr->left ==NULL && ptr->right!=NULL)||(ptr->left !=NULL && ptr->right==NULL)){
 	
 	if(ptr->left!=NULL){
 		if(ptr==parent->left){
 			parent->left=ptr->left;
 			ptr->left=NULL;
 			free(ptr);
		 }else{
		 	parent->right=ptr->left;
		 	ptr->left=NULL;
 			free(ptr);
		 }
	 }else if(ptr->right!=NULL){
	 	
	 	if(ptr==parent->left){
 			parent->left=ptr->right;
 			ptr->right=NULL;
 			free(ptr);
		 }else{
		 	parent->right=ptr->right;
		 	ptr->right=NULL;
 			free(ptr);
		 }
	 	
	 }
 }else {
 	curr=ptr;
 	
 	
 	largest(ptr->left);
	printf("the largest %d",ptr1->data);
 		curr->data=ptr1->data;
 		//free(ptr1);
 		
    	deleteele(ptr2,ptr1->data);
	 
 }
 




}



int main(){
	struct node*ptr;
//	create_tree(tree);
	int choice=0;
	printf("=================The TREE=====================");
	while(choice!=12){
			printf("\n========The MENU============");
			printf("\n 1. Insert Elements ");
			printf("\n 2. Preorder The TREE ");
			printf("\n 3. Inorder The TREE ");
			printf("\n 4. Postorder The TREE ");
			printf("\n 5. The smallest in The TREE ");
			printf("\n 6. The Lagest in Tree");
			printf("\n 7. The search opareation");
			printf("\n 8. The Deletion Node in tree");
			printf("\n Enter The Your Choice =");
			scanf("%d",&choice);
			int val;
			switch(choice){
				
				case 1:
					printf("\n Enter the value of Node=");
					scanf("%d",&val);
					insert(val);
					break;
				
				case 2:
					ptr=root;
					preorder(ptr);	
					break;
					
					
				case 3:
					ptr=root;
					inorder(ptr);
					break;
					
				case 4:
					ptr=root;
					postorder(ptr);
					break;
				
				case 5:
					ptr=root;
					smallest(ptr);
					break;
				
				case 6:
					ptr=root;
					largest(ptr);
					break;
				case 7:
					ptr=root;
					printf("Enter The value U want to search");
					scanf("%d",&val);
					search(ptr,val);
					break;
					
				case 8:
					ptr=root;
					printf("Enter The value U want to delete");
					scanf("%d",&val);
					deleteele(ptr,val);
					break;
			}
			
	}
}



