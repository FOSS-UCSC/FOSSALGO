dataCount=0
dataCount=int(input("Enter Count of the Numbers: "))
array = []
for i in range(dataCount):
    array.append(int(input("enter num :")))

print("Unsorted Dataset: ")
print(array)

count = len(array)
out = 1
while out < count:
    i = 1
    while i < count:
        if array[i - 1] > array[i]:
            array[i - 1], array[i] = array[i], array[i - 1]
        i = i + 1
    out = out + 1
print("Sorted Dataset: ")
print(array)
