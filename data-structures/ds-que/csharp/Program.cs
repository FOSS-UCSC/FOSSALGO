using System;

namespace csharp
{
    public class LinearQueue
    { // implementation of a linear queue using integer array
        private readonly int []que;
        private int front;
        private int rear;
        private readonly int max;

        public LinearQueue(int size) { // constructor to initialise values
            que = new int[size];
            front  = 0 ;
            rear = -1;
            max = size;
        }

        public void enqueue(int item) { // to add elements to queue
            if (rear == max-1)
            { // if queue has reached maximum number of elements
                Console.WriteLine("Queue Overflow");
                return;
            }
            que[++rear] = item;
            Console.WriteLine("Added element: " + item);
        }

        public void dequeue() { // to remove elements from queue
            if(front == rear + 1) { // if queue has no elements to delete
                Console.WriteLine("Queue Underflow");
                return;
            }
            Console.WriteLine("Deleted element: " + que[front++]);
        }

        public void peek() { // to displau the queue
            if (front == rear + 1)
            { // if queue has no elements
                Console.WriteLine("Queue is Empty!");
                return;
            }
            Console.Write("Queue : ");
            for (int i = front; i <= rear; i++) { // iterates the array to print all the queue elements
                Console.Write(que[i] + " ");      
            } 
            Console.WriteLine();
        }
    }

    static class Program
    { // initial class which tests the Queue implementation
        static void Main() {
            LinearQueue queue = new LinearQueue(5);
            // adding elements to emptu queue
            queue.enqueue(1);
            queue.enqueue(2);
            queue.enqueue(3);
            queue.enqueue(4);
            // displaying the elements
            queue.peek();
            // further operations
            queue.enqueue(5);
            queue.dequeue();
            queue.dequeue();
            // display elements again
            queue.peek();
            // try to add and delete more elements till there are none left
            queue.enqueue(6);
            queue.dequeue();
            queue.dequeue();
            queue.dequeue();
            // display the final empty queue
            queue.peek();
        }
    }
} 