public class LinkedList {
    private Node head;
    private int size;

    public LinkedList() {
        size = 0;
    }

    public void append(int value) {
        Node lastNode = new Node(value);
        if (head == null) {
            head = lastNode;
            size++;
            return;
        }

        Node sentinelNode = head;
        while (sentinelNode.next != null) {
            sentinelNode = sentinelNode.next;
        }

        sentinelNode.next = lastNode;
        size++;
    }

    public void prepend(int value) {
        Node newHead = new Node(value);
        newHead.next = head;
        head = newHead;
        size++;
    }

    public int getSize() {
        return size;
    }

    public void remove(int value) {
        if (head == null) {
            return;
        }

        if (head.value == value) {
            head = head.next;
            size--;
            return;
        }

        Node sentinel = head;
        while (sentinel.next != null) {
            if (sentinel.next.value == value) {
                sentinel.next = sentinel.next.next;
                size--;
                return;
            }
            sentinel = sentinel.next;
        }
    }

    public void printContent() {
        Node sentinel = head;

        while (sentinel.next != null) {
            System.out.format("%d -> ", sentinel.value);
            sentinel = sentinel.next;
        }
        System.out.format("%d%n", sentinel.value);
    }



    // Inner class for Node
    private class Node {
        public int value;
        public Node next;

        public Node(int value) {
            this.value  = value;
        }
    }

    public static void main(String[] args) {
        LinkedList list = new LinkedList();
        list.append(3);
        list.append(4);
        list.printContent();
        System.out.format("size = %d%n%n", list.getSize());

        list.prepend(2);
        list.prepend(1);
        list.printContent();
        System.out.format("size = %d%n%n", list.getSize());

        list.remove(1);
        list.remove(3);
        list.remove(123);
        list.printContent();
        System.out.format("size = %d%n%n", list.getSize());
    }
}
