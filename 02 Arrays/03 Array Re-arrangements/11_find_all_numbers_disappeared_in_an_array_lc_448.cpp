#include <iostream>
#include <vector>
#include <map>
using namespace std;

//--------------------------------------------------
// Problem: find_all_numbers_disappeared_in_an_array_lc_448.cpp
// Pattern : Correct Position (Cyclic Sort)
// Constraint:
// 1. Values are in range [1...n]
// 2. Some values may appear twice
// Time : O(n)
// Space: O(1) (excluding answer vector)
//--------------------------------------------------

vector<int> findDisappearedNumbers(vector<int> &nums)
{
    int i = 0;
    int n = nums.size();

    while (i < n)
    {
        int correctIndex = nums[i] - 1;

        // Place current number at its correct position.
        if (nums[i] != nums[correctIndex])
        {
            swap(nums[i], nums[correctIndex]);

            // Don't increment i.
            // New value at current index may also be incorrect.
        }
        else
        {
            i++;
        }
    }

    vector<int> answer;

    for (int i = 0; i < n; i++)
    {
        // Value should be (index + 1)
        if (nums[i] != i + 1)
        {
            answer.push_back(i + 1);
        }
    }

    return answer;
}

vector<int> findDisappearedNumbersMap(vector<int> &nums)
{
    int n = nums.size();

    map<int, int> mp;

    // Store frequency of each number
    for (int num : nums)
    {
        mp[num]++;
    }

    vector<int> answer;

    // Check which numbers are missing
    for (int i = 1; i <= n; i++)
    {
        if (mp.find(i) == mp.end())
        {
            answer.push_back(i);
        }
    }

    return answer;
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

    vector<int> answer = findDisappearedNumbers(nums);

    for (int num : answer)
    {
        cout << num << " ";
    }

    return 0;
}