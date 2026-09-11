#include <bits/stdc++.h>
using namespace std;

int numSubseq(vector<int> &nums, int target)
{

    const int MOD = 1e9 + 7;

    int n = nums.size();

    // Step 1: Sorting allows us to reason about an entire range at once.
    sort(nums.begin(), nums.end());

    // Step 2: Precompute powers of 2.
    vector<long long> powerOfTwo(n);

    powerOfTwo[0] = 1;

    for (int i = 1; i < n; i++)
    {
        powerOfTwo[i] = (powerOfTwo[i - 1] * 2) % MOD;
    }

    long long count = 0;

    int left = 0;
    int right = n - 1;

    while (left <= right)
    {

        // Check minimum + maximum.
        if (nums[left] + nums[right] <= target)
        {

            // nums[left] is definitely included.
            //
            // Every element between left+1 and right
            // can independently be chosen or skipped.
            //
            // Number of optional elements:
            // right - left
            count = (count + powerOfTwo[right - left]) % MOD;

            // We have counted every valid subsequence
            // whose minimum is nums[left].
            left++;
        }
        else
        {

            // Maximum is too large.
            // Try a smaller maximum.
            right--;
        }
    }

    return (int)count;
}

int main()
{

    vector<int> nums = {
        3, 5, 6, 7};

    int target = 9;

    cout << numSubseq(nums, target);

    return 0;
}