array=[]
for i in range(11):
    a = int(input("enter num :"))
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
if(c > array[5]):
    for k in range(6,11):
        d = new_array.append(array[k])
    #print(new_array)
    for l in range(11):
        if (array[l] == c):
            print("search is finished. Index is :", l)

elif(c == array[5]):
    print("search is finished. Index is :", 5)

else:
    for k in range(5):
        e = new_array.append(array[k])
    #print(new_array)
    for l in range(11):
        if (array[l] == c):
            print("search is finished. Index is :", l)
        

        
