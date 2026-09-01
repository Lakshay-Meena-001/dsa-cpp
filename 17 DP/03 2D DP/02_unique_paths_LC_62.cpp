#include <bits/stdc++.h>
using namespace std;

int solveRec(int row, int col)
{   
    // rec  m last col se jaate jaate  up left karet hue 0 par aa gye to matlab mil gaya path
    if (row == 0 && col == 0)
    {
        return 1;
    }

    if (row < 0 || col < 0)
    {
        return 0;
    }

    int up = solveRec(row - 1, col);
    int left = solveRec(row, col - 1);

    return up + left;
}

int uniquePathsRec(int m, int n)
{
    return solveRec(m - 1, n - 1);
}

// Memoization

int solveMemo(int row, int col, vector<vector<int>> &dp)
{
    if (row == 0 && col == 0)
    {
        return 1;
    }

    if (row < 0 || col < 0)
    {
        return 0;
    }

    if (dp[row][col] != -1)
    {
        return dp[row][col];
    }

    int up = solveMemo(row - 1, col, dp);
    int left = solveMemo(row, col - 1, dp);

    return dp[row][col] = up + left;
}

int uniquePathsMemo(int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return solveMemo(m - 1, n - 1, dp);
}

// tabulation

int uniquePathsTab(int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n, 0));
    // imp baat hum stat ebharte hai hum answer nahi bharte 
    dp[0][0] = 1;

    for (int row = 0; row < m; row++)
    {
        for (int col = 0; col < n; col++)
        {
            if (row == 0 && col == 0)
            {
                dp[row][col] = 1;
                continue;
            }

            int up = 0;
            int left = 0;

            if (row > 0)
            {
                up = dp[row - 1][col];
            }
            if (col > 0)
            {
                left = dp[row][col - 1];
            }

            dp[row][col] = up + left;
        }
    }
    return dp[m - 1][n - 1];
}

// space optimization

int uniquePathSpace(int m, int n)
{
    vector<int> prev(n, 0);

    for (int row = 0; row < m; row++)
    {
        vector<int> curr(n, 0);

        for (int col = 0; col < n; col++)
        {
            if (row == 0 && col == 0)
            {
                curr[col] = 1;
                continue;
            }

            int up = 0;
            int left = 0;

            if (row > 0)
            {
                up = prev[col];
            }

            if (col > 0)
            {
                left = curr[col - 1];
            }

            curr[col] = up + left;
        }

        prev = curr;
    }
    
    return prev[n - 1];
}

int main()
{
    int m = 3;
    int n = 7;

    cout << "Recursion          : "
         << uniquePathsRec(m, n)
         << "\n";

    cout << "Memoization        : "
         << uniquePathsMemo(m, n)
         << "\n";

    cout << "Tabulation         : "
         << uniquePathsTab(m, n)
         << "\n";

    cout << "Space Optimization : "
         << uniquePathSpace(m, n)
         << "\n";

    return 0;
}