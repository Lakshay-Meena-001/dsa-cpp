#include <bits/stdc++.h>

using namespace std;

// Recursion
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

int robLinearRec(vector<int> &nums)
{
    int n = nums.size();
    return solveRec(n - 1, nums);
}

int houseRobber2Rec(vector<int> &nums)
{
    int n = nums.size();

    if (n == 1)
    {
        return nums[0];
    }
    vector<int> firstCase;
    vector<int> secondCase;

    for (int i = 0; i < n; i++)
    {
        if (i != 0)
        {
            firstCase.push_back(nums[i]);
        }
        if (i != n - 1)
        {

            secondCase.push_back(nums[i]);
        }
    }
    return max(robLinearRec(firstCase), robLinearRec(secondCase));
}

// Memoization

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

int robLinearMemo(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n, -1);
    return solveMem(n - 1, nums, dp);
}

int houseRobber2Memo(vector<int> &nums)
{
    int n = nums.size();

    if (n == 1)
    {
        return nums[0];
    }
    vector<int> firstCase;
    vector<int> secondCase;

    for (int i = 0; i < n; i++)
    {
        if (i != 0)
        {
            firstCase.push_back(nums[i]);
        }
        if (i != n - 1)
        {
            secondCase.push_back(nums[i]);
        }
    }
    return max(robLinearMemo(firstCase), robLinearMemo(secondCase));
}

// Tabulation

int robLinearTab(vector<int> &nums)
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

int houseRobber2Tab(vector<int> &nums)
{
    int n = nums.size();

    if (n == 1)
    {
        return nums[0];
    }
    vector<int> firstCase;
    vector<int> secondCase;

    for (int i = 0; i < n; i++)
    {
        if (i != 0)
        {
            firstCase.push_back(nums[i]);
        }
        if (i != n - 1)
        {

            secondCase.push_back(nums[i]);
        }
    }
    return max(robLinearTab(firstCase), robLinearTab(secondCase));
}

int robLinearSpace(vector<int> &nums)
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

int houseRobber2Space(vector<int> &nums)
{
    int n = nums.size();

    if (n == 1)
    {
        return nums[0];
    }
    vector<int> firstCase;
    vector<int> secondCase;

    for (int i = 0; i < n; i++)
    {
        if (i != 0)
        {
            firstCase.push_back(nums[i]);
        }
        if (i != n - 1)
        {

            secondCase.push_back(nums[i]);
        }
    }
    return max(robLinearSpace(firstCase), robLinearSpace(secondCase));
}

int main()
{
    vector<int> nums =
        {
            2,
            3,
            2};

    cout << "Recursion          : "
         << houseRobber2Rec(nums)
         << "\n";

    cout << "Memoization        : "
         << houseRobber2Memo(nums)
         << "\n";

    cout << "Tabulation         : "
         << houseRobber2Tab(nums)
         << "\n";

    cout << "Space Optimization : "
         << houseRobber2Space(nums)
         << "\n";

    return 0;
}