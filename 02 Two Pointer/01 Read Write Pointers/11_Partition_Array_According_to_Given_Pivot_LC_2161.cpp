#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> pivotArray(vector<int> &nums, int pivot)
    {

        int n = nums.size();

        vector<int> result(n);

        // First determine how many elements
        // belong to the less-than and equal regions.
        int lessCount = 0;
        int equalCount = 0;

        for (int num : nums)
        {

            if (num < pivot)
            {
                lessCount++;
            }
            else if (num == pivot)
            {
                equalCount++;
            }
        }

        // Starting positions of each region.
        int lessIndex = 0;
        int equalIndex = lessCount;
        int greaterIndex = lessCount + equalCount;

        // Fill each region while scanning from left to right.
        for (int num : nums)
        {

            if (num < pivot)
            {

                result[lessIndex] = num;
                lessIndex++;
            }

            else if (num == pivot)
            {

                result[equalIndex] = num;
                equalIndex++;
            }

            else
            {

                result[greaterIndex] = num;
                greaterIndex++;
            }
        }

        return result;
    }
};

int main()
{

    vector<int> nums = {
        9, 12, 5, 10, 14, 3, 10};

    int pivot = 10;

    Solution solution;

    vector<int> result = solution.pivotArray(nums, pivot);

    cout << "Result: ";

    for (int num : result)
    {
        cout << num << " ";
    }

    cout << endl;

    return 0;
}