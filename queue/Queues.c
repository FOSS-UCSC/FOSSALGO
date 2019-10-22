#include<stdio.h>
#define SIZE 5

void enQueue();
void deQueue();
void display();

int queue[SIZE], front = -1, rear = -1;

int main()
{
    int ch;
	while(1)
	{
		printf("\n1. To insert a element.\n");
		printf("2. To delete a element.\n");
		printf("3. Check wheather it is full.\n");
		printf("4. Check wheather it is empty.\n");
		printf("5. To display all the elements.\n");
		printf("6. To exit.\n\n");
		
		printf("Enter your choice: ");
		scanf("%d", &ch);
		printf("\n");
		
		switch(ch)
		{
			case 1 : enQueue(); break;
			case 2 : deQueue(); break;
			case 3 : isFull(); break;
			case 4 : isEmpty(); break;
			case 5 : display(); break;
			case 6 : exit(1); break;
			default : printf("Invalid choice.");
		}
	}
		
	return 0;
}

void enQueue()
{
	int value;
	printf("Enter the element: ");
	scanf("%d", &value);
	if(!isFull())
	{
		if(front == -1 && rear == -1)
	    {
	    	front = 0;
			rear = 0;
		}
		else
		{
			rear++;
		}
		queue[front] = value;
	}
    
}

void deQueue()
{
	int val;
    if(!isEmpty())
	{
		val = queue[front];
		front++;
		if(front > rear)
		{
			rear = front = -1;
		}
	}
	printf("\nDeleted element is %d", val);
}

void display(){
	int i;
    if(!isEmpty())
	{
		printf("[");
		for(i = front; i <= rear; i++)
		{
			printf("%d, ", queue[i]);
		}
		printf("\b\b ]");
	}
}

int isFull(){
	if(rear == SIZE-1)
    	return 1;
    else
    	return 0;
}

int isEmpty(){
	if(front == -1 && rear == -1)
        return 1;
    else
    	return 0;
}
