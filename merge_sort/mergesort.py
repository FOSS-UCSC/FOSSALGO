def mergesort(arr_A, arr_B):
    arr1 = []
    i,j = 0,0
    while (i < len(arr_A) and j < len(arr_B)):
        if (arr_A[i] < arr_B[j]):
            arr1.append(arr_A[i])
            i += 1

        else:
            arr1.append(arr_B[j])
            j += 1

    while (i < len(arr_A)):
        arr1.append(arr_A[i])
        i += 1

    while (j < len(arr_B)):
        arr1.append(arr_B[j])
        j += 1
        
    print(arr1)


A = [17,26,54,77,93]
B = [20,25,31,44,55]

mergesort(A,B)
