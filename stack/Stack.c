#include <stdio.h>
#define size 100

int stack[100],choice,n;
int top=-1;
int x,i;

void push(){
    if(top == size-1)
        printf("stack is overflow");

    else{
        printf("Enter value to be push :");
        scanf("%d", &x);
        top++;
        stack[top] = x;
    }
}

void pop(){
    if(top == -1){
        printf("Stack is Empty");
    }
    else{
        printf("\n The popped value is %d",stack[top]);
        top--;
    }
}
void display()
{
    if(top>=0)
    {
        printf("\n The value in STACK ");
        for(i=top; i>=0; i--)
            printf("\n%d",stack[i]);
    }
    else
    {
        printf("\n The STACK is empty");
    }
    
}
int main(){
    push();
    push();
    push();
     pop();
     pop();
    display();
    push();
    display();

return 0;
}