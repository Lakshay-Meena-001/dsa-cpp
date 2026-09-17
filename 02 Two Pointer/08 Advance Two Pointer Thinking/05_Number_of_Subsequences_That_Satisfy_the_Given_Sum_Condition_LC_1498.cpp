#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MOD = 1'000'000'007;

int numSubseq(vector<int> &nums, int target)
{
    sort(nums.begin(), nums.end());

    int n = nums.size();

    // power[i] = 2^i % MOD
    vector<long long> power(n);

    power[0] = 1;

    for (int i = 1; i < n; i++)
    {
        power[i] = (power[i - 1] * 2) % MOD;
    }

    int L = 0;
    int R = n - 1;

    long long ans = 0;

    while (L <= R)
    {

        if (nums[L] + nums[R] <= target)
        {

            // nums[L] minimum hai.
            // L+1 se R tak har element choose/skip ho sakta hai.
            ans = (ans + power[R - L]) % MOD;

            L++;
        }
        else
        {

            // Maximum element too large hai.
            R--;
        }
    }

    return ans;
}

int main()
{
    vector<int> nums = {3, 5, 6, 7};
    int target = 9;

    cout << "Number of Valid Subsequences: "
         << numSubseq(nums, target) << endl;

    return 0;
}

/*
Input:
nums = [3,5,6,7]
target = 9

Output:
4

Core Pattern:
Sorting + Two Pointers + Combinatorial Counting

Key Idea:
If nums[L] + nums[R] <= target,
then nums[L] ko minimum rakhkar
L+1 ... R ke har element ko choose/skip
kar sakte hain.

Number of possibilities:
2^(R-L)

If sum > target:
R--

TC: O(n log n)
SC: O(n)
*/