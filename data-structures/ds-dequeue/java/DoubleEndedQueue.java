class Dequeue {
    class Node {
        public Node prev, next;
        public int value;
        public Node(int value) {
            prev = null;
            next = null;
            this.value = value;
        }
    }
    Node head, tail;
    Dequeue() {
        head = tail = null;
    }

    void pushBack(final int value) {
        Node node = new Node(value);
        if (head == null) {
            head = node;
            tail = node;
        }
        else {
            node.prev = tail;
            tail.next = node;
            tail = node;
        }
    }

    void pushFront(final int value) {
        Node node = new Node(value);
        if (head == null) {
            head = node;
            tail = node;
        }
        else {
            node.next = head;
            head.prev = node;
            head = node;
        }
    }

    void popBack() {
        if (tail == null) {
            throw new NullPointerException("Cannot pop from an Empty Dequeue");
        }

        Node node = tail;

        if (head == tail) {
            head = tail = null;
        }

        else {
            node.prev.next = null;
            tail = node.prev;
        }

        System.gc();
    }

    void popFront() {
        if (head == null) {
            throw new NullPointerException("Cannot pop from an Empty Dequeue");
        }

        Node node = head;

        if (head == tail) {
            head = tail = null;
        }

        else {
            node.next.prev = null;
            head = node.next;
        }

        System.gc();
    }

    int back() {
        if (tail == null) {
            throw new NullPointerException("Empty Dequeue");
        }
        return tail.value;
    }

    int front() {
        if (head == null) {
            throw new NullPointerException("Empty Dequeue");
        }
        return head.value;
    }

    boolean isEmpty() {
        return head == null;
    }

    public String toString() {
        Node node = head;
        StringBuilder sb = new StringBuilder();
        sb.append("[");

        while (node != null) {
            sb.append(node.value);
            sb.append(node.next != null ? ", ": "");
            node = node.next;
        }

        sb.append("]");

        return sb.toString();
    }
}

class Main {
    public static void main(String[] args) {
        Dequeue deque = new Dequeue();

        deque.pushBack(5);
        deque.pushBack(10);
        System.out.println(deque);

        deque.pushBack(0);
        deque.popFront();
        System.out.println(deque);

        int valFront = deque.front();
        int valBack = deque.back();

        System.out.println("Front: " + valFront + ", back: " + valBack);
        deque.popBack();
        deque.popBack();

        System.out.println("Dequeue is " + (deque.isEmpty() ? "Empty" : "Not Empty"));
    }
}