arr = []
e = int(input("No. of Elements:"))
for i in range (e):
    val = int(input("Enter the element %d:" %(i+1)))
    arr.append(val)
  
# Traverse through all array elements and sort 
for j in range(e):        
    min_idx = j 
    for k in range(j+1, len(arr)): 
        if arr[min_idx] > arr[k]: 
            min_idx = k 
              
    arr[j], arr[min_idx] = arr[min_idx], arr[j] 
  
print ("Sorted array") 
for i in range(e): 
    print("%d" %arr[i])
