class Dequeue:
    class __Node:
        def __init__(self, value: int):
            self.next = None
            self.prev = None
            self.value = value
    def __init__(self):
        self.head = None
        self.tail = None

    def push_back(self, value: int) -> None:
        node = Dequeue.__Node(value)
        if self.head == None:
            self.head = node
            self.tail = node
        else:
            node.prev = self.tail
            self.tail.next = node
            self.tail = node
    
    def push_front(self, value: int) -> None:
        node = Dequeue.__Node(value)
        if self.head == None:
            self.head = node
            self.tail = node
        else:
            node.next = self.head
            self.head.prev = node
            self.head = node

    def pop_back(self) -> None:
        if self.tail == None:
            raise IndexError("Cannot pop from an Empty Dequeue")
        node = self.tail
        if self.head == self.tail:
            self.head = self.tail = None
        else:
            node.prev.next = None
            self.tail = node.prev
        
    def pop_front(self) -> None:
        if self.head == None:
            raise IndexError("Cannot pop from an Empty Dequeue")
        node = self.head
        if self.head == self.tail:
            self.head = self.tail = None
        else:
            node.next.prev = None
            self.head = node.next

    def back(self) -> int:
        if self.tail == None:
            raise IndexError("Empty Dequeue")
        return self.tail.value

    def front(self) -> int:
        if self.head == None:
            raise IndexError("Empty Dequeue")
        return self.head.value

    def is_empty(self) -> bool:
        return self.head == None

    def __str__(self) -> str:
        node = self.head
        string = ""
        string += "["

        while node:
            string += str(node.value)
            string += str(", " if node.next else "")
            node = node.next
        
        string += "]"
        return string


if __name__ == '__main__':
    deque = Dequeue()

    deque.push_back(5)
    deque.push_back(10)
    print(deque)

    deque.push_back(0)
    deque.pop_front()
    print(deque)

    val_front = deque.front()
    val_back = deque.back()

    print("Front:", val_front, ", back:", val_back)
    deque.pop_back()
    deque.pop_back()

    print("Dequeue is", ("Empty" if deque.is_empty() else "Not Empty"))