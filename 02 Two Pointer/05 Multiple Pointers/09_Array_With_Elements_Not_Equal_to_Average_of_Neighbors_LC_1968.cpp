#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> rearrangeArray(vector<int> &nums)
    {

        // Step 1: Sort the array
        sort(nums.begin(), nums.end());

        // Step 2: Swap adjacent pairs
        // (0,1), (2,3), (4,5), ...
        for (int i = 1; i < nums.size(); i += 2)
        {
            swap(nums[i], nums[i - 1]);
        }

        return nums;
    }
};

int main()
{

    Solution obj;

    vector<int> nums = {1, 2, 3, 4, 5, 6};

    vector<int> ans = obj.rearrangeArray(nums);

    for (int x : ans)
    {
        cout << x << " ";
    }

    return 0;
}