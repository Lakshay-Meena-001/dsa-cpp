#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    { // ek pointer k jo track karega ki next valid element kaha store karna hai
        int k = 0;

        // hum read pointer ka use karenge array ke elements ko traverse karne ke liye
        for (int read = 0; read < nums.size(); read++)
        {
            // agar current element val ke barabar nahi hai to usse k position par store karenge yad ralhna value wo value hai jo hume remove karna hai
            if (nums[read] != val)
            {
                // hum k position par current element ko store karenge aur k ko increment karenge
                nums[k] = nums[read];
                k++;
            }
        }
        // hum k return karenge jo ki new length of array ko represent karega
        return k;
    }
};

int main()
{
    vector<int> nums = {3, 2, 2, 3};
    int val = 3;

    Solution obj;

    int k = obj.removeElement(nums, val);

    cout << "Number of elements: " << k << endl;

    cout << "Array after removing " << val << ": ";

    for (int i = 0; i < k; i++)
    {
        cout << nums[i] << " ";
    }

    return 0;
}