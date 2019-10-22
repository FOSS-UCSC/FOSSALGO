#include<stdio.h>
#define MAX 10 //this line can be altered to increase/decrease size of stack

int stack[MAX],top=-1;

void push(int stack[],int val);
int pop(int stack[]);
int peek(int stack[]);
void display(int stack[]);

int main(){
	
	int value,option;
	do{
		
		printf("\n 1.PUSH");
		printf("\n 2.POP");
		printf("\n 3.PEEK");
		printf("\n 4.DISPLAY");
		printf("\n 5.EXIT");
		printf("\n Enter your option: ");
		scanf("%d",&option);
		
		switch(option){
			case 1:
				printf("\nEnter number to be pushed on to the stack:");
				scanf("%d",&value);
				push(stack,value);
				break;
				
			case 2:
				value=pop(stack);
				if(value!=-1){
					printf("\n Value deleted from stack is :%d",value);
				}
				break;
			
			case 3:
				value=peek(stack);
				if(value!=-1){
					printf("\n Value stored at top of the stack is :%d",value);
				}
				break;
			
			case 4:
				display(stack);
				break;
		}
	}while(option!=5);
	return 0;
}

void push(int stack[],int val){
	
	if(top==MAX-1){
		printf("\n STACK OVERFLOW");
	}
	else{
		top++;
		stack[top]=val;
	}
	
}

int pop(int stack[]){
	
	int val;
	if(top==-1){
		printf("\n STACK UNDERFLOW");
	}
	else{
		val=stack[top];
		top--;
		return val;
	}
}

int peek(int stack[]){
	if(top==-1){
		printf("\n STACK IS EMPTY");
		return -1;
	}
	else{
		return (stack[top]);
	}
}

void display(int stack[]){
	int i;
	if(top==-1){
		printf("\n STACK IS EMPTY");
	}
	else{
		for(i=top;i>=0;i--){
			printf("\n %d",stack[i]);
			printf("\n");
		}
	}
}


