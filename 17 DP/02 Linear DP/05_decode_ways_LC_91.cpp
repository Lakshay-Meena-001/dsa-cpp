#include <bits/stdc++.h>

using namespace std;

int solveRec(int index, string &s)
{
    int n = s.size();

    //matlab ki string k lsat element tak pahunch gye to ek way complete ho gay ahai 
    if (index == n)
    {
        return 1;
    }

    // beech m kahi 0 aa gay a0 se start nahi hog a
    if (s[index] == '0')
    {
        return 0;
    }

    int ways = 0;

    //sirf abhi ek character liya pehle or aage s eans maang liya 
    ways += solveRec(index + 1, s);

    //ab do character liye 
    if (index + 1 < n && (s[index] == '1' || s[index] == '2' && s[index + 1] <= '6'))
    {
        return ways + solveRec(index + 2, s);
    }

    return ways;
}

int numDecodingsRec(string &s)
{
    return solveRec(0, s);
}

int solveMemo(int index, string &s, vector<int> &dp)
{
    int n = s.size();
    if (index == n)
    {
        return 1;
    }

    if (s[index] == '0')
    {
        return 0;
    }

    int ways = 0;

    if (dp[index] != -1)
    {
        return dp[index];
    }

    ways += solveMemo(index + 1, s, dp);

    if (index + 1 < n && (s[index] == '1' || s[index] == '2' && s[index + 1] <= '6'))
    {
        return ways + solveMemo(index + 2, s, dp);
    }

    return dp[index] = ways;
}

int numDecodingsMemo(string &s)
{
    int n = s.size();
    vector<int> dp(n, -1);
    return solveMemo(0, s, dp);
}

int numDecodingsTab(string &s)
{
    int n = s.size();

    vector<int> dp(n + 1, 0);

    dp[n] = 1;

    for (int index = n - 1; index >= 0; index--)
    {
        if (s[index] == '0')
        {
            dp[index] = 0;
            continue;
        }

        int oneDigit = dp[index + 1];
        int secondDigit = 0;

        if (index + 1 < n && (s[index] == '1' || s[index] == '2' && s[index + 1] <= '6'))
        {
            secondDigit = dp[index + 2];
        }

        dp[index] = oneDigit + secondDigit;
    }
    return dp[0];
}

// space Optimization
int numDecodingsSpace(string &s)
{
    int n = s.size();

    int next2 = 1; // dp[n]
    int next1 = 0; // dp[n-1] calculated initially

    for (int index = n - 1; index >= 0; index--)
    {
        int current = 0;

        if (s[index] != '0')
        {
            int oneDigit = next2;
            int secondDigit = 0;

            if (index + 1 < n && (s[index] == '1' || s[index] == '2' && s[index + 1] <= '6'))
            {
                secondDigit = next1;
            }

            current = oneDigit + secondDigit;
        }

        next1 = next2;
        next2 = current;
    }

    return next2;
}

int main()
{
    string s = "226";

    cout << "Recursion          : "
         << numDecodingsRec(s)
         << "\n";

    cout << "Memoization        : "
         << numDecodingsMemo(s)
         << "\n";

    cout << "Tabulation         : "
         << numDecodingsTab(s)
         << "\n";

    cout << "Space Optimization : "
         << numDecodingsSpace(s)
         << "\n";

    return 0;
}