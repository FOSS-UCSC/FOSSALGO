def selection(a):
        for i in range(0,len(a)-1):
                minIndex=i
                for j in range(i+1,len(a)):                        
                        if a[minIndex]>a[j]:
                                minIndex = j
                            
                if minIndex != i:
                    a[i],a[minIndex]=a[minIndex],a[i]
        return a
a=[1,88,2,56,56,5,56,2,5,65,8]
print(selection(a))

