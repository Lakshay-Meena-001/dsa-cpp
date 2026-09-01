#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maximumDifference(vector<int> &nums)
{
    int minimumValue = nums[0];
    int maximumDifference = -1;

    for (int i = 1; i < nums.size(); i++)
    {
        // Calculate difference using smallest value seen so far.
        if (nums[i] > minimumValue)
        {
            maximumDifference = max(maximumDifference, nums[i] - minimumValue);
        }

        // Update running minimum.
        minimumValue = min(minimumValue, nums[i]);
    }

    return maximumDifference;
}

int main()
{
    vector<int> nums = {7, 1, 5, 4};

    cout << "Maximum Difference = ";

    cout << maximumDifference(nums);

    return 0;
}