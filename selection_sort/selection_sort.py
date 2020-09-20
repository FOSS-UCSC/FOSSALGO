def selection(a):
        for i in range(len(a)): 
            min_idx = i 
            for j in range(i+1, len(a)): 
                if a[min_idx] > a[j]: 
                    min_idx = j 
                              
            a[i], a[min_idx] = a[min_idx], a[i] 
          
        print ("Sorted array") 
        for i in range(len(a)): 
            print("%d" %a[i]),  




a=[1,88,2,56,56,5,56,2,5,65,8]


print(selection(a))

