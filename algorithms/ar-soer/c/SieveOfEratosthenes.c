#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

bool* sieve(const int N) {

    // Returns a boolean array, is_prime, of size (N + 1) where
    // is_prime[i] = true if i is prime else false

    bool *is_prime = (bool *)malloc((N + 1) * sizeof(bool));

    for (int i = 0; i <= N; i++) {
        is_prime[i] = false;
    }

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
    int N = 100;
    bool *is_prime = sieve(N);

    printf("Primes less than or equal to %d are listed below.\n", N);

    for (int i = 0; i <= N; i++) {
        if (is_prime[i]) {
            printf("%d ", i);
        }
    }

    printf("\n");

    return 0;
}