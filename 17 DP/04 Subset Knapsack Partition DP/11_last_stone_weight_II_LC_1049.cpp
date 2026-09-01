#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

// =====================================================
// RECURSION
// =====================================================

// index  -> Current Stone Index
// currSum -> Current Subset Sum
// totalSum -> Sum of all Stones

int solveRec(int index, int currSum, int totalSum, vector<int> &stones)
{
    // All stones processed
    if (index == stones.size())
    {
        int subset1 = currSum;
        int subset2 = totalSum - currSum;

        return abs(subset1 - subset2);
    }

    // Pick
    int pick = solveRec(index + 1, currSum + stones[index], totalSum, stones);

    // Don't Pick
    int notPick = solveRec(index + 1, currSum, totalSum, stones);

    return min(pick, notPick);
}

int lastStoneWeightIIRec(vector<int> &stones)
{
    int totalSum = 0;

    for (int stone : stones)
    {
        totalSum += stone;
    }

    return solveRec(0, 0, totalSum, stones);
}

// =====================================================
// MEMOIZATION
// =====================================================

int solveMemo(int index, int currSum, int totalSum, vector<int> &stones, vector<vector<int>> &dp)
{
    if (index == stones.size())
    {
        int subset1 = currSum;
        int subset2 = totalSum - currSum;

        return abs(subset1 - subset2);
    }

    if (dp[index][currSum] != -1)
    {
        return dp[index][currSum];
    }

    int pick = solveMemo(index + 1, currSum + stones[index], totalSum, stones, dp);

    int notPick = solveMemo(index + 1, currSum, totalSum, stones, dp);

    return dp[index][currSum] = min(pick, notPick);
}

int lastStoneWeightIIMemo(vector<int> &stones)
{
    int totalSum = 0;

    for (int stone : stones)
    {
        totalSum += stone;
    }

    int n = stones.size();

    vector<vector<int>> dp(n, vector<int>(totalSum + 1, -1));

    return solveMemo(0, 0, totalSum, stones, dp);
}
// =====================================================
// TABULATION
// =====================================================

int lastStoneWeightIITab(vector<int> &stones)
{
    int n = stones.size();

    int totalSum = 0;

    for (int stone : stones)
    {
        totalSum += stone;
    }

    vector<vector<bool>> dp(n, vector<bool>(totalSum + 1, false));

    // Sum = 0 is always possible
    for (int index = 0; index < n; index++)
    {
        dp[index][0] = true;
    }

    // Base Case
    if (stones[0] <= totalSum)
    {
        dp[0][stones[0]] = true;
    }

    // Build DP Table
    for (int index = 1; index < n; index++)
    {
        for (int target = 1; target <= totalSum; target++)
        {
            // Don't Pick
            bool notPick = dp[index - 1][target];

            // Pick
            bool pick = false;

            if (stones[index] <= target)
            {
                pick = dp[index - 1][target - stones[index]];
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

int lastStoneWeightIISpace(vector<int> &stones)
{
    int n = stones.size();

    int totalSum = 0;

    for (int stone : stones)
    {
        totalSum += stone;
    }

    vector<bool> prev(totalSum + 1, false);

    prev[0] = true;

    if (stones[0] <= totalSum)
    {
        prev[stones[0]] = true;
    }

    for (int index = 1; index < n; index++)
    {
        vector<bool> curr(totalSum + 1, false);

        curr[0] = true;

        for (int target = 1; target <= totalSum; target++)
        {
            // Don't Pick
            bool notPick = prev[target];

            // Pick
            bool pick = false;

            if (stones[index] <= target)
            {
                pick = prev[target - stones[index]];
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
    vector<int> stones = {2, 7, 4, 1, 8, 1};

    cout << "Recursion : "
         << lastStoneWeightIIRec(stones)
         << endl;

    cout << "Memoization : "
         << lastStoneWeightIIMemo(stones)
         << endl;

    cout << "Tabulation : "
         << lastStoneWeightIITab(stones)
         << endl;

    cout << "Space Optimization : "
         << lastStoneWeightIISpace(stones)
         << endl;

    return 0;
}