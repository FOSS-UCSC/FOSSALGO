class Node:                         #create node constructer

    def __init__(self,d,n=None):
        self.data=d
        self.next=n


class LinkedList:                   #create link list constructer


    def __init__(self,r=None):
        self.root=r
        self.size=0

    def add(self,item):
        new_node=Node(item,self.root)
        self.root=new_node
        self.size+=1
        return print("Successfully addes",item)

    def size(self):
        return self.size


    def search(self,item):
        nd=self.root

        while nd:

            if nd.data==item:
                return print(item,"Find")

            else:
                nd=nd.next

        return print(item,"Not find")

    def delet(self,item):
        nd=self.root.next
        prev=self.root
        
        
        if self.root.data==item:
            self.root=self.root.next
            self.item-=1
            return print("Delete",item)

        else:
            while nd:
                if nd.data==item:
                    prev.next=nd.next
                    self.size-=1
                    return print("deleted",item)

                else:
                    nd=nd.next
                    prev=prev.next

            return print(item,"Item not find")


lin=LinkedList()

    #test link list ...
'''
lin.add(23)
lin.add("manjitha")
lin.add("teshara")
lin.add("false")
lin.search(23)
lin.search("manjitha")
print(lin.size)
lin.delet(23)
lin.delet("teran")

lin.add("manji")
lin.add("teshara")
lin.add("true")
lin.search(23)
lin.search("manjitha")
print(lin.size)
lin.delet(23)

'''        
