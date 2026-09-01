#include <bits/stdc++.h>
using namespace std;

// recurion
//  Returns final column where ball exits
//  Returns -1 if ball gets stuck

int solveRec(int row, int col, vector<vector<int>> &grid)
{
    int rows = grid.size();
    int cols = grid[0].size();

    // Ball reached bottom
    if (row == rows)
    {
        return col;
    }

    // Current slope is '\'
    if (grid[row][col] == 1)
    {
        // Right wall
        if (col == cols - 1)
        {
            return -1;
        }

        // V shape trap
        if (grid[row][col + 1] == -1)
        {
            return -1;
        }

        return solveRec(row + 1, col + 1, grid);
    }

    // Current slope is '/'
    else
    {
        // Left wall
        if (col == 0)
        {
            return -1;
        }

        // V shape trap
        if (grid[row][col - 1] == 1)
        {
            return -1;
        }

        return solveRec(row + 1, col - 1, grid);
    }
}

vector<int> findBallRec(vector<vector<int>> &grid)
{
    int cols = grid[0].size();

    vector<int> ans;

    for (int col = 0; col < cols; col++)
    {
        ans.push_back(solveRec(0, col, grid));
    }

    return ans;
}

// memoization

int solveMemo(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &dp)
{
    int rows = grid.size();
    int cols = grid[0].size();

    if (row == rows)
    {
        return col;
    }

    if (dp[row][col] != -2)
    {
        return dp[row][col];
    }

    if (grid[row][col] == 1)
    {
        if (col == cols - 1)
        {
            return dp[row][col] = -1;
        }

        if (grid[row][col + 1] == -1)
        {
            return dp[row][col] = -1;
        }

        return dp[row][col] = solveMemo(row + 1, col + 1, grid, dp);
    }
    else
    {
        if (col == 0)
        {
            return dp[row][col] = -1;
        }

        if (grid[row][col - 1] == 1)
        {
            return dp[row][col] = -1;
        }

        return dp[row][col] = solveMemo(row + 1, col - 1, grid, dp);
    }
}

vector<int> findBallMemo(vector<vector<int>> &grid)
{
    int rows = grid.size();
    int cols = grid[0].size();

    vector<vector<int>> dp(rows, vector<int>(cols, -2));

    vector<int> ans;

    for (int col = 0; col < cols; col++)
    {
        ans.push_back(solveMemo(0, col, grid, dp));
    }

    return ans;
}

// main

int main()
{
    vector<vector<int>> grid =
        {
            {1, 1, 1, -1, -1},
            {1, 1, 1, -1, -1},
            {-1, -1, -1, 1, 1},
            {1, 1, 1, 1, -1},
            {-1, -1, -1, -1, -1}
        };

    vector<int> ans = findBallRec(grid);

    cout << "Output : ";

    for (int x : ans)
    {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}