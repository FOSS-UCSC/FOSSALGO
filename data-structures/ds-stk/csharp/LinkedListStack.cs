using System;
namespace stack
{
    /// <summary>
    /// packed Stack implementation using LinkedList.
    /// </summary>
    internal class LinkedListStack
    {
        private Node _top;

        /// <summary>
        /// On creation of Object of Class LinkedList this constructor will be called.
        /// It will setup
        /// <code>_top = null</code>
        /// 
        /// </summary>
        public LinkedListStack()
        {
            this._top = null;
        }
        /// <summary>
        /// Check, If
        /// <code>_top == null</code>
        /// means if stack is empty,
        /// It returns true else false.
        /// </summary>
        /// <returns>bool</returns>
        internal bool isEmpty()
        {
            if (_top == null)
                return true;
            return false;
        }
        /// <summary>
        /// Push method is used to add element in stack.
        /// Stack follow basic rules, Last In First Out (LIFO).
        /// means element added at the end will be appended at _top of 
        /// stack.
        /// It will not return any value
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
        /// It will remove element and return element at _top of stack or 
        /// remove the element added most recently in stack.
        /// </summary>
        internal int Pop()
        {
            // empty stack operation handler.
            if (isEmpty())
            {
                Console.WriteLine("Stack Underflow. Nothing is to delete.");
                return 0;
            }
            int currentTop = _top.data;
            // replacing element at _top with element at _top.next.
            _top = _top.next;
            return currentTop;
        }
        /// <summary>
        /// It works as Pop but only return the elements, It is not delete the element
        /// from stack.
        /// Only it will returns and you can display it on console.
        /// </summary>
        internal int Peek()
        {
            if (isEmpty())
            {
                Console.WriteLine("Stack Underflow.");
                return 0;
            }
            return this._top.data;
        }
        /// <summary>
        /// As name suggests, It print all the elements
        /// </summary>
        internal void Print()
        {
            if (isEmpty())
            {
                Console.WriteLine("Stack is underflow, Nothing to display yet!");
                return;
            }
            Node tmpNode = this._top;
            while (tmpNode != null)
            {
                Console.Write("{0}", tmpNode.data);
                if (tmpNode.next != null)
                    Console.Write("->");
                tmpNode = tmpNode.next;

            }
            Console.WriteLine();
        }

        internal bool Search(int element)
        {
            Node tmpNode = this._top;
            while (tmpNode != null)
            {
                if (tmpNode.data == element)
                {
                    return true;
                }
                else
                    return false;
            }
            return false;
        }
    }

}