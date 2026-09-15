#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void wiggleSort(vector<int> &nums)
    {

        int n = nums.size();

        //median nikalne k liye STL 
        nth_element(nums.begin(), nums.begin() + n / 2, nums.end());

        int median = nums[n / 2];

        auto virtualIndex = [n](int index)
        {
            return (1 + 2 * index) % (n | 1);
        };

        int left = 0;
        int i = 0;
        int right = n - 1;

        while (i <= right)
        {

            int currentIndex = virtualIndex(i);

            if (nums[currentIndex] > median)
            {

                // Large element ko front virtual position par bhejo.
                swap(nums[virtualIndex(left)], nums[currentIndex]);

                left++;
                i++;
            }

            else if (nums[currentIndex] < median)
            {

                // Small element ko back virtual position par bhejo.
                swap(nums[virtualIndex(right)], nums[currentIndex]);

                right--;
            }

            else
            {

                // Median value ko middle region mein rehne do.
                i++;
            }
        }
    }
};

int main()
{

    Solution sol;

    vector<int> nums = {1, 5, 1, 1, 6, 4};

    sol.wiggleSort(nums);

    for (int x : nums)
    {
        cout << x << " ";
    }

    return 0;
}