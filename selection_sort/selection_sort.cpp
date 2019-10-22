
#include<iostream>
using namespace std; 


int main() 
{ 
	int arr[] = {64, 25, 12, 22, 11}; 
	int n = sizeof(arr)/sizeof(arr[0]); 
	
	
	int i, j, min_index; 
	cout << "Unsorted array: \n"; 
	for (i=0; i < n; i++) 
		cout << arr[i] << " "; 
	cout << endl; 
	
	for (i = 0; i < n-1; i++) 
	{ 
		
		min_index = i; 
		for (j = i+1; j < n; j++) 
		if (arr[j] < arr[min_index]) 
			min_index = j; 

		int temp = arr[min_index]; 
		arr[min_index] = arr[i]; 
		arr[i] = temp;
		
	} 
	
	cout << "Sorted array: \n"; 
	
	for (i=0; i < n; i++) 
		cout << arr[i] << " "; 
	cout << endl; 
	return 0; 
} 



