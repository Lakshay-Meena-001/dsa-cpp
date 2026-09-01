#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> summaryRanges(vector<int> &nums)
{
    vector<string> result;

    if (nums.empty())
    {
        return result;
    }

    int start = nums[0];

    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] != nums[i - 1] + 1)
        {
            if (start == nums[i - 1])
            {
                result.push_back(to_string(start));
            }
            else
            {
                result.push_back(to_string(start) + "->" + to_string(nums[i - 1]));
            }

            start = nums[i];
        }
    }

    if (start == nums.back())
    {
        result.push_back(to_string(start));
    }
    else
    {
        result.push_back(to_string(start) + "->" + to_string(nums.back()));
    }

    return result;
}

int main()
{
    vector<int> nums = {0, 1, 2, 4, 5, 7};

    vector<string> result = summaryRanges(nums);

    for (string range : result)
    {
        cout << range << " ";
    }

    cout << '\n';

    return 0;
}