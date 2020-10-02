def merge_sort(arr_a, arr_b):
    a = len(arr_a)
    b = len(arr_b)

    res = []
    i, j = 0, 0

    while i < a and j < b:
        if arr_a[i] < arr_b[j]:
            res.append(arr_a[i])
            i += 1
        else:
            res.append(arr_b[j])
            j += 1

    res = res + arr_a[i:] + arr_b[j:]

    print("sorted array " + str(res))


A = [17, 26, 54, 77, 93]
B = [20, 25, 31, 44, 55]

merge_sort(A, B)
