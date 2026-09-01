#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

class Solution
{
public:

    vector<int> sortedSquares(vector<int> &nums)
    {

        int n = nums.size();

        vector<int> result(n);

        int left = 0;
        int right = n - 1;
        int write = n - 1;

        while (left <= right)
        {

            if (abs(nums[left]) > abs(nums[right]))
            {

                result[write] = nums[left] * nums[left];
                left++;
            }
            else
            {

                result[write] = nums[right] * nums[right];
                right--;
            }

            write--;
        }

        return result;
    }
};

int main()
{

    vector<int> nums = {-4, -1, 0, 3, 10};

    Solution solution;

    vector<int> result = solution.sortedSquares(nums);

    cout << "Result: ";

    for (int num : result)
    {
        cout << num << " ";
    }

    cout << endl;

    return 0;
}