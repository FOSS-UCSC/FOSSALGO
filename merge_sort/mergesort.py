
def  mergesort(A,B):
    a= len(A) 
    b= len(B) 
      
    res = [] 
    i, j = 0, 0
      
    while i < a and j < b: 
        if A[i] < B[j]: 
          res.append(A[i]) 
          i += 1
      
        else: 
          res.append(B[j]) 
          j += 1
      
    res = res + A[i:] + B[j:] 
      
    print ("sorted array " + str(res)) 

A = [17,26,54,77,93]
B = [20,25,31,44,55]

mergesort(A,B)
