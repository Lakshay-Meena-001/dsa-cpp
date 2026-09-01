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
        // If amount can be formed using only first coin
        if (amount % coins[0] == 0)
        {
            return amount / coins[0];
        }

        return 1e9;
    }

    // Don't Pick
    int notPick = solveRec(index - 1, amount, coins);

    // Pick
    int pick = 1e9;

    if (coins[index] <= amount)
    {
        pick = 1 + solveRec(index, amount - coins[index], coins);
    }

    return min(pick, notPick);
}

int coinChangeRec(vector<int> &coins, int amount)
{
    int n = coins.size();

    int ans = solveRec(n - 1, amount, coins);

    if (ans >= 1e9)
    {
        return -1;
    }

    return ans;
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
            return amount / coins[0];
        }

        return 1e9;
    }

    if (dp[index][amount] != -1)
    {
        return dp[index][amount];
    }

    int notPick = solveMemo(index - 1, amount, coins, dp);

    int pick = 1e9;

    if (coins[index] <= amount)
    {
        pick = 1 + solveMemo(index, amount - coins[index], coins, dp);
    }

    return dp[index][amount] = min(pick, notPick);
}

int coinChangeMemo(vector<int> &coins, int amount)
{
    int n = coins.size();

    vector<vector<int>> dp(n, vector<int>(amount + 1, -1));

    int ans = solveMemo(n - 1, amount, coins, dp);

    if (ans >= 1e9)
    {
        return -1;
    }

    return ans;
}

// =====================================================
// TABULATION
// =====================================================

int coinChangeTab(vector<int> &coins, int amount)
{
    int n = coins.size();

    vector<vector<int>> dp(n, vector<int>(amount + 1, 0));

    // Base Case
    for (int currAmount = 0; currAmount <= amount; currAmount++)
    {
        if (currAmount % coins[0] == 0)
        {
            dp[0][currAmount] = currAmount / coins[0];
        }
        else
        {
            dp[0][currAmount] = 1e9;
        }
    }

    // Build DP Table
    for (int index = 1; index < n; index++)
    {
        for (int currAmount = 0; currAmount <= amount; currAmount++)
        {
            // Don't Pick
            int notPick = dp[index - 1][currAmount];

            // Pick
            int pick = 1e9;

            if (coins[index] <= currAmount)
            {
                pick = 1 + dp[index][currAmount - coins[index]];
            }

            dp[index][currAmount] = min(pick, notPick);
        }
    }

    if (dp[n - 1][amount] >= 1e9)
    {
        return -1;
    }

    return dp[n - 1][amount];
}

// =====================================================
// SPACE OPTIMIZATION
// =====================================================

int coinChangeSpace(vector<int> &coins, int amount)
{
    int n = coins.size();

    vector<int> prev(amount + 1, 0);

    // Base Case
    for (int currAmount = 0; currAmount <= amount; currAmount++)
    {
        if (currAmount % coins[0] == 0)
        {
            prev[currAmount] = currAmount / coins[0];
        }
        else
        {
            prev[currAmount] = 1e9;
        }
    }

    for (int index = 1; index < n; index++)
    {
        vector<int> curr(amount + 1, 0);

        for (int currAmount = 0; currAmount <= amount; currAmount++)
        {
            // Don't Pick
            int notPick = prev[currAmount];

            // Pick
            int pick = 1e9;

            if (coins[index] <= currAmount)
            {
                pick = 1 + curr[currAmount - coins[index]];
            }

            curr[currAmount] = min(pick, notPick);
        }

        prev = curr;
    }

    if (prev[amount] >= 1e9)
    {
        return -1;
    }

    return prev[amount];
}

// =====================================================
// DRIVER CODE
// =====================================================

int main()
{
    vector<int> coins = {1, 2, 5};

    int amount = 11;

    cout << "Recursion : "
         << coinChangeRec(coins, amount)
         << endl;

    cout << "Memoization : "
         << coinChangeMemo(coins, amount)
         << endl;

    cout << "Tabulation : "
         << coinChangeTab(coins, amount)
         << endl;

    cout << "Space Optimization : "
         << coinChangeSpace(coins, amount)
         << endl;

    return 0;
}