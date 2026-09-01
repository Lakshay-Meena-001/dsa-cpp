#include <bits/stdc++.h>

using namespace std;

int tribRec(int n)
{
    if (n == 0)
    {
        return 0;
    }
    if (n == 1 || n == 2)
    {
        return 1;
    }
    return tribRec(n - 1) +
           tribRec(n - 2) +
           tribRec(n - 3);
    ;
}

int solveMemo(int n, vector<int> &dp)
{
    if (n == 0)
    {
        return 0;
    }
    if (n == 1 || n == 2)
    {
        return 1;
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }
    return dp[n] =
               solveMemo(n - 1, dp) + solveMemo(n - 2, dp) + solveMemo(n - 3, dp);
}

int tribMemo(int n)
{
    vector<int> dp(n + 1, -1);
    return solveMemo(n, dp);
}

int tribTab(int n)
{
    if (n == 0)
    {
        return 0;
    }
    if (n == 1 || n == 2)
    {
        return 1;
    }

    vector<int> dp(n + 1);

    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;

    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 2];
    }

    return dp[n];
}

int tribSpace(int n)
{
    if (n == 0)
    {
        return 0;
    }
    if (n == 1 || n == 2)
    {
        return 1;
    }

    int prev3 = 0;
    int prev2 = 1;
    int prev1 = 1;

    for (int i = 3; i <= n; i++)
    {
        int curr = prev1 + prev2 + prev3;
        prev3 = prev2;
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
         << tribRec(n);

    cout << "\nMemoization        : "
         << tribMemo(n);

    cout << "\nTabulation         : "
         << tribTab(n);

    cout << "\nSpace Optimization : "
         << tribSpace(n);

    return 0;
}