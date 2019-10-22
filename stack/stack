#include<stdio.h>
#define max 5
int top=-1;
int stack[5];
int main(){
	int option,val;
	printf("1.Push\n");
	printf("2.Pop\n");
	printf("3.Peek\n");
	printf("4.Display\n");
	printf("5.Exit\n");
	do{
		printf("Select your option:");
		scanf("%d",&option);
	switch (option){
		case 1:
			printf("Enter the number to be pushed on stack:\n");
			scanf("%d",&val);
			push(val);
			break;
		case 2:
			val=pop();
			printf("The value deleted from stack is %d\n",val);
			break;
		case 3:
			peek();
			break;
		case 4:
			display();
			break;
	}
	
	}while (option!=5);

	return 0;	
}
int push(int value){
	if(top==max-1)
	{
		printf("Stack overflow");
	}
	else
	{
		top++;
		stack[top]=value;
	}	
}
int pop(){
	int value;
	if(top==-1)
	{
		printf("Stack underflow\n");
	}	
	else 
	{
		value=stack[top];
		top--;
		return value;	
	}
	
}
int peek(){
	int val;

		if(top==-1)
	{
		printf("Stack underflow\n");
	}	
	else 
	{
	printf("Top most value is %d\n",stack[top]);
	}
	return val;
	
}


int display(){
	int x;
	if(top==-1)
	{
		printf("Stack underflow\n");
	}	
	else 
	{
	printf("List of numbers \n");
	for(x=0;x<=top;x++)
	{
		printf("%d ",stack[x]);
	}
	printf("\n");	
	}
	
}



