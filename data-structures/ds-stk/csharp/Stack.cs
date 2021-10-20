using System.Diagnostics;
using stack;

namespace stack
{
    internal class Node
    {
        internal int data;
        internal Node next;

        public Node(int d)
        {
            data = d;
            next = null;
        }
    }

    internal class LinkedListStack
    {
        private Node _top;

        public LinkedListStack()
        {
            _top = null;
        }

        internal bool isEmpty()
        {
            if (_top == null)
            {
                return true;
            }
            return false;
        }

        internal void Push(int value)
        {
            var newNode = new Node(value);
            if (isEmpty())
            {
                newNode.next = null;
            }
            else
            {
                newNode.next = _top;
            }
            _top = newNode;
        }
        internal int Pop()
        {
            if (isEmpty())
            {
                return -1;
            }
            var currentTop = _top.data;
            _top = _top.next;
            return currentTop;
        }
        internal int Peek()
        {
            if (isEmpty())
            {
                return -1;
            }

            return _top.data;
        }
        
        internal void Print()
        {
            if (isEmpty())
            {
                return;
            }

            var tmpNode = _top;
            while (tmpNode != null)
            {
                Debug.Write(tmpNode.data);
                if (tmpNode.next != null)
                {
                    Debug.Write("->");
                }
                tmpNode = tmpNode.next;
            }
            Debug.WriteLine("");
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
}

internal class Stack
{
    protected Stack()
    {
    }

    public static void Main(string[] args)
    {
        var llStack = new LinkedListStack();
        llStack.Print();
        llStack.Pop();
        llStack.Push(30);
        llStack.Push(20);
        llStack.Print();
        llStack.Push(50);
        llStack.Push(120);
        llStack.Print();
        llStack.Pop();
        llStack.Pop();
        llStack.Print();
        llStack.Search(20);
    }
}