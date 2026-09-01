#include <bits/stdc++.h>
using namespace std;

// =====================================================
// RECURSION
// =====================================================

// index  -> Current index
// target -> Remaining target to achieve

bool solveRec(int index, int target, vector<int> &nums)
{
    // Target achieved
    if (target == 0)
    {
        return true;
    }

    // Only first element left
    if (index == 0)
    {
        return nums[0] == target;
    }

    // Don't Pick current element
    bool notPick = solveRec(index - 1, target, nums);

    // Pick current element
    bool pick = false;

    if (nums[index] <= target)
    {
        pick = solveRec(index - 1, target - nums[index], nums);
    }

    return pick || notPick;
}

bool canPartitionRec(vector<int> &nums)
{
    int n = nums.size();

    // Total Sum
    int totalSum = 0;

    for (int num : nums)
    {
        totalSum += num;
    }

    // Odd sum can never be equally partitioned
    if (totalSum % 2 != 0)
    {
        return false;
    }

    int target = totalSum / 2;

    return solveRec(n - 1, target, nums);
}

// =====================================================
// MEMOIZATION
// =====================================================

bool solveMemo(int index, int target, vector<int> &nums, vector<vector<int>> &dp)
{
    if (target == 0)
    {
        return true;
    }

    if (index == 0)
    {
        return nums[0] == target;
    }

    if (dp[index][target] != -1)
    {
        return dp[index][target];
    }

    bool notPick = solveMemo(index - 1, target, nums, dp);

    bool pick = false;

    if (nums[index] <= target)
    {
        pick = solveMemo(index - 1, target - nums[index], nums, dp);
    }

    return dp[index][target] = pick || notPick;
}

bool canPartitionMemo(vector<int> &nums)
{
    int n = nums.size();

    int totalSum = 0;

    for (int num : nums)
    {
        totalSum += num;
    }

    if (totalSum % 2 != 0)
    {
        return false;
    }

    int target = totalSum / 2;

    vector<vector<int>> dp(n, vector<int>(target + 1, -1));

    return solveMemo(n - 1, target, nums, dp);
}
// =====================================================
// TABULATION
// =====================================================

bool canPartitionTab(vector<int> &nums)
{
    int n = nums.size();

    // Calculate Total Sum
    int totalSum = 0;

    for (int num : nums)
    {
        totalSum += num;
    }

    // Odd sum cannot be equally partitioned
    if (totalSum % 2 != 0)
    {
        return false;
    }

    int target = totalSum / 2;

    vector<vector<bool>> dp(n, vector<bool>(target + 1, false));

    // Target 0 is always possible
    for (int index = 0; index < n; index++)
    {
        dp[index][0] = true;
    }

    // Base Case
    if (nums[0] <= target)
    {
        dp[0][nums[0]] = true;
    }

    // Build DP Table
    for (int index = 1; index < n; index++)
    {
        for (int currTarget = 1;currTarget <= target;currTarget++)
        {
            // Don't Pick
            bool notPick =dp[index - 1][currTarget];

            // Pick
            bool pick = false;

            if (nums[index] <= currTarget)
            {
                pick =dp[index - 1][currTarget - nums[index]];
            }

            dp[index][currTarget] =pick || notPick;
        }
    }

    return dp[n - 1][target];
}

// =====================================================
// SPACE OPTIMIZATION
// =====================================================

bool canPartitionSpace(vector<int> &nums)
{
    int n = nums.size();

    int totalSum = 0;

    for (int num : nums)
    {
        totalSum += num;
    }

    if (totalSum % 2 != 0)
    {
        return false;
    }

    int target = totalSum / 2;

    vector<bool> prev(target + 1, false);

    prev[0] = true;

    if (nums[0] <= target)
    {
        prev[nums[0]] = true;
    }

    for (int index = 1;
         index < n;
         index++)
    {
        vector<bool> curr(target + 1, false);

        curr[0] = true;

        for (int currTarget = 1;
             currTarget <= target;
             currTarget++)
        {
            // Don't Pick
            bool notPick =
                prev[currTarget];

            // Pick
            bool pick = false;

            if (nums[index] <= currTarget)
            {
                pick =
                    prev[currTarget - nums[index]];
            }

            curr[currTarget] =
                pick || notPick;
        }

        prev = curr;
    }

    return prev[target];
}

// =====================================================
// DRIVER CODE
// =====================================================

int main()
{
    vector<int> nums = {1, 5, 11, 5};

    cout << boolalpha;

    cout << "Recursion : "
         << canPartitionRec(nums)
         << endl;

    cout << "Memoization : "
         << canPartitionMemo(nums)
         << endl;

    cout << "Tabulation : "
         << canPartitionTab(nums)
         << endl;

    cout << "Space Optimization : "
         << canPartitionSpace(nums)
         << endl;

    return 0;
}