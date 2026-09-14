#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> sortArrayByParityII(vector<int> &nums)
    {

        int n = nums.size();

        vector<int> ans(n);

        // Even numbers ke liye sirf even indices use honge:
        // 0 -> 2 -> 4 -> 6 -> ...
        int evenIndex = 0;

        // Odd numbers ke liye sirf odd indices use honge:
        // 1 -> 3 -> 5 -> 7 -> ...
        int oddIndex = 1;

        // Original array ko left -> right scan karo.
        for (int x : nums)
        {

            if (x % 2 == 0)
            {

                // Even number ko next even position par rakho.
                ans[evenIndex] = x;

                // Next even position.
                evenIndex += 2;
            }
            else
            {

                // Odd number ko next odd position par rakho.
                ans[oddIndex] = x;

                // Next odd position.
                oddIndex += 2;
            }
        }

        return ans;
    }
};

int main()
{

    Solution sol;

    vector<int> nums = {4, 2, 5, 7};

    vector<int> ans = sol.sortArrayByParityII(nums);

    for (int x : ans)
    {
        cout << x << " ";
    }

    return 0;
}