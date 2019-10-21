class Stack:
     def __init__(self):
         self.container = [] 
     def isEmpty(self):
         return self.size() == 0  
     def push(self, item):
         self.container.append(item)  
     def pop(self):
         print( self.container.pop() )
     def peek(self):
         if self.isEmpty():
             raise Exception("Stack empty!")
         return self.container[-1] 
     def size(self):
         return len(self.container) 
     def show(self):
         return self.container


newStack=Stack()
newStack.push(10)
newStack.push(30)
newStack.pop()
