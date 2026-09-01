#include <bits/stdc++.h>
using namespace std;

// =====================================================
// RECURSION
// =====================================================

// row  -> current row
// col1 -> robot1 current column
// col2 -> robot2 current column

int solveRec(int row, int col1, int col2, vector<vector<int>> &grid)
{
    int rows = grid.size();
    int cols = grid[0].size();

    // Kisi robot ne boundary cross kar di
    if (col1 < 0 || col1 >= cols || col2 < 0 || col2 >= cols)
    {
        return -1e8;
    }

    // Last row par pahunch gaye

    if (row == rows - 1)
    {
        // Dono same cell par hain
        // Chocolate sirf ek baar count hogi

        if (col1 == col2)
        {
            return grid[row][col1];
        }

        // Alag cells par hain

        return grid[row][col1] + grid[row][col2];
    }

    int maxi = -1e8;

    // Robot1 ke 3 possible moves

    for (int move1 = -1; move1 <= 1; move1++)
    {
        // Robot2 ke 3 possible moves or har ek left k liye right 3 k moves

        for (int move2 = -1; move2 <= 1; move2++)
        {
            int currChocolate = 0;

            // Dono same cell par

            if (col1 == col2)
            {
                currChocolate = grid[row][col1];
            }
            else
            {
                currChocolate = grid[row][col1] + grid[row][col2];
            }

            // Future ka best answer lao

            int futureChocolate = solveRec(row + 1, col1 + move1, col2 + move2, grid);

            maxi = max(maxi, currChocolate + futureChocolate);
        }
    }

    return maxi;
}

int maximumChocolatesRec(vector<vector<int>> &grid)
{
    int cols = grid[0].size();

    return solveRec(0, 0, cols - 1, grid);
}

// =====================================================
// MEMOIZATION
// =====================================================

int solveMemo(int row, int col1, int col2, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp)
{
    int rows = grid.size();
    int cols = grid[0].size();

    if (col1 < 0 || col1 >= cols || col2 < 0 || col2 >= cols)
    {
        return -1e8;
    }

    if (row == rows - 1)
    {
        if (col1 == col2)
        {
            return grid[row][col1];
        }

        return grid[row][col1] + grid[row][col2];
    }

    if (dp[row][col1][col2] != -1)
    {
        return dp[row][col1][col2];
    }

    int maxi = -1e8;

    for (int move1 = -1; move1 <= 1; move1++)
    {
        for (int move2 = -1; move2 <= 1; move2++)
        {
            int currChocolate = 0;

            if (col1 == col2)
            {
                currChocolate = grid[row][col1];
            }
            else
            {
                currChocolate = grid[row][col1] + grid[row][col2];
            }

            int futureChocolate = solveMemo(row + 1, col1 + move1, col2 + move2, grid, dp);

            maxi = max(maxi, currChocolate + futureChocolate);
        }
    }

    return dp[row][col1][col2] = maxi;
}

int maximumChocolatesMemo(vector<vector<int>> &grid)
{
    int rows = grid.size();
    int cols = grid[0].size();

    vector<vector<vector<int>>> dp(rows, vector<vector<int>>(cols, vector<int>(cols, -1)));

    return solveMemo(0, 0, cols - 1, grid, dp);
}

// =====================================================
// TABULATION
// =====================================================

int maximumChocolatesTab(vector<vector<int>> &grid)
{
    int rows = grid.size();
    int cols = grid[0].size();

    vector<vector<vector<int>>> dp(rows, vector<vector<int>>(cols, vector<int>(cols, 0)));

    // Base Case
    // Last row fill karo

    for (int col1 = 0; col1 < cols; col1++)
    {
        for (int col2 = 0; col2 < cols; col2++)
        {
            if (col1 == col2)
            {
                dp[rows - 1][col1][col2] = grid[rows - 1][col1];
            }
            else
            {
                dp[rows - 1][col1][col2] = grid[rows - 1][col1] + grid[rows - 1][col2];
            }
        }
    }

    // Bottom se top build karenge

    for (int row = rows - 2; row >= 0; row--)
    {
        for (int col1 = 0; col1 < cols; col1++)
        {
            for (int col2 = 0; col2 < cols; col2++)
            {
                int maxi = -1e8;

                for (int move1 = -1; move1 <= 1; move1++)
                {
                    for (int move2 = -1; move2 <= 1; move2++)
                    {
                        int currChocolate = 0;

                        if (col1 == col2)
                        {
                            currChocolate = grid[row][col1];
                        }
                        else
                        {
                            currChocolate = grid[row][col1] + grid[row][col2];
                        }

                        int nextCol1 = col1 + move1;
                        int nextCol2 = col2 + move2;

                        if (nextCol1 >= 0 && nextCol1 < cols && nextCol2 >= 0 && nextCol2 < cols)
                        {
                            currChocolate += dp[row + 1][nextCol1][nextCol2];
                        }
                        else
                        {
                            currChocolate += -1e8;
                        }

                        maxi = max(maxi, currChocolate);
                    }
                }

                dp[row][col1][col2] = maxi;
            }
        }
    }

    return dp[0][0][cols - 1];
}

// =====================================================
// SPACE OPTIMIZATION
// =====================================================

int maximumChocolatesSpace(vector<vector<int>> &grid)
{
    int rows = grid.size();
    int cols = grid[0].size();

    vector<vector<int>> front(
        cols,
        vector<int>(cols, 0));

    // Last row

    for (int col1 = 0; col1 < cols; col1++)
    {
        for (int col2 = 0; col2 < cols; col2++)
        {
            if (col1 == col2)
            {
                front[col1][col2] = grid[rows - 1][col1];
            }
            else
            {
                front[col1][col2] = grid[rows - 1][col1] + grid[rows - 1][col2];
            }
        }
    }

    for (int row = rows - 2; row >= 0; row--)
    {
        vector<vector<int>> curr(
            cols,
            vector<int>(cols, 0));

        for (int col1 = 0; col1 < cols; col1++)
        {
            for (int col2 = 0; col2 < cols; col2++)
            {
                int maxi = -1e8;

                for (int move1 = -1; move1 <= 1; move1++)
                {
                    for (int move2 = -1; move2 <= 1; move2++)
                    {
                        int currChocolate = 0;

                        if (col1 == col2)
                        {
                            currChocolate = grid[row][col1];
                        }
                        else
                        {
                            currChocolate =
                                grid[row][col1] + grid[row][col2];
                        }

                        int nextCol1 = col1 + move1;
                        int nextCol2 = col2 + move2;

                        if (nextCol1 >= 0 &&
                            nextCol1 < cols &&
                            nextCol2 >= 0 &&
                            nextCol2 < cols)
                        {
                            currChocolate +=
                                front[nextCol1][nextCol2];
                        }
                        else
                        {
                            currChocolate += -1e8;
                        }

                        maxi = max(maxi, currChocolate);
                    }
                }

                curr[col1][col2] = maxi;
            }
        }

        front = curr;
    }

    return front[0][cols - 1];
}