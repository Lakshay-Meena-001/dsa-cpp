#include <bits/stdc++.h>
using namespace std;

// =====================================================
// TABULATION
// =====================================================

string printLCS(string text1, string text2)
{
    int n = text1.size();
    int m = text2.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // Build DP Table
    for (int index1 = 1; index1 <= n; index1++)
    {
        for (int index2 = 1; index2 <= m; index2++)
        {
            if (text1[index1 - 1] == text2[index2 - 1])
            {
                dp[index1][index2] = 1 + dp[index1 - 1][index2 - 1];
            }
            else
            {
                dp[index1][index2] = max(dp[index1 - 1][index2], dp[index1][index2 - 1]);
            }
        }
    }

    // ==========================
    // Backtracking
    // ==========================

    string ans = "";

    int index1 = n;
    int index2 = m;

    while (index1 > 0 && index2 > 0)
    {
        // Character belongs to LCS
        if (text1[index1 - 1] == text2[index2 - 1])
        {
            ans.push_back(text1[index1 - 1]);

            index1--;
            index2--;
        }
        // Move towards larger value
        else if (dp[index1 - 1][index2] > dp[index1][index2 - 1])
        {
            index1--;
        }
        else
        {
            index2--;
        }
    }

    reverse(ans.begin(), ans.end());

    return ans;
}

// =====================================================
// DRIVER CODE
// =====================================================

int main()
{
    string text1 = "abcde";
    string text2 = "ace";

    cout << "Longest Common Subsequence : "
         << printLCS(text1,
                     text2)
         << endl;

    return 0;
}