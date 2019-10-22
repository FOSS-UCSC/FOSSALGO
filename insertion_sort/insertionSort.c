#include<stdio.h>
#include<math.h>
void insertionSort(int arr[], int a) 
{ 
    int i, key, j; 
    for (i = 1; i < a; i++) { 
        key = arr[i]; 
        j = i - 1; 
  
        while (j >= 0 && arr[j] > key) { 
            arr[j + 1] = arr[j]; 
            j = j - 1; 
        } 
        arr[j + 1] = key; 
    } 
} 
   
void printArray(int arr[], int a) 
{ 
    int i; 
    for (i = 0; i < a; i++) 
        printf("%d ", arr[i]); 
    printf("\n"); 
} 
  
int main() 
{ 
    int arr[] = { 5,6,23,53,8}; 
    int a = sizeof(arr) / sizeof(arr[0]); 
  
    insertionSort(arr, a); 
    printArray(arr, a); 
  
    return 0; 
} 