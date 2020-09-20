#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
	struct node *prev;
};

struct node *start=NULL;
void create();
void display();
void insert_beg();
void insert_end();
void insert_before();
void insert_after();
void delete_beg();
void delete_end();
void delete_node();
void delete_before();
void delete_after();

int main(){
	int choice;
	while(1){
		printf("\t MAIN MENU\n");
		printf("1. Create a list\n");
		printf("2. Display the list\n");
		printf("3. Insert an elemenet to beginning\n");
		printf("4. Insert an element to end of the list\n");
		printf("5. Insert an element to before\n");
		printf("6. Insert an elemenet to after \n");
		printf("7. Delete an elemenet from beginning\n");
		printf("8. Delete an elemenet from end of the list\n");
		printf("9. Delete a node\n");
		printf("10. Delete an elemenet before\n");
		printf("11. Delete ana elemenet after\n");
		printf("0. Exit \n");
		printf("-------------------------------\n");
		printf("Enter your choice\n");
		scanf("%d", &choice);
		
	switch(choice){
		case 1: create();
		break;
		case 2: display();
		break;
		case 3: insert_beg();
		break;
		case 4: insert_end();
		break;
		case 5: insert_before();
		break;
		case 6: insert_after();
		break;
		case 7:  delete_beg();
		break; 
		case 8: delete_end();
		break;
		case 9: delete_node();
		break;
		case 10: delete_before();
		break;
		case 11: delete_after();
		break;
		case 0: exit(0);
		break;
		default: printf("Invalied choice!\n");
	}
	}
	return 0;
}
void create(){
int val;
struct node *ptr;
printf("Enter -1 for exit\n");
printf("Enter value for new node:\n");
scanf("%d", &val);

while(val!=-1){
	ptr=start;
	struct node *new_node;
new_node = (struct node*)malloc(sizeof(struct node));
new_node->data=val;
	

if(start==NULL){
	start=new_node;
	new_node->next=NULL;
new_node->prev=NULL;
}
else{
while(ptr->next!=NULL)
ptr=ptr->next;
new_node->prev=ptr;
ptr->next=new_node;
new_node->next=NULL;

}
printf("Enter value for new nde:\n");
scanf("%d", &val);	
  }

}

void display(){
struct node *ptr;
ptr=start;
while(ptr!=NULL){

	printf("%d\n", ptr->data);
	ptr= ptr->next;
}
	
}
void insert_beg(){
struct node *ptr, *new_node;
new_node= (struct node*)malloc(sizeof(struct node));
printf("Enter your value for new node:\n");
scanf("%d", &new_node->data);
ptr=start;
if(start==NULL){
	printf("Empty liist! New node set as first node.\n");
	start=new_node;
	new_node->next=NULL;
	new_node->prev=NULL;
}
else{
	new_node->next=ptr->next;
	ptr->prev=new_node;
	new_node->prev=NULL;
	start=new_node;
}
}

void insert_end(){
	struct node *new_node, *ptr;
	new_node=(struct node*)malloc(sizeof(struct node));
	printf("Enter value for new node:\n");
	scanf("%d", &new_node->data);
	ptr=start;
	while(ptr->next!=NULL){
		ptr=ptr->next;
	}
	ptr->next=new_node;
	new_node->prev=ptr;
	new_node->next=NULL;
}

 void insert_after(){
 struct node *new_node, *ptr;
 int data;
 printf("Enter value from the list:\n");
 scanf("%d",&data);
 new_node=(struct node*)malloc(sizeof(struct node));
 printf("Enter value for new node:\n");
 scanf("%d", &new_node->data);
ptr=start;
while(ptr->data!=data)
ptr= ptr->next;
new_node->next=ptr->next;
ptr->next->prev=new_node;
new_node->prev=ptr;
ptr->next=new_node; 	
}
void insert_before(){
struct node *new_node, *ptr, *preptr;
int data;
new_node=(struct node*)malloc(sizeof(struct node));
printf("Enter value from the list:\n");
scanf("%d", &data);
printf("Enter value for new node:\n");
scanf("%d", &new_node->data);
ptr=start;
while(ptr->data!=data){
	preptr=ptr;
	ptr=ptr->next;

}
	new_node->next=ptr;
	ptr->prev=new_node;
	preptr->next=new_node;
	new_node->prev=preptr;

}
void delete_beg(){
struct node *ptr;
ptr=start;
if(start==NULL){
	printf("Empty list\n");
}
else{
	ptr->next->prev=NULL;

	start=ptr->next;
		free(ptr);
}
	printf("Successfull Delete!\n");
}
void delete_end(){
struct node *ptr;
 ptr=start;
 while(ptr->next!=NULL)
 ptr=ptr->next;
 ptr->prev->next=NULL;
 free(ptr);
}
void delete_node(){
	struct node *ptr , *preptr;
	int data;
	printf("Enter value from the list, you want delete:\n");
	scanf("%d", &data);
	ptr=start;
	while(ptr->data!=data){
		preptr=ptr;
		ptr=ptr->next;
	}
	preptr->next=ptr->next;
	ptr->next->prev=preptr;
	free(ptr);
	printf("Successfull Delete!\n");
	
	
}
void delete_before(){
struct node *ptr, *preptr;
int data;
printf("Enter value, after value to delete node:\n");
scanf("%d" , &data);
ptr=start;
while(ptr->data!=data){
	preptr=ptr;
	ptr=ptr->next;
}
preptr->prev->next=ptr;
ptr->prev=preptr->prev;
free(preptr);
printf("Successfull Delete!\n");
}
void delete_after(){
struct node *ptr;
int data;
printf("Enter value, before value to delete node:\n");
scanf("%d" ,&data);
ptr=start;
while(ptr->data!=data)
ptr=ptr->next;
ptr=ptr->next;
ptr->next->prev=ptr->prev;
ptr->prev->next=ptr->next;
free(ptr);
printf("Successfull Delete!\n");
}
