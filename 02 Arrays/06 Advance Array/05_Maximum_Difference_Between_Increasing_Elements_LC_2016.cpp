#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maximumDifference(vector<int>& nums)
{
    int minSoFar = nums[0];
    int answer = -1;

    for (int i = 1; i < nums.size(); i++)
    {
        // Current element acts as nums[j].
        // Use only previous elements as nums[i].
        int difference = nums[i] - minSoFar;

        answer = max(answer, difference);

        // Current element can be the minimum
        // for future positions.
        minSoFar = min(minSoFar, nums[i]);
    }

    return answer > 0 ? answer : -1;
}

int main()
{
    vector<int> nums = {7, 1, 5, 4};

    cout << maximumDifference(nums) << endl;

    return 0;
}