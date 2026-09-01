#include <bits/stdc++.h>
using namespace std;

// =====================================================
// RECURSION
// =====================================================

// index1 -> Current Index of string
// index2 -> Current Index of reversed string

int solveRec(int index1, int index2, string &text, string &revText)
{
    // Base Case
    if (index1 < 0 || index2 < 0)
    {
        return 0;
    }

    // Characters Match
    if (text[index1] == revText[index2])
    {
        return 1 + solveRec(index1 - 1, index2 - 1, text, revText);
    }

    // Characters Don't Match
    int skipText = solveRec(index1 - 1, index2, text, revText);

    int skipRevText = solveRec(index1, index2 - 1, text, revText);

    return max(skipText, skipRevText);
}

int longestPalindromeSubseqRec(string s)
{
    string rev = s;

    reverse(rev.begin(), rev.end());

    return solveRec(s.size() - 1, rev.size() - 1, s, rev);
}

// =====================================================
// MEMOIZATION
// =====================================================

int solveMemo(int index1, int index2, string &text, string &revText, vector<vector<int>> &dp)
{
    if (index1 < 0 || index2 < 0)
    {
        return 0;
    }

    if (dp[index1][index2] != -1)
    {
        return dp[index1][index2];
    }

    if (text[index1] == revText[index2])
    {
        return dp[index1][index2] = 1 + solveMemo(index1 - 1, index2 - 1, text, revText, dp);
    }

    int skipText = solveMemo(index1 - 1, index2, text, revText, dp);

    int skipRevText = solveMemo(index1, index2 - 1, text, revText, dp);

    return dp[index1][index2] = max(skipText, skipRevText);
}

int longestPalindromeSubseqMemo(string s)
{
    string rev = s;

    reverse(rev.begin(), rev.end());

    int n = s.size();

    vector<vector<int>> dp(n, vector<int>(n, -1));

    return solveMemo(n - 1, n - 1, s, rev, dp);
}

// =====================================================
// TABULATION
// =====================================================

int longestPalindromeSubseqTab(string s)
{
    string rev = s;

    reverse(rev.begin(), rev.end());

    int n = s.size();

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    // Base Case
    // First row and first column are already 0

    // Build DP Table
    for (int index1 = 1; index1 <= n; index1++)
    {
        for (int index2 = 1; index2 <= n; index2++)
        {
            // Characters Match
            if (s[index1 - 1] == rev[index2 - 1])
            {
                dp[index1][index2] = 1 + dp[index1 - 1][index2 - 1];
            }
            else
            {
                // Skip character from either string
                dp[index1][index2] = max(dp[index1 - 1][index2], dp[index1][index2 - 1]);
            }
        }
    }

    return dp[n][n];
}

// =====================================================
// SPACE OPTIMIZATION
// =====================================================

int longestPalindromeSubseqSpace(string s)
{
    string rev = s;

    reverse(rev.begin(), rev.end());

    int n = s.size();

    vector<int> prev(n + 1, 0);

    for (int index1 = 1; index1 <= n; index1++)
    {
        vector<int> curr(n + 1, 0);

        for (int index2 = 1; index2 <= n; index2++)
        {
            // Characters Match
            if (s[index1 - 1] == rev[index2 - 1])
            {
                curr[index2] = 1 + prev[index2 - 1];
            }
            else
            {
                // Skip character from either string
                curr[index2] = max(prev[index2], curr[index2 - 1]);
            }
        }

        prev = curr;
    }

    return prev[n];
}

// =====================================================
// DRIVER CODE
// =====================================================

int main()
{
    string s = "bbbab";

    cout << "Recursion : "
         << longestPalindromeSubseqRec(s)
         << endl;

    cout << "Memoization : "
         << longestPalindromeSubseqMemo(s)
         << endl;

    cout << "Tabulation : "
         << longestPalindromeSubseqTab(s)
         << endl;

    cout << "Space Optimization : "
         << longestPalindromeSubseqSpace(s)
         << endl;

    return 0;
}
