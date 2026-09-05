#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool canJump(vector<int> &nums)
{
    // maximum kaha tak reach kiya abhi tak
    int farthestReach = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        //agar current index hi khud reachable nahi hai to hum aage nahi badh skte
        if (i > farthestReach)
        {
            return false;
        }

        // Update the farthest position we can reach.
        farthestReach = max(farthestReach, i + nums[i]);

        // agar hum pehle hi last index tak pahunch gaye ya usse aage nikal gaye to return true
        if (farthestReach >= nums.size() - 1)
        {
            return true;
        }
    }

    return true;
}

int main()
{
    vector<int> nums = {2, 3, 1, 1, 4};

    cout << boolalpha << canJump(nums) << endl;

    return 0;
}