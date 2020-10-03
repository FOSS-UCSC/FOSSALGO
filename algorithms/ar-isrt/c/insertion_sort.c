# include <stdio.h>

// Insertion sort function
void insertionSort(int arr[], int len) {
	int i, key;
	for (i=1 ; i<len ; i++) {
		int j = i-1;
		key = arr[i];
		while (j>=0 && arr[j]>key) {
			arr[j+1] = arr[j];
			j-=1;
		}
		arr[j+1] = key;
	}
}

// Function to print an array
void printArray(int arr[], int len) {
	int i;
	for (i=0 ; i<len ; i++)
		printf("%d ", arr[i]);\
	printf("\n");
}

// Function to test insetion sort
int main() {
	int arr[] = {22, 11, 8, 5, 30};
	int len = sizeof(arr)/sizeof(arr[0]);
	insertionSort(arr, len);
	printArray(arr, len);
	return 0;
}