
# This is function for sorting the array using bubble sort
def bubble_sort(length, array): # It takes two arguments -> Length of the array and the array itself.
                                # It returns the sorted array
    for i in range(length):
        j = 0
        for j in range(0, length-i-1):
            if array[j] > array[j+1]:
                array[j], array[j+1] = array[j+1], array[j]

    return array


# This is the main function of the program
def main():                                   
    length = int(input('Enter the length of the array to be entered : ')) # Taking the length of array
    array = [int(i) for i in input('Enter Array Elements : ').split()]    # Taking array elements
    sorted_array = bubble_sort(length,array)     # Calling the function for sorting the array using bubble sort
    print("Sorted Array is : ")
    for i in sorted_array:                       # Printing the sorted array
        print(i, end = " ")


# Running the main code of the program
if __name__ == '__main__':                      
    main()