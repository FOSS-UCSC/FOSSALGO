class Node:    
    def __init__(self,data):    
        self.data = data;    
        self.previous = None;    
        self.next = None;    
            
class DoublyLinkedList:    
    def __init__(self):    
        self.head = None;    
        self.tail = None;    
            
  
    def addNode(self, data):
        newNode = Node(data);    
                
        if(self.head == None):    
            self.head = self.tail = newNode;    
            self.head.previous = None;    
            self.tail.next = None;    
        else:    
            self.tail.next = newNode;    
            newNode.previous = self.tail;    
            self.tail = newNode;    
            self.tail.next = None;    
                
    def display(self):    
        current = self.head;    
        if(self.head == None):    
            print("Doubly Link List is empty");    
            return;    
        print("Nodes");    
        while(current != None):     
            print(current.data),;    
            current = current.next;    
                
dList = DoublyLinkedList();    


dList.addNode(54);    
dList.addNode(27);    
dList.addNode(76);    
dList.addNode(65);    
dList.addNode(4);    
     

dList.display();  
