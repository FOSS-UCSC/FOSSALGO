// Importing the library
#include <stdio.h>

// Function for giving the partition point
int partition(int arr[], int low, int high){  //It takes array ,high and low point and returns the pivot point
    int i = low - 1, pivot = arr[high], temp;
    // The pivot element is placed at its correct position in sorted array
    // And places all smaller (smaller than pivot) to left of pivot
    // And all greater elements to right of pivot
    for(int j = low; j < high; j++){

        if(arr[j] < pivot){
            i ++;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return ( i+1 );

}


// Main function of quick sort algorithm (It is recursive in nature)
int quicksort(int arr[], int low, int high){    // It takes the array and high and low point
    // Initially low point is first index of array and high the last index

    if(low < high){     //Check if low is less then high
        int pivot;
         // It takes array ,high and low point and returns the pivot point
        pivot = partition(arr, low, high);
        quicksort(arr, low, pivot-1);    // Again calling the quick sort function with high point be pivot - 1
        quicksort(arr, pivot+1, high);   // Again calling the quick sort function with low point be pivot + 1
    }   // This recursion runs while low is less then high.
        // After that we get the sorted array.
}


// The main program
int main()
{
    int n;

    printf("Enter array length : ");
    scanf("%d", &n);            // Taking the length/size of the array

    int arr[n];
    printf("Enter array elements : ");
    for(int i=0;i<n;i++)
    {
        scanf("%d", &arr[i]);     // Taking array elements
    }

    quicksort(arr, 0, n-1);      // Calling the quicksort function for sorting the array in increasing order

    printf("Sorted Array is : ");
    for(int i=0;i<n;i++)
    {
        printf("%d ", arr[i]);    // Printing the sorted array
    }
    return 0;
}