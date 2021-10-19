
# Queue Implementation in Python

class Queue: 
    # Queue Initialization
    def __init__(self, size):
        self.q = [None] * size     
        self.capacity = size        
        self.front = 0              
        self.rear = -1           
        self.count = 0
    # Dequeue the Front Element
    def pop(self):
        if self.isEmpty():
            print("Underflow")
            exit(1)
        print("Dequeuing Element", self.q[self.front])
        self.front = (self.front + 1) % self.capacity
        self.count = self.count - 1
    # Add Element to the Queue
    def append(self, value):
        if self.isFull():
            print("Overflow!")
            exit(1)
        print("Enqueuing Element", value)
        self.rear = (self.rear + 1) % self.capacity
        self.q[self.rear] = value
        self.count = self.count + 1
    # Return the Front Element of the Queue
    def peek(self):
        if self.isEmpty():
            print("UnderFlow")
            exit(1)
        return self.q[self.front]
    # Return the Size of the Queue
    def size(self):
        return self.count
    # Check if the Queue Is Empty or Not
    def isEmpty(self):
        return self.size() == 0
    # Check if the Queue Is Full or Not
    def isFull(self):
        return self.size() == self.capacity
if __name__ == '__main__':
    # Queue Creation
    q = Queue(5)
    q.append(1)
    q.append(2)
    q.append(3)
    print("Size of Queue: ", q.size())
    print("Front Element: ", q.peek())
    q.pop()
    print("Front Element: ", q.peek())
    q.pop()
    q.pop()
    if q.isEmpty():
        print("Queue Is Empty")
    else:
        print("Queue Isn't Empty")