class Queue():
    def __init__(self):
        '''Initialize this queue to the empty queue.'''
        self.queue=list()
        self.rear=-1
        self.front=0
        self.size=0
        
    '''add element to the queue'''
    def enqueue(self,data):
        '''If queue already full can't add element further'''
        if(self.isFull()):
            return 0
        self.rear+=1
        print(self.rear)
        self.queue.insert(self.rear,data)
        self.size+=1
        
        return self.queue


    def isFull(self):
        if(self.rear==100):
            return 1;
        else:
            return 0;
    def isEmpty(self):
        if(self.rear<self.front or self.front<0):
            return 1
        else:
            return 0

    '''remove front element in the queueu'''
    def dequeue(self):
        
        if(self.isEmpty()):
            data=queue[front]
            front+=1
            return data
        else:
            print("Queue is Empty")

    '''return front element no delete here'''
    def peek(self):
        return queue[front]

    '''show current elemrnt in the queue'''
    def show(self):
        for i in self.queue:
            print (i)

q=Queue()
q.enqueue(10)
q.show()

