def linear_search(a,k):
    l = len(a)
    for i in range( l ):
        print(i,'->',a[i])
        if a[i] == k:
            return i
    return -1
def main():  
    choice = input("Are you entering integers ? Enter (yes / no)")
    if choice.lower() == "yes" :
        arr = list(map(int, input("Enter the comma-seperated elements: ").strip().split(',')))
        key = int(input("Enter an element to search: "))       
    elif choice.lower() == "no":
        arr = list((input("Enter the comma-seperated elements: ").strip().split(',')))
        key = input("Enter an element to search: ")
    index = linear_search(arr,key)
    if index == -1:
        print("Element {} is not in the list.".format(key))
    else:
        print("Element {} is found at index {}".format(key,index))       
if __name__=="__main__":
    main()
