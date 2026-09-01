#include <bits/stdc++.h>

using namespace std;

int solveRec(int i, vector<int> &nums)
{
    if (i == 0)
    {
        return nums[0];
    }

    if (i < 0)
    {
        return 0;
    }

    int pick = nums[i] + solveRec(i - 2, nums);
    int notPick = solveRec(i - 1, nums);

    return max(pick, notPick);
}

int houseRobberRec(vector<int> &nums)
{
    int n = nums.size();
    return solveRec(n - 1, nums);
}

int solveMem(int i, vector<int> &nums, vector<int> &dp)
{
    if (i == 0)
    {
        return nums[0];
    }

    if (i < 0)
    {
        return 0;
    }

    if (dp[i] != -1)
    {
        return dp[i];
    }

    int pick = nums[i] + solveMem(i - 2, nums, dp);
    int notPick = solveMem(i - 1, nums, dp);

    dp[i] = max(pick, notPick);

    return dp[i];
}

int houseRobberRec(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n, -1);
    return solveMem(n - 1, nums, dp);
}

int solveTab(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n);
    dp[0] = nums[0];

    for (int i = 1; i < n; i++)
    {
        int pick = nums[i];
        if (i > 1)
        {
            pick = pick + dp[i - 2];
        }
        int notPick = dp[i - 1];

        dp[i] = max(pick, notPick);
    }

    return dp[n - 1];
}

int houseRobberSpace(vector<int> &nums)
{
    int n = nums.size();
    int prev2 = 0;
    int prev1 = nums[0];

    for (int i = 0; i < n; i++)
    {
        int pick = nums[i];
        if (i > 1)
        {
            pick = pick + prev2;
        }
        int notPick = prev1;

        int curr = max(pick, notPick);
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}