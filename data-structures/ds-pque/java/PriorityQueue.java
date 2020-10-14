import java.util.ArrayList;

public class PriorityQueue {
    public static class PriorityQueue {
        ArrayList<Integer> data;

        public PriorityQueue() {
            data = new ArrayList<>();
        }

        //Add Element In PriorityQueue
        public void add(int val) {
            data.add(val);
            upheapify(data.size() - 1);
        }

        private void upheapify(int i) {
            if (i == 0) {
                return;
            }

            int pi = (i - 1) / 2;
            if (data.get(i) < data.get(pi)) {
                swap(i, pi);
                upheapify(pi);
            }
        }

        private void swap(int i, int j) {
            int ith = data.get(i);
            int jth = data.get(j);
            data.set(i, jth);
            data.set(j, ith);
        }


        //Remove Element In PriorityQueue
        public int remove() {
            if (this.size() == 0) {
                System.out.println("Underflow");
                return -1;
            }
            swap(0, data.size() - 1);
            int val = data.remove(data.size() - 1);
            downheapify(0);
            return val;
        }

        private void downheapify(int pi) {
            int min = pi;
            int li = 2 * pi + 1;
            if (li < data.size() && data.get(li) < data.get(min)) {
                min = li;
            }
            int ri = 2 * pi + 2;
            if (ri < data.size() && data.get(ri) < data.get(min)) {
                min = ri;
            }
            if (min != pi) {
                swap(pi, min);
                downheapify(min);
            }

        }

        public int peek() {
            if (this.size() == 0) {
                System.out.println("Underflow");
                return -1;
            }
            return data.get(0);
        }

        public int size() {
            return data.size();
        }
    }
    
    public static void main(String args[]) {
        PriorityQueue pq = new PriorityQueue();
         pq.add(1);
         pq.add(2);
         pq.add(3);
         pq.add(4);
         pq.add(5);
       
        pq.remove();
        
        System.out.print(pq.peek());
        System.out.print(pq.size());
    }
}
