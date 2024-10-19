# Function to get the maximum value in the list
def getMax(arr):
    max_val = arr[0]
    for i in arr:
        if i > max_val:
            max_val = i
    return max_val

# Counting sort to sort elements based on the significant digit
def countingSort(arr, exp):
    n = len(arr)
    output = [0] * n  # Output array to hold sorted elements
    count = [0] * 10  # Initialize counting array (for base 10 digits)
    
    # Store the count of occurrences
    for i in range(n):
        index = (arr[i] // exp) % 10
        count[index] += 1

    # Change count[i] so that count[i] contains the actual position
    for i in range(1, 10):
        count[i] += count[i - 1]

    # Build the output array
    i = n - 1
    while i >= 0:
        index = (arr[i] // exp) % 10
        output[count[index] - 1] = arr[i]
        count[index] -= 1
        i -= 1

    # Copy the output array to arr
    for i in range(n):
        arr[i] = output[i]

# Main function to implement Radix Sort
def radixSort(arr):
    # Find the maximum number to determine the number of digits
    max_val = getMax(arr)
    # Do counting sort for every digit
    exp = 1
    while max_val // exp > 0:
        countingSort(arr, exp)
        exp *= 10

# Example usage
arr = [170, 45, 75, 90, 802, 24, 2, 66]
print("Original array:", arr)
radixSort(arr)
print("Sorted array:", arr)

