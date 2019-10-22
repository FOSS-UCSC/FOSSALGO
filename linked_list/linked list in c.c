#include<stdio.h>
#include<stdlib.h>

// function prototypes

void create();
void display();
void insert_begin();
void insert_end();
void insert_pos();
void delete_begin();
void delete_end();
void delete_pos();

// -----------------------

struct node
{
	int info;
	struct node *next;
};
struct node *start=NULL;

// starting the main function---------------------------------------------------
int main()
{
	while(1)
	{
		int ch;
		printf("\n------------------ Singly Linked List --------------\n");
		printf("\n1.create");
		printf("\n2.display");
		printf("\n3.insert at begining ");
		printf("\n4.insert at end");
		printf("\n5.insert at specified position");
		printf("\n6.delete from begining");
		printf("\n7.delete from end");
		printf("\n8.delete from specified position ");
		printf("\n9.exit");
		
		printf("\n enter your choise:");
		scanf("%d",&ch);
		
		switch (ch)
		{
			case 1: create();
			break;
			case 2: display();
			break;
			case 3: insert_begin();
			break;
			case 4: insert_end();
			break;
			case 5: insert_pos();
			break;
			case 6: delete_begin();
			break;
			case 7: delete_end();
			break;
			case 8: delete_pos();
			break;
			case 9: exit(0);
			break;
			default: printf("\n Invalid choice");
		
		}}
	return 0;	
	
}
//-------------------------------------------------------

void create()
{
	struct node *temp,*ptr;
	temp=(struct node *)malloc(sizeof(struct node));
	if (temp==NULL)
	{
		printf("\nout of memory space");
		exit(0);
	}
	printf("enter the data value for the node:");
	scanf("%d",&temp->info);
	temp->next=NULL;
	if (start==NULL)
	{
		start=temp;
	}
	else
	{
		ptr=start;
		while (ptr->next!=NULL)
		{
			ptr=ptr->next;
		}
		ptr->next=temp;
	}
}

//-----------------------------------------------------------

void display()
{
	struct node *ptr;
	if (start==NULL)
	{
		printf("\nList is empty");
		return;
	}
	else
	{
		ptr=start;
		printf("\nthe list elements are :\n");
		while (ptr!=NULL)
		{
			printf("%d\t",ptr->info);
			ptr=ptr->next;
		}
	}
}

//----------------------------------------------------------

void insert_begin()
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	if (temp==NULL)
	{
		printf("\nout of memory space");
		return;
	}
	printf("enter the data value for the first node: ");
	scanf("%d",&temp->info);
	temp->next=NULL;
	if (start==NULL)
	{
		start=temp;
	}
	else
	{
		temp->next=start;
		start=temp;
	}
}
//------------------------------------------------------------

void insert_end()
{
	struct node *temp,*ptr;
	temp=(struct node*)malloc(sizeof(struct node));
	if (temp==NULL)
	{
		printf("\nout of memory space");
		return;
	}
	printf("enter the data value for the last node: ");
	scanf("%d",&temp->info);
	temp->next=NULL;
	if (start==NULL)
	{
		start=temp;
	}
	else
	{
		ptr=start;
		while (ptr->next!=NULL)
		{
			ptr=ptr->next;
		}
		ptr->next=temp;
	}
}

//-------------------------------------------------------------------

void insert_pos()
{
	struct node *temp,*ptr;
	int i,pos;
	temp=(struct node*)malloc(sizeof(struct node));
	
	if (temp==NULL)
	{
		printf("\nout of memory space");
		return;
	}
	
	printf("enter the position for the new node to be inserted: ");
	scanf("%d",&pos);
	
	printf("enter the data value for the node: ");
	scanf("%d",&temp->info);
	
	temp->next=NULL;
	if (pos==0)
	{
		temp->next=start;
		start=temp;
	}
	else
	{
		for (i=0,ptr=start;i<pos-1;i++)
		{
			ptr=ptr->next;
			if(ptr==NULL)
			{
				printf("\nposition not found ");
				return;
			}
		}
		temp->next=ptr->next;
		ptr->next=temp;
	}
}

//--------------------------------------------------------------------

void delete_begin()
{
	struct node *ptr;
	if (ptr==NULL)
	{
		printf("\nlist is empty");
		return;
	}
	else
	{
		ptr=start;
		start=start->next;
		printf("\nthe deleted element is %d",ptr->info);
		free(ptr);
	}
}

//-------------------------------------------------------------------

void delete_end()
{
	struct node *temp,*ptr;
	if (start==NULL)
	{
		printf("\nlist is empty");
		exit(0);
	}
	else if (start->next==NULL)
	{
		ptr=start;
		start=NULL;
		printf("\nthe deleted element is %d",ptr->info);
		free(ptr);
	}
	else
	{
		ptr=start;
		while (ptr->next!=NULL)
		{
			temp=ptr;
			ptr=ptr->next;
		}
		temp->next=NULL;
		printf("\nThe deleted element is %d",ptr->info);
		free(ptr);
	}
}

//---------------------------------------------------

void delete_pos()
{
	struct node *temp,*ptr;
	int i,pos;
	
	if (start==NULL)
	{
		printf("\nlist is empty");
		exit(0);
	}
	else
	{
		printf("enter the position for the new node to be inserted: ");
		scanf("%d",&pos);
		if (pos==0)
		{
			ptr=start;
			start=start->next;
			printf("\nthe deleted element is %d",ptr->info);
			free(ptr);
		}
		else
		{
			ptr=start;
			for (i=0;i<pos-1;i++)
			{
				ptr=ptr->next;
				if(ptr==NULL)
				{
					printf("\nposition not found ");
					return;
				}
			}
			temp->next=ptr->next;
			printf("\nthe deleted element is %d",ptr->info);
			free(ptr);
		}
	}
}










