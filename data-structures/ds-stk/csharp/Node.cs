namespace stack
{  
    /// <summary>
    /// Creating Node for adding
    /// elements into stack using Linked List.
    /// </summary>
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
}