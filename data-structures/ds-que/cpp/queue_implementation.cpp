
// Implementation of queue in c++ using array.

#include <iostream>
using namespace std;
int queue[100];
int front, rear;
int maxLength;

// Function to insert element.
void enqueue(int x)
{
	if (maxLength == rear)
	{
		cout << "Overflow\n";
	}
	else
	{
		queue[rear] = x;
		rear++;
	}
	return;
}

// Function to delete top most element of queue.
void dequeue()
{
	if (front == rear)
	{
		cout << "Underflow\n";
	}
	else
	{
		for (int i = 0; i < rear - 1; i++)
		{
			queue[i] = queue[i + 1];
		}
		rear--;
	}
	return;
}

// Function to display elements of queue
void display()
{
	int i;
	if (front == rear)
	{
		cout << "\nQueue is Empty\n";
		return;
	}
	else
	{
		for (i = front; i < rear; i++)
		{
			cout << queue[i] << " ";
		}
		cout << '\n';
	}
	return;
}

// Function to print top most element of queue
void frontQueue()
{
	if (front == rear)
	{
		cout << "Underflow\n";
	}
	else
	{
		cout << "Front Element is:" << queue[front] << "\n";
	}
	return;
}

int main()
{
	// your code goes here
	int x, p;
	front = rear = 0;
	cout << "Enter maximum length of queue\n";
	cin >> maxLength;
	cout << "1)Insert the element at last of queue\n";
	cout << "2)Delete the front element of queue\n";
	cout << "3)Print front element of queue\n";
	cout << "4)Print the queue\n";
	cout << "5)End the program\n";
	cout << "Enter the operation number to be performed\n";
	while (true)
	{
		cin >> x;
		if (x == 5)
		{
			break;
		}
		if (x == 1)
		{
			cout << "Enter element to be inserted\n";
			cin >> p;
			enqueue(p);
		}
		else if (x == 2)
		{
			dequeue();
		}
		else if (x == 3)
		{
			frontQueue();
		}
		else
		{
			display();
		}
	}
	return 0;
}
