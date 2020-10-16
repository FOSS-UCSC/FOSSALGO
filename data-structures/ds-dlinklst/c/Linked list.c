#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *head=0,*temp=0;
void create()
{
    struct node *ptr=0;
    ptr=(struct node*)malloc(sizeof(struct node));
    printf("Enter data : ");
    scanf("%d",&ptr->data);

    ptr->next=0;
    if(head==0)
    {
        head=temp=ptr;
    }
    else
    {
        temp->next=ptr;
        temp=ptr;
    }
}
void delete()
{
    struct node *x,*ptr;
    int pos,i=1;
    x=head;
    printf("Enter the position to delete : ");
    scanf("%d",&pos);
    while(i < pos - 1)
    {
        x = x -> next;
        i++;
    }
    ptr = x -> next;
    x -> next = ptr -> next;
    free(ptr);
}
void insert()
{
    struct node *ptr,*x;
    int pos,i=1;
    printf("Enter the position where you want to insert : ");
    scanf("%d",&pos);
    ptr=(struct node*)malloc(sizeof(struct node));
    printf("Enter data : ");
    scanf("%d",&ptr->data);
    x=head;
    while(i<pos-1)
    {
        x=x->next;
        i++;
    }
    ptr->next=x->next;
    x->next=ptr;
}
void display()
{
    struct node *t=head;
    if(head == 0)
    {
        printf("Empty list");
        return;
    }
    while(t!=0)
    {
        printf("\n%d",t->data);
        t=t->next;
    }
}
int main()
{
    int choice;
    while (1)
    {
        printf("\nEnter 1 for insert\n");
        printf("Enter 2 for display \n");
        printf("Enter 3 to Delete a node \n");
        printf("Enter 4 to insert node in Middle \n");
        printf("Enter 5 for display and exit\n");
        scanf("\n%d",&choice);
        switch(choice)
        {
        case 1:
            create();
            break;
        case 2:
            display();
            break;
        case 3:
            delete();
            display();
            break;
        case 4:
            insert();
            break;
        default :
            display();
            exit(1);
        }
    }
    return 0;
}
