#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node* link;
};

struct node *root = NULL;
int len;

void append(void);
void addatbegin(void);
void addatafter(void);
int length(void);
void display(void);
void Delete(void);

int main()
{
	int ch;
	while(1){
		printf("Single linked list Operations : \n");
		printf("1.Append\n");
		printf("2.Addatbegin\n");
		printf("3.Addatafter\n");
		printf("4.length\n");
		printf("5.Display\n");
		printf("6.Delete\n");
		printf("7.Quit\n");
		
		printf("\nEnter your choice: ");
		scanf("%d", &ch);
		
		switch(ch)
		{
			case 1 : append(); break;
			case 2 : addatbegin(); break;
			case 3 : addatafter(); break;
			case 4 : len = length();
					 printf("Lenth of the list : %d", len);
					 break;
			case 5 : display(); break;
			case 6 : Delete(); break;
			case 7 : exit(1);
			default : printf("invalid input.\n\n");
		}
	}
}

void append(){
	struct node* temp;
	temp = (struct node*)malloc(sizeof(struct node));
	printf("Enter the data: ");
	scanf("%d", &temp->data);
	temp->link = NULL;
	if(root == NULL) //list is empty
	{
		root=temp;
	}else
	{
		struct node* p;
		p=root;
		while(p->link != NULL)
		{
			p = p->link;
		}
		p->link = temp;
	}
}

void addatbegin()
{
	struct node* temp;
	temp = (struct node*)malloc(sizeof(struct node));
	printf("Enter the data : ");
	scanf("%d", &temp->data);
	temp->link = NULL;
	if(root == NULL)
	{
		temp = root;
	}
	else
	{
		temp->link = root;
		root = temp;
	}
}

void addatafter()
{
	struct node* temp, *p;
	int loc, i=1;
	printf("Enter the location : ");
	scanf("%d", &loc);
	if(loc > len)
	{
		printf("Invalid input.");
	}
	else
	{
		p = root;
		while(i > loc)
		{
			p = p->link;
			i++;
		}
		temp = (struct node*)malloc(sizeof(struct node));
		printf("Enter the data : ");
		scanf("%d", &temp->data);
		temp->link = NULL;
		temp->link = p->link;
		p->link = temp;
	}	
}

int length()
{
	int count = 0;
	struct node* temp;
	temp = root;
	while(temp->link != NULL)
	{
		count++;
		temp = temp->link;
	}
	return count;
}

void display(){
	struct node* temp;
	temp = root;
	if(temp == NULL)
	{
		printf("List id empty.\n");
	}
	else
	{
		while (temp != NULL){
			printf("%d -> ", temp->data);
			temp = temp->link;
		}
		printf("\n\n");
	}
}

void Delete(){
	struct node *temp;
	int loc;
	printf("Enter the location of node which has to be deleted: ");
	scanf("%d", &loc);
	if(loc > len)
	{
		printf("Invalid inpuyt.");
	}
	else if(loc == 1)
	{
		temp = root;
		root = temp->link;
		temp->link = NULL;
		free(temp);
	}else{
		struct node *p = root, *q;
		int i=1;
		while(i < loc-1)
		{
			p = p->link;
			i++;
		}
		q = p->link;
		p->link = q->link;
		q->link = NULL;
		free(q);
	}
}

