public class PriorityQueue {
    static class Node {
        int data;
        int priority;
        Node next;

    }

    static Node node = new Node();

    static Node newNode(int d, int p) {
        Node temp = new Node();
        temp.data = d;
        temp.priority = p;
        temp.next = null;

        return temp;
    }

    static int peek(Node head) {
        return (head).data;
    }

    // Remove the element
    static Node pop(Node head) {
        Node temp = head;
        (head) = (head).next;
        return head;
    }

    // Add elements according to priority
    static Node add(Node head, int d, int p) {
        Node start = (head);
        Node temp = newNode(d, p);
        if ((head).priority > p) {
            temp.next = head;
            (head) = temp;
        } else {
            while (start.next != null && start.next.priority < p) {
                start = start.next;
            }
            temp.next = start.next;
            start.next = temp;
        }
        return head;
    }

    // Check if list is empty
    static int isEmpty(Node head) {
        return ((head) == null) ? 1 : 0;
    }

    public static void main(String args[]) {
        Node pq = newNode(1, 3);
        pq = add(pq, 2, 1);
        pq = add(pq, 3, 2);
        pq = add(pq, 4, 0);

        while (isEmpty(pq) == 0) {
            System.out.printf("%d ", peek(pq));
            pq = pop(pq);
        }
    }

}
