#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {

        if (nums.size() <= 2)
        {
            return nums.size();
        }
        // 
        int write = 2;

        for (int read = 2; read < nums.size(); read++)
        {

            // Allow the current value only if
            // it is different from the value
            // two positions behind in the valid region.
            if (nums[read] != nums[write - 2])
            {

                nums[write] = nums[read];

                write++;
            }
        }

        return write;
    }
};

int main()
{

    vector<int> nums = {1, 1, 1, 2, 2, 3};

    Solution solution;

    int k = solution.removeDuplicates(nums);

    cout << "Result: ";

    for (int i = 0; i < k; i++)
    {
        cout << nums[i] << " ";
    }

    cout << "\nCount: " << k << endl;

    return 0;
}