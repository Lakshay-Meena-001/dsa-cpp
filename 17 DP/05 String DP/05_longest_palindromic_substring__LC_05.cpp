#include <bits/stdc++.h>
using namespace std;

// =====================================================
// RECURSION
// =====================================================

// NOTE:
// Pure recursion is not practical for this problem because
// checking palindrome repeatedly leads to exponential complexity.
// Hence, recursion and memoization are generally skipped.

// =====================================================
// MEMOIZATION
// =====================================================

// Not Recommended

// =====================================================
// TABULATION
// =====================================================

string longestPalindromeTab(string s)
{
    int n = s.size();

    vector<vector<bool>> dp(n, vector<bool>(n, false));

    int start = 0;
    int maxLength = 1;

    // Length = 1
    for (int i = 0; i < n; i++)
    {
        dp[i][i] = true;
    }

    // Length = 2
    for (int i = 0; i < n - 1; i++)
    {
        if (s[i] == s[i + 1])
        {
            dp[i][i + 1] = true;
            start = i;
            maxLength = 2;
        }
    }

    // Length >= 3
    for (int length = 3; length <= n; length++)
    {
        for (int startIndex = 0; startIndex + length - 1 < n; startIndex++)
        {
            int endIndex = startIndex + length - 1;

            if (s[startIndex] == s[endIndex] && dp[startIndex + 1][endIndex - 1])
            {
                dp[startIndex][endIndex] = true;

                if (length > maxLength)
                {
                    maxLength = length;
                    start = startIndex;
                }
            }
        }
    }

    return s.substr(start, maxLength);
}

// =====================================================
// SPACE OPTIMIZATION
// =====================================================

// Not Possible
// DP depends on diagonal values.

// =====================================================
// DRIVER CODE
// =====================================================

int main()
{
    string s = "babad";

    cout << "Longest Palindromic Substring : "
         << longestPalindromeTab(s)
         << endl;

    return 0;
}