class Queue():
    def __init__(self):
        """Initialize this queue to the empty queue."""
        self.queue = list()
        self.rear = -1
        self.front = 0
        self.size = 0

    def enqueue(self, data):
        """If queue already full can't add element further"""
        if self.is_full():
            print("Queue is full")
        else:
            self.rear += 1
            self.queue.insert(self.rear, data)
            self.size += 1

    def is_full(self):
        if self.rear == 100:
            return 1
        else:
            return 0

    def is_empty(self):
        if self.size == 0:
            return 1
        else:
            return 0

    def dequeue(self):
        if not self.is_empty():
            self.data = self.queue[self.front]
            self.front += 1
            self.size -= 1
            return self.data
        else:
            return -1

    def peek(self):
        """return front element no delete here"""
        if not self.is_empty():
            return self.queue[self.front]
        else:
            print("Queue is Empty")

    def show(self):
        """show current elements in the queue"""
        for i in range(self.front, self.rear + 1, 1):
            print(self.queue[i], end=" ")
        print()


def main():
    # create new Stack
    qu = Queue()
    print("#### Welcome ####")
    op = 1

    while op != 7:
        print("1.isEmpty\n2.Enqueue\n3.Dequeue\n4.Peek\n5.size\n6.Print\n7.Exit")
        op = int(input("Select your option : "))

        print("-------------------------------------")
        if op == 1:
            if qu.is_empty():
                print("Queue is Empty")
            else:
                print("Queue is not empty")
        elif op == 2:
            data = input("Enter data : ")
            qu.enqueue(data)
        elif op == 3:
            if qu.is_empty():
                print("Can't dequeue because quack is empty")
            else:
                print(qu.dequeue(), " is dequeue from queue.")
        elif op == 4:
            if qu.is_empty():
                print("No element in queue.")
            else:
                print(qu.peek(), " is the front element.")
        elif op == 5:
            if qu.size == 0:
                print("Queue is empty")
            else:
                print("Queue have ", qu.size, " element(s).")
        elif op == 6:
            if qu.is_empty():
                print("Stack is empty")
            else:
                print("Queue : ")
                qu.show()
        elif op != 7:
            print("Invalid Option.\n")

        print("-------------------------------------")
    print("GoodBye")


if __name__ == "__main__":
    main()
