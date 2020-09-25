def insertionSort(array):
    n=len(array)
    i=0
    j=0
    for i in range(1,n):
        temp=array[i]
        print(temp)
        j=i
        while(j>0 and temp<array[j-1]):
            array[j]=array[j-1];
            j-=1
        array[j]=temp
    return array

a=[5,2,4,3,0,6,7,8,11]
print(insertionSort(a))

                   
