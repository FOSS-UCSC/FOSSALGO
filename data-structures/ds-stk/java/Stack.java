class Stack {
    // store elements of stack
    private int arr[];
    // represent top of stack
    private int top;
    // total capacity of the stack
    private int capacity;
    // construct a stack
    Stack(int size) {
      arr = new int[size];
      capacity = size;
      top = -1;
    }

    // push elements to the top of stack
    public void push(int x) {
      if (isFull()) {
        System.out.println("Stack OverFlow");
  
        // terminates the program
        System.exit(1);
      }

      // insert element on top of stack
      System.out.println("Inserting " + x);
      arr[++top] = x;
    }

    // pop elements from top of stack
    public int pop() {
      if (isEmpty()) {
        System.out.println("STACK EMPTY");
        // terminates the program
        System.exit(1);
      }
      // pop element from top of stack
      return arr[top--];
    }

    // return size of the stack
    public int getSize() {
      return top + 1;
    }

    // check if the stack is empty
    public Boolean isEmpty() {
      return top == -1;
    }

    // check if the stack is full
    public Boolean isFull() {
      return top == capacity - 1;
    }

    // display elements of stack
    public void printStack() {
      for (int i = 0; i <= top; i++) {
        System.out.print(arr[i] + ", ");
      }
    }

    public static void main(String[] args) {
      Stack stack = new Stack(6);
  
      stack.push(12);
      stack.push(88);
      stack.push(32);
      stack.push(3);
      stack.push(22);
      stack.push(5);
  
      System.out.print("Stack: ");
      stack.printStack();
  
      stack.pop();
      System.out.print("\nAfter popping out\nStack:");
      stack.printStack();
  
    }
  }