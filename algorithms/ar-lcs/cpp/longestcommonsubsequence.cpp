#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

int lcs(int m, int n, const string& s1, const string& s2) {
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            }
            else if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            } 
        }
    }
    return dp[n][m];
}

int main() {
    string s1, s2;
    cin >> s1;
    cin >> s2;

    int m = s1.length();
    int n = s2.length();

    cout << lcs(m, n, s1, s2) << '\n';

    return 0;
}
