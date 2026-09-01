#include <bits/stdc++.h>
using namespace std;

// RECURSION
// Ye function batata hai:
//
// Current cell ko bottom-right maan kar
// largest square kitne size ka ban sakta hai

int solveRec(int row, int col, vector<vector<char>> &matrix, int &maxi)
{
    // Grid se bahar aa gaye
    if (row < 0 || col < 0)
    {
        return 0;
    }

    // Agar current cell 0 hai
    // to yahan square ban hi nahi sakta
    if (matrix[row][col] == '0')
    {
        return 0;
    }

    // First row ya first column
    // to maximum square size sirf 1 ho sakta hai
    if (row == 0 || col == 0)
    {
        maxi = max(maxi, 1);
        return 1;
    }

    // Teen neighbours dekho

    int up = solveRec(row - 1, col, matrix, maxi);

    int left = solveRec(row, col - 1, matrix, maxi);

    int diagonal = solveRec(row - 1, col - 1, matrix, maxi);

    // Current square size

    int currSize = 1 + min({up, left, diagonal});

    // Global answer update

    maxi = max(maxi, currSize);

    return currSize;
}

int maximalSquareRec(vector<vector<char>> &matrix)
{
    int rows = matrix.size();
    int cols = matrix[0].size();

    int maxi = 0;

    // Har cell ko square ka
    // bottom-right corner maan kar try karo

    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {
            solveRec(row, col, matrix, maxi);
        }
    }

    // LC area maangta hai
    return maxi * maxi;
}

// =====================================================
// MEMOIZATION
// =====================================================

int solveMemo(int row, int col, vector<vector<char>> &matrix, vector<vector<int>> &dp, int &maxi)
{
    if (row < 0 || col < 0)
    {
        return 0;
    }

    if (matrix[row][col] == '0')
    {
        return 0;
    }

    if (row == 0 || col == 0)
    {
        maxi = max(maxi, 1);
        return 1;
    }

    if (dp[row][col] != -1)
    {
        return dp[row][col];
    }

    int up = solveMemo(row - 1, col, matrix, dp, maxi);

    int left = solveMemo(row, col - 1, matrix, dp, maxi);

    int diagonal = solveMemo(row - 1, col - 1, matrix, dp, maxi);

    dp[row][col] = 1 + min({up, left, diagonal});

    maxi = max(maxi, dp[row][col]);

    return dp[row][col];
}

int maximalSquareMemo(
    vector<vector<char>> &matrix)
{
    int rows = matrix.size();
    int cols = matrix[0].size();

    vector<vector<int>> dp(rows, vector<int>(cols, -1));

    int maxi = 0;

    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {
            solveMemo(row, col, matrix, dp, maxi);
        }
    }

    return maxi * maxi;
}

// =====================================================
// TABULATION
// =====================================================

int maximalSquareTab(vector<vector<char>> &matrix)
{
    int rows = matrix.size();
    int cols = matrix[0].size();

    vector<vector<int>> dp(rows, vector<int>(cols, 0));

    int maxi = 0;

    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {
            // Current cell 0 hai
            // to square size bhi 0

            if (matrix[row][col] == '0')
            {
                dp[row][col] = 0;
            }

            // First row ya first column
            // aur value 1 hai

            else if (row == 0 || col == 0)
            {
                dp[row][col] = 1;
            }

            else
            {
                dp[row][col] = 1 + min({dp[row - 1][col], dp[row][col - 1], dp[row - 1][col - 1]});
            }

            maxi = max(maxi, dp[row][col]);
        }
    }

    return maxi * maxi;
}

// =====================================================
// SPACE OPTIMIZATION
// =====================================================

int maximalSquareSpace(
    vector<vector<char>> &matrix)
{
    int rows = matrix.size();
    int cols = matrix[0].size();

    vector<int> prev(cols, 0);

    int maxi = 0;

    for (int row = 0; row < rows; row++)
    {
        vector<int> curr(cols, 0);

        for (int col = 0; col < cols; col++)
        {
            if (matrix[row][col] == '0')
            {
                curr[col] = 0;
            }

            else if (row == 0 || col == 0)
            {
                curr[col] = 1;
            }

            else
            {
                curr[col] = 1 + min({
                                    prev[col],     // up
                                    curr[col - 1], // left
                                    prev[col - 1]  // diagonal
                                });
            }

            maxi = max(maxi, curr[col]);
        }

        // Current row ko
        // next iteration ke liye previous bana do

        prev = curr;
    }

    return maxi * maxi;
}

// =====================================================
// DRIVER CODE
// =====================================================

int main()
{
    vector<vector<char>> matrix =
        {
            {'1', '0', '1', '0', '0'},
            {'1', '0', '1', '1', '1'},
            {'1', '1', '1', '1', '1'},
            {'1', '0', '0', '1', '0'}};

    cout << "Recursion : "
         << maximalSquareRec(matrix)
         << endl;

    cout << "Memoization : "
         << maximalSquareMemo(matrix)
         << endl;

    cout << "Tabulation : "
         << maximalSquareTab(matrix)
         << endl;

    cout << "Space Optimization : "
         << maximalSquareSpace(matrix)
         << endl;

    return 0;
}