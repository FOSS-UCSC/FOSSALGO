// C# implementation of Binary Search 
using System; 

class BinarySearch { 
	// Returns index of x if it is present in arr[], 
	// else return -1 
	static int DoBinarySearch(int[] arr, int x) 
	{ 
		int l = 0, r = arr.Length - 1; 
		while (l <= r) {

			int m = l + (r - l) / 2; //mid point

			//1) Check if x is present at mid 
			if (arr[m] == x) 
				return m; 

			//2) If x greater, ignore left half 
			if (arr[m] < x) 
				l = m + 1; 

			//3) If x is smaller, ignore right half 
			else
				r = m - 1; 
		} 

		// if we reach here, then element was 
		// not present 
		return -1; 
	} 

	//Driver program to test above function 
	public static void Main() 
	{ 
		int[] arr = { 2, 3, 4, 10, 40 }; 
		int n = arr.Length; 
		int x = 10; 
		int result = DoBinarySearch(arr, x); 
		if (result == -1) 
			Console.WriteLine("Element not present"); 
		else
			Console.WriteLine("Element found at "
							+ "index " + result); 
	} 
} 
