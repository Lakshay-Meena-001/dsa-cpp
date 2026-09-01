#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> rearrangeArray(vector<int> &nums)
    {

        int n = nums.size();

        vector<int> result(n);

        int positiveIndex = 0;
        int negativeIndex = 1;

        for (int num : nums)
        {

            if (num > 0)
            {

                result[positiveIndex] = num;
                positiveIndex += 2;
            }
            else
            {

                result[negativeIndex] = num;
                negativeIndex += 2;
            }
        }

        return result;
    }
};

int main()
{

    vector<int> nums = {
        3, 1, -2, -5, 2, -4};

    Solution solution;

    vector<int> result = solution.rearrangeArray(nums);

    cout << "Result: ";

    for (int num : result)
    {
        cout << num << " ";
    }

    cout << endl;

    return 0;
}