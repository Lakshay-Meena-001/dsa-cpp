#include <bits/stdc++.h>

using namespace std;

int solveRec(int n)
{
    if (n == 1)
    {
        return 1;
    }

    int ans = 0;

    for (int i = 1; i < n; i++)
    {
        int breakHere = i * (n - i);

        int furtherBreak = i * solveRec(n - i);

        ans = max(ans, max(breakHere, furtherBreak));
    }

    return ans;
}

int integerBreakRec(int n)
{
    return solveRec(n);
}

// Memoization

int solveMemo(int n, vector<int> &dp)
{
    if (n == 1)
    {
        return 1;
    }

    if (dp[n] != -1)
    {
        return dp[n];
    }
    int ans = 0;

    for (int i = 1; i < n; i++)
    {
        int breakHere = i * (n - i);

        int furtherBreak = i * solveMemo(n - i, dp);

        ans = max(ans, max(breakHere, furtherBreak));
    }

    return dp[n] = ans;
}

int integerBreakMemo(int n)
{
    vector<int> dp(n + 1, -1);
    return solveMemo(n, dp);
}

// Tabulation

int integerBreakTab(int n)
{
    vector<int> dp(n + 1, 0);

    dp[1] = 1;

    for (int target = 2; target < n; target++)
    {
        for (int j = 1; j < target; j++)
        {
            int breakHere = j * (target - j);
            int furtherBreak = j * dp[target - j];
            dp[target] = max(dp[target], max(breakHere, furtherBreak));
        }
    }
    return dp[n];
}

int main()
{
    int n = 10;

    cout << "Recursion          : "
         << integerBreakRec(n)
         << "\n";

    cout << "Memoization        : "
         << integerBreakMemo(n)
         << "\n";

    cout << "Tabulation         : "
         << integerBreakTab(n)
         << "\n";

    return 0;
}