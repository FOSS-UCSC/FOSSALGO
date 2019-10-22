def binarySearch (sarr, start, end, x):

    if end >= start:
       mid = start + (end- start)//2
   
       if arr[mid] == x:
          return mid
       elif arr[mid] > x:
          return binarySearchAppr(arr, start, mid-1, x)
       else:
          return binarySearchAppr(arr, mid+1, end, x)
    else:
        return -1
arr = []
sarr = []
n = int(input("No of Elements:"))
for i in range(n):
    val = int(input("Enter element %d:" %(i+1)))
    arr.append(val)          
sarr = sorted(arr)
x=int(input("Enter Search Number:"))
print ("Sorted array") 
for i in range(n): 
    print("%d" %sarr[i])
result = binarySearch(sarr, 0, len(sarr)-1, x)
if result != -1:
   print ("Element is present at index "+str(result))
else:
    print ("Element is not present in array")
