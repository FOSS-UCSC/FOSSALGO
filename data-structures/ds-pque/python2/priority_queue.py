# using Linked List

class Node:     
  def __init__(self, value, priority):
    self.value = value
    self.priority = priority
    self.next = None
         

class PriorityQueue:
    
    # init
    def __init__(self):    
        self.front = None
         
    # Check priority queue is empty
    def isEmpty(self): 
        if self.front == None:
            return True
        else: 
            return False
     
    # Add a new node in priority queue
    def push(self, value, priority):
        if self.isEmpty() == True:
            self.front = Node(value, priority)
            return 1
        else:
            if self.front.priority > priority:
                newNode = Node(value, priority)
                newNode.next = self.front
                self.front = newNode
                 
                return 1
            else:
                temp = self.front
                while temp.next:
                    if priority <= temp.next.priority:
                        break
                    temp = temp.next
                
                newNode = Node(value, priority)
                newNode.next = temp.next
                temp.next = newNode

                return 1
     
    # Remove high priority node
    def pop(self):
        if self.isEmpty() == True:
            return
        else: 
            self.front = self.front.next
            return 1
             
    # Return high priority node
    def peek(self):
        if self.isEmpty() == True:
            return
        else:
            return self.front.value
             
    def traverse(self):
        if self.isEmpty() == True:
            return "Queue is Empty!"
        else:
            temp = self.front
            while temp:
                print(temp.value)
                temp = temp.next
 
if __name__ == "__main__":

    priority = PriorityQueue()
    priority.push(4, 1)
    priority.push(5, 2)
    priority.push(6, 3)
    priority.push(7, 0)
     
    priority.traverse()
    
    priority.pop()
   