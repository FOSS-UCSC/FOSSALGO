# liner Queue class
# for breadth-first traversal
class Queue:
    def __init__(self):
        self.items = []

    def isEmpty(self):
        return len(self.items) == 0

    def enqueue(self, item):
        self.items.append(item)

    def dequeue(self):
        assert not self.isEmpty(), "Cannot dequeue from an empty queue."
        return self.items.pop(0)

    def size(self):
        return len(self.items)

    def peek(self):
        return self.items[len(self.items) - 1]

    def printQ(self):
        print(self.items)


# basic node for tree
class Node:
    def __init__(self, data_in):
        self.data = data_in
        self.left = None
        self.right = None


# binary tree
class Tree:
    def __init__(self):
        self.root = None
        self.size = 0

# inserts a new node to the tree
    def insert(self, data_in):
        if self.root is None:
            self.root = Node(data_in)
            self.size += 1
        else:
            self._insert(data_in, self.root)

# helper function for insert node
    def _insert(self, data_in, current_node):
        if data_in < current_node.data:
            if current_node.left is None:
                current_node.left = Node(data_in)
                self.size += 1
            else:
                self._insert(data_in, current_node.left)
        else:
            if current_node.right is None:
                current_node.right = Node(data_in)
                self.size += 1
            else:
                self._insert(data_in, current_node.right)

    def pre_order(self):
        if self.root is not None:
            print(self.root.data)
        if self.root.left is not None:
            self._pre_order(self.root)

# helper function for pre_order
    def _pre_order(self, current_node):
        if current_node.left is not None:
            print(current_node.left.data)
            self._pre_order(current_node.left)

        if current_node.right is not None:
            print(current_node.right.data)
            self._pre_order(current_node.right)

    def post_order(self):
        if self.root.left is not None:
            self._post_order(self.root)

# helper function for post_order
    def _post_order(self, current_node):
        if current_node.left is not None:
            self._post_order(current_node.left)

        if current_node.right is not None:
            self._post_order(current_node.right)
        print(current_node.data)

    def in_order(self):
        if self.root.left is not None:
            self._in_order(self.root)

# helper function for in_order
    def _in_order(self, current_node):
        if current_node.left is not None:
            self._in_order(current_node.left)
        print(current_node.data)
        if current_node.right is not None:
            self._in_order(current_node.right)

    def breadth_first(self):
        q = Queue()
        q.enqueue(self.root)

        while not q.isEmpty():
            node = q.dequeue()
            print(node.data)

            if node.left is not None:
                q.enqueue(node.left)
            if node.right is not None:
                q.enqueue(node.right)

t = Tree()
t.insert(50)
t.insert(60)
t.insert(40)
t.insert(45)
t.insert(30)
t.insert(20)
t.insert(55)
t.insert(56)
t.insert(51)
t.insert(31)
t.insert(70)

print(t.size)
print("--pre--")
t.pre_order()
print("--in--")
t.in_order()
print("--post--")
t.post_order()
print("--bd first--")
t.breadth_first()
