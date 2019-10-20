# Recursive Algorithm For LCS

def recLcs(string1,string2):
    stringx=string1+'\0'
    stringy=string2+'\0'
    return(lcsUtil(stringx,stringy))
    

def lcsUtil(stringx,stringy,i=0,j=0):
    if(stringx[i]=='\0' or stringy[j]=='\0'):
        return 0
    if(stringx[i]==stringy[j]):
        return 1+lcsUtil(stringx,stringy,i+1,j+1)
    else:
        return max(lcsUtil(stringx,stringy,i,j+1),lcsUtil(stringx,stringy,i+1,j))

print(recLcs("LONGEST","ONE"))

# /Recursive Algorithm For LCS


#Dynamic Programming Algorithm

def dpLcs(string1,string2):
    x=len(string1)
    y=len(string2)
    matrix = [[0 for c in range(y+1)] for v in range(x+1)]
    for i in range(1,x+1): 
        for j in range(1,y+1): 

            if string1[i-1] == string2[j-1]: 
                matrix[i][j] = matrix[i-1][j-1]+1
            else: 
                matrix[i][j] = max(matrix[i-1][j] , matrix[i][j-1]) 
    return(matrix[i][j])

print(dpLcs("LONGEST","SON"))


