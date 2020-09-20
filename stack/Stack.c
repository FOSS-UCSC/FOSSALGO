#include<stdio.h>
#include<stdbool.h>
#define max 3

int top=-1;
int stack[max];
bool isfull(){
	if(top==max){
		return true;
	}
	else{
		return false;
	}
}
bool isempty(){
	if(top==-1){
		return true;
	}
	else{
		return false;
	}
}
int push(int data){
	if(isfull()){
		printf("overflow:");
	}
	else{
		stack[++top]=data;
	}
}

int pop(){
	if(isempty()){
		printf("underflow:");
	}
	else{
		int data=stack[top];
		top--;
		return data;
	}
}
int peek(){
	return stack[top];
}
void display(){
	int i;
	for(i=0;i<max;i++){
		printf("%d:",stack[i]);
	}	
}


int main(){
	int x;
	int data;
	for(x=0;x<max;x++){
		printf("enter push data:");
		scanf("%d",&data);
		push(data);
	}
	display();
	
	}








