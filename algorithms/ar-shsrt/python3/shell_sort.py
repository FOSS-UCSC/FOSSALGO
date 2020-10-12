def shellSort(arr):    
    n = len(arr)     
    # Rearrange elements at each n/2, n/4, n/8, ... gaps
    gap = n//2  
    while gap > 0:   
        for i in range(gap,n):             
            temp = arr[i] 
            j = i 
            while  j >= gap and arr[j-gap] >temp: 
                arr[j] = arr[j-gap] 
                j -= gap   
            arr[j] = temp 
        gap //= 2

def main():
    arr = [ 1,31,78,26,11,16,46] 
    shellSort(arr) 
    print(arr) 

if __name__ == '__main__':
    main() 