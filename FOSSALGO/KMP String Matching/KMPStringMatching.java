package kmpstringmatching;

import java.util.Scanner;
import java.util.Arrays;

/**
 *
 * @author Amith Liyanage
 */
public class KMPStringMatching {

    static void longestProperPrefix(String P, int m, int x[]) {
        int j = 0, i = 1;   //this i, j visible only this method
        x[0] = 0;
        while (i < m) {
            if (P.charAt(j) == P.charAt(i)) {
                j++;
                x[i] = j;
                i++;
            } else {  //P.charAt(j)!=P.charAt(i)
                if (j == 0) {
                    x[i] = j;
                    i++;
                } else {    //j!=0
                    j = x[j-1];
                }
            }
        }
        //System.out.println(Arrays.toString(x));
    }

    static void KMPSearch(String T, String P) {
        int n = T.length();
        int m = P.length();
        
        int x[] = new int[m];
        longestProperPrefix(P, m, x);   //find prefix and suffix in pattern(P)
        
        int i = 0, j = 0; //i is index of T, j is index of P
        while(i<n){
            if (P.charAt(j) == T.charAt(i)) {
                i++;
                j++;
            }if(j==m){
                System.out.println("Pattern found at index "+(i-m));
                j = x[j-1];
            }else if (i<n && P.charAt(j) != T.charAt(i)) {
                if (j == 0) {
                    i++;
                } else {    //j!=0
                    j = x[j-1];
                }
            }

        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter text    :");
        String text = sc.nextLine();
        System.out.println("Enter pattern :");
        String pattern = sc.nextLine();
        
        KMPSearch(text, pattern);
    }
}
