#include <bits/stdc++.h>

using namespace std;

int solveRec(int index, vector<int> &heights, int k)
{
    if (index == 0)
    {
        return 0;
    }
    
    int minCost = INT_MAX;

    for (int jump = 1; jump <= k; jump++)
    {
        if (index - jump >= 0)
        {
            int cost = solveRec(index - jump, heights, k) + abs(heights[index] - heights[index - jump]);
            minCost = min(minCost, cost);
        }
    }

    return minCost;
}

int frogJumpRec(vector<int> &heights, int k)
{
    int n = heights.size();
    return solveRec(n - 1, heights, k);
}

int solveMemo(int index, vector<int> &heights, int k, vector<int> &dp)
{
    if (index == 0)
    {
        return 0;
    }

    if (dp[index] != -1)
    {
        return dp[index];
    }

    int minCost = INT_MAX;

    for (int jump = 1; jump <= k; jump++)
    {
        if (index - jump >= 0)
        {
            int cost = solveMemo(index - jump, heights, k, dp) + abs(heights[index] - heights[index - jump]);
            minCost = min(minCost, cost);
        }
    }

    return dp[index] = minCost;
}

int frogJumpMemo(vector<int> &heights, int k)
{
    int n = heights.size();
    vector<int> dp(n, -1);
    return solveMemo(n - 1, heights, k, dp);
}

int frogJumpTab(vector<int> &heights, int k)
{
    int n = heights.size();

    vector<int> dp(n);

    dp[0] = 0;

    for (int index = 1; index < n; index++)
    {
        int minCost = INT_MAX;

        for (int jump = 1; jump <= k; jump++)
        {
            if (index - jump >= 0)
            {
                int cost = dp[index - jump] + abs(heights[index] - heights[index - jump]);
                minCost = min(minCost, cost);
            }
        }
        dp[index] = minCost;
    }
    return dp[n - 1];
}

int main()
{
    vector<int> height =
    {
        10,
        30,
        40,
        20
    };

    int k = 3;

    cout << "Recursion          : "
         << frogJumpRec(height, k)
         << "\n";

    cout << "Memoization        : "
         << frogJumpMemo(height, k)
         << "\n";

    cout << "Tabulation         : "
         << frogJumpTab(height, k)
         << "\n";

    return 0;
}