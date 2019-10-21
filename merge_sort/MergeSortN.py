def arrSort(arr): 
    if len(arr)>1: 
        mid = len(arr)//2 #mid value of the array
        LS = arr[:mid] #Left side of the array 
        RS = arr[mid:] #Right side of the array  
  
        arrSort(LS) # Sorting the Left half 
        arrSort(RS) # Sorting the Right half 
  
        i = j = k = 0
          
        # Copy data to temp arrays L[] and R[] 
        while i < len(LS) and j < len(RS): 
            if LS[i] < RS[j]: 
                arr[k] = LS[i] 
                i+=1
            else: 
                arr[k] = RS[j] 
                j+=1
            k+=1
          
        # Checking if any element was left 
        while i < len(LS): 
            arr[k] = LS[i] 
            i+=1
            k+=1
          
        while j < len(RS): 
            arr[k] = RS[j] 
            j+=1
            k+=1
   
def printList(arr): 
    for i in range(len(arr)):         
        print(arr[i],end=" ") 
    print() 
  
# driver code to test the above code 
if __name__ == '__main__':
    arr = []
    e = int(input("Enter the array size:"))
    for i in range(e):
        val = int(input("Enter the element no %d:" %(i+1)))
        arr.append(val)    
    print ("Original array: ", end="\n")  
    printList(arr) 
    arrSort(arr) 
    print("Sorted array: ", end="\n") 
    printList(arr) 
