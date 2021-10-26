from collections import deque


# Priority Queue using heap in Python
# Can be configured as max or min heap by passing
# the appropriate comparator function
class PriorityQueue:
    def __init__(self, comparator):
        self.heap = deque()
        self.comparator = comparator

    def size(self):
        return len(self.heap)

    def isEmpty(self):
        return self.size() == 0

    def peek(self):
        if self.heap:
            return self.heap[0]
        else:
            return None

    def __parent__(self, index):
        return (index - 1) // 2

    def __left__(self, index):
        return index * 2 + 1

    def __right__(self, index):
        return index * 2 + 2

    def __swap__(self, i, j):
        temp = self.heap[i]
        self.heap[i] = self.heap[j]
        self.heap[j] = temp

    def __swap_if_needed__(self, index1, index2):
        if self.__compare__(index1, index2):
            self.__swap__(index1, index2)
        else:
            return

    def __compare__(self, i, j):
        return self.comparator(self.heap[i], self.heap[j])

    def push(self, num):
        self.heap.append(num)
        self.__siftup__(len(self.heap) - 1)

    def __siftup__(self, index):
        parent_index = self.__parent__(index)
        if parent_index < 0:
            return
        else:
            self.__siftup_float__(index, parent_index)

    def __siftup_float__(self, index, parent_index):
        while parent_index >= 0:
            self.__swap_if_needed__(index, parent_index)
            index = parent_index
            parent_index = self.__parent__(index)

    def pop(self):
        if self.heap:
            first_value = self.heap.popleft()
            self.__siftdown__()
            return first_value

    def __siftdown__(self):
        if self.heap:
            last_value = self.heap.pop()
            self.heap.appendleft(last_value)
            index = 0
            last_index = len(self.heap) - 1
            self.__siftdown_push__(index, last_index)

    def __siftdown_push__(self, index, last_index):
        while True:
            left_index = self.__left__(index)
            right_index = self.__right__(index)
            if left_index > last_index and right_index > last_index:
                return
            comp_index = self.__siftdown_get_comp_index__(left_index, right_index, last_index)
            self.__swap_if_needed__(comp_index, index)
            index = comp_index

    def __siftdown_get_comp_index__(self, left_index, right_index, last_index):
        comp_index = right_index
        if left_index <= last_index and right_index <= last_index:
            if self.__compare__(left_index, right_index):
                comp_index = left_index
        elif left_index <= last_index:
            comp_index = left_index
        return comp_index


def main():
    print("Max Heap Priority Queue (largest value priority):")
    print("input: 15, 12, 50, 7, 40, 22")
    print("output:")
    max_heap = PriorityQueue(lambda a, b: a > b)
    max_heap.push(15)
    max_heap.push(12)
    max_heap.push(50)
    max_heap.push(7)
    max_heap.push(40)
    max_heap.push(22)

    while not max_heap.isEmpty():
        print(max_heap.pop())

    print()

    print("Min Heap Priority Queue (smallest value priority):")
    print("input: 12, 15, 7, 50, 22, 40")
    print("output:")
    min_heap = PriorityQueue(lambda a, b: a < b)
    min_heap.push(12)
    min_heap.push(15)
    min_heap.push(7)
    min_heap.push(50)
    min_heap.push(22)
    min_heap.push(40)

    while not min_heap.isEmpty():
        print(min_heap.pop())


if __name__ == '__main__':
    main()
