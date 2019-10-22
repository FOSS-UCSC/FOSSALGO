#include <stdio.h>
#define MAX 5
int stack[MAX];
int TOP=-1;

void push(int x){

   if(TOP==isFull()){
        printf("Stack Full");
   }else{
        TOP  +=1;
        stack[TOP] = x;
        printf("stack[%d] is :%d\n",TOP,stack[TOP]);
   }

}
int pop(){

    if(TOP==isEmpty()){
    printf("EMPTY");
    }else{
        int data = stack[TOP];
        TOP-=1;
        return data;

    }

}
int peek(){
 return stack[TOP];

}
int isEmpty(){

return -1;
}
int isFull(){
return MAX-1;
}

int main(){


push(1);
push(2);
printf("\nremove %d",pop());
printf("\nlast %d",peek());
return 0;
}
