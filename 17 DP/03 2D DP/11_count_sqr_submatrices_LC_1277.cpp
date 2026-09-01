#include <bits/stdc++.h>

using namespace std;

int solveRec(int row, int col, vector<vector<int>> &matrix)
{   
    // grid se baher aa gye 
    if (row < 0 || col < 0)
    {
        return 0;
    }

    // square ki requirement hi hai 1 ho elementto element 0 hua to 
    if (matrix[row][col] == 0)
    {
        return 0;
    }

    //like agar row 0 hai but element 1 hai to single element bhi ek count hoga mtlb 1 one 1 square
    if (row == 0 || col == 0)
    {
        return 1;
    }

    int up = solveRec(row - 1, col, matrix);
    int left = solveRec(row, col - 1, matrix);
    int diagonal = solveRec(row - 1, col - 1, matrix);

    return 1 + min({up, left, diagonal});
}

int countSquaresRec(vector<vector<int>> &matrix)
{
    int rows = matrix.size();
    int cols = matrix[0].size();

    int total = 0;

    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {
            total += solveRec(row, col, matrix);
        }
    }
    return total;
}

// memoizaton

int solveMemo(int row, int col, vector<vector<int>> &matrix, vector<vector<int>> &dp)
{
    if (row < 0 || col < 0)
    {
        return 0;
    }

    if (matrix[row][col] == 0)
    {
        return 0;
    }

    if (row == 0 || col == 0)
    {
        return 1;
    }

    if (dp[row][col] != -1)
    {
        return dp[row][col];
    }

    int up = solveMemo(row - 1, col, matrix, dp);
    int left = solveMemo(row, col - 1, matrix, dp);
    int diagonal = solveMemo(row - 1, col - 1, matrix, dp);

    return dp[row][col] = 1 + min({up, left, diagonal});
}

int countSquaresMemo(vector<vector<int>> &matrix)
{
    int rows = matrix.size();
    int cols = matrix[0].size();

    vector<vector<int>> dp(rows, vector<int>(cols, -1));

    int total = 0;

    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {
            total += solveMemo(row, col, matrix, dp);
        }
    }
    return total;
}

// tabulation
int countSquaresTab(vector<vector<int>> &matrix)
{
    int rows = matrix.size();
    int cols = matrix[0].size();

    vector<vector<int>> dp(rows, vector<int>(cols, 0));

    int total = 0;

    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {
            if (matrix[row][col] == 0)
            {
                dp[row][col] = 0;
            }
            else if (row == 0 || col == 0)
            {
                dp[row][col] = 1;
            }
            else
            {
                dp[row][col] = 1 + min({dp[row - 1][col], dp[row][col - 1], dp[row - 1][col - 1]});
            }

            total += dp[row][col];
        }
    }
    return total;
}

// space
int countSquaresSpace(vector<vector<int>> &matrix)
{
    int rows = matrix.size();
    int cols = matrix[0].size();

    vector<int> prev(cols, 0);

    int total = 0;

    for (int row = 0; row < rows; row++)
    {
        vector<int> curr(cols, 0);

        for (int col = 0; col < cols; col++)
        {
            if (matrix[row][col] == 0)
            {
                curr[col] = 0;
            }

            else if (row == 0 || col == 0)
            {
                curr[col] = 1;
            }

            else
            {
                curr[col] = 1 + min({prev[col], curr[col - 1], prev[col - 1]});
            }

            total += curr[col];
        }

        prev = curr;
    }

    return total;
}
