#include <bits/stdc++.h>

using namespace std;

int solveRec(int index, vector<int> &days, vector<int> &costs)
{
    if (index >= days.size())
    {
        return 0;
    }

    // 1 day pass

    int option1 = costs[0] + solveRec(index + 1, days, costs);

    // 7 day pass

    int i = index;

    while (i < days.size() && days[i] < days[index] + 7)
    {
        i++;
    }

    int option2 = costs[1] + solveRec(i, days, costs);

    // 30 Days pass

    i = index;

    while (i < days.size() && days[i] < days[index] + 30)
    {
        i++;
    }

    int option3 = costs[2] + solveRec(i, days, costs);

    return min(option1, min(option2, option3));
}

int minCostTicketsRec(vector<int> &days, vector<int> &costs)
{
    return solveRec(0, days, costs);
}

// memoization

int solveMemo(int index, vector<int> &days, vector<int> &costs, vector<int> &dp)
{
    if (index >= days.size())
    {
        return 0;
    }

    if (dp[index] != -1)
    {
        return dp[index];
    }

    // 1 day pass

    int option1 = costs[0] + solveMemo(index + 1, days, costs, dp);

    // 7 day pass

    int i = index;

    while (i < days.size() && days[i] < days[index] + 7)
    {
        i++;
    }

    int option2 = costs[1] + solveMemo(i, days, costs, dp);

    // 30 Days pass

    i = index;

    while (i < days.size() && days[i] < days[index] + 30)
    {
        i++;
    }

    int option3 = costs[2] + solveMemo(i, days, costs, dp);

    return dp[index] = min(option1, min(option2, option3));
}

int minCostTicketsRec(vector<int> &days, vector<int> &costs)
{
    vector<int> dp(days.size(), -1);
    return solveMemo(0, days, costs, dp);
}

int minCostTicketsTab(vector<int> &days, vector<int> &costs)
{
    int n = days.size();

    vector<int> dp(n + 1, 0);

    dp[n] = 0;

    for (int index = n - 1; index >= 0; index--)
    {
        int option1 = costs[0] + dp[index + 1];

        int i = index;

        while (i < n && days[i] < days[index] + 7)
        {
            i++;
        }

        int option2 = costs[1] + dp[i];   

        i = index;

        while (i < n && days[i] < days[index] + 30)
        {
            i++;
        }

        int option3 = costs[2] + dp[i];

        dp[index] = min(option1, min(option2, option3));
    }

    return dp[0];
}