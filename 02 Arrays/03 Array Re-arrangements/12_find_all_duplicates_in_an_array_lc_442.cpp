#include <iostream>
#include <vector>
#include <map>
using namespace std;

//--------------------------------------------------
// Problem: find_all_duplicates_in_an_array_lc_442.cpp
// Pattern : Correct Position (Cyclic Sort)
// Constraint:
// 1. Values are in range [1...n]
// 2. Some values appear twice
// Time : O(n)
// Space: O(1) (excluding answer vector)
//--------------------------------------------------

vector<int> findDuplicatesOptimal(vector<int> &nums)
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

    vector<int> answer;

    for (int i = 0; i < n; i++)
    {
        // Correct value at index i should be (i + 1).
        // If not, current value is a duplicate.
        if (nums[i] != i + 1)
        {
            answer.push_back(nums[i]);
        }
    }

    return answer;
}

vector<int> findDuplicatesMap(vector<int> &nums)
{
    map<int, int> mp;

    // Store frequency of each number
    for (int num : nums)
    {
        mp[num]++;
    }

    vector<int> answer;

    // Numbers with frequency > 1 are duplicates
    for (auto it : mp)
    {
        if (it.second > 1)
        {
            answer.push_back(it.first);
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

    vector<int> answer = findDuplicatesOptimal(nums);

    for (int x : answer)
    {
        cout << x << " ";
    }

    return 0;
}