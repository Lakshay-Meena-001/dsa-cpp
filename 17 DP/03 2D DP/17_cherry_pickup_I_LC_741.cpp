#include <bits/stdc++.h>
using namespace std;

// =====================================================
// RECURSION
// =====================================================

// r1,c1 -> Person1 ki position
// r2     -> Person2 ki row
//
// c2 hum derive kar lenge

int solveRec(int r1, int c1, int r2, vector<vector<int>> &grid)
{
    int n = grid.size();

    // Person2 ka column derive karo

    int c2 = r1 + c1 - r2;

    // Boundary check

    if (r1 >= n || c1 >= n || r2 >= n || c2 >= n)
    {
        return -1e8;
    }

    // Thorn cell
    // Yahan ja hi nahi sakte

    if (grid[r1][c1] == -1 || grid[r2][c2] == -1)
    {
        return -1e8;
    }

    // Dono destination par pahunch gaye

    if (r1 == n - 1 && c1 == n - 1)
    {
        return grid[r1][c1];
    }

    int cherries = 0;

    // Same cell par hain

    if (r1 == r2 && c1 == c2)
    {
        cherries = grid[r1][c1];
    }
    else
    {
        cherries = grid[r1][c1] + grid[r2][c2];
    }

    // 4 possible combinations

    int option1 = solveRec(r1 + 1, c1, r2 + 1, grid);

    int option2 = solveRec(r1 + 1, c1, r2, grid);

    int option3 = solveRec(r1, c1 + 1, r2 + 1, grid);

    int option4 = solveRec(r1, c1 + 1, r2, grid);

    // Future ka best answer

    int future = max({option1, option2, option3, option4});

    return cherries + future;
}

int cherryPickupRec(vector<vector<int>> &grid)
{
    return max(0, solveRec(0, 0, 0, grid));
}

// =====================================================
// MEMOIZATION
// =====================================================

int solveMemo(int r1, int c1, int r2, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp)
{
    int n = grid.size();

    int c2 = r1 + c1 - r2;

    // Boundary

    if (r1 >= n || c1 >= n || r2 >= n || c2 >= n)
    {
        return -1e8;
    }

    // Thorn

    if (grid[r1][c1] == -1 || grid[r2][c2] == -1)
    {
        return -1e8;
    }

    // Destination

    if (r1 == n - 1 && c1 == n - 1)
    {
        return grid[r1][c1];
    }

    if (dp[r1][c1][r2] != -1)
    {
        return dp[r1][c1][r2];
    }

    int cherries = 0;

    // Same cell

    if (r1 == r2 && c1 == c2)
    {
        cherries = grid[r1][c1];
    }
    else
    {
        cherries = grid[r1][c1] + grid[r2][c2];
    }

    int future =
        max({solveMemo(r1 + 1, c1, r2 + 1, grid, dp),

             solveMemo(r1 + 1, c1, r2, grid, dp),

             solveMemo(r1, c1 + 1, r2 + 1, grid, dp),

             solveMemo(r1, c1 + 1, r2, grid, dp)});

    return dp[r1][c1][r2] = cherries + future;
}

int cherryPickupMemo(vector<vector<int>> &grid)
{
    int n = grid.size();

    vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n, -1)));

    return max(0, solveMemo(0, 0, 0, grid, dp));
}