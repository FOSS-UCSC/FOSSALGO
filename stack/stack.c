#include <stdio.h>

int MAX = 10,stack[10],top = -1;            

int isempty() {

   if(top == -1)
      return 1;
   else
      return 0;
}
   
int isfull() {

   if(top ==MAX)
      return 1;
   else
      return 0;
}

void peek() {
	if(top==-1)
		printf("error!,stack is empty\n");
	else
   		printf("%d",stack[top]);
}

void pop() {
   int data;
	
   if(!isempty()) {
      data = stack[top];
      top = top - 1;   
      printf("%d\n",data);
   } else {
      printf("error!!,Stack is empty.\n");
   }
}

void push(int n) {

   if(!isfull()) {
      top = top + 1;   
      stack[top] = n;
   } else {
      printf("error!!,Stack is full.\n");
   }
}

void size()
{
	printf("%d\n",top+1);
}

void printstack()
{
	int i;
	if(top==-1)
		printf("stack is empty");
		
	else
	{
		for(i=0;i<=top;i++)
			printf("%d ",stack[i]);
	}

}


int main() 
{
	int a,n;
	
		printf("1.push\n");
 		printf("2.pop\n");
  		printf("3.peek\n");
  		printf("4.print stack\n");
 		printf("5.print size\n");
 		printf("6.quit\n");
 		
	while(a!=6)
	{
		
  		printf("enter your choice:");
  		scanf("%d",&a);	
  		
  		switch(a)
  		{
  			case 1:printf("enter number:");
  					scanf("%d",&n);
  					push(n);
  					break;
  					
  			case 2:pop();
  					break;
  			
  			case 3:peek();
  					break;
  			
  			case 4:printstack();
  					break;
  			
  			case 5:size();
  				break;
  			
  			case 6:continue;
  					break;
  				
  			default:printf("error!!\n");
		}
	}
   return 0;
}
