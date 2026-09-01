#include <bits/stdc++.h>

using namespace std;

// Recursion
int solveRec(int index, vector<int> &points)
{
    if (index == 0)
    {
        return points[0];
    }
    if (index < 0)
    {
        return 0;
    }

    int pick = points[index] + solveRec(index - 2, points);

    int notPick = solveRec(index - 1, points);

    return max(pick, notPick);
}

int deleteAndEarnRec(vector<int> &nums)
{
    int maxNum = *max_element(nums.begin(), nums.end());

    vector<int> points(maxNum + 1, 0);

    // freq array 
    for (int num : nums)
    {
        points[num] = points[num]+ num;
    }

    return solveRec(maxNum, points);
}

// Memoization

int solveMemo(int index, vector<int> &points, vector<int> &dp)
{
    if (index == 0)
    {
        return points[0];
    }

    if (index < 0)
    {
        return 0;
    }

    if (dp[index] != -1)
    {
        return dp[index];
    }

    int pick = points[index] + solveMemo(index - 2, points, dp);

    int notPick = solveMemo(index - 1, points, dp);

    return dp[index] = max(pick, notPick);
}

int deleteAndEarnMemo(vector<int> &nums)
{
    int maxNum = *max_element(nums.begin(), nums.end());

    vector<int> points(maxNum + 1, 0);

    vector<int> dp(maxNum + 1, -1);

    for (int num : nums)
    {
        points[num] = points[num] + num;
    }

    return solveMemo(maxNum, points, dp);
}

// tabulation

int deleteAndEarnTab(vector<int> &nums)
{
    int maxNum = *max_element(nums.begin(), nums.end());

    vector<int> points(maxNum + 1, 0);

    for (int num : nums)
    {
        points[num] = points[num] + num;
    }

    vector<int> dp(maxNum + 1, 0);

    // start element bana liya ki agar 1 ho hua to whi ans hai 
    dp[0] = points[0];

    // ab second element bana liya ki agar size 1 se zyada hai to kyuki ya to 0 se lenge start ya 1 se jaha se maximum mile 
    if (maxNum >= 1)
    {
        dp[1] = max(points[0], points[1]);
    }

    for (int i = 2; i <= maxNum; i++)
    {
        int pick = points[i] + dp[i - 2];

        int notPick = dp[i - 1];

        dp[i] = max(pick, notPick);
    }

    return dp[maxNum];
}

// space optimization
int deleteAndEarnSpace(vector<int> &nums)
{
    int maxNum = *max_element(nums.begin(), nums.end());

    vector<int> points(maxNum + 1, 0);

    for (int num : nums)
    {
        points[num] += num;
    }

    int prev2 = points[0];

    int prev1 = (maxNum >= 1) ? max(points[0], points[1]) : points[0];

    for (int i = 2; i <= maxNum; i++)
    {
        int pick = points[i] + prev2;

        int notPick = prev1;

        int curr = max(pick, notPick);

        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}

int main()
{
    vector<int> nums =
        {3, 4, 2};

    cout << "Recursion          : "
         << deleteAndEarnRec(nums)
         << "\n";

    cout << "Memoization        : "
         << deleteAndEarnMemo(nums)
         << "\n";

    cout << "Tabulation         : "
         << deleteAndEarnTab(nums)
         << "\n";

    cout << "Space Optimization : "
         << deleteAndEarnSpace(nums)
         << "\n";

    return 0;
}