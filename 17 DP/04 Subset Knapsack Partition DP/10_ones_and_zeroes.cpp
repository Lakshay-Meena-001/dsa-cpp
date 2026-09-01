#include <bits/stdc++.h>
using namespace std;

// =====================================================
// RECURSION
// =====================================================

// index -> Current String Index
// zeros -> Remaining Zeroes Allowed
// ones  -> Remaining Ones Allowed

int solveRec(int index, int zeros, int ones, vector<string> &strs)
{
    // Base Case
    if (index == 0)
    {
        int zeroCount = 0;
        int oneCount = 0;

        for (char ch : strs[0])
        {
            if (ch == '0')
            {
                zeroCount++;
            }
            else
            {
                oneCount++;
            }
        }

        if (zeroCount <= zeros && oneCount <= ones)
        {
            return 1;
        }

        return 0;
    }

    // Don't Pick
    int notPick = solveRec(index - 1, zeros, ones, strs);

    // Count zeroes and ones of current string
    int zeroCount = 0;
    int oneCount = 0;

    for (char ch : strs[index])
    {
        if (ch == '0')
        {
            zeroCount++;
        }
        else
        {
            oneCount++;
        }
    }

    // Pick
    int pick = 0;

    if (zeroCount <= zeros && oneCount <= ones)
    {
        pick = 1 + solveRec(index - 1, zeros - zeroCount, ones - oneCount, strs);
    }

    return max(pick, notPick);
}

int findMaxFormRec(vector<string> &strs, int m, int n)
{
    return solveRec(strs.size() - 1, m, n, strs);
}

// =====================================================
// MEMOIZATION
// =====================================================

int solveMemo(int index, int zeros, int ones, vector<string> &strs, vector<vector<vector<int>>> &dp)
{
    if (index == 0)
    {
        int zeroCount = 0;
        int oneCount = 0;

        for (char ch : strs[0])
        {
            if (ch == '0')
            {
                zeroCount++;
            }
            else
            {
                oneCount++;
            }
        }

        if (zeroCount <= zeros && oneCount <= ones)
        {
            return 1;
        }

        return 0;
    }

    if (dp[index][zeros][ones] != -1)
    {
        return dp[index][zeros][ones];
    }

    int notPick = solveMemo(index - 1, zeros, ones, strs, dp);

    int zeroCount = 0;
    int oneCount = 0;

    for (char ch : strs[index])
    {
        if (ch == '0')
        {
            zeroCount++;
        }
        else
        {
            oneCount++;
        }
    }

    int pick = 0;

    if (zeroCount <= zeros && oneCount <= ones)
    {
        pick = 1 + solveMemo(index - 1, zeros - zeroCount, ones - oneCount, strs, dp);
    }

    return dp[index][zeros][ones] = max(pick, notPick);
}

int findMaxFormMemo(vector<string> &strs, int m, int n)
{
    int size = strs.size();

    vector<vector<vector<int>>> dp(size, vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));

    return solveMemo(size - 1, m, n, strs, dp);
}
// =====================================================
// TABULATION
// =====================================================

int findMaxFormTab(vector<string> &strs, int m, int n)
{
    int size = strs.size();

    vector<vector<vector<int>>> dp(size, vector<vector<int>>(m + 1, vector<int>(n + 1, 0)));

    // ==========================
    // Base Case
    // ==========================

    int zeroCount = 0;
    int oneCount = 0;

    for (char ch : strs[0])
    {
        if (ch == '0')
        {
            zeroCount++;
        }
        else
        {
            oneCount++;
        }
    }

    for (int zeros = 0; zeros <= m; zeros++)
    {
        for (int ones = 0; ones <= n; ones++)
        {
            if (zeroCount <= zeros && oneCount <= ones)
            {
                dp[0][zeros][ones] = 1;
            }
        }
    }

    // ==========================
    // Build DP Table
    // ==========================

    for (int index = 1; index < size; index++)
    {
        zeroCount = 0;
        oneCount = 0;

        for (char ch : strs[index])
        {
            if (ch == '0')
            {
                zeroCount++;
            }
            else
            {
                oneCount++;
            }
        }

        for (int zeros = 0; zeros <= m; zeros++)
        {
            for (int ones = 0; ones <= n; ones++)
            {
                // Don't Pick
                int notPick = dp[index - 1][zeros][ones];

                // Pick
                int pick = 0;

                if (zeroCount <= zeros && oneCount <= ones)
                {
                    pick = 1 + dp[index - 1][zeros - zeroCount][ones - oneCount];
                }

                dp[index][zeros][ones] = max(pick, notPick);
            }
        }
    }

    return dp[size - 1][m][n];
}

// =====================================================
// SPACE OPTIMIZATION
// =====================================================

int findMaxFormSpace(vector<string> &strs, int m, int n)
{
    int size = strs.size();

    vector<vector<int>> prev(m + 1, vector<int>(n + 1, 0));

    // ==========================
    // Base Case
    // ==========================

    int zeroCount = 0;
    int oneCount = 0;

    for (char ch : strs[0])
    {
        if (ch == '0')
        {
            zeroCount++;
        }
        else
        {
            oneCount++;
        }
    }

    for (int zeros = 0; zeros <= m; zeros++)
    {
        for (int ones = 0; ones <= n; ones++)
        {
            if (zeroCount <= zeros && oneCount <= ones)
            {
                prev[zeros][ones] = 1;
            }
        }
    }

    // ==========================
    // DP
    // ==========================

    for (int index = 1; index < size; index++)
    {
        vector<vector<int>> curr(m + 1, vector<int>(n + 1, 0));

        zeroCount = 0;
        oneCount = 0;

        for (char ch : strs[index])
        {
            if (ch == '0')
            {
                zeroCount++;
            }
            else
            {
                oneCount++;
            }
        }

        for (int zeros = 0; zeros <= m; zeros++)
        {
            for (int ones = 0; ones <= n; ones++)
            {
                // Don't Pick
                int notPick = prev[zeros][ones];

                // Pick
                int pick = 0;

                if (zeroCount <= zeros && oneCount <= ones)
                {
                    pick = 1 + prev[zeros - zeroCount][ones - oneCount];
                }

                curr[zeros][ones] = max(pick, notPick);
            }
        }

        prev = curr;
    }

    return prev[m][n];
}

// =====================================================
// DRIVER CODE
// =====================================================

int main()
{
    vector<string> strs =
        {
            "10",
            "0001",
            "111001",
            "1",
            "0"};

    int m = 5;
    int n = 3;

    cout << "Recursion : "
         << findMaxFormRec(strs, m, n)
         << endl;

    cout << "Memoization : "
         << findMaxFormMemo(strs, m, n)
         << endl;

    cout << "Tabulation : "
         << findMaxFormTab(strs, m, n)
         << endl;

    cout << "Space Optimization : "
         << findMaxFormSpace(strs, m, n)
         << endl;

    return 0;
}