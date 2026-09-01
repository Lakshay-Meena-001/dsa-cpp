#include<iostream>
#include<vector>
#include<climits>
#include<cmath>
using namespace std;

// LC 1749 Maximum Absolute Sum of Any Subarray
// Pattern
// Dual Kadane
// Time : O(n)
// Space : O(1)

int maxAbsoluteSum(vector<int>& nums)
{
    int currentMax = nums[0];
    int bestMax = nums[0];

    int currentMin = nums[0];
    int bestMin = nums[0];

    for(int i=1;i<nums.size();i++)
    {
        currentMax =
        max(nums[i],
            currentMax + nums[i]);

        bestMax =
        max(bestMax,currentMax);

        currentMin =
        min(nums[i],
            currentMin + nums[i]);

        bestMin =
        min(bestMin,currentMin);
    }

    return max(abs(bestMax),
               abs(bestMin));
}

int main()
{
    vector<int> nums =
    {1,-3,2,3,-4};

    cout<<maxAbsoluteSum(nums);

    return 0;
}