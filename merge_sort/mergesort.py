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


A = []
B = []

n1 = int(input("\n Enter number of elements : "))

for i in range(0, n1): 
    ele = int(input()) 
  
    A.append(ele)
    
n2 = int(input("\n Enter number of elements : "))

for i in range(0, n2): 
    ele = int(input()) 
  
    B.append(ele)

mergesort(A,B)
