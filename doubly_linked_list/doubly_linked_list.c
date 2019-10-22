#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node* left;
	struct node* right;
};

struct node* root = NULL;
int len;

void append(void);
void addatbegin(void);
void addatafter(void);
void display(void);
int length(void);

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
		printf("6.Quit\n");
		
		printf("Enter your choice: ");
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
			case 6 : exit(1);
			default : printf("invalid input.\n\n");
		}
	}
}

void append()
{
	struct node* temp;
	temp = (struct node*)malloc(sizeof(struct node));
	printf("Enter the data: ");
	scanf("%d", &temp->data);
	temp->left = NULL;
	temp->right = NULL;
	if(root == NULL)
	{
		root = temp;
	}
	else
	{
		struct node* p;
		while(p->right != NULL)		
		{
			p = p->left;
		}
		p->right = temp;
		temp->left = p;
	}
}

void addatbegin()
{
	struct node* temp;
	temp = (struct node*)malloc(sizeof(struct node));
	printf("Enter the data: ");
	scanf("%d", &temp->data);
	temp->left = NULL;
	temp->right = NULL;	
	if(root == NULL)
	{
		root = temp;
	}
	else
	{
		temp->right = root;
		root->left = temp;
		root = temp;
	}
}

void addatafter()
{
	struct node*temp;
	int loc, i=1;
	printf("Enter the location: ");
	scanf("%d", &loc);
	if(loc > len)
	{
		printf("Invalid input.");
	}
	else
	{
		struct node*p = root;
		while(i < loc)
		{
			p = p->right;
			i++;
		}
		temp = (struct node*)malloc(sizeof(struct node));
		printf("Enter the data: ");
		scanf("%d", &temp->data);
		temp->left = NULL;
		temp->right = NULL;
	}
}

void display()
{
	struct node* temp;
	temp = root;
	if(temp == NULL)
	{
		printf("List is empty.");
	}
	else{
		while(temp != NULL)
		{
			printf("%d ->", temp->data);
			temp = temp->right;
		}
	}
}

int length()
{
	struct node* temp;
	int count=0;
	temp = root;
	while(temp != NULL)
	{
		count++;
		temp = temp->right;
	}
	return count;
}
