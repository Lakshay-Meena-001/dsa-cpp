#include <bits/stdc++.h>

using namespace std;

// recursion
int solveRec(int n)
{
    if (n == 0)
    {
        return 0;
    }

    int ans = INT_MAX;

    for (int i = 1; i * i <= n; i++)
    {
        int square = i * i;

        ans = min(ans, 1 + solveRec(n - square));
    }
    return ans;
}

int perfectSquare(int n)
{
    return solveRec(n);
}

// memoization
int solveMemo(int n, vector<int> &dp)
{
    if (n == 0)
    {
        return 0;
    }

    if (dp[n] != -1)
    {
        return dp[n];
    }

    int ans = INT_MAX;

    for (int i = 1; i * i < n; i++)
    {
        int square = i * i;

        ans = min(ans, 1 + solveRec(n - square));
    }

    return dp[n] = ans;
}

int perfectSquareMemo(int n)
{
    vector<int> dp(n + 1, -1);
    return solveMemo(n, dp);
}

int solvePerfectSquareTab(int n)
{
    vector<int> dp(n + 1, INT_MAX);

    dp[0] = 0;

    for (int target = 1; target <= n; target++)
    {
        for (int i = 1; i * i <= target; i++)
        {
            int square = i * i;
            dp[target] = min(dp[target], 1 + dp[target - square]);
        }
    }
    return dp[n];
}