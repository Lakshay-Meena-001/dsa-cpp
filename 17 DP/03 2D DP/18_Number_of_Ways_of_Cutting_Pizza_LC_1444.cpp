#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

// =====================================================
// PREFIX SUM BUILD
// =====================================================

// appleCount[row][col]
//
// (row,col) se bottom-right tak
// total apples kitne hain

vector<vector<int>> buildAppleCount(vector<string> &pizza)
{
    int rows = pizza.size();
    int cols = pizza[0].size();

    vector<vector<int>> appleCount(
        rows + 1,
        vector<int>(cols + 1, 0));

    for (int row = rows - 1; row >= 0; row--)
    {
        for (int col = cols - 1; col >= 0; col--)
        {
            appleCount[row][col] =
                appleCount[row + 1][col] +
                appleCount[row][col + 1] -
                appleCount[row + 1][col + 1] +
                (pizza[row][col] == 'A');
        }
    }

    return appleCount;
}

// =====================================================
// RECURSION
// =====================================================

int solveRec(int row,
             int col,
             int cuts,
             vector<string> &pizza,
             vector<vector<int>> &appleCount)
{
    int rows = pizza.size();
    int cols = pizza[0].size();

    // Current pizza me apple hi nahi hai

    if (appleCount[row][col] == 0)
    {
        return 0;
    }

    // Aur cuts nahi bache

    if (cuts == 0)
    {
        return 1;
    }

    long long ways = 0;

    // =====================================
    // Horizontal Cut
    // =====================================

    for (int nextRow = row + 1;
         nextRow < rows;
         nextRow++)
    {
        // Upper piece me apple hona chahiye

        if (appleCount[row][col] >
            appleCount[nextRow][col])
        {
            ways += solveRec(
                nextRow,
                col,
                cuts - 1,
                pizza,
                appleCount);

            ways %= MOD;
        }
    }

    // =====================================
    // Vertical Cut
    // =====================================

    for (int nextCol = col + 1;
         nextCol < cols;
         nextCol++)
    {
        // Left piece me apple hona chahiye

        if (appleCount[row][col] >
            appleCount[row][nextCol])
        {
            ways += solveRec(
                row,
                nextCol,
                cuts - 1,
                pizza,
                appleCount);

            ways %= MOD;
        }
    }

    return ways;
}

int waysRec(vector<string> &pizza, int k)
{
    vector<vector<int>> appleCount =
        buildAppleCount(pizza);

    return solveRec(
        0,
        0,
        k - 1,
        pizza,
        appleCount);
}

// =====================================================
// MEMOIZATION
// =====================================================

int solveMemo(int row,
              int col,
              int cuts,
              vector<string> &pizza,
              vector<vector<int>> &appleCount,
              vector<vector<vector<int>>> &dp)
{
    int rows = pizza.size();
    int cols = pizza[0].size();

    if (appleCount[row][col] == 0)
    {
        return 0;
    }

    if (cuts == 0)
    {
        return 1;
    }

    if (dp[row][col][cuts] != -1)
    {
        return dp[row][col][cuts];
    }

    long long ways = 0;

    // =====================================
    // Horizontal Cut
    // =====================================

    for (int nextRow = row + 1;
         nextRow < rows;
         nextRow++)
    {
        if (appleCount[row][col] >
            appleCount[nextRow][col])
        {
            ways += solveMemo(
                nextRow,
                col,
                cuts - 1,
                pizza,
                appleCount,
                dp);

            ways %= MOD;
        }
    }

    // =====================================
    // Vertical Cut
    // =====================================

    for (int nextCol = col + 1;
         nextCol < cols;
         nextCol++)
    {
        if (appleCount[row][col] >
            appleCount[row][nextCol])
        {
            ways += solveMemo(
                row,
                nextCol,
                cuts - 1,
                pizza,
                appleCount,
                dp);

            ways %= MOD;
        }
    }

    return dp[row][col][cuts] = ways;
}

int waysMemo(vector<string> &pizza, int k)
{
    int rows = pizza.size();
    int cols = pizza[0].size();

    vector<vector<int>> appleCount =
        buildAppleCount(pizza);

    vector<vector<vector<int>>> dp(
        rows,
        vector<vector<int>>(
            cols,
            vector<int>(k, -1)));

    return solveMemo(
        0,
        0,
        k - 1,
        pizza,
        appleCount,
        dp);
}

// =====================================================
// DRIVER
// =====================================================

int main()
{
    vector<string> pizza =
        {
            "A..",
            "AAA",
            "..."};

    int k = 3;

    cout << "Recursion : "
         << waysRec(pizza, k)
         << endl;

    cout << "Memoization : "
         << waysMemo(pizza, k)
         << endl;

    return 0;
}