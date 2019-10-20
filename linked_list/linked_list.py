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
        return print("Successfully added",item)

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

            return print(item,"Item not found")

    def prnt(self):
        nd = self.root
        print("===============================================")
        while nd:

            print(nd.data,end=" ")
            nd=nd.next
        print("")
        print("===============================================")



lin=LinkedList()


k=0
while k is not 6:
    k=int (input(" 1.for added a element for Link list \n 2.for delete a element for Link list \n 3.for search a element for Link list \n 4.Size of Link list \n 5.Print Link list \n 6.Exit "))
    print("===============================================")
    if k == 1:
        l =input("Enter the elements")
        lin.add(l)
    elif k ==2:
        l=input("what is the element you want to delete")
        lin.delet(l)
    elif k ==3:
        l=input("Enter the searching element")
        lin.search(l)
    elif k==4:
        if lin.root == None:
            print("Empty one")
        else:
            print("The size of link list",lin.size)
    elif k==5:
        if lin.root == None :
            print("Empty one")
        else:
            lin.prnt()
    elif k==6:
        break
    else:
        print("Enter correct input")







