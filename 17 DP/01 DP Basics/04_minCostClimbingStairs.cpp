#include <bits/stdc++.h>

using namespace std;

int solveRec(int i, vector<int> &cost)
{
    //  maan lo step 0 se start karte hai to sirf is step ki cost lagegi
    if (i == 0)
    {
        return cost[0];
    }

    //  maan lo step 1 se start karte hai to sirf is step ki cost lagegi
    if (i == 1)
    {
        return cost[1];
    }
    // abhi ki cost kya hai current or piche se jo minimum aayi hai i-1 ya i-2 step se 
    return cost[i] + min(solveRec(i - 1, cost), solveRec(i - 2, cost));
}

int minCostRec(vector<int> &cost)
{
    int n = cost.size();
    // cost calculate hogi stair n se aage jake to last se ek step baher nikal skte hai ya second last se isliye dono m se o min aaya
    return min(solveRec(n - 1, cost), solveRec(n - 2, cost));
}

int solveMemo(int i, vector<int> &cost, vector<int> &dp)
{
    if (i == 0)
    {
        return cost[0];
    }
    if (i == 1)
    {
        return cost[1];
    }
    if (dp[i] != -1)
    {
        return dp[i];
    }
    
    return dp[i] = cost[i] + min(solveMemo(i - 1, cost, dp), solveMemo(i - 2, cost, dp));
}

int minCostMemo(vector<int> &cost)
{
    int n = cost.size();
    vector<int> dp(n, -1);

    return min(solveMemo(n - 1, cost, dp), solveMemo(n - 2, cost, dp));
}

int minCostTab(vector<int> &cost)
{

    int n = cost.size();
    vector<int> dp(n);

    dp[0] = cost[0];
    dp[1] = cost[1];

    for (int i = 2; i < n; i++)
    {
        dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
    }

    return min(dp[n - 1], dp[n - 2]);
}

int minCostSpace(vector<int> &cost)
{
    int n = cost.size();
    int prev2 = cost[0];
    int prev1 = cost[1];

    for (int i = 2; i < n; i++)
    {
        int curr = cost[i] + min(prev2, prev1);
        prev2 = prev1;
        prev1 = curr;
    }
    return min(prev1, prev2);
}

int main()
{
    vector<int> cost = {10, 15, 20};

    cout << "Recursion          : "
         << minCostRec(cost) << "\n";

    cout << "Memoization        : "
         << minCostMemo(cost) << "\n";

    cout << "Tabulation         : "
         << minCostTab(cost) << "\n";

    cout << "Space Optimization : "
         << minCostSpace(cost) << "\n";

    return 0;
}
