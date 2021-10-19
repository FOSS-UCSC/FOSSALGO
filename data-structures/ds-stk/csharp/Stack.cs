using System;

namespace stack
{
    internal class Node
    {
        internal int data;
        internal Node next;

        // Constructor to create a new node.Next is by default initialized as null 
        public Node(int d)
        {
            data = d;
            next = null;
        }
    }

    internal class LinkedListStack
    {
        private Node _top;

        /// <summary>
        ///     On creation of Object of Class LinkedList this constructor will be called.
        ///     It will setup
        ///     <code>_top = null</code>
        /// </summary>
        public LinkedListStack()
        {
            _top = null;
        }

        /// <summary>
        ///     Check, If
        ///     <code>_top == null</code>
        ///     means if stack is empty,
        ///     It returns true else false.
        /// </summary>
        /// <returns>bool</returns>
        internal bool isEmpty()
        {
            if (_top == null) 
	    {
		    return true;
	    }
            return false;
        }

        /// <summary>
        ///     Push method is used to add element in stack.
        ///     Stack follow basic rules, Last In First Out (LIFO).
        ///     means element added at the end will be appended at _top of
        ///     stack.
        ///     It will not return any value
        /// </summary>
        /// <param name="value"></param>
        internal void Push(int value)
        {
            var newNode = new Node(value);
            // if stack is null
            if (isEmpty()) 
	    {
                newNode.next = null;
	    }
            // if already some data exists.
            else 
	    {
                newNode.next = _top;
	    }
            _top = newNode;
            Console.WriteLine("{0} pushed to stack", value);
        }

        /// <summary>
        ///     It will remove element and return element at _top of stack or
        ///     remove the element added most recently in stack.
        /// </summary>
        internal int Pop()
        {
            // empty stack operation handler.
            if (isEmpty())
            {
                Console.WriteLine("Stack Underflow. Nothing is to delete.");
                return 0;
            }

            var currentTop = _top.data;
            // replacing element at _top with element at _top.next.
            _top = _top.next;
            return currentTop;
        }

        /// <summary>
        ///     It works as Pop but only return the elements, It is not delete the element
        ///     from stack.
        ///     Only it will returns and you can display it on console.
        /// </summary>
        internal int Peek()
        {
            if (isEmpty())
            {
                Console.WriteLine("Stack Underflow.");
                return 0;
            }

            return _top.data;
        }

        /// <summary>
        ///     As name suggests, It print all the elements
        /// </summary>
        internal void Print()
        {
            if (isEmpty())
            {
                Console.WriteLine("Stack is underflow, Nothing to display yet!");
                return;
            }

            var tmpNode = _top;
            while (tmpNode != null)
            {
                Console.Write("{0}", tmpNode.data);
                if (tmpNode.next != null)
		{
			Console.Write("->");
		}
                tmpNode = tmpNode.next;
            }

            Console.WriteLine();
        }

        internal bool Search(int element)
        {
            var tmpNode = _top;
            while (tmpNode != null)
            {
                if (tmpNode.data == element)
                {
                    return true;
                }
                return false;
            }
            return false;
        }
    }

    internal class Stack
    {
        /**
            Stack is underflow, Nothing to display yet!
            Stack Underflow. Nothing is to delete.
            30 pushed to stack
            20 pushed to stack
            Element 20 found? : True
            20->30
            Element 20 is popped.
            50 pushed to stack
            120 pushed to stack
            120->50->30
            Element 120 is popped.
            Element 50 is popped.
            Element 30 is popped.
            Stack is underflow, Nothing to display yet!
            Element 20 found? : False
        */
        private static void Main(string[] args)
        {
            var llStack = new LinkedListStack();
            llStack.Print();
            llStack.Pop();
            llStack.Push(30);
            llStack.Push(20);
            Console.WriteLine("Element {0} found? : {1}", 20, llStack.Search(20));
            llStack.Print();
            Console.WriteLine("Element {0} is popped.", llStack.Pop());
            llStack.Push(50);
            llStack.Push(120);
            llStack.Print();
            Console.WriteLine("Element {0} is popped.", llStack.Pop());
            Console.WriteLine("Element {0} is popped.", llStack.Pop());
            Console.WriteLine("Element {0} is popped.", llStack.Pop());
            llStack.Print();
            Console.WriteLine("Element {0} found? : {1}", 20, llStack.Search(20));
        }
    }
}
