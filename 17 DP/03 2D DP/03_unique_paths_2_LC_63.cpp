#include <bits/stdc++.h>
using namespace std;

// recursion
int solveRec(int row, int col, vector<vector<int>> &obstacleGrid)
{
    if (row < 0 || col < 0)
    {
        return 0;
    }
    if (obstacleGrid[row][col] == 1)
    {
        return 0;
    }

    if (row == 0 && col == 0)
    {
        return 1;
    }

    int up = solveRec(row - 1, col, obstacleGrid);
    int left = solveRec(row, col - 1, obstacleGrid);

    return up + left;
}

int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
{
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();

    return solveRec(m - 1, n - 1, obstacleGrid);
}

// memo
int solveMemo(int row, int col,
              vector<vector<int>> &obstacleGrid,
              vector<vector<int>> &dp)
{

    if (row < 0 || col < 0)
    {
        return 0;
    }

    if (obstacleGrid[row][col] == 1)
    {
        return 0;
    }

    if (row == 0 && col == 0)
    {
        return 1;
    }

    if (dp[row][col] != -1)
    {
        return dp[row][col];
    }

    int up = solveMemo(row - 1, col, obstacleGrid, dp);
    int left = solveMemo(row, col - 1, obstacleGrid, dp);

    return dp[row][col] = up + left;
}

int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
{
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();

    // obstacle hi start m hai or end m koi way hi nahi hai tab to 
    if (obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1)
    {
        return 0;
    }

    vector<vector<int>> dp(m, vector<int>(n, -1));

    return solveMemo(m - 1, n - 1, obstacleGrid, dp);
}

//tabulation
int uniquePathWithObstacleTab(vector<vector<int>> &obstacleGrid)
{
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();

    if (obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1)
    {
        return 0;
    }

    vector<vector<int>> dp(m, vector<int>(n, 0));

    for (int row = 0; row < m; row++)
    {
        for (int col = 0; col < n; col++)
        {   //agar obstacle hai to koi way nahi hai 
            if (obstacleGrid[row][col] == 1)
            {
                dp[row][col] = 0;
                continue;
            }

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

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
{
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();

    vector<int> dp(n, 0);
    
    dp[0] = obstacleGrid[0][0] == 1 ? 0 : 1;

    for (int row = 0; row < m; row++)
    {
        for (int col = 0; col < n; col++)
        {
            if (obstacleGrid[row][col] == 1)
            {
                dp[col] = 0;
            }
            else if (col > 0)
            {
                dp[col] += dp[col - 1];
            }
        }
    }

    return dp[n - 1];
}