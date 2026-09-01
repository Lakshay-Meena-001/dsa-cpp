#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int kadaneMax(vector<int> &nums)
{
    int current = nums[0];
    int best = nums[0];

    for (int i = 1; i < nums.size(); i++)
    {
        current = max(nums[i], current + nums[i]);
        best = max(best, current);
    }

    return best;
}

int kadaneMin(vector<int> &nums)
{
    int current = nums[0];
    int best = nums[0];

    for (int i = 1; i < nums.size(); i++)
    {
        current = min(nums[i], current + nums[i]);
        best = min(best, current);
    }

    return best;
}

int maxSubarraySumCircular(vector<int> &nums)
{
    int totalSum = 0;

    for (int num : nums)
    {
        totalSum += num;
    }

    int normalMax = kadaneMax(nums);

    // All elements are negative.
    // Circular formula would incorrectly produce 0.
    if (normalMax < 0)
    {
        return normalMax;
    }

    int minSum = kadaneMin(nums);

    int circularMax = totalSum - minSum;

    return max(normalMax, circularMax);
}

int main()
{
    vector<int> nums = {5, -3, 5};

    cout << maxSubarraySumCircular(nums) << endl;

    return 0;
}