#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> rearrangeArray(vector<int> &nums)
    {

        int n = nums.size();

        // Answer array because direct in-place rearrangement
        // stability ke saath unnecessarily complicated ho jayega.
        vector<int> ans(n);

        // Positive numbers ki positions:
        // 0, 2, 4, 6...
        int positiveIndex = 0;

        // Negative numbers ki positions:
        // 1, 3, 5, 7...
        int negativeIndex = 1;

        // Original order preserve karne ke liye
        // LEFT -> RIGHT scan kar rahe hain.
        for (int x : nums)
        {

            if (x > 0)
            {
                // Positive ko next positive slot par rakho.
                ans[positiveIndex] = x;

                // Agla positive slot 2 positions baad.
                positiveIndex += 2;
            }
            else
            {
                // Negative ko next negative slot par rakho.
                ans[negativeIndex] = x;

                // Agla negative slot 2 positions baad.
                negativeIndex += 2;
            }
        }

        return ans;
    }
};

int main()
{

    Solution sol;

    vector<int> nums = {3, 1, -2, -5, 2, -4};

    vector<int> ans = sol.rearrangeArray(nums);

    for (int x : ans)
    {
        cout << x << " ";
    }

    return 0;
}