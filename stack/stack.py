# Implementing the Stack class


class Stack:
    def __init__(self):
        self.items = []

    def isEmpty(self):
        return self.items == []

    def push(self, data):
        self.items.append(data)

    def pop(self):
        return self.items.pop()

    def peek(self):
        return self.items[len(self.items) - 1]

    def size(self):
        return len(self.items)

    def printStack(self):
        print(self.items)

# End of Stack class


def Main():
    # create new Stack
    st = Stack()
    print("#### Welcome ####")
    op = 1

    while op != 7:
        print("1.isEmpty\n2.Push\n3.POP\n4.Peek\n5.size\n6.Print\n7.Exit")
        op = int(input("Select your option : "))

        print("-------------------------------------")
        if(op == 1):
            if(st.isEmpty()):
                print("Stack is Empty")
            else:
                print("Stack is not empty")
        elif(op == 2):
            data = input("Enter data : ")
            st.push(data)
        elif(op == 3):
            if(st.isEmpty()):
                print("Can't pop because stack is empty")
            else:
                print(st.pop(), " is popped out from stack.")
        elif(op == 4):
            if(st.isEmpty()):
                print("No element in stack.")
            else:
                print(st.pop(), " is the top most element.")
        elif(op == 5):
            if(st.size() == 0):
                print("Stack is empty")
            else:
                print("stack have ", st.size(), " element(s).")
        elif(op == 6):
            if(st.isEmpty()):
                print("Stack is empty")
            else:
                print("Stack : ")
                st.printStack()
        elif(op != 7):
            print("Invalid Option.\n")

        print("-------------------------------------")
    print("GoodBye")


if __name__ == "__main__":
    Main()
