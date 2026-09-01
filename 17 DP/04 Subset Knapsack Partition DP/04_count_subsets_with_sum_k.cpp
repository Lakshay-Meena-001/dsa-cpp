#include <bits/stdc++.h>
using namespace std;

// =====================================================
// RECURSION
// =====================================================

// index  -> Current index
// target -> Remaining target

int solveRec(int index, int target, vector<int> &arr)
{
    // Target achieved
    if (target == 0)
    {
        return 1;
    }

    // Only first element left
    if (index == 0)
    {
        return (arr[0] == target);
    }

    // Don't Pick
    int notPick = solveRec(index - 1, target, arr);

    // Pick
    int pick = 0;

    if (arr[index] <= target)
    {
        pick = solveRec(index - 1, target - arr[index], arr);
    }

    return pick + notPick;
}

int countSubsetsRec(vector<int> &arr, int target)
{
    int n = arr.size();

    return solveRec(n - 1, target, arr);
}

// =====================================================
// MEMOIZATION
// =====================================================

int solveMemo(int index, int target, vector<int> &arr, vector<vector<int>> &dp)
{
    if (target == 0)
    {
        return 1;
    }

    if (index == 0)
    {
        return (arr[0] == target);
    }

    if (dp[index][target] != -1)
    {
        return dp[index][target];
    }

    int notPick = solveMemo(index - 1, target, arr, dp);

    int pick = 0;

    if (arr[index] <= target)
    {
        pick = solveMemo(index - 1, target - arr[index], arr, dp);
    }

    return dp[index][target] = pick + notPick;
}

int countSubsetsMemo(vector<int> &arr, int target)
{
    int n = arr.size();

    vector<vector<int>> dp(n, vector<int>(target + 1, -1));

    return solveMemo(n - 1, target, arr, dp);
}
// =====================================================
// TABULATION
// =====================================================

int countSubsetsTab(vector<int> &arr, int target)
{
    int n = arr.size();

    vector<vector<int>> dp(n, vector<int>(target + 1, 0));

    // Target = 0 can always be formed by taking nothing
    for (int index = 0; index < n; index++)
    {
        dp[index][0] = 1;
    }

    // Base Case
    if (arr[0] <= target)
    {
        dp[0][arr[0]] = 1;
    }

    // Build DP Table
    for (int index = 1; index < n; index++)
    {
        for (int currTarget = 1; currTarget <= target; currTarget++)
        {
            // Don't Pick
            int notPick = dp[index - 1][currTarget];

            // Pick
            int pick = 0;

            if (arr[index] <= currTarget)
            {
                pick = dp[index - 1][currTarget - arr[index]];
            }

            dp[index][currTarget] = pick + notPick;
        }
    }

    return dp[n - 1][target];
}

// =====================================================
// SPACE OPTIMIZATION
// =====================================================

int countSubsetsSpace(vector<int> &arr, int target)
{
    int n = arr.size();

    vector<int> prev(target + 1, 0);

    prev[0] = 1;

    if (arr[0] <= target)
    {
        prev[arr[0]] = 1;
    }

    for (int index = 1; index < n; index++)
    {
        vector<int> curr(target + 1, 0);

        curr[0] = 1;

        for (int currTarget = 1; currTarget <= target; currTarget++)
        {
            // Don't Pick
            int notPick = prev[currTarget];

            // Pick
            int pick = 0;

            if (arr[index] <= currTarget)
            {
                pick = prev[currTarget - arr[index]];
            }

            curr[currTarget] = pick + notPick;
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
    vector<int> arr = {1, 2, 2, 3};

    int target = 3;

    cout << "Recursion : "
         << countSubsetsRec(arr, target)
         << endl;

    cout << "Memoization : "
         << countSubsetsMemo(arr, target)
         << endl;

    cout << "Tabulation : "
         << countSubsetsTab(arr, target)
         << endl;

    cout << "Space Optimization : "
         << countSubsetsSpace(arr, target)
         << endl;

    return 0;
}