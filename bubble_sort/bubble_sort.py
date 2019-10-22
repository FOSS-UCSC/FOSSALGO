# Python program for implementation of Bubble Sort 

# Function containing the bubble sort algorithm

def bubbleSort(arr):
    
    # Traverse through 1 to len(arr) 
    for i in range(len(arr)-1):
        
        # After i numberof iterarions the last i elements are in place
        for j in range(0, len(arr)-i-1):

            # Traverse array from index 0 to len(arr)- i - 1
            # Swap if next element is smaller than current element
            if(arr[j] > arr[j+1]):
               (arr[j], arr[j+1]) = (arr[j+1], arr[j])


# tests for the code
arr1 = [12, 11, 13, 5, 6] 
bubbleSort(arr1) 
print("Sorted array ---> ", arr1)

arr2 = [1, 2, 31, 46, 59]
bubbleSort(arr2) 
print("Sorted array ---> ", arr2)

arr3 = [55, 44, 33, 2, 1]
bubbleSort(arr3) 
print("Sorted array ---> ", arr3)
