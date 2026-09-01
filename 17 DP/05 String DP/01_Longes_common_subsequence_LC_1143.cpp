#include <bits/stdc++.h>
using namespace std;

// =====================================================
// RECURSION
// =====================================================

// index1 -> Current Index of text1
// index2 -> Current Index of text2

int solveRec(int index1, int index2, string &text1, string &text2)
{
    // Base Case
    if (index1 < 0 || index2 < 0)
    {
        return 0;
    }

    // Characters Match
    if (text1[index1] == text2[index2])
    {
        return 1 + solveRec(index1 - 1, index2 - 1, text1, text2);
    }

    // Characters Don't Match

    int skipText1 = solveRec(index1 - 1, index2, text1, text2);

    int skipText2 = solveRec(index1, index2 - 1, text1, text2);

    return max(skipText1, skipText2);
}

int longestCommonSubsequenceRec(string text1, string text2)
{
    int n = text1.size();
    int m = text2.size();

    return solveRec(n - 1, m - 1, text1, text2);
}

// =====================================================
// MEMOIZATION
// =====================================================

int solveMemo(int index1, int index2, string &text1, string &text2, vector<vector<int>> &dp)
{
    if (index1 < 0 || index2 < 0)
    {
        return 0;
    }

    if (dp[index1][index2] != -1)
    {
        return dp[index1][index2];
    }

    if (text1[index1] == text2[index2])
    {
        return dp[index1][index2] = 1 + solveMemo(index1 - 1, index2 - 1, text1, text2, dp);
    }

    int skipText1 = solveMemo(index1 - 1, index2, text1, text2, dp);

    int skipText2 = solveMemo(index1, index2 - 1, text1, text2, dp);

    return dp[index1][index2] = max(skipText1, skipText2);
}

int longestCommonSubsequenceMemo(string text1, string text2)
{
    int n = text1.size();
    int m = text2.size();

    vector<vector<int>> dp(n, vector<int>(m, -1));

    return solveMemo(n - 1, m - 1, text1, text2, dp);
}
// =====================================================
// TABULATION
// =====================================================

int longestCommonSubsequenceTab(string text1, string text2)
{
    int n = text1.size();
    int m = text2.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // Base Case
    // First row and first column are already 0

    // Build DP Table
    for (int index1 = 1; index1 <= n; index1++)
    {
        for (int index2 = 1; index2 <= m; index2++)
        {
            // Characters Match
            if (text1[index1 - 1] == text2[index2 - 1])
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

    return dp[n][m];
}

// =====================================================
// SPACE OPTIMIZATION
// =====================================================

int longestCommonSubsequenceSpace(string text1, string text2)
{
    int n = text1.size();
    int m = text2.size();

    vector<int> prev(m + 1, 0);

    for (int index1 = 1; index1 <= n; index1++)
    {
        vector<int> curr(m + 1, 0);

        for (int index2 = 1; index2 <= m; index2++)
        {
            // Characters Match
            if (text1[index1 - 1] == text2[index2 - 1])
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

    return prev[m];
}

// =====================================================
// DRIVER CODE
// =====================================================

int main()
{
    string text1 = "abcde";
    string text2 = "ace";

    cout << "Recursion : "
         << longestCommonSubsequenceRec(text1,
                                        text2)
         << endl;

    cout << "Memoization : "
         << longestCommonSubsequenceMemo(text1,
                                         text2)
         << endl;

    cout << "Tabulation : "
         << longestCommonSubsequenceTab(text1,
                                        text2)
         << endl;

    cout << "Space Optimization : "
         << longestCommonSubsequenceSpace(text1,
                                          text2)
         << endl;

    return 0;
}