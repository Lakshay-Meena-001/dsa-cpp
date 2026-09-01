#include <iostream>
#include <vector>
using namespace std;

//--------------------------------------------------
// Problem: first_missing_positive_lc_41.cpp
// Pattern : Correct Position (Modified Cyclic Sort)
// Constraint:
// 1. Ignore values <= 0
// 2. Ignore values > n
// 3. Only values [1...n] have valid positions
// Time : O(n)
// Space: O(1)
//--------------------------------------------------

int firstMissingPositiveOptimal(vector<int> &nums)
{
    int n = nums.size();
    int i = 0;

    while (i < n)
    {
        // Current value belongs to index (value - 1)
        int correctIndex = nums[i] - 1;

        // Ignore invalid values.
        // Swap only valid values that are not already at their correct position.
        
        if (nums[i] > 0 && nums[i] <= n && nums[i] != nums[correctIndex])
        {
            swap(nums[i], nums[correctIndex]);

            // Don't increment i.
            // Newly swapped value may also need to be placed.
        }
        else
        {
            i++;
        }
    }

    // First mismatch gives the smallest missing positive.
    for (int i = 0; i < n; i++)
    {
        if (nums[i] != i + 1)
        {
            return i + 1;
        }
    }

    // All values [1...n] are present.
    return n + 1;
}

int main()
{
    int n;
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    cout << firstMissingPositiveOptimal(nums);

    return 0;
}