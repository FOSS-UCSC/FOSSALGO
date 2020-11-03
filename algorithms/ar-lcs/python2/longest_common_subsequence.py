def LongestCommonSubsequence(A, B):
    row, col = len(A), len(B)
    # constructing the dp matrix intialized with zeros
    dp = []
    for _ in range(row + 1):
        dp.append([0] * (col + 1))

    for i in range(1, row + 1):
        for j in range(1, col + 1):
            if A[i - 1] == B[j - 1]:
                dp[i][j] = dp[i - 1][j - 1] + 1
            else:
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])
    return dp[row][col]

# testing section
if __name__ == "__main__":
    A = "AGGTAB"
    B = "GXTXAYB"
    print "Length of LCS is " + str(LongestCommonSubsequence(A, B))
