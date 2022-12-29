#include <iostream>
#include <vector>
#include <bitset>
#include <string>
#include <set>

using namespace std;

vector<bool> sieve(const int N) {
    vector<bool> is_prime(N + 1);

    for (int i = 3; i <= N; i += 2) {
        is_prime[i] = true;
    }
    
    for (int i = 3; i * i <= N; i += 2) {
        if (is_prime[i]) {
            for (int j = i * i; j <= N; j += i) {
                is_prime[j] = false;
            }
        }
    }

    is_prime[2] = true;

    return is_prime;
}


int main() {

    const int N = 100;

    vector<bool> is_prime = sieve(N);

    cout << "Primes less than or equal to " << N << " are listed below" << '\n';

    for (int i = 0; i <= N; i++) {
        if (is_prime[i]) {
            cout << i << ' ';
        }
    }

    cout << '\n';

    return 0;
}