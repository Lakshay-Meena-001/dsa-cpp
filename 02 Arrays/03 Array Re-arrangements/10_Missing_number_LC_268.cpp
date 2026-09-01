#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

//--------------------------------------------------
// Problem: _Missing_number_LC_268.cpp
// Pattern : Correct Position (Cyclic Sort)
// Time : O(n)
// Space: O(1)
//--------------------------------------------------

int missingNumberOptimal(vector<int> &nums)
{
    int i = 0;
    int n = nums.size();

    while (i < n)
    {
        if (nums[i] < n && nums[i] != nums[nums[i]])
        {
            swap(nums[i], nums[nums[i]]);
        }
        else
        {
            i++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (nums[i] != i)
        {
            return i;
        }
    }

    return n;
}

vector<int> findDisappearedNumbersMap(vector<int> &nums)
{
    int n = nums.size();

    unordered_map<int, int> mp;

    // Store frequency of each number
    for (int num : nums)
    {
        mp[num]++;
    }

    vector<int> answer;

    // Numbers not present in map are missing
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
    cout << "Enter size: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter elements (0 to n with one missing): ";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    int ans = missingNumberOptimal(nums);

    cout << "Missing Number: " << ans << endl;

    return 0;
}