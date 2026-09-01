#include <bits/stdc++.h>

using namespace std;

int fibRec(int n)
{
    if (n <= 1)
    {
        return n;
    }
    return fibRec(n - 1) + fibRec(n - 2);
}

int solveMemo(int n, vector<int> &dp)
{
    if (n <= 1)
    {
        return n;
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }
    return dp[n] = solveMemo(n - 1, dp) + solveMemo(n - 2, dp);
}

int fibMemo(int n)
{
    vector<int> dp(n + 1, -1);
    return solveMemo(n, dp);
}

int fibTab(int n)
{
    if (n == 0)
    {
        return 0;
    }
    vector<int> dp(n + 1);
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

int fibSpace(int n)
{
    if (n == 0)
    {
        return 0;
    }

    int prev2 = 0;
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
         << fibRec(n);

    cout << "\nMemoization        : "
         << fibMemo(n);

    cout << "\nTabulation         : "
         << fibTab(n);

    cout << "\nSpace Optimization : "
         << fibSpace(n);

    return 0;
}