# Python program for implementation of Insertion Sort 

# Function containing the insertion sort algorithm

def insertionSort(array): 
    # Traverse through 1 to len(arr) 
    for i in range(1, len(array)): 

        key = array[i]

	# Move the  elements in the array greater 
	# than the key, to one position ahead 
	# of their current position 
        j = i-1
        while j >= 0 and key < array[j] : 
            array[j + 1] = array[j] 
            j -= 1
        array[j + 1] = key 


# tests for the code
arr1 = [12, 11, 13, 5, 6] 
insertionSort(arr1) 
print("Sorted array ---> ", arr1)

arr2 = [1, 2, 31, 46, 59]
insertionSort(arr2) 
print("Sorted array ---> ", arr2)

arr3 = [55, 44, 33, 2, 1]
insertionSort(arr3) 
print("Sorted array ---> ", arr3)
