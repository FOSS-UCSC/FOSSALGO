#include<stdio.h>
#define MAX 100

int stack[MAX];
void push(int);
void pop();
int peek();
int display();
int top =-1;
int i;


void push(int x){
	if(top==MAX-1){
		printf("stack overflow");
	}else{
		top++;
		stack[top]=x;
		
	}
}
void pop(){
	if(top==-1){
		printf("stack underflow");
		
	}else{
		stack[top--];
	}
}

int peek(){
	if(top==-1){
		return 0;
		
	}else{
		return stack[top];
	}
}

int display(){
	if(top==-1){
		printf("stack is underflow");
	}else{
		for(i=top;i>=0;i--){
			printf("\n %d",stack[i]);
            printf("\n");
		}
	}
}
int main(){
	int x,option,i;
	do{
	  	printf("\n ***MAIN MENU****");
	  	printf("\n 1. push");	
	  	printf("\n 2. pop");
	  	printf("\n 3. peek");
	  	printf("\n 4. display");
	  	printf("\n 5. exit");
	  	
	  	printf("\n Enter the option:");
	  	scanf("%d",&option);
	  	switch(option){
	  		case 1: 
	  		    printf("\nEnter the push number:");
	  		    scanf("%d",&x);
	  		    push(x);
	  		    break;
	  		 
			case 2:
				pop();
				//if(x!= -1);
				//printf("\n The deleted from stack is:%d",x);
				break;
			
			case 3:
			     peek();
				if(top!= -1);
				printf("\n value:%d\n",x);
				break;
		    
			case 4:
				display();
				break;
				
			    		
				}	
				
			          
	  		    
		  }while(option != 5);
		  return 0;
	}
