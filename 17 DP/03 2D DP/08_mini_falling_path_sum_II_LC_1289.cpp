#include <bits/stdc++.h>
using namespace std;

int solveRec(int row, int col, vector<vector<int>> &grid)
{
    int n = grid.size();

    // hum niche se oopr aa reh ahai to ans end hoga last row par means nice se oopr aat ehue last first row
    if (row == 0)
    {
        return grid[0][col];
    }

    int ans = INT_MAX;

    // prev row k saare col check karo or min dhundo
    for (int prevCol = 0; prevCol < n; prevCol++)
    {
        if (prevCol != col)
        {
            ans = min(ans, grid[row][col] + solveRec(row - 1, prevCol, grid));
        }
    }

    return ans;
}

int minFallingPathSumRec(vector<vector<int>> &grid)
{
    int n = grid.size();

    int ans = INT_MAX;

    // hum niche col se oopr jaa rehe hai last row se kyuki agar oor se niche aat eto kisi bhi col par khatam ho skta hai isliye

    for (int col = 0; col < n; col++)
    {
        ans = min(ans, solveRec(n - 1, col, grid));
    }

    return ans;
}

// memoization

int solveMemo(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &dp)
{
    int n = grid.size();

    if (row == 0)
    {
        return grid[0][col];
    }

    if (dp[row][col] != -1)
    {
        return dp[row][col];
    }

    int ans = INT_MAX;

    for (int prevCol = 0; prevCol < n; prevCol++)
    {
        if (prevCol != col)
        {
            ans = min(ans, grid[row][col] + solveMemo(row - 1, prevCol, grid, dp));
        }
    }

    return dp[row][col] = ans;
}

int minFallingPathSumMemo(
    vector<vector<int>> &grid)
{
    int n = grid.size();

    vector<vector<int>> dp(n, vector<int>(n, -1));

    int ans = INT_MAX;

    for (int col = 0; col < n; col++)
    {
        ans = min(ans, solveMemo(n - 1, col, grid, dp));
    }

    return ans;
}

// tabulation

int minFallingPathSumTab(vector<vector<int>> &grid)
{
    int n = grid.size();

    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int col = 0; col < n; col++)
    {
        dp[0][col] = grid[0][col];
    }

    for (int row = 1; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            dp[row][col] = INT_MAX;

            for (int prevCol = 0; prevCol < n; prevCol++)
            {
                if (prevCol != col)
                {
                    dp[row][col] = min(dp[row][col], grid[row][col] + dp[row - 1][prevCol]);
                }
            }
        }
    }

    int ans = INT_MAX;

    for (int col = 0; col < n; col++)
    {
        ans = min(ans, dp[n - 1][col]);
    }

    return ans;
}

// optimized

int minFallingPathSumOptimal(
    vector<vector<int>> &grid)
{
    int n = grid.size();

    vector<int> prev = grid[0];

    for (int row = 1; row < n; row++)
    {
        int min1 = INT_MAX;
        int min2 = INT_MAX;

        int minCol = -1;

        for (int col = 0; col < n; col++)
        {
            if (prev[col] < min1)
            {
                min2 = min1;
                min1 = prev[col];
                minCol = col;
            }
            else if (prev[col] < min2)
            {
                min2 = prev[col];
            }
        }

        vector<int> curr(n);

        for (int col = 0; col < n; col++)
        {
            if (col == minCol)
            {
                curr[col] = grid[row][col] + min2;
            }
            else
            {
                curr[col] = grid[row][col] + min1;
            }
        }

        prev = curr;
    }

    return *min_element(prev.begin(), prev.end());
}

/*
========================================================
DRIVER CODE
========================================================
*/

int main()
{
    vector<vector<int>> grid =
        {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}};

    cout << "Recursion      : "
         << minFallingPathSumRec(grid)
         << "\n";

    cout << "Memoization    : "
         << minFallingPathSumMemo(grid)
         << "\n";

    cout << "Tabulation     : "
         << minFallingPathSumTab(grid)
         << "\n";

    cout << "Optimized DP   : "
         << minFallingPathSumOptimal(grid)
         << "\n";

    return 0;
}
