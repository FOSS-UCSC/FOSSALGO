array=[]
Num=1

Num= int (input("Enter the length of your array : "))

for i in range(Num):
    a = int(input("enter array items :"))
    b = array.append(a)
print("Array --------> " ,array)

for i in range(len(array)-1,0,-1):
    for j in range(i):
        if (array[j] > array[j+1]):
            temp = array[j]
            array[j] = array[j+1]
            array[j+1] = temp

print("\nSorted Array --------> " ,array)

c = int (input("\nEnter search num :"))
new_array=[]
if(c > array[len(array)/2]):
    for k in range((len(array)/2+1),len(array)+1):
        d = new_array.append(array[k])
    #print(new_array)
    for l in range(Num):
        if (array[l] == c):
            print("search is finished. Index is :", l)

elif(c == array[len(array)/2]):
    print("search is finished. Index is :", len(array)/2)

else:
    for k in range(len(array)/2):
        e = new_array.append(array[k])
    print(new_array)
    for l in range(len(array)+1):
        if (array[l] == c):
            print("search is finished. Index is :", l)
        

        
