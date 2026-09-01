#include <bits/stdc++.h>
using namespace std;

// recursion / optimization
int solveRec(int day, int last, vector<vector<int>> &points)
{
    if (day == 0)
    {
        int maxi = 0;

        for (int task = 0; task < 3; task++)
        {
            if (task != last)
            {
                maxi = max(maxi, points[0][task]);
            }
        }

        return maxi;

    }

    int maxi = 0;

    for (int task = 0; task < 3; task++)
    {
        if (task != last)
        { 
            //to day last hai koi bhi activity nahi ki hai to isliye 3 bheja koi restriction nahi hai rec possibilities generate kar raha hai har start k element se day 0 tak 
            int curr = points[day][task] + solveRec(day - 1, task, points);
            maxi = max(maxi, curr);
        }
    }

    return maxi;
}

int ninjaTrainingRec(vector<vector<int>> &points)
{
    int n = points.size();
    return solveRec(n - 1, 3, points);
}

// Memoixation
int solveMemo(int day, int last, vector<vector<int>> &points, vector<vector<int>> &dp)
{
    if (day == 0)
    {
        int maxi = 0;

        for (int task = 0; task < 3; task++)
        {
            if (task != last)
            {
                maxi = max(maxi, points[0][task]);
            }
        }

        return maxi;
    }

    if (dp[day][last] != -1)
    {
        return dp[day][last];
    }

    int maxi = 0;

    for (int task = 0; task < 3; task++)
    {
        if (task != last)
        {
            int curr = points[day][task] + solveMemo(day - 1, task, points, dp);
            maxi = max(maxi, curr);
        }
    }

    return dp[day][last] = maxi;
}

int ninjaTrainingMemo(vector<vector<int>> &points)
{
    int n = points.size();
    vector<vector<int>> dp(n, vector<int>(4, -1));
    return solveMemo(n - 1, 3, points, dp);
}

// tabulation
int ninjaTrainingTab(vector<vector<int>> &points)
{
    int n = points.size();

    vector<vector<int>> dp(n, vector<int>(4, 0));

    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][0], points[0][1]);
    dp[0][3] = max({points[0][0], points[0][1], points[0][2]});

    for (int day = 1; day < n; day++)
    {
        for (int last = 0; last < 4; last++)
        {
            dp[day][last] = 0;

            for (int task = 0; task < 3; task++)
            {
                if (task != last)
                {
                    int curr = points[day][task] + dp[day - 1][task];
                    dp[day][last] = max(dp[day][last], curr);
                }
            }
        }
    }
    return dp[n - 1][3];
}

// space optimization

int ninjaTrainingSpace(vector<vector<int>> &points)
{
    int n = points.size();

    vector<int> prev(4, 0);

    prev[0] = max(points[0][1], points[0][2]);
    prev[1] = max(points[0][0], points[0][2]);
    prev[2] = max(points[0][0], points[0][1]);
    prev[3] = max({points[0][0], points[0][1], points[0][2]});

    for (int day = 1; day < n; day++)
    {
        vector<int> curr(4, 0);

        for (int last = 0; last < 4; last++)
        {
            for (int task = 0; task < 3; task++)
            {
                if (task != last)
                {
                    curr[last] = max(curr[last], points[day][task] + prev[task]);
                }
            }

            prev = curr;
        }
    }
    
    return prev[3];
}

int main()
{
    vector<vector<int>> points =
        {
            {10, 40, 70},
            {20, 50, 80},
            {30, 60, 90}};

    cout << "Recursion          : "
         << ninjaTrainingRec(points)
         << "\n";

    cout << "Memoization        : "
         << ninjaTrainingMemo(points)
         << "\n";

    cout << "Tabulation         : "
         << ninjaTrainingTab(points)
         << "\n";

    cout << "Space Optimization : "
         << ninjaTrainingSpace(points)
         << "\n";

    return 0;
}
