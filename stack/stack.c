#include <stdio.h>
#define N 1000

int stack[N];
int top=-1;

void push(int val){
	if(top==N){
		return;
	}
	stack[++top]=val;
}

int pop(){
	if(top==-1){
		return;
	}
	return stack[top--];
}

void printStack(){
	int tempTop=top;
	while(tempTop!=-1){
		printf("%d ",stack[tempTop]);
		--tempTop;
	}
}

