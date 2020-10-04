# Bubble sort function
def bubbleSort(arr):
	n = len(arr)
	for i in range(n-1):
		for j in range(0, n-i-1):
			# Swap if current element is greater than next element
			if (arr[j]>arr[j+1]):
				arr[j], arr[j+1] = arr[j+1], arr[j]

# Function to print an array
def printArray(arr):
	for i in range(len(arr)):
		print "%d" % arr[i],

# Testing bubbleSort
arr = [62, 25, 13, 9, 36, 19, 20] 
print("**** Original Array ****")
printArray(arr)
bubbleSort(arr)
print("\n\n**** Sorted Array ****")
printArray(arr)
