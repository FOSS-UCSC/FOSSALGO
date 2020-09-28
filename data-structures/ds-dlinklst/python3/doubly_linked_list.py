#!/usr/bin/env python3
"""Python3 script for doubly linked list data structure."""


class Node(object):
    """Node for the linked list."""

    def __init__(self, data):
        """Node object initialize."""
        self.data = data
        self.previous = None
        self.next = None


class DoublyLinkedList(object):
    """Doubly linked-list implementation."""

    def __init__(self):
        """Doubly linked-list object initialize."""
        self.head = None
        self.tail = None

    def add_node(self, data):
        """Add a new node to the linked list."""
        new_node = Node(data)

        if self.head is None:
            self.head = self.tail = new_node
            self.head.previous = None
            self.tail.next = None
        else:
            self.tail.next = new_node
            new_node.previous = self.tail
            self.tail = new_node
            self.tail.next = None

    def display(self):
        """Display items of the linked list."""
        current = self.head
        if self.head is None:
            print("Doubly Link List is empty")
            return
        print("Nodes")
        while current is not None:
            cur_data = current.data
            print(cur_data)
            current = current.next


DLIST = DoublyLinkedList()

DLIST.add_node(54)
DLIST.add_node(27)
DLIST.add_node(76)
DLIST.add_node(65)
DLIST.add_node(4)

DLIST.display()
