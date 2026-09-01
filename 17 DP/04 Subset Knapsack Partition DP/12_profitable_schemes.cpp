#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

// =====================================================
// RECURSION
// =====================================================

// index  -> Current Crime Index
// members -> Remaining Members
// profit -> Remaining Profit Needed

int solveRec(int index, int members, int profit, int minProfit, vector<int> &group, vector<int> &profits)
{
    // All crimes processed
    if (index == group.size())
    {
        if (profit >= minProfit)
        {
            return 1;
        }

        return 0;
    }

    // Don't Pick
    int notPick = solveRec(index + 1, members, profit, minProfit, group, profits);

    // Pick
    int pick = 0;

    if (group[index] <= members)
    {
        pick = solveRec(index + 1, members - group[index], profit + profits[index], minProfit, group, profits);
    }

    return (pick + notPick) % MOD;
}

// Wrapper
int profitableSchemesRec(int n, int minProfit, vector<int> &group, vector<int> &profits)
{
    return solveRec(0, n, 0, minProfit, group, profits);
}

// =====================================================
// MEMOIZATION
// =====================================================

int solveMemo(int index, int members, int profit, int minProfit, vector<int> &group, vector<int> &profits, vector<vector<vector<int>>> &dp)
{
    // Enough profit achieved
    profit = min(profit, minProfit);

    if (index == group.size())
    {
        return (profit >= minProfit);
    }

    if (dp[index][members][profit] != -1)
    {
        return dp[index][members][profit];
    }

    int notPick = solveMemo(index + 1, members, profit, minProfit, group, profits, dp);

    int pick = 0;

    if (group[index] <= members)
    {
        pick = solveMemo(index + 1, members - group[index], min(profit + profits[index], minProfit), minProfit, group, profits, dp);
    }

    return dp[index][members][profit] = (pick + notPick) % MOD;
}

int profitableSchemesMemo(int n, int minProfit, vector<int> &group, vector<int> &profits)
{
    int size = group.size();

    vector<vector<vector<int>>> dp(size, vector<vector<int>>(n + 1, vector<int>(minProfit + 1, -1)));

    return solveMemo(0, n, 0, minProfit, group, profits, dp);
}
// =====================================================
// TABULATION
// =====================================================

int profitableSchemesTab(int n, int minProfit, vector<int> &group, vector<int> &profits)
{
    int size = group.size();

    vector<vector<vector<int>>> dp(size + 1, vector<vector<int>>(n + 1, vector<int>(minProfit + 1, 0)));

    // ==========================
    // Base Case
    // ==========================

    for (int members = 0; members <= n; members++)
    {
        dp[size][members][minProfit] = 1;
    }

    // ==========================
    // Build DP Table
    // ==========================

    for (int index = size - 1; index >= 0; index--)
    {
        for (int members = 0; members <= n; members++)
        {
            for (int profit = 0; profit <= minProfit; profit++)
            {
                // Don't Pick
                int notPick = dp[index + 1][members][profit];

                // Pick
                int pick = 0;

                if (group[index] <= members)
                {
                    int newProfit = min(minProfit, profit + profits[index]);

                    pick = dp[index + 1][members - group[index]][newProfit];
                }

                dp[index][members][profit] = (pick + notPick) % MOD;
            }
        }
    }

    return dp[0][n][0];
}

// =====================================================
// SPACE OPTIMIZATION
// =====================================================

int profitableSchemesSpace(int n, int minProfit, vector<int> &group, vector<int> &profits)
{
    int size = group.size();

    vector<vector<int>> next(n + 1, vector<int>(minProfit + 1, 0));

    // Base Case
    for (int members = 0; members <= n; members++)
    {
        next[members][minProfit] = 1;
    }

    for (int index = size - 1; index >= 0; index--)
    {
        vector<vector<int>> curr(n + 1, vector<int>(minProfit + 1, 0));

        for (int members = 0;
             members <= n;
             members++)
        {
            for (int profit = 0; profit <= minProfit; profit++)
            {
                // Don't Pick
                int notPick = next[members][profit];

                // Pick
                int pick = 0;

                if (group[index] <= members)
                {
                    int newProfit = min(minProfit, profit + profits[index]);

                    pick = next[members - group[index]][newProfit];
                }

                curr[members][profit] = (pick + notPick) % MOD;
            }
        }

        next = curr;
    }

    return next[n][0];
}

// =====================================================
// DRIVER CODE
// =====================================================

int main()
{
    int n = 5;
    int minProfit = 3;

    vector<int> group = {2, 2};
    vector<int> profits = {2, 3};

    cout << "Recursion : "
         << profitableSchemesRec(
                n,
                minProfit,
                group,
                profits)
         << endl;

    cout << "Memoization : "
         << profitableSchemesMemo(
                n,
                minProfit,
                group,
                profits)
         << endl;

    cout << "Tabulation : "
         << profitableSchemesTab(
                n,
                minProfit,
                group,
                profits)
         << endl;

    cout << "Space Optimization : "
         << profitableSchemesSpace(
                n,
                minProfit,
                group,
                profits)
         << endl;

    return 0;
}