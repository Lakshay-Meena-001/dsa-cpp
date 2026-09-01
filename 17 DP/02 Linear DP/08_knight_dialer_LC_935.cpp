#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> moves = {
    {4, 6},    // 0
    {6, 8},    // 1
    {7, 9},    // 2
    {4, 8},    // 3
    {0, 3, 9}, // 4
    {},        // 5
    {0, 1, 7}, // 6
    {2, 6},    // 7
    {1, 3},    // 8
    {2, 4}     // 9
};

const int MOD = 1e9 + 7;

long long solveRec(int digit, int remaining)
{
    if (remaining == 0)
    {
        return 1; // found a valid number
    }

    long long count = 0;

    for (int nextDigit : moves[digit])
    {
        count = (count + solveRec(nextDigit, remaining - 1)) % MOD;
    }

    return count;
}

int knightDialerRec(int n)
{
    long long totalCount = 0;

    for (int digit = 0; digit <= 9; digit++)
    {
        totalCount = (totalCount + solveRec(digit, n - 1)) % MOD;
    }

    return totalCount;
}

// memoization

long long solveMemo(int digit, int remaining, vector<vector<long long>> &dp)
{
    if (remaining == 0)
    {
        return 1; // found a valid number
    }

    if (dp[digit][remaining] != -1)
    {
        return dp[digit][remaining];
    }

    long long count = 0;

    for (int nextDigit : moves[digit])
    {
        count = (count + solveMemo(nextDigit, remaining - 1, dp)) % MOD;
    }

    return dp[digit][remaining] = count;
}

int knightDialerMemo(int n)
{
    vector<vector<long long>> dp(10, vector<long long>(n, -1));

    long long totalCount = 0;

    for (int digit = 0; digit <= 9; digit++)
    {
        totalCount = (totalCount + solveMemo(digit, n - 1, dp)) % MOD;
    }

    return totalCount;
}

// tabulation

int knightDialerTab(int n)
{
    vector<vector<long long>> dp(n, vector<long long>(10, 0));

    for (int digit = 0; digit <= 9; digit++)
    {
        dp[0][digit] = 1;
    }

    for (int len = 1; len < n; len++)
    {
        for (int digit = 0; digit <= 9; digit++)
        {
            for (int nextDigit : moves[digit])
            {
                dp[len][digit] = (dp[len][digit] + dp[len - 1][nextDigit]) % MOD;
            }
        }
    }

    long long ans = 0;

    for (int digit = 0; digit <= 9; digit++)
    {
        ans = (ans + dp[n - 1][digit]) % MOD;
    }

    return ans;
}

// space optimization

int knightDialerSpace(int n)
{
    vector<long long> prev(10, 1);

    for (int len = 1; len < n; len++)
    {
        vector<long long> curr(10, 0);

        for (int digit = 0; digit <= 9; digit++)
        {
            for (int nextDigit : moves[digit])
            {
                curr[digit] = (curr[digit] + prev[nextDigit]) % MOD;
            }
        }

        prev = curr;
    }

    long long ans = 0;

    for (long long ways : prev)
    {
        ans = (ans + ways) % MOD;
    }

    return ans;
}

int main()
{
    int n = 3;

    cout << "Recursion          : "
         << knightDialerRec(n)
         << "\n";

    cout << "Memoization        : "
         << knightDialerMemo(n)
         << "\n";

    cout << "Tabulation         : "
         << knightDialerTab(n)
         << "\n";

    cout << "Space Optimization : "
         << knightDialerSpace(n)
         << "\n";

    return 0;
}