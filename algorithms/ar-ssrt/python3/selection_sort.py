def selection(arr):
    for i in range(len(arr)):
        min_idx = i
        for j in range(i + 1, len(arr)):
            if arr[min_idx] > arr[j]:
                min_idx = j

        arr[i], arr[min_idx] = arr[min_idx], arr[i]

    print("Sorted array")
    for i in range(len(arr)):
        print("%d" % arr[i]),


a = [1, 88, 2, 56, 56, 5, 56, 2, 5, 65, 8]

print(selection(a))
