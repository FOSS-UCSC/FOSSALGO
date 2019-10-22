#include<stdio.h>
#define max 50
int num,val;
int front=-1,back=-1;
int que[max];
enQueue(int);
deQueue();
display();
isEmpty();
isFull();

int main(){
    int x;
    do{
    printf("\n\t1:Insert Number to Queue \n\t2:Delete From Queue \n\t3:Print \n\t4:Exit \n");
    scanf("%d",&x);
    switch(x){
        case 1:
            printf("Enter Number to Add to the Queue:");
            scanf("%d",&num);
            enQueue(num);
            break;
        case 2:
            deQueue();
            break;
        case 3:
            display();
            break;
        case 4:
            break;
    }
    }while(x!=4);
}
int enQueue(int data){
    if(isFull()==1)
        printf("Queue Is Full");
    else
        if(front==back==-1){
            front=back=0;
            que[back]=data;
        }
        else
            back=back+1;
            que[back]=data;
}
int deQueue(){
    if(isEmpty()==1){
        printf("Queue Is Empty");
    }
    else{
        val=que[front];
        que[front]=999;
        printf("Number %d is Deleted",val);
        front=front+1;
        }
}
int isEmpty(){
    if(back==front==-1 || front>back)
        return 1;
    else
        return 0;
}
int isFull(){
    if(back==max)
        return 1;
    else
        return 0;
}
int display(){
    int i,j=back;
    printf("Values In The Queue:");

    for(i=0;i<=j;i++){
        printf("%d  ",que[i]);
    }
}
