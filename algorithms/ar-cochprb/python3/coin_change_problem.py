#python3 program for coin change problem using dynamic programming approach
def coin_change(S, m, n):
    solution = [0 for k in range(n+1)]
    solution[0] = 1

    for i in range(0,m):
        for j in range(S[i],n+1):
              solution[j] = solution[j] + solution[j-S[i]]

    return solution[n]

#driver code
S = [1, 2, 3]
m = len(S)
n = 4
print(coin_change(S, m, n))

