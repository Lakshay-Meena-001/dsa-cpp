#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int closestPairSum(vector<int> &nums, int target)
    {

        sort(nums.begin(), nums.end());

        int L = 0;
        int R = nums.size() - 1;

        int closestSum = nums[L] + nums[R];

        while (L < R)
        {

            int sum = nums[L] + nums[R];

            // Update closest answer
            if (abs(sum - target) < abs(closestSum - target))
            {
                closestSum = sum;
            }

            // Exact target found
            if (sum == target)
            {
                return sum;
            }

            // Sum is too small
            // Increase sum
            if (sum < target)
            {
                L++;
            }

            // Sum is too large
            // Decrease sum
            else
            {
                R--;
            }
        }

        return closestSum;
    }
};

int main()
{

    Solution obj;

    vector<int> nums = {10, 22, 28, 29, 30, 40};
    int target = 54;

    cout << obj.closestPairSum(nums, target) << endl;

    return 0;
}