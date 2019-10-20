import java.util.*;

public class naive{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter The Text : ");        
        String T = sc.nextLine();

        System.out.print("Enter The Pattern : ");       
        String P = sc.nextLine();

        naive n = new naive();
        n.Naive(T, P);
        
    }

    public void Naive(String T, String P){
        
        int N = T.length();
        int M = P.length();

        for(int i=0; i<N-M; i++){
            int j = 0;
            for(j=0; j<M; j++){
                if(P.charAt(j) != T.charAt(i+j)){
                    break;
                }
            }

            if(j == M){
                System.out.print("Pattern Found At Index "+i);
            }
        }
    }
}