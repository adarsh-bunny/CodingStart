#include <bits/stdc++.h>

using namespace std;

int maxBlessing(string s1, string s2, int k, int ***dp)
{
    if (k == 0)
        return 0;

    if (k > s1.length() || k > s2.length())
    {
        return 0;
    }

    int n = s1.length();
    int m = s2.length();
    if (dp[n][m][k] >= 0)
    {
        return dp[n][m][k];
    }

    int ans = -1;
    if (s1[0] == s2[0])
    {
        int ascii_value = s1[0];
        int option1 = ascii_value+ maxBlessing(s1.substr(1), s2.substr(1), k - 1, dp);
       if (option1 - ascii_value == 0 && k > 1)
       {
           option1 = 0;
       }

        int option2 = maxBlessing(s1.substr(1), s2, k, dp);
        int option3 = maxBlessing(s1, s2.substr(1), k, dp);
        ans = max(option1, max(option2, option3));
    }
    else 
    {
        int option1 = maxBlessing(s1.substr(1), s2, k, dp);
        int option2 = maxBlessing(s1, s2.substr(1), k, dp);
        ans = max(option1, option2);
    }

    dp[m][n][k] = ans;

    return ans;
}

int main()
{
    string s1, s2;
    int k;
    cin >> s1 >> s2 >> k;
    // making dp 3d array of length 101 
    int ***dp = new int **[101];

    for (int i = 0; i < 101; i++)
    {
        dp[i] = new int *[101];
        for (int j = 0; j < 101; j++)
        {
            dp[i][j] = new int[101];
            for (int k = 0; k < 101; k++)
            {
                dp[i][j][k] = -1;
            }
        }
    }
    cout << "DP method " << maxBlessing(s1, s2, k, dp) << endl;

    for (int i = 0; i < 101; i++)
    {
        for (int j = 0; j < 101; j++)
        {
            delete[] dp[i][j];
        }
        delete[] dp[i];
    }
    delete[] dp;
}