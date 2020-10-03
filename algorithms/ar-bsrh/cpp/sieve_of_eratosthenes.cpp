//this program is for prime number using sieveOfEratosthenes algorithm
//Time Complexity: linear
//Space complexity: O(√n)

#include <iostream>
using namespace std;

// Create a bool array "prime[0..n]" and initialize all entries to be true.
// Avalue in prime[i] will be false if ith is Not a prime.
//providing output as final prime number upto n.
void sieveOfEratosthenes(int n) {
    bool primes[n+1];
    memset(primes, true, sizeof(primes));

    for (int p=2; p*p<=n; p++) {
        if (primes[p] == true) {
            for (int i=p*p; i<=n; i += p) {
                primes[i] = false;
            }
        }
    }
    
    for (int p=2; p<=n; p++) {
        if (primes[p]) {
            cout << p << " ";
        }
    }
}
 
int main() {
    int n;
    cout << "Enter number upto which to check prime numbers: ";
    cin >> n;
    cout << "Prime numbers upto " << n << " are: ";
    sieveOfEratosthenes(n);
    return 0;
}