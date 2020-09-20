#include <stdio.h>

struct Node{
        int data;
        struct Node* link;

};

struct Node* root = root= NULL;

void append(){

    struct Node* temp;
    temp = (struct Node*)malloc(sizeof(struct Node));

    printf("Enter Data :");
    scanf("%d",&temp->data);
    temp->link=NULL;

    if(root==NULL){
        root =temp;
    }else{
        p =(struct Node*)malloc(sizeof(struct Node));
        q =(struct Node*)malloc(sizeof(struct Node));
        p=root;
        while(p->link=NULL){


            p=p->link;
        }
        p->link =temp;


    }



}

int length(){
    int count=0;
    if(root==NULL){
        return 0;

    }else{
        struct Node* temp;
        temp = (struct Node*)malloc(sizeof(struct Node));

        while(temp!=NULL){
          count++;

            temp =temp->link;
        }
        return count;
    }

}



int main(){

        while(1){

            printf("1.Append");
            printf("2.Add");
            printf("3.Delete");
            printf("4.Length");


           }


return 0;
}
