#include <bits/stdc++.h>
using namespace std;

// =====================================================
// RECURSION
// =====================================================

// index  -> Current Item Index
// capacity -> Remaining Capacity

int solveRec(int index, int capacity, vector<int> &weight, vector<int> &value)
{
    // Base Case
    if (index == 0)
    {
        return (capacity / weight[0]) * value[0];
    }

    // Don't Pick
    int notPick = solveRec(index - 1, capacity, weight, value);

    // Pick
    int pick = INT_MIN;

    if (weight[index] <= capacity)
    {
        pick = value[index] + solveRec(index, capacity - weight[index], weight, value);
    }

    return max(pick, notPick);
}

int unboundedKnapsackRec(int capacity, vector<int> &weight, vector<int> &value)
{
    int n = weight.size();
    return solveRec(n - 1, capacity, weight, value);
}

// =====================================================
// MEMOIZATION
// =====================================================

int solveMemo(int index, int capacity, vector<int> &weight, vector<int> &value, vector<vector<int>> &dp)
{
    if (index == 0)
    {
        return (capacity / weight[0]) * value[0];
    }

    if (dp[index][capacity] != -1)
    {
        return dp[index][capacity];
    }

    int notPick = solveMemo(index - 1, capacity, weight, value, dp);

    int pick = INT_MIN;

    if (weight[index] <= capacity)
    {
        pick = value[index] + solveMemo(index, capacity - weight[index], weight, value, dp);
    }

    return dp[index][capacity] = max(pick, notPick);
}

int unboundedKnapsackMemo(int capacity, vector<int> &weight, vector<int> &value)
{
    int n = weight.size();

    vector<vector<int>> dp(n, vector<int>(capacity + 1, -1));

    return solveMemo(n - 1, capacity, weight, value, dp);
}
// =====================================================
// TABULATION
// =====================================================

int unboundedKnapsackTab(int capacity, vector<int> &weight, vector<int> &value)
{
    int n = weight.size();

    vector<vector<int>> dp(n, vector<int>(capacity + 1, 0));

    // Base Case
    for (int currCapacity = 0; currCapacity <= capacity; currCapacity++)
    {
        dp[0][currCapacity] = (currCapacity / weight[0]) * value[0];
    }

    // Build DP Table
    for (int index = 1; index < n; index++)
    {
        for (int currCapacity = 0; currCapacity <= capacity; currCapacity++)
        {
            // Don't Pick
            int notPick = dp[index - 1][currCapacity];

            // Pick
            int pick = INT_MIN;

            if (weight[index] <= currCapacity)
            {
                pick = value[index] + dp[index][currCapacity - weight[index]];
            }

            dp[index][currCapacity] = max(pick, notPick);
        }
    }

    return dp[n - 1][capacity];
}

// =====================================================
// SPACE OPTIMIZATION
// =====================================================

int unboundedKnapsackSpace(int capacity, vector<int> &weight, vector<int> &value)
{
    int n = weight.size();

    vector<int> prev(capacity + 1, 0);

    // Base Case
    for (int currCapacity = 0; currCapacity <= capacity; currCapacity++)
    {
        prev[currCapacity] = (currCapacity / weight[0]) * value[0];
    }

    for (int index = 1; index < n; index++)
    {
        vector<int> curr(capacity + 1, 0);

        for (int currCapacity = 0; currCapacity <= capacity; currCapacity++)
        {
            // Don't Pick
            int notPick = prev[currCapacity];

            // Pick
            int pick = INT_MIN;

            if (weight[index] <= currCapacity)
            {
                pick = value[index] + curr[currCapacity - weight[index]];
            }

            curr[currCapacity] = max(pick, notPick);
        }

        prev = curr;
    }

    return prev[capacity];
}

// =====================================================
// DRIVER CODE
// =====================================================

int main()
{
    vector<int> weight = {2, 4, 6};
    vector<int> value = {5, 11, 13};

    int capacity = 10;

    cout << "Recursion : "
         << unboundedKnapsackRec(capacity,
                                 weight,
                                 value)
         << endl;

    cout << "Memoization : "
         << unboundedKnapsackMemo(capacity,
                                  weight,
                                  value)
         << endl;

    cout << "Tabulation : "
         << unboundedKnapsackTab(capacity,
                                 weight,
                                 value)
         << endl;

    cout << "Space Optimization : "
         << unboundedKnapsackSpace(capacity,
                                   weight,
                                   value)
         << endl;

    return 0;
}