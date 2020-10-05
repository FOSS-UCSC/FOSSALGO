#include <stdio.h>

// Function to swap 2 values
void swap(int *x, int *y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}

// Bubble Sort function
void bubbleSort(int arr[], int len) {
	int i;
	for (i=0; i<len-1; i++) {
		int j;
		bool swapped = false;
		for (j=0; j<len-i-1; j++) {
			if (arr[j]>arr[j+1]) {
				swap(&arr[j], &arr[j+1]);
				swapped = true;
			}
		}
		if(swapped == false) {
			break;
		}
	}
}

// Function to print an array
void printArray(int arr[], int len) {
	int i;
	for (i=0; i<len; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

// Function to test bubbleSort
int main() {
	int arr[] = {62, 25, 13, 9, 36, 19, 20};
	int len = sizeof(arr)/sizeof(arr[0]);
	printf("**** Original Array ****\n");
	printArray(arr, len);
	bubbleSort(arr, len);
	printf("\n**** Sorted Array ****\n");
	printArray(arr, len);
	return 0;
}