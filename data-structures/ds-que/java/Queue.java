public class Queue {
    private final static int N = 20;

    private static int queue[] = new int[N];
    private static int front = -1;
    private static int rear = -1;

    public static void enqueue(int val) {
        if (rear == N - 1) {
            System.out.println("Overflow");
        } else {
            if (front == -1 && rear == -1) {
                front = rear = 0;
                queue[rear] = val;
            } else {
                queue[++rear] = val;
            }
        }
    }

    public static int dequeue() {
        int val;
        if (front == -1 || front > rear) {
            System.out.println("Underflow");
            return -1;
        } else {
            val = queue[front++];
            if (front > rear) {
                front = rear = -1;
            }
            return val;
        }
    }

    public static void print() {
        int i;
        if (front == -1 || front > rear) {
            System.out.println("Queue is empty");
            return;
        }
        for (i = front; i <= rear; i++) {
            System.out.print(queue[i] + " ");
        }
        System.out.print("\n");
    }

    public static void main(String args[]) {
        enqueue(11);
        print();
        enqueue(22);
        print();
        enqueue(33);
        print();
        dequeue();
        print();
        dequeue();
        print();
        enqueue(44);
        print();
    }
}
