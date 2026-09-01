#include <bits/stdc++.h>
using namespace std;

// =====================================================
// RECURSION
// =====================================================

// Question i se start karke
// maximum points kitne kama sakte hain

long long solveRec(int index, vector<vector<int>> &questions)
{
    int n = questions.size();

    // Saare questions khatam

    if (index >= n)
    {
        return 0;
    }

    // Current question solve karo

    long long take = questions[index][0] + solveRec(index + questions[index][1] + 1, questions);

    // Current question skip karo

    long long skip = solveRec(index + 1, questions);

    return max(take, skip);
}

long long mostPointsRec(vector<vector<int>> &questions)
{
    return solveRec( 0,questions);
}

// =====================================================
// MEMOIZATION
// =====================================================

long long solveMemo(
    int index,
    vector<vector<int>> &questions,
    vector<long long> &dp)
{
    int n = questions.size();

    if (index >= n)
    {
        return 0;
    }

    if (dp[index] != -1)
    {
        return dp[index];
    }

    long long take =
        questions[index][0] +
        solveMemo(
            index +
                questions[index][1] + 1,
            questions,
            dp);

    long long skip =
        solveMemo(
            index + 1,
            questions,
            dp);

    return dp[index] =
               max(take, skip);
}

long long mostPointsMemo(
    vector<vector<int>> &questions)
{
    int n = questions.size();

    vector<long long> dp(
        n,
        -1);

    return solveMemo(
        0,
        questions,
        dp);
}

// =====================================================
// TABULATION
// =====================================================

long long mostPointsTab(
    vector<vector<int>> &questions)
{
    int n = questions.size();

    vector<long long> dp(
        n + 1,
        0);

    // Peeche se build karenge

    for (int index = n - 1; index >= 0; index--)
    {
        long long take = questions[index][0];

        int nextIndex = index + questions[index][1] + 1;

        if (nextIndex < n)
        {
            take += dp[nextIndex];
        }

        long long skip = dp[index + 1];

        dp[index] = max(take, skip);
    }

    return dp[0];
}

int main()
{
    vector<vector<int>> questions =
        {
            {3, 2},
            {4, 3},
            {4, 4},
            {2, 5}};

    cout << "Recursion : "
         << mostPointsRec(questions)
         << endl;

    cout << "Memoization : "
         << mostPointsMemo(questions)
         << endl;

    cout << "Tabulation : "
         << mostPointsTab(questions)
         << endl;

    return 0;
}