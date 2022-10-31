#include <iostream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <math.h>
using namespace std;

int lcs(int m, int n, string s1, string s2)
{
    int dp[n + 1][m + 1];

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
            else
            {
                if (s1[i - 1] == s2[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            } 
        }
    }
    return dp[n][m];
}

int main()
{
    string s1, s2;
    int k = 0;
    cin >> s1;
    cin >> s2;

    int n = s1.length();
    int m = s2.length();
    int dp[n + 1][m + 1];


    cout << lcs(m, n, s1, s2);
  
    lcs(m, n, s1, s2);
    for (int i = 0; i < m; i++)
    {
        cout << "\n";
        for (int j = 0; j < n; j++)
        {
            cout << dp[j][i];
        }
    }

    
    return 0;
}
