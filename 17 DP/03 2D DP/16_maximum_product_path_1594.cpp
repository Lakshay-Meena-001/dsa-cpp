#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;

// =====================================================
// RECURSION
// =====================================================

pair<long long, long long>
solveRec(int row, int col, vector<vector<int>> &grid)
{
    // Start cell

    if (row == 0 && col == 0)
    {
        return {grid[0][0], grid[0][0]};
    }

    long long maxi = LLONG_MIN;
    long long mini = LLONG_MAX;

    // Upar se aa sakte hain

    if (row > 0)
    {
        auto up = solveRec(row - 1, col, grid);

        long long val = grid[row][col];

        maxi = max(maxi, max(up.first * val, up.second * val));

        mini = min(mini, min(up.first * val, up.second * val));
    }

    // Left se aa sakte hain

    if (col > 0)
    {
        auto left = solveRec(row, col - 1, grid);

        long long val = grid[row][col];

        maxi = max(maxi, max(left.first * val, left.second * val));

        mini = min(mini, min(left.first * val, left.second * val));
    }

    return {maxi, mini};
}

int maxProductPathRec(vector<vector<int>> &grid)
{
    int rows = grid.size();
    int cols = grid[0].size();

    auto ans = solveRec(rows - 1, cols - 1, grid);

    if (ans.first < 0)
    {
        return -1;
    }

    return ans.first % MOD;
}

// =====================================================
// MEMOIZATION
// =====================================================

pair<long long, long long> solveMemo(int row, int col, vector<vector<int>> &grid, vector<vector<pair<long long, long long>>> &dp, vector<vector<int>> &vis)
{
    if (row == 0 && col == 0)
    {
        return {grid[0][0], grid[0][0]};
    }
    /*
    if(dp[row][col].first != LLONG_MIN)
    return dp[row][col];
    */

    if (vis[row][col])
    {
        return dp[row][col];
    }

    vis[row][col] = 1;

    long long maxi = LLONG_MIN;
    long long mini = LLONG_MAX;

    if (row > 0)
    {
        auto up = solveMemo(row - 1, col, grid, dp, vis);

        long long val = grid[row][col];

        maxi = max(maxi, max(up.first * val, up.second * val));

        mini = min(mini, min(up.first * val, up.second * val));
    }

    if (col > 0)
    {
        auto left = solveMemo(row, col - 1, grid, dp, vis);

        long long val = grid[row][col];

        maxi = max(maxi, max(left.first * val, left.second * val));

        mini = min(mini, min(left.first * val, left.second * val));
    }

    return dp[row][col] = {maxi, mini};
}

int maxProductPath(vector<vector<int>> &grid)
{
    int rows = grid.size();
    int cols = grid[0].size();

    vector<vector<pair<long long, long long>>> dp(
        rows, vector<pair<long long, long long>>(cols));

    vector<vector<int>> vis(rows, vector<int>(cols, 0));
    /*
    // ye bhi use kar skte hai
    vector<vector<pair<long long,long long>>> dp(
    m,
    vector<pair<long long,long long>>(n, {LLONG_MIN, LLONG_MAX})
);
    */

    auto ans = solveMemo(rows - 1, cols - 1, grid, dp, vis);

    if (ans.first < 0)
        return -1;

    return (int)(ans.first % MOD);
}
// =====================================================
// TABULATION
// =====================================================

int maxProductPathTab(
    vector<vector<int>> &grid)
{
    int rows = grid.size();
    int cols = grid[0].size();

    vector<vector<long long>> maxDP(rows, vector<long long>(cols, 0));

    vector<vector<long long>> minDP(rows, vector<long long>(cols, 0));

    maxDP[0][0] = grid[0][0];

    minDP[0][0] = grid[0][0];

    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {
            if (row == 0 && col == 0)
            {
                continue;
            }

            long long maxi = LLONG_MIN;

            long long mini = LLONG_MAX;

            if (row > 0)
            {
                long long val = grid[row][col];

                maxi = max(maxi, max(maxDP[row - 1][col] * val, minDP[row - 1][col] * val));

                mini = min(mini, min(maxDP[row - 1][col] * val, minDP[row - 1][col] * val));
            }

            if (col > 0)
            {
                long long val = grid[row][col];

                maxi = max(maxi, max(maxDP[row][col - 1] * val, minDP[row][col - 1] * val));

                mini = min(mini, min(maxDP[row][col - 1] * val, minDP[row][col - 1] * val));
            }

            maxDP[row][col] = maxi;
            minDP[row][col] = mini;
        }
    }

    long long ans = maxDP[rows - 1][cols - 1];

    if (ans < 0)
    {
        return -1;
    }

    return ans % MOD;
}