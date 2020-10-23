def insertionSort(b):
    for i in xrange(1, len(b)):
        up = b[i]
        j = i - 1
        while j >= 0 and b[j] > up:
            b[j+1] = b[j]
            j = j - 1
        b[j+1] = up
    return b

def bucketSort(x):
    arr = []
    slot_num = 10
    for i in xrange(slot_num):
        arr.append([])

    for j in x:
        index_b = int(slot_num * j)
        arr[index_b].append(j)

    for i in xrange(slot_num):
        arr[i] = insertionSort(arr[i])

    k = 0
    for i in xrange(slot_num):
        for j in xrange(len(arr[i])):
            x[k] = arr[i][j]
            k += 1
    return x

def main():
    x = [0.1534, 0.9493, 0.4969,
     0.8888, 0.663, 0.525]
    print "Sorted Array is"
    for no in bucketSort(x):
        print no

if __name__ == "__main__":
    main()