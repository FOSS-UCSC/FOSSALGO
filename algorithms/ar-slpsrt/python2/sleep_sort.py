from time import sleep
from threading import Timer

def sleepSort(values):
    sortedList = []
    def add(x):
        sortedList.append(x)
    maxVal = values[0]
    for value in values:
        if maxVal < value: maxVal = value
        Timer(value, add, [value]).start()
    sleep(maxVal+1)
    return sortedList

lst = [3,2,4,5,1]
print "Original list:", lst
sortedList = sleepSort(lst)
print "Sorted list:", sortedList
