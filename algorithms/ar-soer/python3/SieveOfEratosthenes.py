# Python3 Program to find Primes less than or equal to N

def sieve(N: int) -> list:
    is_prime = [False] * (N + 1)

    for i in range(3, N + 1, 2):
        is_prime[i] = True

    for i in range(3, int(N ** 0.5) + 1, 2):
        if is_prime[i]:
            for j in range(i * i, N + 1, i):
                is_prime[j] = False

    is_prime[2] = True

    return is_prime


if __name__ == '__main__':
    N = 100
    is_prime = sieve(N)

    print("Primes less than or equal to", N, "are listed below.")

    print(*[i for i in range(N) if is_prime[i]])