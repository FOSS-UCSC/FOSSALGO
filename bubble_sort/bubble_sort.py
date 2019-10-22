dataCount=0
dataCount=int(input("Enter Count of the Numbers: "))
array = []
for i in range(dataCount):
    array.append(int(input("enter num :")))

print("Unsorted Dataset")
for j in array:
    print(j ,end=" ")
