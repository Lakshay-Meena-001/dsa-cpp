#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> applyOperations(vector<int> &nums)
    {

        int n = nums.size();

        /*
        PHASE 1: APPLY OPERATIONS

        Left -> right scan.

        Agar adjacent elements equal hain:
            nums[i] *= 2
            nums[i + 1] = 0

        */

        for (int i = 0; i < n - 1; i++)
        {

            if (nums[i] == nums[i + 1])
            {

                nums[i] *= 2;

                // Next element ko zero kar do.
                nums[i + 1] = 0;
            }
        }

        /*
        PHASE 2: MOVE ALL ZEROES TO END

        Read pointer:
            i

        Write pointer:
            write

        write hamesha batata hai:
        "next non-zero element kahan jaana hai?"
        */

        int write = 0;

        for (int i = 0; i < n; i++)
        {

            // Sirf non-zero elements ko front mein compact karo.
            if (nums[i] != 0)
            {

                nums[write] = nums[i];

                // Next non-zero ki destination.
                write++;
            }
        }

        /*
        Ab [0 ... write-1] mein saare non-zero elements hain.

        Baaki positions ko zero fill kar do.
        */

        while (write < n)
        {

            nums[write] = 0;

            write++;
        }

        return nums;
    }
};

int main()
{

    Solution sol;

    vector<int> nums = {1, 2, 2, 1, 1, 0};

    vector<int> ans = sol.applyOperations(nums);

    for (int x : ans)
    {
        cout << x << " ";
    }

    return 0;
}
