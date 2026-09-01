#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// LC53 - Maximum Subarray

// Pattern:
// Kadane Algorithm

// Time  : O(n)
// Space : O(1)

int maxSubArray(vector<int> &nums)
{
    int currentSum = nums[0];

    int bestSum = nums[0];

    for (int i = 1; i < nums.size(); i++)
    {
        // Continue previous subarray OR Start new subarray

        currentSum = max(nums[i], currentSum + nums[i]);

        // Best answer till now

        bestSum = max(bestSum, currentSum);
    }

    return bestSum;
}

int main()
{
    vector<int> nums =
        {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    cout << "Maximum Sum = ";

    cout << maxSubArray(nums);

    return 0;
}