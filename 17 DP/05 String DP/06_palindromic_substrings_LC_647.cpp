#include <bits/stdc++.h>
using namespace std;

// =====================================================
// RECURSION
// =====================================================

// Not Recommended

// =====================================================
// MEMOIZATION
// =====================================================

// Not Recommended

// =====================================================
// TABULATION
// =====================================================

int countSubstringsTab(string s)
{
    int n = s.size();

    vector<vector<bool>> dp(n, vector<bool>(n, false));

    int count = 0;

    // ==========================
    // Length = 1
    // ==========================

    for (int i = 0; i < n; i++)
    {
        dp[i][i] = true;
        count++;
    }

    // ==========================
    // Length = 2
    // ==========================

    for (int i = 0; i < n - 1; i++)
    {
        if (s[i] == s[i + 1])
        {
            dp[i][i + 1] = true;
            count++;
        }
    }

    // ==========================
    // Length >= 3
    // ==========================

    for (int length = 3; length <= n; length++)
    {
        for (int start = 0; start + length - 1 < n; start++)
        {
            int end = start + length - 1;

            if (s[start] == s[end] && dp[start + 1][end - 1])
            {
                dp[start][end] = true;
                count++;
            }
        }
    }

    return count;
}

// =====================================================
// SPACE OPTIMIZATION
// =====================================================

// Not Possible

// =====================================================
// DRIVER CODE
// =====================================================

int main()
{
    string s = "aaa";

    cout << "Palindromic Substrings : "
         << countSubstringsTab(s)
         << endl;

    return 0;
}