from time import sleep
from threading import Timer

def sleepSort(values):
    sortedList = []
    def add(x):
        sortedList.append(x)
    max = values[0]
    for value in values:
        if max < value: max = value
        Timer(value, add, [value]).start()
    sleep(max+1)
    return sortedList

list = [3,2,4,5,1]
print "Original list:", list
sortedList = sleepSort(list)
print "Sorted list:", sortedList
