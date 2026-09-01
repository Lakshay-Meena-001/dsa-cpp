#include <bits/stdc++.h>
using namespace std;

// =====================================================
// RECURSION
// =====================================================

// index1 -> Current Index of str1
// index2 -> Current Index of str2
// count  -> Current Matching Length

int solveRec(int index1, int index2, int count, string &str1, string &str2)
{
    // Base Case
    if (index1 < 0 || index2 < 0)
    {
        return count;
    }

    int match = count;

    // Characters Match
    if (str1[index1] == str2[index2])
    {
        match = solveRec(index1 - 1, index2 - 1, count + 1, str1, str2);
    }

    // Break Current Substring
    int skipStr1 = solveRec(index1 - 1, index2, 0, str1, str2);

    int skipStr2 = solveRec(index1, index2 - 1, 0, str1, str2);

    return max(match, max(skipStr1, skipStr2));
}

int longestCommonSubstringRec(string str1, string str2)
{
    int n = str1.size();
    int m = str2.size();

    return solveRec(n - 1, m - 1, 0, str1, str2);
}

// =====================================================
// MEMOIZATION
// =====================================================

// Not Recommended// =====================================================
// TABULATION
// =====================================================

int longestCommonSubstringTab(string str1, string str2)
{
    int n = str1.size();
    int m = str2.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    int maxi = 0;

    // Base Case
    // First row and first column are already 0

    // Build DP Table
    for (int index1 = 1; index1 <= n; index1++)
    {
        for (int index2 = 1; index2 <= m; index2++)
        {
            // Characters Match
            if (str1[index1 - 1] == str2[index2 - 1])
            {
                dp[index1][index2] = 1 + dp[index1 - 1][index2 - 1];

                maxi = max(maxi, dp[index1][index2]);
            }
            else
            {
                // Current Substring Breaks
                dp[index1][index2] = 0;
            }
        }
    }

    return maxi;
}

// =====================================================
// SPACE OPTIMIZATION
// =====================================================

int longestCommonSubstringSpace(string str1, string str2)
{
    int n = str1.size();
    int m = str2.size();

    vector<int> prev(m + 1, 0);

    int maxi = 0;

    for (int index1 = 1; index1 <= n; index1++)
    {
        vector<int> curr(m + 1, 0);

        for (int index2 = 1; index2 <= m; index2++)
        {
            if (str1[index1 - 1] == str2[index2 - 1])
            {
                curr[index2] = 1 + prev[index2 - 1];

                maxi = max(maxi, curr[index2]);
            }
            else
            {
                curr[index2] = 0;
            }
        }

        prev = curr;
    }

    return maxi;
}

// =====================================================
// DRIVER CODE
// =====================================================

int main()
{
    string str1 = "abcjklp";
    string str2 = "acjkp";

    cout << "Recursion : "
         << longestCommonSubstringRec(str1,
                                      str2)
         << endl;

    // Memoization skipped

    cout << "Tabulation : "
         << longestCommonSubstringTab(str1,
                                      str2)
         << endl;

    cout << "Space Optimization : "
         << longestCommonSubstringSpace(str1,
                                        str2)
         << endl;

    return 0;
}
// This problem cannot be efficiently memoized using only
// (index1, index2) because 'count' is also part of the state.
// Memoization would require a 3D DP (index1, index2, count),
// making it inefficient.
// Hence, Tabulation is the preferred DP approach.
