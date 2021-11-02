size = 0
INF = 100000

# Get right child of a node of a tree
def right_child(arr, index):
    if(2*index + 1 < len(arr) and index >= 1):
        return 2*index + 1
    return -1

# Get left child of a node of a tree
def left_child(arr, index):
    if(2*index < len(arr) and index >= 1):
        return 2*index
    return -1

# Get the parent of a node of a tree
def parent(arr, index):
    if (index > 1 and index < len(arr)):
        return index//2
    return -1

def max_heapify(arr, index):
    left_child_index = left_child(arr, index)
    right_child_index = right_child(arr, index)

    biggest = index

    if (left_child_index <= size and left_child_index > 0):
        if (arr[left_child_index] > arr[biggest]):
            biggest = left_child_index

    if (right_child_index <= size and right_child_index > 0):
        if (arr[right_child_index] > arr[biggest]):
            biggest = right_child_index

    if (biggest != index):
        arr[index], arr[biggest] = arr[biggest], arr[index]
        max_heapify(arr, biggest)

def maxvalue(arr):
    return arr[1]

def extract_max(arr):
    global size
    minm = arr[1]
    arr[1] = arr[size]
    size = size-1
    max_heapify(arr, 1)
    return minm

def increase_key(arr, index, key):
    arr[index] = key
    while(index > 1 and arr[parent(arr, index)] < arr[index]):
        arr[index], arr[parent(arr, index)] = arr[parent(arr, index)], arr[index]
        index = parent(arr, index)

def insert(arr , key):
    global size
    size = size + 1
    arr[size] = -1*INF
    increase_key(arr, size, key)

if __name__ == '__main__':
    arr = [None]*20

    insert(arr, 20)
    insert(arr, 15)
    insert(arr, 8)
    insert(arr, 10)
    insert(arr, 5)
    insert(arr, 7)
    insert(arr, 6)
    insert(arr, 2)
    insert(arr, 9)
    insert(arr, 1)

    print("Input: ")
    print(arr[1:size+1])

    max = maxvalue(arr)
    
    print("Output: ")
    for i in range(len(arr[1:size+1])):
        print(extract_max(arr))

    print("Max value: ")
    print(max)


