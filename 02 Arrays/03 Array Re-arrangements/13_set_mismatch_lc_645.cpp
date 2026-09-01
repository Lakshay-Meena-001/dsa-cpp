#include <iostream>
#include <map>
#include <vector>
using namespace std;

//--------------------------------------------------
// Problem: set_mismatch_lc_645.cpp
// Pattern : Correct Position (Cyclic Sort)
// Constraint:
// 1. Values are in range [1...n]
// 2. One value is duplicated
// 3. One value is missing
// Time : O(n)
// Space: O(1)
//--------------------------------------------------

vector<int> findErrorNumsOptimal(vector<int> &nums)
{
    int i = 0;
    int n = nums.size();

    while (i < n)
    {
        int correctIndex = nums[i] - 1;

        if (nums[i] != nums[correctIndex])
        {
            // Place current value at its correct position.
            swap(nums[i], nums[correctIndex]);

            // Don't increment i.
            // Swapped value may still be at the wrong position.
        }
        else
        {
            i++;
        }
    }

    // Mismatch gives both answers.
    for (int i = 0; i < n; i++)
    {
        if (nums[i] != i + 1)
        {
            // nums[i]  -> Duplicate
            // i + 1    -> Missing
            return {nums[i], i + 1};
        }
    }

    return {};
}

vector<int> findErrorNumsMap(vector<int> &nums)
{
    int n = nums.size();

    map<int, int> mp;

    // Store frequency of each number
    for (int num : nums)
    {
        mp[num]++;
    }

    int duplicate = -1;
    int missing = -1;

    for (int i = 1; i <= n; i++)
    {
        if (mp[i] == 2)
        {
            duplicate = i;
        }
        else if (mp[i] == 0)
        {
            missing = i;
        }
    }

    return {duplicate, missing};
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

    vector<int> answer = findErrorNumsOptimal(nums);

    cout << answer[0] << " " << answer[1];

    return 0;
}