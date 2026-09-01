#include <bits/stdc++.h>
using namespace std;

// =====================================================
// RECURSION
// =====================================================

// index1 -> Current Index of string
// index2 -> Current Index of reversed string

int solveRec(int index1,
             int index2,
             string &text,
             string &revText)
{
    // Base Case
    if (index1 < 0 || index2 < 0)
    {
        return 0;
    }

    // Characters Match
    if (text[index1] == revText[index2])
    {
        return 1 +
               solveRec(index1 - 1,
                        index2 - 1,
                        text,
                        revText);
    }

    // Characters Don't Match
    int skipText =
        solveRec(index1 - 1,
                 index2,
                 text,
                 revText);

    int skipRevText =
        solveRec(index1,
                 index2 - 1,
                 text,
                 revText);

    return max(skipText,
               skipRevText);
}

int minInsertionsRec(string s)
{
    string rev = s;

    reverse(rev.begin(),
            rev.end());

    int lps =
        solveRec(s.size() - 1,
                 rev.size() - 1,
                 s,
                 rev);

    return s.size() - lps;
}

// =====================================================
// MEMOIZATION
// =====================================================

int solveMemo(int index1,
              int index2,
              string &text,
              string &revText,
              vector<vector<int>> &dp)
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
        return dp[index1][index2] =
            1 +
            solveMemo(index1 - 1,
                      index2 - 1,
                      text,
                      revText,
                      dp);
    }

    int skipText =
        solveMemo(index1 - 1,
                  index2,
                  text,
                  revText,
                  dp);

    int skipRevText =
        solveMemo(index1,
                  index2 - 1,
                  text,
                  revText,
                  dp);

    return dp[index1][index2] =
        max(skipText,
            skipRevText);
}

int minInsertionsMemo(string s)
{
    string rev = s;

    reverse(rev.begin(),
            rev.end());

    int n = s.size();

    vector<vector<int>> dp(
        n,
        vector<int>(n, -1));

    int lps =
        solveMemo(n - 1,
                  n - 1,
                  s,
                  rev,
                  dp);

    return n - lps;
}

// =====================================================
// TABULATION
// =====================================================

int minInsertionsTab(string s)
{
    string rev = s;

    reverse(rev.begin(),
            rev.end());

    int n = s.size();

    vector<vector<int>> dp(
        n + 1,
        vector<int>(n + 1, 0));

    for (int index1 = 1;
         index1 <= n;
         index1++)
    {
        for (int index2 = 1;
             index2 <= n;
             index2++)
        {
            if (s[index1 - 1] ==
                rev[index2 - 1])
            {
                dp[index1][index2] =
                    1 +
                    dp[index1 - 1]
                      [index2 - 1];
            }
            else
            {
                dp[index1][index2] =
                    max(dp[index1 - 1][index2],
                        dp[index1][index2 - 1]);
            }
        }
    }

    int lps = dp[n][n];

    return n - lps;
}

// =====================================================
// SPACE OPTIMIZATION
// =====================================================

int minInsertionsSpace(string s)
{
    string rev = s;

    reverse(rev.begin(),
            rev.end());

    int n = s.size();

    vector<int> prev(n + 1, 0);

    for (int index1 = 1;
         index1 <= n;
         index1++)
    {
        vector<int> curr(n + 1, 0);

        for (int index2 = 1;
             index2 <= n;
             index2++)
        {
            if (s[index1 - 1] ==
                rev[index2 - 1])
            {
                curr[index2] =
                    1 +
                    prev[index2 - 1];
            }
            else
            {
                curr[index2] =
                    max(prev[index2],
                        curr[index2 - 1]);
            }
        }

        prev = curr;
    }

    int lps = prev[n];

    return n - lps;
}

// =====================================================
// DRIVER CODE
// =====================================================

int main()
{
    string s = "mbadm";

    cout << "Recursion : "
         << minInsertionsRec(s)
         << endl;

    cout << "Memoization : "
         << minInsertionsMemo(s)
         << endl;

    cout << "Tabulation : "
         << minInsertionsTab(s)
         << endl;

    cout << "Space Optimization : "
         << minInsertionsSpace(s)
         << endl;

    return 0;
}