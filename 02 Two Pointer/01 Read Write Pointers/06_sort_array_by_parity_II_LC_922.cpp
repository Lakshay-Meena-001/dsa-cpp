#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> sortArrayByParityII(vector<int> &nums)
    {

        int n = nums.size();

        int even = 0;
        int odd = 1;

        while (even < n && odd < n)
        {

            // Jab tak even elements correct mil rahe hain, continuously aage jaate raho.
            // dont use if kyuki if ke andar sirf ek hi baar check hoga, lekin while ke andar continuously check hoga.
            while (even < n && nums[even] % 2 == 0)
            {
                even += 2;
            }

            // Jab tak odd elements correct mil rahe hain, continuously aage jaate raho.
            // dont use if kyuki if ke andar sirf ek hi baar check hoga, lekin while ke andar continuously check hoga.
            while (odd < n && nums[odd] % 2 == 1)
            {
                odd += 2;
            }

            // Swap the two misplaced values.
            if (even < n && odd < n)
            {
                swap(nums[even], nums[odd]);

                even += 2;
                odd += 2;
            }
        }

        return nums;
    }
};

int main()
{

    vector<int> nums = {3, 4, 1, 2};

    Solution solution;

    solution.sortArrayByParityII(nums);

    cout << "Result: ";

    for (int num : nums)
    {
        cout << num << " ";
    }

    cout << endl;

    return 0;
}