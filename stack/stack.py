# Implementing the Stack class

class Stack:
    def __init__(self):
        self.container = []

    def isEmpty(self):
        return self.size() == []

    def push(self, item):
        self.container.append(item)

    def pop(self):
        return self.container.pop()

    def peek(self):
        if self.isEmpty():
            raise Exception("stack empty")
        return self.container[- 1]

    def size(self):
        return len(self.container)

    def printStack(self):
        return self.container

s = Stack()
s.push('1')
s.push('2')
s.push('3')
s.push('4')


print(s.pop())
print(s.printStack())

# End of Stack class
