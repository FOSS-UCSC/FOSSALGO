import java.util.Scanner;
class BubbleSort 
{ 
    void Sort(int arr[]) 
    { 
        int n = arr.length; 
        for (int i = 0; i < n-1; i++) 
            for (int j = 0; j < n-i-1; j++) 
                if (arr[j] > arr[j+1]) 
                { 
                    int temp = arr[j]; 
                    arr[j] = arr[j+1]; 
                    arr[j+1] = temp; 
                } 
    } 
  
    
    void printArray(int arr[]) 
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
		BubbleSort ob = new BubbleSort();
        ob.Sort(arr); 
        System.out.println("Sorted array"); 
        ob.printArray(arr); 
    } 
} 