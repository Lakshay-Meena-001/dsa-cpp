#include <bits/stdc++.h>

using namespace std;

int solveRec(int row, int col, vector<vector<int>> &matrix)
{
    int n = matrix.size();
    //like oopr jate hue col se baher ho gye galti se isliye check hai 
    if (col < 0 || col >= n)
    {
        return 1e9;
    }
    
    // hum niche s eoopr aa rahe hai then hum kis bhi col par ruk skte hai pehle row k 
    if (row == 0)
    {
        return matrix[0][col];
    }

    //movements 
    int up = matrix[row][col] + solveRec(row - 1, col, matrix);
    int leftDiagonal = matrix[row][col] + solveRec(row - 1, col - 1, matrix);
    int rightDiagonal = matrix[row][col] + solveRec(row - 1, col + 1, matrix);

    return min({up, leftDiagonal, rightDiagonal});
}

int minFallingPathSumRec(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int ans = 1e9;
    for (int col = 0; col < n; col++)
    {
        ans = min(ans, solveRec(n - 1, col, matrix));
    }

    return ans;
}

// memoization
int solveMemo(int row, int col, vector<vector<int>> &matrix, vector<vector<int>> &dp)
{
    int n = matrix.size();

    if (col < 0 || col >= n)
    {
        return 1e9;
    }

    if (row == 0)
    {
        return matrix[0][col];
    }

    if (dp[row][col] != -1)
    {
        return dp[row][col];
    }

    int up = matrix[row][col] + solveMemo(row - 1, col, matrix, dp);
    int leftDiagonal = matrix[row][col] + solveMemo(row - 1, col - 1, matrix, dp);
    int rightDiagonal = matrix[row][col] + solveMemo(row - 1, col + 1, matrix, dp);

    return dp[row][col] = min({up, leftDiagonal, rightDiagonal});
}

int minFallingPathSumMemo(vector<vector<int>> &matrix)
{
    int n = matrix.size();

    int ans = 1e9;

    vector<vector<int>> dp(n, vector<int>(n, -1));

    for (int col = 0; col < n; col++)
    {
        ans = min(ans, solveMemo(n - 1, col, matrix, dp));
    }

    return ans;
}

// Tabulation

int minFallingPathSumTab(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // hume sirf start row pata hai
    for (int col = 0; col < n; col++)
    {
        dp[0][col] = matrix[0][col];
    }

    for (int row = 1; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            int up = matrix[row][col] + dp[row - 1][col];
            int leftDiagonal = matrix[row][col] + (col > 0 ? dp[row - 1][col - 1] : (int)1e9);
            int rightDiagonal = matrix[row][col] + (col < n - 1 ? dp[row - 1][col + 1] : (int)1e9);
            dp[row][col] = min({up, leftDiagonal, rightDiagonal});
        }
    }

    int ans = 1e9;

    // last row ka minimum column
    for (int col = 0; col < n; col++)
    {
        ans = min(ans, dp[n - 1][col]);
    }

    return ans;
}


// Tabulation

int minFallingPathSumSpace(vector<vector<int>> &matrix)
{
    int n = matrix.size();

    vector<int> prev = matrix[0];

    for (int row = 1; row < n; row++)
    {
        vector<int> curr(n, 0);

        for (int col = 0; col < n; col++)
        {
            int up = matrix[row][col] + prev[col];
            int leftDiagonal = matrix[row][col] + (col > 0 ? prev[col - 1] : (int)1e9);
            int rightDiagonal = matrix[row][col] + (col < n - 1 ? prev[col + 1] : (int)1e9);
            curr[col] = min({up, leftDiagonal, rightDiagonal});
        }
        prev = curr;
    }

    return *min_element(prev.begin(), prev.end());
}

int main()
{
    vector<vector<int>> matrix =
        {
            {2, 1, 3},
            {6, 5, 4},
            {7, 8, 9}};

    cout << "Recursion          : "
         << minFallingPathSumRec(matrix)
         << "\n";

    cout << "Memoization        : "
         << minFallingPathSumMemo(matrix)
         << "\n";

    cout << "Tabulation         : "
         << minFallingPathSumTab(matrix)
         << "\n";

    cout << "Space Optimization : "
         << minFallingPathSumSpace(matrix)
         << "\n";

    return 0;
}