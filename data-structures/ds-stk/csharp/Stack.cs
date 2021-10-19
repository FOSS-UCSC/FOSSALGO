namespace stack
{
    class Stack
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
        static void Main(string[] args)
        {
            var llStack = new LinkedListStack();
            llStack.Print();
            llStack.Pop();
            llStack.Push(30);
            llStack.Push(20);
            System.Console.WriteLine("Element {0} found? : {1}", 20, llStack.Search(20));
            llStack.Print();
            System.Console.WriteLine("Element {0} is popped.", llStack.Pop());
            llStack.Push(50);
            llStack.Push(120);
            llStack.Print();
            System.Console.WriteLine("Element {0} is popped.", llStack.Pop());
            System.Console.WriteLine("Element {0} is popped.", llStack.Pop());
            System.Console.WriteLine("Element {0} is popped.", llStack.Pop());
            llStack.Print();
            System.Console.WriteLine("Element {0} found? : {1}", 20, llStack.Search(20));
        }
    }
}
