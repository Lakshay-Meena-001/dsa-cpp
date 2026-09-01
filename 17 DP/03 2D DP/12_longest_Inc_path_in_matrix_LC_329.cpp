#include <bits/stdc++.h>
using namespace std;

int solveRec(int row, int col, vector<vector<int>> &matrix)
{

    int rows = matrix.size();
    int cols = matrix[0].size();

    int ans = 1;

    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    for (int i = 0; i < 4; i++)
    {
        int nr = row + dr[i];
        int nc = col + dc[i];

        if (nr >= 0 && nr < rows &&
            nc >= 0 && nc < cols &&
            matrix[nr][nc] > matrix[row][col])
        {

            ans = max(ans, 1 + solveRec(nr, nc, matrix));
        }
    }

    return ans;
}

int longestIncreasingPath(vector<vector<int>> &matrix)
{

    int rows = matrix.size();
    int cols = matrix[0].size();

    int ans = 0;

    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {

            ans = max(ans,
                      solveRec(row, col, matrix));
        }
    }

    return ans;
}

// memoization
int solveMemo(int row, int col, vector<vector<int>> &matrix, vector<vector<int>> &dp)
{

    int rows = matrix.size();
    int cols = matrix[0].size();

    int ans = 1;

    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    if (dp[row][col] != -1)
    {
        return dp[row][col];
    }

    for (int i = 0; i < 4; i++)
    {

        int nr = row + dr[i];
        int nc = col + dc[i];

        if (nr >= 0 && nr < rows &&
            nc >= 0 && nc < cols &&
            matrix[nr][nc] > matrix[row][col])
        {

            ans = max(ans,
                      1 + solveMemo(nr, nc, matrix, dp));
        }
    }

    return dp[row][col] = ans;
}

int longestIncreasingPath(vector<vector<int>> &matrix)
{

    int rows = matrix.size();
    int cols = matrix[0].size();

    int ans = 0;

    vector<vector<int>> dp(rows, vector<int>(cols, -1));

    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {

            ans = max(ans,
                      solveMemo(row, col, matrix, dp));
        }
    }

    return ans;
}

/*
no tabulation
Current state ka dependency direction fixed hi nahi hai.

Kabhi upar.

Kabhi niche.

Kabhi left.

Kabhi right.
*/