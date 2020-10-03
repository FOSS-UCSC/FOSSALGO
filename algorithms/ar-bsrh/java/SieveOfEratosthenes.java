import java.util.*;

public class SieveOfEratosthenes {
	public static void main(String[] a) {
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter number upto which to check prime numbers: ");
		int n = sc.nextInt();
		System.out.print("Prime numbers upto " + n + " are: ");
		sieveOfEratosthenes(n);
		System.out.println();
		sc.close();
	}
	
	// Create a bool array "prime[0..n]" and initialize all entries to be true.
	// Avalue in prime[i] will be false if ith is Not a prime.
	//providing output as final prime number upto n.
	public static void sieveOfEratosthenes(int n) {
	    boolean primes[] = new boolean[n+1];
		for(int i = 0; i < n + 1; ++i) {
			primes[i] = true;
		}

	    for (int p=2; p*p<=n; p++) {
		    if (primes[p] == true) {
			    for (int i=p*p; i<=n; i += p) {
				    primes[i] = false;
	            }
		    }
	    }

	    for (int p=2; p<=n; p++) {
		    if (primes[p]) {
				System.out.print(p + " ");
	        }
		}
	}
}
