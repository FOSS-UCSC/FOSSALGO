import java.util.Scanner;

class Stack { 
    static final int MAX = 1000; 
    int top; 
    int a[] = new int[MAX]; // Maximum size of Stack 
  
    boolean isEmpty() 
    { 
        return (top < 0); 
    } 
    Stack() 
    { 
        top = -1; 
    } 
  
    boolean push(int x) 
    { 
        if (top >= (MAX - 1)) { 
            System.out.println("Stack Overflow"); 
            return false; 
        } 
        else { 
            a[++top] = x; 
            System.out.println(x + " pushed into stack"); 
            return true; 
        } 
    } 
  
    int pop() 
    { 
        if (top < 0) { 
            System.out.println("Stack Underflow"); 
            return 0; 
        } 
        else { 
            int x = a[top--]; 
            return x; 
        } 
    } 
  
    int peek() 
    { 
        if (top < 0) { 
            System.out.println("Stack Underflow"); 
            return 0; 
        } 
        else { 
            int x = a[top]; 
            return x; 
        } 
    } 
} 
  
// Driver code 
class Start { 
    public static void main(String args[]) 
    { 
        int a=0,n=0;
        Stack s = new Stack(); 
        Scanner myObj = new Scanner(System.in); 

        System.out.println("1.push ");
        System.out.println("2.pop");
        System.out.println("3.peek");
        System.out.println("4.print stack");
        System.out.println("5.print size");
        System.out.println("6.quit");

        while(a!=6)
        {
            System.out.println("Enter choice:");
            a = myObj.nextInt();

            switch(a)
  		{
  			//case 1:push(10);
  			//		break;
  					
  			case 2: s.pop();
  					break;
  			
  			case 3:s.peek();
  					break;
  			
  		//	case 4:s.printstack();
  		//			break;
  			
  		//	case 5:s.size();
  		//		break;
  			
  			case 6:continue;
  		//			break;
  				
  			default:System.out.println("error!!");
		}
        }
       
    } 
} 