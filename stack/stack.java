import java.util.Scanner;

class Stack { 
    static final int MAX = 10; 
    int top; 
    int a[] = new int[MAX]; 
  
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
    
    void size()
    {
        if (top < 0){
             System.out.println("Stack Underflow");
        }        
        else
        {
            System.out.println(top+1);
        }
    
    } 

    void printstack()
    {
        int i;
	    if(top==-1)
        System.out.println("Stack Underflow");
		
	else
	{
		for(i=0;i<=top;i++)
        System.out.println(a[i]);
	}
    }
}
  
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
              case 1: System.out.println("Enter number:");
                    n = myObj.nextInt();
                    s.push(n);
  					break;
  					
  			case 2: s.pop();
  					break;
  			
  			case 3:s.peek();
  					break;
  			
  			case 4:s.printstack();
  					break;
  			
  			case 5:s.size();
  				break;
  			
  			case 6:continue;
  				
  			default:System.out.println("error!!");
		}
        }
       
    } 
} 