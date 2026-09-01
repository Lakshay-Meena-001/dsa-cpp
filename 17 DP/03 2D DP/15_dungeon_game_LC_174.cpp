#include <bits/stdc++.h>
using namespace std;

// =====================================================
// RECURSION
// =====================================================

// row,col par khade hain
// Princess tak pahunchne ke liye
// minimum health kitni chahiye ?

int solveRec(int row, int col, vector<vector<int>> &dungeon)
{
    int rows = dungeon.size();
    int cols = dungeon[0].size();

    // Boundary ke bahar
    if (row >= rows || col >= cols)
    {
        return 1e9;
    }

    // Princess cell
    if (row == rows - 1 && col == cols - 1)
    {
        return max(1, 1 - dungeon[row][col]);
    }

    // Right aur Down me se better future choose karo

    int right = solveRec(row, col + 1, dungeon);
    int down = solveRec(row + 1, col, dungeon);

    int need = min(right, down);

    // Current cell effect apply karo

    return max(1, need - dungeon[row][col]);
}

int calculateMinimumHPRec(vector<vector<int>> &dungeon)
{
    return solveRec(0, 0, dungeon);
}

// =====================================================
// MEMOIZATION
// =====================================================

int solveMemo(int row, int col, vector<vector<int>> &dungeon, vector<vector<int>> &dp)
{
    int rows = dungeon.size();
    int cols = dungeon[0].size();

    if (row >= rows || col >= cols)
    {
        return 1e9;
    }

    if (row == rows - 1 && col == cols - 1)
    {
        return max(1, 1 - dungeon[row][col]);
    }

    if (dp[row][col] != -1)
    {
        return dp[row][col];
    }

    int right = solveMemo(row, col + 1, dungeon, dp);

    int down = solveMemo(row + 1, col, dungeon, dp);

    int need = min(right, down);

    return dp[row][col] = max(1, need - dungeon[row][col]);
}

int calculateMinimumHPMemo(
    vector<vector<int>> &dungeon)
{
    int rows = dungeon.size();
    int cols = dungeon[0].size();

    vector<vector<int>> dp(rows, vector<int>(cols, -1));

    return solveMemo(0, 0, dungeon, dp);
}

// =====================================================
// TABULATION
// =====================================================

int calculateMinimumHPTab(vector<vector<int>> &dungeon)
{
    int rows = dungeon.size();
    int cols = dungeon[0].size();

    vector<vector<int>> dp(rows, vector<int>(cols, 0));

    // princess cell
    dp[rows - 1][cols - 1] = max(1, 1 - dungeon[rows - 1][cols - 1]);

    // Last column fill karo

    for (int row = rows - 2; row >= 0; row--)
    {
        dp[row][cols - 1] = max(1, dp[row + 1][cols - 1] - dungeon[row][cols - 1]);
    }

    // Last row fill karo

    for (int col = cols - 2; col >= 0; col--)
    {
        dp[rows - 1][col] = max(1, dp[rows - 1][col + 1] - dungeon[rows - 1][col]);
    }

    // Baaki cells

    for (int row = rows - 2; row >= 0; row--)
    {
        for (int col = cols - 2; col >= 0; col--)
        {
            int need = min(dp[row + 1][col], dp[row][col + 1]);

            dp[row][col] = max(1, need - dungeon[row][col]);
        }
    }

    return dp[0][0];
}

// =====================================================
// SPACE OPTIMIZATION
// =====================================================

int calculateMinimumHPSpace(
    vector<vector<int>> &dungeon)
{
    int rows = dungeon.size();
    int cols = dungeon[0].size();

    vector<int> front(cols, 0);

    // Last row fill karo

    front[cols - 1] =
        max(
            1,
            1 - dungeon[rows - 1][cols - 1]);

    for (int col = cols - 2;
         col >= 0;
         col--)
    {
        front[col] =
            max(
                1,
                front[col + 1] -
                    dungeon[rows - 1][col]);
    }

    // Bottom se top

    for (int row = rows - 2;
         row >= 0;
         row--)
    {
        vector<int> curr(cols, 0);

        // Last column

        curr[cols - 1] =
            max(
                1,
                front[cols - 1] -
                    dungeon[row][cols - 1]);

        for (int col = cols - 2;
             col >= 0;
             col--)
        {
            int need =
                min(
                    front[col],   // down
                    curr[col + 1] // right
                );

            curr[col] =
                max(
                    1,
                    need - dungeon[row][col]);
        }

        front = curr;
    }

    return front[0];
}

// =====================================================
// DRIVER CODE
// =====================================================

int main()
{
    vector<vector<int>> dungeon =
        {
            {-2, -3, 3},
            {-5, -10, 1},
            {10, 30, -5}};

    cout << "Recursion : "
         << calculateMinimumHPRec(dungeon)
         << endl;

    cout << "Memoization : "
         << calculateMinimumHPMemo(dungeon)
         << endl;

    cout << "Tabulation : "
         << calculateMinimumHPTab(dungeon)
         << endl;

    cout << "Space Optimization : "
         << calculateMinimumHPSpace(dungeon)
         << endl;

    return 0;
}

/*
=====================================================

LEETCODE

LC 174

Dungeon Game

=====================================================

STATE

dp[row][col]

=

Current cell par enter karne ke liye
minimum health kitni chahiye
taaki princess tak safely pahunch sake

=====================================================

RECURRENCE

need = min(right, down)

dp[row][col]

=

max(
    1,
    need - dungeon[row][col]
)

=====================================================

MOST IMPORTANT THINKING

Normal DP:

Start -> End

Dungeon Game:

End -> Start

Future decide karta hai
aaj kitni health chahiye

=====================================================

TIME COMPLEXITY

Recursion     : Exponential

Memoization   : O(rows * cols)

Tabulation    : O(rows * cols)

Space Opt     : O(cols)

=====================================================
*/