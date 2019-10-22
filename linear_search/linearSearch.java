public class linearSearch
{
    
    public static void main(String[] args)
    {
    	int arr[] = {1, 20, 5, 41, 8, 9};
    	int n = arr.length;
    	int x = 1;
    	

        for (int i = 0; i < n; i++)
        {
        
            
            if (arr[i] == x)
            	System.out.println("Element found index is :"+ i );
        }
    }
} 