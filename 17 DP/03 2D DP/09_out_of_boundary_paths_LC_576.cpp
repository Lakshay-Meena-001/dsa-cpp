#include <bits/stdc++.h>
using namespace std;

// recursion

int MOD = 1e9 + 7;

int solveRec(int m, int n, int maxMove, int row, int col)
{
    /*
    Boundary Crossed
    */

    if (row < 0 || row >= m || col < 0 || col >= n)
    {
        return 1;
    }

    /*
    No moves left
    */

    if (maxMove == 0)
    {
        return 0;
    }

    int up = solveRec(m, n, maxMove - 1, row - 1, col);

    int down = solveRec(m, n, maxMove - 1, row + 1, col);

    int left = solveRec(m, n, maxMove - 1, row, col - 1);

    int right = solveRec(m, n, maxMove - 1, row, col + 1);

    return (((up + down) % MOD + (left + right) % MOD) % MOD);
}

int findPathsRec(int m, int n, int maxMove, int startRow, int startColumn)
{
    return solveRec(m, n, maxMove, startRow, startColumn);
}

// memoization

int solveMemo(int m, int n, int maxMove, int row, int col, vector<vector<vector<int>>> &dp)
{
    if (row < 0 || row >= m || col < 0 || col >= n)
    {
        return 1;
    }

    if (maxMove == 0)
    {
        return 0;
    }

    if (dp[row][col][maxMove] != -1)
    {
        return dp[row][col][maxMove];
    }

    long long up = solveMemo(m, n, maxMove - 1, row - 1, col, dp);

    long long down = solveMemo(m, n, maxMove - 1, row + 1, col, dp);

    long long left = solveMemo(m, n, maxMove - 1, row, col - 1, dp);

    long long right = solveMemo(m, n, maxMove - 1, row, col + 1, dp);

    return dp[row][col][maxMove] = (up + down + left + right) % MOD;
}

int findPathsMemo(int m, int n, int maxMove, int startRow, int startColumn)
{
    vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(maxMove + 1, -1)));

    return solveMemo(m, n, maxMove, startRow, startColumn, dp);
}

// tabulation

int findPathsTab(int m, int n, int maxMove, int startRow, int startColumn)
{
    vector<vector<vector<long long>>> dp(maxMove + 1, vector<vector<long long>>(m, vector<long long>(n, 0)));

    for (int move = 1; move <= maxMove; move++)
    {
        for (int row = 0; row < m; row++)
        {
            for (int col = 0; col < n; col++)
            {
                long long count = 0;

                // up 
                if (row == 0)
                {
                    count++;
                }
                else
                {
                    count += dp[move - 1][row - 1][col];
                }

                // down
                if (row == m - 1)
                {
                    count++;
                }
                else
                {
                    count += dp[move - 1][row + 1][col];
                }

                //left

                if (col == 0)
                {
                    count++;
                }
                else
                {
                    count += dp[move - 1][row][col - 1];
                }

                // right

                if (col == n - 1)
                {
                    count++;
                }
                else
                {
                    count += dp[move - 1][row][col + 1];
                }

                dp[move][row][col] = count % MOD;
            }
        }
    }

    return dp[maxMove][startRow][startColumn];
}

/*
========================================================
APPROACH 4 : SPACE OPTIMIZATION
========================================================
*/

int findPathsSpace(
    int m,
    int n,
    int maxMove,
    int startRow,
    int startColumn)
{
    vector<vector<long long>> prev(m, vector<long long>(n, 0));

    for (int move = 1; move <= maxMove; move++)
    {
        vector<vector<long long>> curr(m, vector<long long>(n, 0));

        for (int row = 0; row < m; row++)
        {
            for (int col = 0; col < n; col++)
            {
                long long count = 0;

                if (row == 0)
                {
                    count++;
                }
                else
                {
                    count += prev[row - 1][col];
                }

                if (row == m - 1)
                {
                    count++;
                }
                else
                {
                    count += prev[row + 1][col];
                }

                if (col == 0)
                {
                    count++;
                }
                else
                {
                    count += prev[row][col - 1];
                }

                if (col == n - 1)
                {
                    count++;
                }
                else
                {
                    count += prev[row][col + 1];
                }

                curr[row][col] = count % MOD;
            }
        }

        prev = curr;
    }

    return prev[startRow][startColumn];
}

/*
========================================================
DRIVER CODE
========================================================
*/

int main()
{
    int m = 2;
    int n = 2;

    int maxMove = 2;

    int startRow = 0;
    int startColumn = 0;

    cout << "Recursion      : "
         << findPathsRec(
                m, n,
                maxMove,
                startRow,
                startColumn)
         << endl;

    cout << "Memoization    : "
         << findPathsMemo(
                m, n,
                maxMove,
                startRow,
                startColumn)
         << endl;

    cout << "Tabulation     : "
         << findPathsTab(
                m, n,
                maxMove,
                startRow,
                startColumn)
         << endl;

    cout << "Space Opt      : "
         << findPathsSpace(
                m, n,
                maxMove,
                startRow,
                startColumn)
         << endl;
}