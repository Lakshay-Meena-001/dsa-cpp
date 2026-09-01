#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> sortArrayByParity(vector<int> &nums)
    {
        int left = 0;
        int right = nums.size() - 1;

        while (left < right)
        {

            // Left element is already in the correct region.
            if (nums[left] % 2 == 0)
            {
                left++;
            }

            // Right element is already in the correct region.
            else if (nums[right] % 2 == 1)
            {
                right--;
            }

            // Left is odd and right is even.
            else
            {
                swap(nums[left], nums[right]);

                left++;
                right--;
            }
        }

        return nums;
    }
};

int main()
{

    vector<int> nums = {3, 1, 2, 4};

    Solution solution;

    solution.sortArrayByParity(nums);

    cout << "Result: ";

    for (int num : nums)
    {
        cout << num << " ";
    }

    cout << endl;

    return 0;
}