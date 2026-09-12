#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool pairInSortedRotatedArray(vector<int> &nums, int target)
    {

        int n = nums.size();

        // Find the rotation point
        // rotation point = index where nums[i] > nums[i + 1]
        int R = -1;

        for (int i = 0; i < n - 1; i++)
        {

            if (nums[i] > nums[i + 1])
            {
                R = i;
                break;
            }
        }

        // If no rotation exists,
        // array is normally sorted.
        if (R == -1)
        {
            R = n - 1;
        }

        // Smallest element is just after rotation point
        int L = (R + 1) % n;

        // Circular two pointer
        while (L != R)
        {

            int sum = nums[L] + nums[R];

            if (sum == target)
            {
                return true;
            }

            if (sum < target)
            {
                // Need a larger value
                L = (L + 1) % n;
            }
            else
            {
                // Need a smaller value
                R = (R - 1 + n) % n;
            }
        }

        return false;
    }
};

int main()
{

    Solution obj;

    vector<int> nums = {11, 15, 6, 8, 9, 10};

    int target = 16;

    cout << boolalpha
         << obj.pairInSortedRotatedArray(nums, target)
         << endl;

    return 0;
}