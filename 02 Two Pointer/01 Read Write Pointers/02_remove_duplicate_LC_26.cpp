#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {

        if (nums.empty())
        {
            return 0;
        }

        // matlab 0th element to already  unique hai to write pointer ko 1st index se start karenge
        int write = 1;

        for (int read = 1; read < nums.size(); read++)
        {
            // Only a new value should enter the unique region.
            if (nums[read] != nums[write - 1])
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

    vector<int> nums = {1, 1, 2, 2, 3, 3, 4};

    Solution obj;

    int k = obj.removeDuplicates(nums);

    cout << "Unique elements: ";

    for (int i = 0; i < k; i++)
    {
        cout << nums[i] << " ";
    }

    cout << "\nCount = " << k << endl;

    return 0;
}