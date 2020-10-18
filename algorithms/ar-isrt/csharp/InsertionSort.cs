// C# program to implement Insertion Sort 
using System; 

public static class InsertionSort { 

	// Function to sort array using insertion sort 
	static void sort(int[] arr) 
	{ 
		int n = arr.Length; 
		for (int i = 1; i < n; ++i) 
		{ 
			int key = arr[i]; 
			int j = i - 1; 


			while (j >= 0 && arr[j] > key) 
			{ 
				arr[j + 1] = arr[j]; 
				j = j - 1; 
			} 
			arr[j + 1] = key; 
		} 
	} 

	// Function to print array of size n 
	static void printArray(int[] arr) 
	{ 
		int n = arr.Length; 
		for (int i = 0; i < n; ++i) 
		{
			//print(arr[i]) 
		}

	} 

	// Driver Code to test above function
	public static void Main() 
	{ 
		int[] arr = { 12, 11, 13, 5, 6 , 1, 2, 5, 4, 7, 8, 6, 8}; 
		sort(arr); 
		printArray(arr); 
	} 
} 

