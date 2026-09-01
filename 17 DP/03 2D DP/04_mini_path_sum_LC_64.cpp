#include <bits/stdc++.h>

using namespace std;

int solveRec(int row, int col, vector<vector<int>> &grid)
{
    if (row == 0 && col == 0)
    {
        return grid[0][0];
    }

    if (row < 0 || col < 0)
    {
        // yaha ways nahi piche gay ehai nahi to return 0 karte yaha cost puchi gyi hai invald path se infinite cost
        return 1e9;
    }

    int up = grid[row][col] + solveRec(row - 1, col, grid);
    int left = grid[row][col] + solveRec(row, col - 1, grid);

    return min(up, left);
}

int minPathSumRec(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();

    return solveRec(m - 1, n - 1, grid);
}

// memoization

int solveMemo(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &dp)
{
    if (row == 0 && col == 0)
    {
        return grid[0][0];
    }

    if (row < 0 || col < 0)
    {
        return 1e9;
    }

    if (dp[row][col] != -1)
    {
        return dp[row][col];
    }

    int up = grid[row][col] + solveMemo(row - 1, col, grid, dp);
    int left = grid[row][col] + solveMemo(row, col - 1, grid, dp);

    return dp[row][col] = min(up, left);
}

int minPathSumMemo(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();

    vector<vector<int>> dp(n, vector<int>(n, -1));

    return solveMemo(m - 1, n - 1, grid, dp);
}

// tabulation

int minPathSumTab(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();

    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int row = 0; row < m; row++)
    {
        for (int col = 0; col < n; col++)
        {
            if (row == 0 && col == 0)
            {
                dp[row][col] = grid[0][0];
                continue;
            }

            int up = 1e9;
            int left = 1e9;

            if (row > 0)
            {
                up = grid[row][col] + dp[row - 1][col];
            }

            if (col > 0)
            {
                left = grid[row][col] + dp[row][col - 1];
            }

            dp[row][col] = min(up, left);
        }
    }

    return dp[m - 1][n - 1];
}

int minPathSumSpace(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();

    vector<int> prev(n, 0);

    for (int row = 0; row < m; row++)
    {
        vector<int> curr(n, 0);

        for (int col = 0; col < n; col++)
        {
            if (row == 0 && col == 0)
            {
                curr[col] = grid[0][0];
                continue;
            }

            int up = 1e9;
            int left = 1e9;

            if (row > 0)
            {
                up = grid[row][col] + prev[col];
            }

            if (col > 0)
            {
                left = grid[row][col] + curr[col - 1];
            }

            curr[col] = min(up, left);
        }

        prev = curr;
    }

    return prev[n - 1];
}

int main()
{
    vector<vector<int>> grid =
        {
            {1, 3, 1},
            {1, 5, 1},
            {4, 2, 1}};

    cout << "Recursion          : "
         << minPathSumRec(grid)
         << "\n";

    cout << "Memoization        : "
         << minPathSumMemo(grid)
         << "\n";

    cout << "Tabulation         : "
         << minPathSumTab(grid)
         << "\n";

    cout << "Space Optimization : "
         << minPathSumSpace(grid)
         << "\n";

    return 0;
}