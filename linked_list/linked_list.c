#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* link;
};

struct node* root = NULL;
void append();
void addatbegin();
void addatafter();
void delete();
void display();
int length();
void reverse();
int len;

void main(){
    int ch;
    while (1){
        printf("Linked list operations\n\n");
        printf("1.Append :\n");
        printf("2.Add the Begginin :\n");
        printf("3.Add After choice :\n");
        printf("4.Display :\n");
        printf("5.Delete :\n");
        printf("6.length :\n");
        printf("7.Reverse\n");
        printf("8.Exit \n");

        printf("Enter your Choice :\n");
        scanf("%d",&ch);

        switch (ch)
        {
        case 1: append();
                break;
        case 2: addatbegin();
                break;
        case 3: addatafter();
                break;
        case 4: display();
                break;
        case 5: delete();
                break;
        case 6: len = length();
                printf("length is :%d\n",len);
                break;
        case 7: reverse();
                break;
        case 8: exit(1);
        
        default: printf("Invalid choice :\n");
        }
    }
    
}
void append(){
    struct node* temp;
    temp = (struct node*)malloc(sizeof(struct node));
    printf("Enter the Node Data :");
    scanf("%d",&temp->data);
    
    temp->link = NULL;

    if (root == NULL){
        root = temp;    
    }else{
        struct node* p;
        p = root;
        while (p->link != NULL){
            p = p->link;
        }
        p->link = temp;
    }
    
}
int length(){
    int count = 0;
    struct node* temp;
    temp = root;

    while(temp != NULL){
        count++;
        temp = temp->link;
        
    }
    return count;
}
void display(){
    struct node* temp;
    temp = root;

    if (temp == NULL){
        printf("Empty list \n");
    }else{
        while (temp != NULL){
            printf("%d-->",temp->data);
            temp= temp->link;
        }
        printf("\n\n");
    }
    
}
void addatbegin(){
    struct node* temp;
    temp = (struct node*)malloc(sizeof(struct node));
    printf("Enter the data ");
    scanf("%d",&temp->data);
    temp->link = NULL;
    if (root == NULL)
    {
      root = temp;
    }else{
        temp->link = root;
        root = temp;
    }
    
}
void addatafter(){
int i=1;
int loc;
struct node* temp,*p;

printf("Enter location :");
scanf("%d",&loc);

if (loc > length()){
    printf("Invalid Locaton \n");
    printf("Length is : %d\n",len);
}
else{
    p = root;
    while(i < loc){
        p = p->link;
        i++;
    }
    temp = (struct node*)malloc(sizeof(struct node));
    printf("Enter node data :\n");
    scanf("%d",&temp->data);
    temp->link = p->link;
    p->link = temp;
}


}   
void delete(){
    int loc = 0;
    struct node* temp;

    printf("Enter the location :");
    scanf("%d",&loc);

    if(loc > length()){
        printf("Invalid Location \n");
    }
    else if(loc == 1){
        temp = root;
        root = temp->link;
        temp->link = NULL;
        free(temp);
    }
    else{
        struct node* p = root;
        struct node* q;
        int i = 1;
        while(i < loc-1){
            p = p->link;
            i++;
        }
        q = p->link;
        p->link = q->link;
        q->link = NULL;
        free(q);
    }
}
void reverse(){
    
}