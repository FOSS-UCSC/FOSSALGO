import java.util.Scanner;
class InsertionSort
{
    
    void sort(int arr[])
    {
        int n = arr.length;
        for (int i=1; i<n; ++i)
        {
            int key = arr[i];
            int j = i-1;
 
            while (j>=0 && arr[j] > key)
            {
                arr[j+1] = arr[j];
                j = j-1;
            }
            arr[j+1] = key;
        }
    }
    static void printArray(int arr[])
    {
        int n = arr.length;
        for (int i=0; i<n; ++i)
            System.out.print(arr[i] + " ");
 
        System.out.println();
    }
 
    public static void main(String args[])
    {
		Scanner sc = new Scanner(System.in);
        System.out.print("Enter the length of the array:");
		int length = sc.nextInt();
		int [] arr = new int[length];
		System.out.println("Enter the elements of the array:");

		for(int i=0; i<length; i++ ) 
		{
			arr[i] = sc.nextInt();
		}
 
        InsertionSort ob = new InsertionSort();        
        ob.sort(arr);
         
        printArray(arr);
    }
} 