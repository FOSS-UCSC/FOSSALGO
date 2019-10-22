count=0
count=int(input("Enter Count of the Numbers: "))
dataSet = []
for i in range(count):
    dataSet.append(int(input("enter num :")))
out = 1
print("Before Sort: ")
print(dataSet)
while out < count:
    i = 1
    while i < count:
        if dataSet[i - 1] > dataSet[i]:
            dataSet[i - 1], dataSet[i] = dataSet[i], dataSet[i - 1]
        i = i + 1
    out = out + 1
print("After Sort: ")
print(dataSet)
