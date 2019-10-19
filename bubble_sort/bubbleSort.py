def sort(array):
    n = len(array)
    for i in range(n):
        for j in range(0, n - i - 1):
            if array[j] > array[j + 1]:
                array[j], array[j + 1] = array[j + 1], array[j]
    print("Sorted array is:")
    for i in range(len(array)):
        print("%d" % array[i])


array = [6, 3, 5, 1, 2, 10, 9, 8, 4, 7]

sort(array)


