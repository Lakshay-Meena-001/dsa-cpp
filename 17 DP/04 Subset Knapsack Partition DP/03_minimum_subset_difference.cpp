#include <bits/stdc++.h>
using namespace std;

// =====================================================
// RECURSION
// =====================================================

// index  -> Current index
// currSum -> Sum of first subset till now
// totalSum -> Total sum of array

int solveRec(int index, int currSum, int totalSum, vector<int> &arr)
{
    // All elements processed
    if (index == arr.size())
    {
        int subset1 = currSum;
        int subset2 = totalSum - currSum;

        return abs(subset1 - subset2);
    }

    // Pick current element
    int pick = solveRec(index + 1, currSum + arr[index], totalSum, arr);

    // Don't Pick current element
    int notPick = solveRec(index + 1, currSum, totalSum, arr);

    return min(pick, notPick);
}

int minimumDifferenceRec(vector<int> &arr)
{
    int totalSum = 0;

    for (int num : arr)
    {
        totalSum += num;
    }

    return solveRec(0, 0, totalSum, arr);
}

// =====================================================
// MEMOIZATION
// =====================================================

int solveMemo(int index, int currSum, int totalSum, vector<int> &arr, vector<vector<int>> &dp)
{
    if (index == arr.size())
    {
        int subset1 = currSum;
        int subset2 = totalSum - currSum;

        return abs(subset1 - subset2);
    }

    if (dp[index][currSum] != -1)
    {
        return dp[index][currSum];
    }

    int pick = solveMemo(index + 1, currSum + arr[index], totalSum, arr, dp);

    int notPick = solveMemo(index + 1, currSum, totalSum, arr, dp);

    return dp[index][currSum] = min(pick, notPick);
}

int minimumDifferenceMemo(vector<int> &arr)
{
    int totalSum = 0;

    for (int num : arr)
    {
        totalSum += num;
    }

    int n = arr.size();

    vector<vector<int>> dp(n, vector<int>(totalSum + 1, -1));

    return solveMemo(0, 0, totalSum, arr, dp);
}
// =====================================================
// TABULATION
// =====================================================

int minimumDifferenceTab(vector<int> &arr)
{
    int n = arr.size();

    int totalSum = 0;

    for (int num : arr)
    {
        totalSum += num;
    }

    vector<vector<bool>> dp(n, vector<bool>(totalSum + 1, false));

    // Sum = 0 is always possible
    for (int index = 0; index < n; index++)
    {
        dp[index][0] = true;
    }

    // Base Case
    if (arr[0] <= totalSum)
    {
        dp[0][arr[0]] = true;
    }

    // Build DP Table
    for (int index = 1; index < n; index++)
    {
        for (int target = 1; target <= totalSum; target++)
        {
            bool notPick = dp[index - 1][target];

            bool pick = false;

            if (arr[index] <= target)
            {
                pick = dp[index - 1][target - arr[index]];
            }

            dp[index][target] = pick || notPick;
        }
    }

    int mini = INT_MAX;

    // Check every possible subset sum
    for (int s1 = 0; s1 <= totalSum / 2; s1++)
    {
        if (dp[n - 1][s1])
        {
            int s2 = totalSum - s1;

            mini = min(mini, abs(s2 - s1));
        }
    }

    return mini;
}

// =====================================================
// SPACE OPTIMIZATION
// =====================================================

int minimumDifferenceSpace(vector<int> &arr)
{
    int n = arr.size();

    int totalSum = 0;

    for (int num : arr)
    {
        totalSum += num;
    }

    vector<bool> prev(totalSum + 1, false);

    prev[0] = true;

    if (arr[0] <= totalSum)
    {
        prev[arr[0]] = true;
    }

    for (int index = 1; index < n; index++)
    {
        vector<bool> curr(totalSum + 1, false);

        curr[0] = true;

        for (int target = 1; target <= totalSum; target++)
        {
            bool notPick = prev[target];

            bool pick = false;

            if (arr[index] <= target)
            {
                pick = prev[target - arr[index]];
            }

            curr[target] = pick || notPick;
        }

        prev = curr;
    }

    int mini = INT_MAX;

    for (int s1 = 0; s1 <= totalSum / 2; s1++)
    {
        if (prev[s1])
        {
            int s2 = totalSum - s1;

            mini = min(mini, abs(s2 - s1));
        }
    }

    return mini;
}

// =====================================================
// DRIVER CODE
// =====================================================

int main()
{
    vector<int> arr = {1, 2, 3, 9};

    cout << "Recursion : "
         << minimumDifferenceRec(arr)
         << endl;

    cout << "Memoization : "
         << minimumDifferenceMemo(arr)
         << endl;

    cout << "Tabulation : "
         << minimumDifferenceTab(arr)
         << endl;

    cout << "Space Optimization : "
         << minimumDifferenceSpace(arr)
         << endl;

    return 0;
}