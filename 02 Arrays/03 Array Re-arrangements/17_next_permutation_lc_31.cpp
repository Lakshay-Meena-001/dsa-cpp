#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//--------------------------------------------------
// Problem: next_permutation_lc_31.cpp
// Pattern : Pivot + Reverse
// Constraint:
// 1. Modify array in-place
// 2. Return next lexicographical permutation
// Time : O(n)
// Space: O(1)
//--------------------------------------------------

void nextPermutationOptimal(vector<int> &nums)
{
    int n = nums.size();

    int pivot = -1;

    // Find first decreasing element from right.
    for (int i = n - 2; i >= 0; i--)
    {
        if (nums[i] < nums[i + 1])
        {
            pivot = i;
            break;
        }
    }

    // Already largest permutation.
    if (pivot == -1)
    {
        reverse(nums.begin(), nums.end());
        return;
    }

    // Find next greater element from right.
    for (int i = n - 1; i > pivot; i--)
    {
        if (nums[i] > nums[pivot])
        {
            swap(nums[i], nums[pivot]);
            break;
        }
    }

    // Right side is in descending order.
    // Reverse it to get the smallest possible suffix.
    reverse(nums.begin() + pivot + 1, nums.end());
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

    nextPermutationOptimal(nums);

    for (int x : nums)
    {
        cout << x << " ";
    }

    return 0;
}