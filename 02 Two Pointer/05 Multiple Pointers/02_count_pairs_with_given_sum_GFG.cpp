#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long countPairs(vector<int> &nums, int target)
    {

        sort(nums.begin(), nums.end());

        int L = 0;
        int R = nums.size() - 1;

        long long count = 0;

        while (L < R)
        {

            long long sum = (long long)nums[L] + nums[R];

            // Sum is too small
            if (sum < target)
            {
                L++;
            }

            // Sum is too large
            else if (sum > target)
            {
                R--;
            }

            // Found target sum
            else
            {

                // Case 1:
                // Both values are the same
                if (nums[L] == nums[R])
                {

                    long long n = R - L + 1;

                    // Choose any 2 elements from n elements
                    count += n * (n - 1) / 2;

                    break;
                }

                // Case 2:
                // Count duplicates on the left
                long long leftCount = 1;

                while (L + leftCount <= R &&
                       nums[L + leftCount] == nums[L])
                {
                    leftCount++;
                }

                // Count duplicates on the right
                long long rightCount = 1;

                while (R - rightCount >= L &&
                       nums[R - rightCount] == nums[R])
                {
                    rightCount++;
                }

                // Every left duplicate can pair
                // with every right duplicate
                count += leftCount * rightCount;

                // Move beyond duplicate groups
                L += leftCount;
                R -= rightCount;
            }
        }

        return count;
    }
};

int main()
{

    Solution obj;

    vector<int> nums = {1, 5, 7, -1, 5};

    int target = 6;

    cout << obj.countPairs(nums, target) << endl;

    return 0;
}