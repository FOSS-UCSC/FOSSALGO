def search(array,x):
    index=0
    for i in array:
        if(i==x):
            return index
        index+=1

    return -1


userArray=[]

user=int(input("Enter elements for array: enter negative value to end"))
while(user>-1):
    userArray.append(user)
    user=int(input("Enter elements for array: enter negative value to end"))

x=int(input("Enter elementto find"))
result=search(userArray,x)

if(result==-1):
    print("Element is unavailable")

else:
    print("Element is at index"+str(result))
