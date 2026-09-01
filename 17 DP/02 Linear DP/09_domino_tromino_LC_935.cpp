#include <bits/stdc++.h>
using namespace std;

/*
========================================================
APPROACH 1 : RECURSION
========================================================
*/

const long long MOD = 1e9 + 7;

long long solveRec(int n)
{
    if (n == 0)
    {
        return 1;
    }

    if (n == 1)
    {
        return 1;
    }

    if (n == 2)
    {
        return 2;
    }

    return (2 * solveRec(n - 1) + solveRec(n - 3)) % MOD;
}

int numTilingsRec(int n)
{
    return solveRec(n);
}

/*
========================================================
APPROACH 2 : MEMOIZATION
========================================================
*/

long long solveMemo(int n,
                    vector<long long> &dp)
{
    if (n == 0)
    {
        return 1;
    }

    if (n == 1)
    {
        return 1;
    }

    if (n == 2)
    {
        return 2;
    }

    if (dp[n] != -1)
    {
        return dp[n];
    }

    return dp[n] = (2 * solveMemo(n - 1, dp) + solveMemo(n - 3, dp)) % MOD;
}

int numTilingsMemo(int n)
{
    vector<long long> dp(n + 1, -1);

    return solveMemo(n, dp);
}

/*
========================================================
APPROACH 3 : TABULATION
========================================================
*/

int numTilingsTab(int n)
{
    vector<long long> dp(n + 1, 0);

    dp[0] = 1;
    dp[1] = 1;

    if (n >= 2)
    {
        dp[2] = 2;
    }

    for (int i = 3; i <= n; i++)
    {
        dp[i] = (2 * dp[i - 1] + dp[i - 3]) % MOD;
    }

    return dp[n];
}

/*
========================================================
APPROACH 4 : SPACE OPTIMIZATION
========================================================
*/

int numTilingsSpace(int n)
{
    if (n == 0)
        return 1;

    if (n == 1)
        return 1;

    if (n == 2)
        return 2;

    long long prev3 = 1; // dp[0]
    long long prev2 = 1; // dp[1]
    long long prev1 = 2; // dp[2]

    for (int i = 3;
         i <= n;
         i++)
    {
        long long curr =
            (2 * prev1 +
             prev3) %
            MOD;

        prev3 = prev2;
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}

/*
========================================================
DRIVER CODE
========================================================
*/

int main()
{
    int n = 5;

    cout << "Recursion          : "
         << numTilingsRec(n)
         << "\n";

    cout << "Memoization        : "
         << numTilingsMemo(n)
         << "\n";

    cout << "Tabulation         : "
         << numTilingsTab(n)
         << "\n";

    cout << "Space Optimization : "
         << numTilingsSpace(n)
         << "\n";

    return 0;
}
