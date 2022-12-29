#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

static inline int max(const int a, const int b) {
    return a > b ? a : b;
}

int longest_common_subsequence(const char* s1, const char* s2, int m, int n) {

    int** dp = (int**) malloc(sizeof(int*) * (m + 1));
    for (int i = 0; i <= m; i++) {
        dp[i] = (int*) malloc(sizeof(int) * (n + 1));
    }

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            }
            else if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[m][n];
}

int main() {

    int m = 0, n = 0;

    printf("Enter length of String 1: ");
    scanf("%d", &m);

    printf("Enter length of String 2: ");
    scanf("%d", &n);

    char *s1 = malloc(m + 1);
    char *s2 = malloc(n + 1);

    printf("Enter string 1: ");
    scanf("%s", s1);
    printf("Enter string 2: ");
    scanf("%s", s2);

    int lcs_length = longest_common_subsequence(s1, s2, m, n);

    printf("Length of Longest common subsequence is: %d\n", lcs_length);

    return 0;
}