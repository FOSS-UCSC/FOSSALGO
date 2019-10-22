def sort (a, b, res, n, m):
   
   a.sort()
   b.sort()
   
   i, j, k = 0, 0, 0
   while (i < n and j < m):
      if (a[i] <= b[j]):
         res[k] = a[i]
         i += 1
         k += 1
      else:
         res[k] = b[j]
         j += 1
         k += 1
   while (i < n):  
      res[k] = a[i]
      i += 1
      k += 1
   while (j < m):  
      res[k] = b[j]
      j += 1
      k += 1

# Driver code

array1=list()
n=int(input("Enter the size of the First List:"))
print("Enter the Element of First List:")
for i in range(int(n)):
   k=int(input(""))
   array1.append(k)

array2=list()
m=int(input("Enter the size of the Second List:"))
print("Enter the Element of Second List:")
for i in range(int(m)):
   k=int(input(""))
   array2.append(k)

# Final merge list
res = [0 for i in range(n + m)]
sort(array1, array2, res, n, m)
print ("Sorted merged list :")
for i in range(n + m):
   print (res[i])
