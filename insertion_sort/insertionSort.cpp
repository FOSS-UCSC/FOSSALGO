// C Implementation for insertion sort FOSSALGO
#include <math.h> 
#include <stdio.h> 

void insertionSort(int arr[], int n);
int main() 
{ 
	int n,i;
	printf("Enter Size of ARRAY : ");
	scanf("%d",&n);
	int arr[n];
	for (i=0;i<n;i++){
		printf("Enter %d Element:",i);
		scanf("%d",&arr[i]);
	}
	insertionSort(arr,n); 
	printf("\nSorted Array \n============\n");
	for (i = 0; i < n; i++) 
		printf("%d ", arr[i]); 
	return 0; 
} 

void insertionSort(int arr[], int n) 
{ 
	int i, key, j; 
	for (i = 1; i < n; i++) { 
		key = arr[i]; 
		j = i - 1; 
		while (j >= 0 && arr[j] > key) { 
			arr[j + 1] = arr[j]; 
			j = j - 1; 
		} 
		arr[j + 1] = key; 
	} 
} 
