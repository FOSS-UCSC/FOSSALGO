#include <stdio.h>
#include <stdlib.h>
#define CAPACITY 5 // macro prefrocer
int stack[CAPACITY],top= -1;

void push(int);
int pop(void);
int peek(void);
int traverse(void);
int isEmpty(void);
int isFull(void);

void main(){
while(1){
    int ch;
    int item;
    printf("1.PUSH\n");
    printf("2.POP\n");
    printf("3.PEEK\n");
    printf("4.TRAVERSE\n");
    printf("5.Exit\n");

    printf("Enter Your Choice :");
    scanf("%d",&ch);

    switch(ch){
        case 1: printf("Enter Element :");
                scanf("%d",&item);
                push(item);
                break;

        case 2: item = pop();
                if(item == 0){
                    printf("Stack is UnderFlow\n");
                }else{
                    printf("Poped Item is : %d\n",item);
                }
                break;
        case 3: peek();
                break;
        case 4: traverse();
                break; 
        case 5: exit(0);
                break;
        default: printf("Invalid Input!!!!\n");  
    }

}
}
void push(int item){
    if (isFull()){
        printf("Stack is OverFlow\n");
    }
    else{
        top++;
        stack[top] = item;
        printf("Push Element %d\n",item);
    }
    
}
int isFull(){
    if (top == CAPACITY - 1 ){
        return 1;
    }
    else{
        return 0;
    }
    
}
int pop(){
    if (isEmpty()){
        return 0;
    }
    else{
        return stack[top--];
    }
    
}
int isEmpty(){
    if (top == -1)
    {
       return 1;
    }else
    {
        return 0;
    }
}
int peek(){
    if(isEmpty()){
        printf("Stack UnderFlow\n");
    }else{
        printf("Peek is %d\n",stack[top]);
    }
}
int traverse(){
    if(isEmpty()){
        printf("Stack  is overFlow\n");
    }else{
        int i;
        for(i=0;i<=top;i++){
            printf("Elements are %d\n",stack[i]);
        }
    }
}