def binarysearch(arr,x):
  low=0
  high=len(arr)-1
  mid=0
  while(low<=high): 
    mid=(low+high)//2
    if(arr[mid]<x):
      low=mid+1
    elif(arr[mid]>x):
      high=mid-1
    else: 
      return mid
  return -1
  
def main():
  arr = [1,2,3,4,5,6]
  index = binarysearch(arr,5)
  if(index==-1):
    print "The element is not found!"
  else:
    print 'Element is found at index:',index

if __name__ == '__main__':
    main()



