#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countPairs(vector<int> &nums, int k)
    {

        sort(nums.begin(), nums.end());

        int n = nums.size();
        int L = 0;
        int R = 1;
        int count = 0;

        while (R < n)
        {

            int diff = nums[R] - nums[L];

            if (diff < k)
            {
                // Difference is too small
                // Increase R to make difference larger
                R++;
            }
            else if (diff == k)
            {
                // Found a valid pair
                count++;

                L++;
                R++;
            }
            else
            {
                // Difference is too large
                // Increase L to reduce difference
                L++;
            }

            // Keep pointers valid
            if (L == R)
            {
                R++;
            }
        }

        return count;
    }
};

int main()
{

    Solution obj;

    vector<int> nums = {1, 5, 3, 4, 2};
    int k = 2;

    cout << obj.countPairs(nums, k) << endl;

    return 0;
}