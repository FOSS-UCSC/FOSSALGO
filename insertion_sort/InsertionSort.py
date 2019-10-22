# Insertion Sort Implementation IN Python #FOSSALGO 

def insertionSort(Array): 
	for i in range(1, len(arr)):# Traverse through the all elements in Array
		value = arr[i] 
		j = i-1
		while j >= 0 and value < arr[j] : 
				arr[j + 1] = arr[j] 
				j -= 1
		arr[j + 1] = value 


arr=list(map(int,input("Enter any SpaceSaparated Array :").split()))#get Array

insertionSort(arr)

print("Sorted Array :",*arr)
