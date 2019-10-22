#include <stdio.h>
#include <stdlib.h>
#define max 100

void push();
void pop();
void peek();
void display();

int top = -1;
int stack[max];

int main()
{
	int ch;
	while(1)
	{
		printf("\n1. To enter a element.\n");
		printf("2. To delete a element.\n");
		printf("3. To get the top element.\n");
		printf("4. To display all the elements.\n");
		printf("5. To exit.\n\n");
		
		printf("Enter your choice: ");
		scanf("%d", &ch);
		printf("\n");
		
		switch(ch)
		{
			case 1 : push(); break;
			case 2 : pop(); break;
			case 3: peek(); break;
			case 4 : display(); break;
			case 5 : exit(1); break;
			default : printf("Invalid choice.");
		}
	}
}

void push()
{
	int val;
	if(top == max-1)
	{
		printf("Stack is full");
	}
	else
	{
		printf("Enter the element: ");
		scanf("%d", &val);
		top++;
		stack[top] = val;
	}
}

void pop()
{
	if(top == -1)
	{
		printf("Stack is empty.");
	}
	else
	{
		printf("Deleted element is %d", stack[top]);
		top = top-1;
	}
}

void peek()
{
	if(top == -1)
	{
		printf("Stack is empty");
	}
	else
	{
		printf("The element is %d", stack[top]);
	}
}

void display()
{
	int i;
	if(top == -1)
	{
		printf("Stack is empty.");
	}
	else
	{
		printf("[");
		for(i=0; i<max; i++)
		{
			printf("%d, ", stack[i]);
		}
		printf("\b\b ]");
	}
}
