#include <bits/stdc++.h>

using namespace std;

int climbRec(int n)
{
    if (n == 0)
    {
        return 1;
    }
    if (n == 1)
    {
        return 1;
    }
    return climbRec(n - 1) + climbRec(n - 2);
}

int solveMemo(int n, vector<int> &dp)
{
    if (n == 0)
    {
        return 1;
    }
    if (n == 1)
    {
        return 1;
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }
    return dp[n] = solveMemo(n - 1, dp) + solveMemo(n - 2, dp);
}

int climbMemo(int n)
{
    vector<int> dp(n + 1, -1);
    return solveMemo(n, dp);
}

int climbTab(int n)
{
    vector<int> dp(n + 1);
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

int climbSpace(int n)
{
    if (n == 0)
        return 1;

    int prev2 = 1;
    int prev1 = 1;

    for (int i = 2; i <= n; i++)
    {
        int curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}

int main()
{
    int n;

    cout << "Enter n : ";
    cin >> n;

    cout << "\nRecursion          : "
         << climbRec(n);

    cout << "\nMemoization        : "
         << climbMemo(n);

    cout << "\nTabulation         : "
         << climbTab(n);

    cout << "\nSpace Optimization : "
         << climbSpace(n);

    return 0;
}