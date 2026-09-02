#include <bits/stdc++.h>
using namespace std;

pair<int, int> closestPair(vector<int> &A, vector<int> &B, int target)
{
    // i ko A ke start se aur j ko B ke end se point karenge kyu ki A sorted hai aur B bhi sorted hai, to humein dono arrays ke elements ko compare karna hai taki hum target ke closest sum ko find kar sakein.
    int i = 0;
    int j = B.size() - 1;

    // Initialize best difference to a large value and answer pair
    int bestDiff = INT_MAX;
    pair<int, int> answer;

    while (i < A.size() && j >= 0)
    {

        int sum = A[i] + B[j];
        int diff = abs(sum - target);

        // Update best pair
        if (diff < bestDiff)
        {
            bestDiff = diff;
            answer = {A[i], B[j]};
        }

        // Exact target: cannot do better
        if (sum == target)
        {
            return {A[i], B[j]};
        }

        // Need a bigger sum
        if (sum < target)
        {
            i++;
        }

        // Need a smaller sum
        else
        {
            j--;
        }
    }

    return answer;
}

int main()
{

    vector<int> A = {1, 4, 7, 10};
    vector<int> B = {2, 5, 8, 12};

    int target = 15;

    pair<int, int> answer = closestPair(A, B, target);

    cout << "Closest pair: "
         << answer.first << " "
         << answer.second << endl;

    cout << "Sum: "
         << answer.first + answer.second << endl;

    return 0;
}