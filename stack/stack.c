#include<stdio.h>

void push(int);
void pop();
void peek();
int stack[4];
int size=sizeof(stack)/sizeof(int);
int top=-1;
int main(){
	
	return 0;
}

//value insertion
void push(int data){
	if(top!=size-1){
		top=top+1;
		stack[top]=data;
	}else
		printf("%d with Stack overflow\n",data);
}

//value deletion
void pop(){
	if(top>-1){
		printf("%d ",stack[top]);
		top=top-1;
	}else
		printf("\nStack underflow");
}


//get top most value
void peek(){
	if(top>-1)
		printf("Current peek is %d \n",stack[top]);
	else
		printf("\nStack is empty");
}
