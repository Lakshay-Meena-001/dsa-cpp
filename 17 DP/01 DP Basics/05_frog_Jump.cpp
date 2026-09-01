#include <bits/stdc++.h>

using namespace std;

int solveRec(int index, vector<int> &heights)
{
    if (index == 0)
    {
        return 0;
    }
    
    int oneJump = solveRec(index - 1, heights) + abs(heights[index] - heights[index - 1]);

    int twoJump = INT_MAX;

    if (index > 1)
    {
        twoJump = solveRec(index - 2, heights) + abs(heights[index] - heights[index - 2]);
    }

    return min(oneJump, twoJump);
}

int frogJumpRec(vector<int> &heights)
{
    int n = heights.size();
    return solveRec(n - 1, heights);
}

int solveMemo(int index, vector<int> &heights, vector<int> &dp)
{
    if (index == 0)
    {
        return 0;
    }

    if (dp[index] != -1)
    {
        return dp[index];
    }

    int oneJump = solveMemo(index - 1, heights, dp) + abs(heights[index] - heights[index - 1]);

    int twoJump = INT_MAX;

    if (index > 1)
    {
        twoJump = solveMemo(index - 2, heights, dp) + abs(heights[index] - heights[index - 2]);
    }

    return dp[index] = min(oneJump, twoJump);
}

int frogJumpMemo(vector<int> &heights)
{
    int n = heights.size();
    vector<int> dp(n, -1);
    return solveMemo(n - 1, heights, dp);
}

int frogJumpTab(vector<int> &heights)
{
    int n = heights.size();
    vector<int> dp(n);

    dp[0] = 0;

    for (int index = 1; index < n; index++)
    {
        int oneJump = dp[index - 1] + abs(heights[index] - heights[index - 1]);
        int twoJump = INT_MAX;
        if (index > 1)
        {
            twoJump = dp[index - 2] + abs(heights[index] - heights[index - 2]);
        }
        dp[index] = min(oneJump, twoJump);
    }
    return dp[n - 1];
}

int frogJumpSpace(vector<int> &heights)
{
    int n = heights.size();
    int prev2 = 0;
    int prev1 = 0;
    for (int index = 1; index < n; index++)
    {
        int oneJump = prev1 + abs(heights[index] - heights[index - 1]);
        int twoJump = INT_MAX;
        if (index > 1)
        {
            twoJump = prev2 + abs(heights[index] - heights[index - 2]);
        }
        int curr = min(oneJump, twoJump);
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}
int main()
{
    vector<int> height = {30, 10, 60, 10, 60, 50};

    cout << "Recursion          : "
         << frogJumpRec(height) << "\n";

    cout << "Memoization        : "
         << frogJumpMemo(height) << "\n";

    cout << "Tabulation         : "
         << frogJumpTab(height) << "\n";

    cout << "Space Optimization : "
         << frogJumpSpace(height) << "\n";

    return 0;
}