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
    //kadane kya bolta hai ki agar hum current sum ko track karte hai aur har element ke liye check karte hai ki kya hum current sum ko continue kare ya fir new subarray start kare to hume maximum subarray sum mil jata hai.
    int currentSum = nums[0];

    int maxSum = nums[0];

    for (int i = 1; i < nums.size(); i++)
    {
        // Continue previous subarray OR Start new subarray

        currentSum = max(nums[i], currentSum + nums[i]);

        // Best answer till now

        maxSum = max(maxSum, currentSum);
    }

    return maxSum;
}

int main()
{
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    cout << "Maximum Sum = ";

    cout << maxSubArray(nums);

    return 0;
}