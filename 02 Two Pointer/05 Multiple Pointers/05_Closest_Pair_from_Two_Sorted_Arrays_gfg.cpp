#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int closestPairFromTwoArrays(vector<int> &A, vector<int> &B, int target)
    {

        int i = 0;
        int j = B.size() - 1;

        int bestSum = A[i] + B[j];

        while (i < A.size() && j >= 0)
        {

            int sum = A[i] + B[j];

            // Update closest sum
            if (abs(sum - target) < abs(bestSum - target))
            {
                bestSum = sum;
            }

            // Exact target
            if (sum == target)
            {
                return sum;
            }

            // Sum is too small
            // Need a larger A value
            if (sum < target)
            {
                i++;
            }

            // Sum is too large
            // Need a smaller B value
            else
            {
                j--;
            }
        }

        return bestSum;
    }
};

int main()
{

    Solution obj;

    vector<int> A = {1, 4, 5, 7};
    vector<int> B = {10, 20, 30, 40};

    int target = 32;

    cout << obj.closestPairFromTwoArrays(A, B, target)
         << endl;

    return 0;
}