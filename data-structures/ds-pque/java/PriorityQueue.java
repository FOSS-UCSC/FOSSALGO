import java.util.Collections;
import java.util.PriorityQueue;

public class Main {

    public static void main(String[] args) {
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        int[] ranks = {22,99,11,88,3,4,1};

      //Adding Values
        for(int val : ranks){
            pq.add(val);
        }

        //Showing the peek values
        while (pq.size()>0){
            System.out.print(pq.peek()+" ");
            
            //Removing Values
            pq.remove();
        }
        System.out.println();
        
        //For reversing the Priority Queue
        //PriorityQueue<Integer> pqReverse = new PriorityQueue<>(Collections.reverseOrder());
        
    }
}
