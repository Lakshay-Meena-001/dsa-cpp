#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {

        int write = 0;

        // Phase 1: Move all non-zero elements
        // to the front while preserving order.
        // non zero elements ko front me laate raho bina order break kare
        for (int read = 0; read < nums.size(); read++)
        {
            if (nums[read] != 0)
            {
                //bas one by one non zero elements ko front m laate raho
                nums[write] = nums[read];

                write++;
            }
        }

        // Phase 2: Fill remaining positions with zero.
        for (int i = write; i < nums.size(); i++)
        {
            nums[i] = 0;
        }
    }
};

int main()
{

    vector<int> nums = {0, 1, 0, 3, 12};

    Solution solution;

    solution.moveZeroes(nums);

    cout << "Result: ";

    for (int num : nums)
    {
        cout << num << " ";
    }

    cout << endl;

    return 0;
}