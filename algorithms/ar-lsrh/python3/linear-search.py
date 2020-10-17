print ("Enter length of array:")
n = int(input())
arr = []
found = -1
print("Give inputs for array:")
for i in range(n):
    arr.append(int(input()))

print ("Enter the number to be searched")
find = int(input())

for no in arr:
    if no == find:
        found = arr.index(no)
        break

if  found != -1:
    print ("Found at index",found)
else:
    print("Not found")