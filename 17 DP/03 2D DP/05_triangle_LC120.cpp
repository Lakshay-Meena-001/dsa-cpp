#include <bits/stdc++.h>

using namespace std;

int solveRec(int row, int col, vector<vector<int>> &triangle)
{
    int n = triangle.size();

    if (row == n - 1)
    {
        return triangle[row][col];
    }

    int down = triangle[row][col] + solveRec(row + 1, col, triangle);
    int diagonal = triangle[row][col] + solveRec(row + 1, col + 1, triangle);

    return min(down, diagonal);
}

int minimumTotalRec(vector<vector<int>> &triangle)
{
    return solveRec(0, 0, triangle);
}

// memoization
int solveMemo(int row, int col, vector<vector<int>> &triangle, vector<vector<int>> &dp)
{
    int n = triangle.size();

    if (row = n - 1)
    {
        return triangle[row][col];
    }

    if (dp[row][col] != INT_MAX)
    {
        return dp[row][col];
    }

    int down = triangle[row][col] + solveRec(row + 1, col, triangle);
    int diagonal = triangle[row][col] + solveRec(row + 1, col + 1, triangle);

    return dp[row][col] = min(down, diagonal);
}

int minimumTotalMemo(vector<vector<int>> &triangle)
{
    int n = triangle.size();
    // size k dhyaan rakhan hai only cols hai "n" or default value INT_max kyuki answer m -1 bhi ho skta hai values
    vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
    return solveMemo(0, 0, triangle, dp);
}

// tabulation

int minimumTotalTab(vector<vector<int>> &triangle)
{
    int n = triangle.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // like ulta chal rahe hai niche se oopr triangle bana hai aakhiri row same rahegi
    for (int col = 0; col < n; col++)
    {
        dp[n - 1][col] = triangle[n - 1][col];
    }

    for (int row = n - 2; row >= 0; row--)
    {
        for (int col = row; col >= 0; col--)
        {
            int down = triangle[row][col] + dp[row + 1][col];
            int diagonal = triangle[row][col] + dp[row + 1][col + 1];
            dp[row][col] = min(down, diagonal);
        }
    }
    return dp[0][0];
}

// space Optimization

int minimumTotalSpace(vector<vector<int>> &triangle)
{
    int n = triangle.size();

    // last row leli build karne k liye bottom se up
    vector<int> front = triangle[n - 1];

    for (int row = n - 2; row >= 0; row--)
    {
        vector<int> curr(n, 0);

        for (int col = row; col >= 0; col--)
        {
            int down = triangle[row][col] + front[col];
            int diagonal = triangle[row][col] + front[col + 1];
            curr[col] = min(down, diagonal);
        }

        front = curr;
    }
    return front[0];
}

int main()
{
    vector<vector<int>> triangle =
        {
            {2},
            {3, 4},
            {6, 5, 7},
            {4, 1, 8, 3}};

    cout << "Recursion          : "
         << minimumTotalRec(triangle)
         << "\n";

    cout << "Memoization        : "
         << minimumTotalMemo(triangle)
         << "\n";

    cout << "Tabulation         : "
         << minimumTotalTab(triangle)
         << "\n";

    cout << "Space Optimization : "
         << minimumTotalSpace(triangle)
         << "\n";

    return 0;
}