#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> pivotArray(vector<int> &nums, int pivot)
    {

        vector<int> left;   // Elements < pivot
        vector<int> middle; // Elements == pivot
        vector<int> right;  // Elements > pivot

        // LEFT -> RIGHT scan is important because stability
        // means original relative order ko preserve karna hai.
        for (int x : nums)
        {

            if (x < pivot)
            {
                left.push_back(x);
            }
            else if (x == pivot)
            {
                middle.push_back(x);
            }
            else
            {
                right.push_back(x);
            }
        }

        // Ab teen stable groups ko order mein combine kar do.
        vector<int> ans;

        ans.reserve(nums.size());

        for (int x : left)
        {
            ans.push_back(x);
        }

        for (int x : middle)
        {
            ans.push_back(x);
        }

        for (int x : right)
        {
            ans.push_back(x);
        }

        return ans;
    }
};

/*
===========================================================
MAIN DRIVER
===========================================================
*/

int main()
{

    Solution sol;

    vector<int> nums = {9, 12, 5, 10, 14, 3, 10};
    int pivot = 10;

    vector<int> ans = sol.pivotArray(nums, pivot);

    for (int x : ans)
    {
        cout << x << " ";
    }

    return 0;
}
