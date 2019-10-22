array = []
s=int(input("Enter Number Of Elements:"))
for i in range(s):
    a = int(input("enter num :"))
    b = array.append(a)
print("Array --------> ", array)

for i in range(len(array) - 1, 0, -1):
    for j in range(i):
        if (array[j] > array[j + 1]):
            temp = array[j]
            array[j] = array[j + 1]
            array[j + 1] = temp

print("\nSorted Array --------> ", array)

c = int(input("\nEnter search num :"))

aLen = len(array)
t = aLen // 2

while((t != -1) and (t < aLen)):
    if(c > array[t]):
        t = (t + aLen + 1) // 2
    elif(c < array[t]):
        t = t // 2
    elif(c == array[t]):
        break
    else:
        t = aLen + 1

if(t < aLen):
    print("search is finished. Index is :", t)
else:
    print("search is finished.Value Not found.")
