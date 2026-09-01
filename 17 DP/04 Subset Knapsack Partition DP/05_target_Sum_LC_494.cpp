#include <bits/stdc++.h>
using namespace std;

// =====================================================
// RECURSION
// =====================================================

// index  -> Current index
// target -> Remaining target to achieve

int solveRec(int index, int target, vector<int> &nums)
{
    // Base Case
    if (index == 0)
    {
        // Special case when first element is 0
        if (target == 0 && nums[0] == 0)
        {
            return 2;
        }

        // Either take the element or don't take it
        if (target == 0 || target == nums[0])
        {
            return 1;
        }

        return 0;
    }

    // Don't Pick
    int notPick = solveRec(index - 1, target, nums);

    // Pick
    int pick = 0;

    if (nums[index] <= target)
    {
        pick = solveRec(index - 1, target - nums[index], nums);
    }

    return pick + notPick;
}

int findTargetSumWaysRec(vector<int> &nums, int target)
{
    int totalSum = accumulate(nums.begin(), nums.end(), 0);

    // Impossible case
    if (totalSum - target < 0 || (totalSum - target) % 2 != 0)
    {
        return 0;
    }

    int requiredSum = (totalSum - target) / 2;

    return solveRec(nums.size() - 1, requiredSum, nums);
}

// =====================================================
// MEMOIZATION
// =====================================================

int solveMemo(int index, int target, vector<int> &nums, vector<vector<int>> &dp)
{
    if (index == 0)
    {
        if (target == 0 && nums[0] == 0)
        {
            return 2;
        }

        if (target == 0 || target == nums[0])
        {
            return 1;
        }

        return 0;
    }

    if (dp[index][target] != -1)
    {
        return dp[index][target];
    }

    int notPick = solveMemo(index - 1, target, nums, dp);

    int pick = 0;

    if (nums[index] <= target)
    {
        pick = solveMemo(index - 1, target - nums[index], nums, dp);
    }

    return dp[index][target] = pick + notPick;
}

int findTargetSumWaysMemo(vector<int> &nums, int target)
{
    int totalSum = accumulate(nums.begin(), nums.end(), 0);

    if (totalSum - target < 0 || (totalSum - target) % 2 != 0)
    {
        return 0;
    }

    int requiredSum = (totalSum - target) / 2;

    int n = nums.size();

    vector<vector<int>> dp(n, vector<int>(requiredSum + 1, -1));

    return solveMemo(n - 1, requiredSum, nums, dp);
}
// =====================================================
// TABULATION
// =====================================================

int findTargetSumWaysTab(vector<int> &nums, int target)
{
    int totalSum = accumulate(nums.begin(), nums.end(), 0);

    // Impossible Case
    if (totalSum - target < 0 || (totalSum - target) % 2 != 0)
    {
        return 0;
    }

    int requiredSum = (totalSum - target) / 2;

    int n = nums.size();

    vector<vector<int>> dp(n, vector<int>(requiredSum + 1, 0));

    // ==========================
    // Base Case
    // ==========================

    // First element is zero
    if (nums[0] == 0)
    {
        dp[0][0] = 2;
    }
    else
    {
        dp[0][0] = 1;

        if (nums[0] <= requiredSum)
        {
            dp[0][nums[0]] = 1;
        }
    }

    // ==========================
    // Build DP Table
    // ==========================

    for (int index = 1; index < n; index++)
    {
        for (int currTarget = 0; currTarget <= requiredSum; currTarget++)
        {
            // Don't Pick
            int notPick = dp[index - 1][currTarget];

            // Pick
            int pick = 0;

            if (nums[index] <= currTarget)
            {
                pick = dp[index - 1][currTarget - nums[index]];
            }

            dp[index][currTarget] = pick + notPick;
        }
    }

    return dp[n - 1][requiredSum];
}

// =====================================================
// SPACE OPTIMIZATION
// =====================================================

int findTargetSumWaysSpace(vector<int> &nums, int target)
{
    int totalSum = accumulate(nums.begin(), nums.end(), 0);

    if (totalSum - target < 0 || (totalSum - target) % 2 != 0)
    {
        return 0;
    }

    int requiredSum = (totalSum - target) / 2;

    int n = nums.size();

    vector<int> prev(requiredSum + 1, 0);

    // ==========================
    // Base Case
    // ==========================

    if (nums[0] == 0)
    {
        prev[0] = 2;
    }
    else
    {
        prev[0] = 1;

        if (nums[0] <= requiredSum)
        {
            prev[nums[0]] = 1;
        }
    }

    // ==========================
    // DP
    // ==========================

    for (int index = 1; index < n; index++)
    {
        vector<int> curr(requiredSum + 1, 0);

        for (int currTarget = 0; currTarget <= requiredSum; currTarget++)
        {
            int notPick = prev[currTarget];

            int pick = 0;

            if (nums[index] <= currTarget)
            {
                pick = prev[currTarget - nums[index]];
            }

            curr[currTarget] = pick + notPick;
        }

        prev = curr;
    }

    return prev[requiredSum];
}

// =====================================================
// DRIVER CODE
// =====================================================

int main()
{
    vector<int> nums = {1, 1, 1, 1, 1};

    int target = 3;

    cout << "Recursion : "
         << findTargetSumWaysRec(nums,
                                 target)
         << endl;

    cout << "Memoization : "
         << findTargetSumWaysMemo(nums,
                                  target)
         << endl;

    cout << "Tabulation : "
         << findTargetSumWaysTab(nums,
                                 target)
         << endl;

    cout << "Space Optimization : "
         << findTargetSumWaysSpace(nums,
                                   target)
         << endl;

    return 0;
}