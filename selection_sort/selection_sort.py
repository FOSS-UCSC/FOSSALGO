def selection(a):
        for i in range(0,l):
                minIndex=i
                for j in range(i+1,l):                        
                        if arr[minIndex]>arr[j]:
                                minIndex = j
                            
                if minIndex != i:
                    arr[i],arr[minIndex]=arr[minIndex],arr[i]
        return arr

arr = []

l=int(input("Enter Number Of Elements:"))
for i in range(l):
    a = int(input("enter num :"))
    b = arr.append(a)
        
print(selection(a))

