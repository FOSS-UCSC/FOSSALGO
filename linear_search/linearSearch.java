class linearSearch
{    
    static int search(int arr[], int n, int x)
    {
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == x)
                return i;
        } 
        return -1;
    }
	
	public static void main(String args[]) 
	{ 
		int arr[] = {21,34,12,3,10,45,19};  
		int x = 10; 
		int n = arr.length;
		int result = search(arr,n,x); 
		if(result == -1)
		{
			System.out.print("Element is not present in array");
		} 
		else
		{
			System.out.print("Element is present at index " + result);
		}
	}
} 
 