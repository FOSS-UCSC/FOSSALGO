#include <stdio.h>
#include <stdlib.h>
void control_panel(int);
void selector();
struct newNode* createNode();
void display(struct newNode *start);
struct newNode * create_list(struct newNode *start);
struct newNode * add_bigin(struct newNode* start);
struct newNode * add_end(struct newNode *start);
struct newNode * add_before(struct newNode * start);
struct newNode * add_after(struct newNode * start);
struct newNode * del_beg(struct newNode * start);
struct newNode * del_end(struct newNode *start);
struct newNode * del_node(struct newNode*start);
struct newNode *del_after(struct newNode *start);
struct newNode *del_list(struct newNode *start);
struct newNode *sort_list(struct newNode *start);
struct newNode* start=NULL;	
int main()
{
	selector();
	return 0;
}

void selector()
{
	int opt;
	do
	{
		printf("\n");
		printf("###### MAIN MENU ######\n");
		printf("\n");
		printf("1.Create Linked list.\n");
		printf("2.Display the list\n");
		printf("3.Add a node to biginning\n");
		printf("4.Add a node to end\n");
		printf("5.Add a node to before given node \n");
		printf("6.Add a node to after given node\n");
		printf("7.Delete a node from beginning.\n");
		printf("8.Delete a node from end\n");
		printf("9.Delete a given node\n");
		printf("10.Delete a node after given node\n");
		printf("11.Delete entire list\n");
		printf("12.Sort the list\n");
		printf("0.Exit\n");
		printf("______________________________________\n");
		printf("Selete a option : ");
		scanf("%d",&opt);
		control_panel(opt);
		printf("---------------------------------------\n");
	}while(opt);
}

void control_panel(int opt)
{
	switch(opt)
	{
		case 1:
			start = create_list(start);
			break;
		case 2:
			display(start);
			break;
		case 3:
			start = add_bigin(start);
			break;
		case 4:
			start = add_end(start);
			break;
		case 5:
			start = add_before(start);
			break;
		case 6:
			start = add_after(start);
			break;
		case 7:
			start = del_beg(start);
			break;
		case 8:
			start = del_end(start);
			break;
		case 9:
			start = del_node(start);
			break;
		case 10:
			start = del_after(start);
			break;
		case 11:
			start = del_list(start);
			break;
		case 12:
			start = sort_list(start);
		case 13:
			printf("<< GOOD BYE >>\n");
			break;
	}
	printf("______________________________________\n\n");
	return;
}

struct newNode
{
	int data;
	struct newNode *next;
};

struct newNode* createNode(struct newNode *start,int val)
{
	struct newNode* Node,*ptr;
	Node  = (struct newNode*) malloc(sizeof(struct newNode));
	Node->data = val;
	if(start==NULL){
		Node->next = NULL;
		start = Node;
	}
	else
	{
		ptr = start;
		while(ptr->next!=NULL)
			ptr = ptr->next;
		ptr->next = Node;
		Node->next = NULL;
	}
	return start;
}
struct newNode * create_list(struct newNode *start)
{
	int num=1;
	printf("Enter 0 to exit.\n");
	printf("Enter a data : ");
	scanf("%d",&num);
	while(num)
	{
		start = createNode(start,num);
		printf("Enter a data : ");
		scanf("%d",&num);
	}
	return start;
}

void display(struct newNode *start)
{
	printf("Linked list : ");
	struct newNode *ptr;
	ptr = start;
	if(ptr==NULL)
	{
		printf("List is empty\n");
		return;
	}
	while(ptr != NULL)
	{
		printf("%d ",ptr->data );
		ptr = ptr->next;
	}
	printf("\n");
	return;
}

struct newNode * add_bigin(struct newNode* start)
{
	struct newNode *Node;
	Node = (struct newNode *)malloc(sizeof(struct newNode));
	printf("Enter a data : ");
	scanf("%d",&Node->data);

	if(start==NULL){
		start=Node;
		start->next=NULL;
	}
	else
	{
		Node->next=start;
		start=Node;
	}
	return start;
}

struct newNode * add_end(struct newNode *start)
{
	struct newNode *Node,*ptr=start;
	Node = (struct newNode *) malloc(sizeof(struct newNode));
	printf("Enter a data : ");
	scanf("%d",&Node->data);
	if(ptr==NULL)
		start = Node;
	else
	{
		while(ptr->next!=NULL)
		{
			ptr=ptr->next;
		}
		ptr->next=Node;
	}
		Node->next=NULL;
		return start;
}

struct newNode * add_before(struct newNode * start)
{
	struct newNode * ptr=start,*preptr=start,*Node;
	int val;
	Node = (struct newNode*) malloc(sizeof(struct newNode));
	printf("Enter the data before which data inserted : ");
	scanf("%d",&val);
	printf("Enter a data : ");
	scanf("%d",&Node->data);
	if(ptr!=NULL)
	{
        if(start->data == val)
        {
            Node->next = start;
            start = Node;
            return start;
        }
        else
        {   
			while(ptr->data !=val)
			{
				if(ptr->next==NULL)
				{
					printf("You entered data is not in list.\n");
					free(Node);
					return start;
				}
				preptr = ptr;
				ptr = ptr->next;
			}
        }
	}
	else
	{
		printf("List is Empty.\n");
		free(Node);
		return start;
	}
	preptr->next = Node;
	Node->next = ptr;
	return start;
}

struct newNode * add_after(struct newNode * start)
{
	struct newNode * ptr,*Node;
	int val;
	Node = (struct newNode*)malloc(sizeof(struct newNode));
	ptr = start;
	printf("Enter the data which data after inserted.");
	scanf("%d",&val);
	printf("Enter the data : ");
	scanf("%d",&Node->data);
	if(ptr!=NULL)
	{
		while(ptr->data != val)
		{
			if(ptr->next==NULL)
			{
				printf("Data is not in a list.\n");
				free(Node);
				return start;
			}
			ptr = ptr->next;
		}
	}else{
		printf("List is empty.\n");
		free(Node);
		return start;
	}
	Node->next=ptr->next;
	ptr->next = Node;
	return start;
}

struct newNode * del_beg(struct newNode * start)
{
	struct newNode * ptr=start;
	if(start!=NULL){
		start = ptr->next;
		printf("Deleted : %d\n", ptr->data);
		free(ptr);
	}
	return start;
}

struct newNode * del_end(struct newNode *start)
{
	struct newNode *ptr=start,*preptr=start;
	if(start != NULL)
	{
		while(ptr->next != NULL)
		{
			preptr = ptr;
			ptr = ptr->next;
		}
		preptr->next = NULL;
		free(ptr);
		if(start->next==NULL){
			printf("List has only one Node.Just it Deleted.\n");
			return NULL;
		}
	}
	else
		printf("List is Empty.\n");
	return start;
}

struct newNode * del_node(struct newNode*start)
{
	struct newNode * ptr=start,*preptr=start;
	int val;
	if(start != NULL)
	{
		printf("Enter the value of data which want to deleted : ");
		scanf("%d",&val);
		while(ptr->data != val)
		{
			if(ptr->next==NULL)
			{
				printf("You entered data not in a list.\n");
				return start;
			}
			preptr = ptr;
			ptr = ptr->next;
		}
		preptr->next = ptr->next;
		if(start->next==NULL && ptr->data == val)
			return NULL;
		if(start->data==val)
		{
			start=ptr->next;
		}
		free(ptr);
	}
	else
		printf("List is empty.\n");
	return start;
}

struct newNode *del_after(struct newNode *start)
{
	int val;
	struct newNode *ptr=start,*preptr=start;
    if(start != NULL)
    {
    printf("Enter the value after which node has to deleted : ");
    scanf("%d",&val);
	    while(preptr->data != val)
	    {
	    	if(ptr->next == NULL)
	    	{
	    		printf("Can,t find value after node.\n");
	    		return start;
	    	}
	    	preptr= ptr;
	    	ptr=ptr->next;
	    }
	    preptr->next = ptr->next;
	    free(ptr);
	}
	else
		printf("List is empty.\n");
   return start;
}

struct newNode *del_list(struct newNode *start)
{
	struct newNode *ptr=start;
	if(start != NULL)
	{
		while(ptr != NULL)
		{
			start = del_beg(ptr);
			ptr = start;
		}
	}
	else
		printf("List is Empty.\n");
	return start;
}

struct newNode *sort_list(struct newNode *start)
{
	struct newNode *preptr=start,*ptr;
	int tmp;
	while(preptr != NULL)
	{
		ptr = preptr->next;
		while(ptr != NULL)
		{
			if(preptr->data >ptr->data)
			{
				tmp = preptr->data;
				preptr->data = ptr->data;
				ptr->data = tmp;
			}
			ptr = ptr->next;
		}
		preptr = preptr->next;
	}
	return start;
}
