#include <bits/stdc++.h>
using namespace std;

// =====================================================
// RECURSION
// =====================================================

// index     -> Current Piece Index
// rodLength -> Remaining Rod Length

int solveRec(int index, int rodLength, vector<int> &price)
{
    // Base Case
    if (index == 0)
    {
        return rodLength * price[0];
    }

    // Current piece length
    int pieceLength = index + 1;

    // Don't Cut
    int notPick = solveRec(index - 1, rodLength, price);

    // Cut
    int pick = INT_MIN;

    if (pieceLength <= rodLength)
    {
        pick = price[index] + solveRec(index, rodLength - pieceLength, price);
    }

    return max(pick, notPick);
}

int cutRodRec(vector<int> &price)
{
    int n = price.size();

    return solveRec(n - 1, n, price);
}

// =====================================================
// MEMOIZATION
// =====================================================

int solveMemo(int index, int rodLength, vector<int> &price, vector<vector<int>> &dp)
{
    if (index == 0)
    {
        return rodLength * price[0];
    }

    if (dp[index][rodLength] != -1)
    {
        return dp[index][rodLength];
    }

    int pieceLength = index + 1;

    int notPick = solveMemo(index - 1, rodLength, price, dp);

    int pick = INT_MIN;

    if (pieceLength <= rodLength)
    {
        pick = price[index] + solveMemo(index, rodLength - pieceLength, price, dp);
    }

    return dp[index][rodLength] = max(pick, notPick);
}

int cutRodMemo(vector<int> &price)
{
    int n = price.size();

    vector<vector<int>> dp(n, vector<int>(n + 1, -1));

    return solveMemo(n - 1, n, price, dp);
}

// =====================================================
// TABULATION
// =====================================================

int cutRodTab(vector<int> &price)
{
    int n = price.size();

    vector<vector<int>> dp(n, vector<int>(n + 1, 0));

    // Base Case
    for (int rodLength = 0; rodLength <= n; rodLength++)
    {
        dp[0][rodLength] = rodLength * price[0];
    }

    // Build DP Table
    for (int index = 1; index < n; index++)
    {
        int pieceLength = index + 1;

        for (int rodLength = 0; rodLength <= n; rodLength++)
        {
            // Don't Cut
            int notPick = dp[index - 1][rodLength];

            // Cut
            int pick = INT_MIN;

            if (pieceLength <= rodLength)
            {
                pick = price[index] + dp[index][rodLength - pieceLength];
            }

            dp[index][rodLength] = max(pick, notPick);
        }
    }

    return dp[n - 1][n];
}

// =====================================================
// SPACE OPTIMIZATION
// =====================================================

int cutRodSpace(vector<int> &price)
{
    int n = price.size();

    vector<int> prev(n + 1, 0);

    // Base Case
    for (int rodLength = 0; rodLength <= n; rodLength++)
    {
        prev[rodLength] = rodLength * price[0];
    }

    for (int index = 1; index < n; index++)
    {
        vector<int> curr(n + 1, 0);

        int pieceLength = index + 1;

        for (int rodLength = 0; rodLength <= n; rodLength++)
        {
            // Don't Cut
            int notPick = prev[rodLength];

            // Cut
            int pick = INT_MIN;

            if (pieceLength <= rodLength)
            {
                pick = price[index] + curr[rodLength - pieceLength];
            }

            curr[rodLength] = max(pick, notPick);
        }

        prev = curr;
    }

    return prev[n];
}

// =====================================================
// DRIVER CODE
// =====================================================

int main()
{
    vector<int> price = {2, 5, 7, 8, 10};

    cout << "Recursion : "
         << cutRodRec(price)
         << endl;

    cout << "Memoization : "
         << cutRodMemo(price)
         << endl;

    cout << "Tabulation : "
         << cutRodTab(price)
         << endl;

    cout << "Space Optimization : "
         << cutRodSpace(price)
         << endl;

    return 0;
}