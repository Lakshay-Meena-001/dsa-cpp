#include <bits/stdc++.h>
using namespace std;

// =====================================================
// RECURSION
// =====================================================

// index  -> Current index
// target -> Remaining target to achieve

bool solveRec(int index, int target, vector<int> &arr)
{
    // Target achieved
    if (target == 0)
    {
        return true;
    }

    // Only first element left
    if (index == 0)
    {
        return arr[0] == target;
    }

    // Don't Pick
    bool notPick = solveRec(index - 1, target, arr);

    // Pick
    bool pick = false;

    if (arr[index] <= target)
    {
        pick = solveRec(index - 1, target - arr[index], arr);
    }

    return pick || notPick;
}

bool subsetSumToKRec(vector<int> &arr, int target)
{
    int n = arr.size();

    return solveRec(n - 1, target, arr);
}

// =====================================================
// MEMOIZATION
// =====================================================

bool solveMemo(int index, int target, vector<int> &arr, vector<vector<int>> &dp)
{
    if (target == 0)
    {
        return true;
    }

    if (index == 0)
    {
        return arr[0] == target;
    }

    if (dp[index][target] != -1)
    {
        return dp[index][target];
    }

    bool notPick = solveMemo(index - 1, target, arr, dp);

    bool pick = false;

    if (arr[index] <= target)
    {
        pick = solveMemo(index - 1, target - arr[index], arr, dp);
    }

    return dp[index][target] = pick || notPick;
}

bool subsetSumToKMemo(vector<int> &arr, int target)
{
    int n = arr.size();

    vector<vector<int>> dp(n, vector<int>(target + 1, -1));

    return solveMemo(n - 1, target, arr, dp);
}

// =====================================================
// TABULATION
// =====================================================

bool subsetSumToKTab(vector<int> &arr, int target)
{
    int n = arr.size();

    vector<vector<bool>> dp(n, vector<bool>(target + 1, false));

    // Target = 0 is always possible
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = true;
    }

    // Base Case
    if (arr[0] <= target)
    {
        dp[0][arr[0]] = true;
    }

    // Build table
    for (int index = 1; index < n; index++)
    {
        for (int currTarget = 1; currTarget <= target; currTarget++)
        {
            bool notPick = dp[index - 1][currTarget];

            bool pick = false;

            if (arr[index] <= currTarget)
            {
                pick = dp[index - 1][currTarget - arr[index]];
            }

            dp[index][currTarget] = pick || notPick;
        }
    }
    return dp[n - 1][target];
}

// =====================================================
// SPACE OPTIMIZATION
// =====================================================

bool subsetSumToKSpace(vector<int> &arr, int target)
{
    int n = arr.size();

    vector<bool> prev(target + 1, false);

    prev[0] = true;

    if (arr[0] <= target)
    {
        prev[arr[0]] = true;
    }

    for (int index = 1; index < n; index++)
    {
        vector<bool> curr(target + 1, false);

        curr[0] = true;

        for (int currTarget = 1; currTarget <= target; currTarget++)
        {
            bool notPick = prev[currTarget];

            bool pick = false;

            if (arr[index] <= currTarget)
            {
                pick = prev[currTarget - arr[index]];
            }

            curr[currTarget] = pick || notPick;
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
    vector<int> arr = {1, 2, 3, 4};

    int target = 4;

    cout << "Recursion : "
         << subsetSumToKRec(arr, target)
         << endl;

    cout << "Memoization : "
         << subsetSumToKMemo(arr, target)
         << endl;

    cout << "Tabulation : "
         << subsetSumToKTab(arr, target)
         << endl;

    cout << "Space Optimization : "
         << subsetSumToKSpace(arr, target)
         << endl;

    return 0;
}