#include <stdio.h>
#include<stdlib.h>

#define CAPACITY 5
int queue[CAPACITY];

 int front = 0;
 int rear = 0;

void push(void);
void pop(void);
void traverse(void);

 void main(){
     int ch;
     while(1){
         printf("Queue operations !!!!\n");
         printf("1.Push\n");
         printf("2.Pop\n");
         printf("3.Traverse\n");
         printf("4.Exit\n");
        
        printf("Enter your choice :\n");
        scanf("%d",&ch);

        switch(ch){
            case 1: push();
                    break;
            case 2: pop();
                    break;
            case 3: traverse();
                    break;
            case 4: exit(1);
                    break;
            default: printf("Invalid choice!!\n");
        }
     }
 }
 void push(){
     if(CAPACITY == rear){
         printf("List Full...\n");
     }else{
         int ele;
         printf("Enter data :\n");
         scanf("%d",&ele);

         queue[rear] = ele;
         rear++;
     }
 }
 void pop(){
     if(rear == front){
         printf("Empty list...\n");
     }else{
        printf("Delete data is : %d\n",queue[front]);
        for(int i = 0;i<rear-1;i++){
            queue[i] = queue[i+1];
        }
        rear--;
     }
 }

 void traverse(){
     if(rear == front){
         printf("Empty List...\n");
     }else{
         printf("Queues Elements :\n");
         for(int i=front;i < rear;i++){
             printf("%d\n",queue[i]);
         }
     }
 }