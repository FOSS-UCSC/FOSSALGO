def sort(array):
    for i in range(len(array) - 1, 0, -1):
        for j in range(i):
            if (array[j] > array[j + 1]):
                temp = array[j]
                array[j] = array[j + 1]
                array[j + 1] = temp
                
    print("\nSorted Array --------> ", array)

def search(c):  
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

if __name__ == '__main__':

    array = []
    for i in range(11):
        a = int(input("enter num :"))
        b = array.append(a)
    print("Array --------> ", array)

    sort(array)
    
    c = int(input("\nEnter search num :"))
    
    search(c)
    
def main():
    exit




