import java.util.*;

public class LinearSearch {
    public static void main (String[] args) {
        Scanner sc = new Scanner(System.in);
        int n, x, q;
        System.out.print("Enter size of array: ");
        n = sc.nextInt();
        int arr[] = new int[n];
        System.out.print("Enter array elements space separated: ");
        for(int i = 0; i < n; ++i) {
            arr[i] = sc.nextInt();
        }
        
        System.out.print("Enter number of queries you want: ");
        q = sc.nextInt();
        for(int i = 0; i < q; ++i) {
            System.out.print("Enter a number to search in array: ");
            x = sc.nextInt();
            if(linearSearch(arr, x, n)) {
                System.out.print(x + " is present in the array.\n");
            }else {
                System.out.print(x + " is not present in the array.\n");
            }
        }
    }
    
	public static boolean linearSearch(int arr[], int x, int n) {
        for(int i = 0; i < n; ++i) {
            if(arr[i] == x) {
                return true;
            }
        }
        return false;
	}
}
