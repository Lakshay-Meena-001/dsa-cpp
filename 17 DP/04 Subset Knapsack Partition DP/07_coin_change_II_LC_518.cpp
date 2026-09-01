#include <bits/stdc++.h>
using namespace std;

// =====================================================
// RECURSION
// =====================================================

// index  -> Current Coin Index
// amount -> Remaining Amount

int solveRec(int index, int amount, vector<int> &coins)
{
    // Base Case
    if (index == 0)
    {
        // Amount can be formed using only first coin
        if (amount % coins[0] == 0)
        {
            return 1;
        }

        return 0;
    }

    // Don't Pick
    int notPick = solveRec(index - 1, amount, coins);

    // Pick
    int pick = 0;

    if (coins[index] <= amount)
    {
        pick = solveRec(index, amount - coins[index], coins);
    }

    return pick + notPick;
}

int changeRec(int amount, vector<int> &coins)
{
    int n = coins.size();

    return solveRec(n - 1, amount, coins);
}

// =====================================================
// MEMOIZATION
// =====================================================

int solveMemo(int index, int amount, vector<int> &coins, vector<vector<int>> &dp)
{
    if (index == 0)
    {
        if (amount % coins[0] == 0)
        {
            return 1;
        }

        return 0;
    }

    if (dp[index][amount] != -1)
    {
        return dp[index][amount];
    }

    int notPick = solveMemo(index - 1, amount, coins, dp);

    int pick = 0;

    if (coins[index] <= amount)
    {
        pick = solveMemo(index, amount - coins[index], coins, dp);
    }

    return dp[index][amount] = pick + notPick;
}

int changeMemo(int amount, vector<int> &coins)
{
    int n = coins.size();

    vector<vector<int>> dp(n, vector<int>(amount + 1, -1));

    return solveMemo(n - 1, amount, coins, dp);
}
// =====================================================
// TABULATION
// =====================================================

int changeTab(int amount, vector<int> &coins)
{

    int n = coins.size();

    vector<vector<unsigned long long>> dp(n, vector<unsigned long long>(amount + 1, 0));

    // Base Case
    for (int currAmount = 0; currAmount <= amount; currAmount++)
    {
        if (currAmount % coins[0] == 0)
        {
            dp[0][currAmount] = 1;
        }
    }

    // DP
    for (int index = 1; index < n; index++)
    {
        for (int currAmount = 0; currAmount <= amount; currAmount++)
        {
            unsigned long long notPick = dp[index - 1][currAmount];

            unsigned long long pick = 0;

            if (coins[index] <= currAmount)
            {
                pick = dp[index][currAmount - coins[index]];
            }

            dp[index][currAmount] = pick + notPick;
        }
    }

    return (int)dp[n - 1][amount];
}

// =====================================================
// SPACE OPTIMIZATION
// =====================================================

int changeSpace(int amount, vector<int> &coins)
{
    int n = coins.size();

    vector<int> prev(amount + 1, 0);

    // Base Case
    for (int currAmount = 0; currAmount <= amount; currAmount++)
    {
        if (currAmount % coins[0] == 0)
        {
            prev[currAmount] = 1;
        }
    }

    for (int index = 1;
         index < n;
         index++)
    {
        vector<int> curr(amount + 1, 0);

        for (int currAmount = 0; currAmount <= amount; currAmount++)
        {
            // Don't Pick
            int notPick = prev[currAmount];

            // Pick
            int pick = 0;

            if (coins[index] <= currAmount)
            {
                pick = curr[currAmount - coins[index]];
            }

            curr[currAmount] = pick + notPick;
        }

        prev = curr;
    }

    return prev[amount];
}

// =====================================================
// DRIVER CODE
// =====================================================

int main()
{
    vector<int> coins = {1, 2, 5};

    int amount = 5;

    cout << "Recursion : "
         << changeRec(amount,
                      coins)
         << endl;

    cout << "Memoization : "
         << changeMemo(amount,
                       coins)
         << endl;

    cout << "Tabulation : "
         << changeTab(amount,
                      coins)
         << endl;

    cout << "Space Optimization : "
         << changeSpace(amount,
                        coins)
         << endl;

    return 0;
}