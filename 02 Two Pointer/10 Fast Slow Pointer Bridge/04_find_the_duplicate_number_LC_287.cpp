#include <iostream>
#include <vector>
using namespace std;

int findDuplicate(vector<int> &nums)
{

    // PHASE 1: Find meeting point

    int slow = nums[0];
    int fast = nums[0];

    do
    {
        // Slow ek step badhega jaise linked list cycle detection m kiya tha
        slow = nums[slow];

        // Fast do step badhega jaise linked list cycle detection m kiya tha
        fast = nums[nums[fast]];

    } while (slow != fast);

    // PHASE 2: Find cycle entrance

    // Reset slow to starting point
    slow = nums[0];

    while (slow != fast)
    {
        // Both move 1 step, array ki hi avalue next time usk eliye new valu eka kama kar rahi hai like chaining ho rahi hai
        /*
        0
         ↓ nums[0]=1
        1
        ↓ nums[1]=3
        3
         ↓ nums[3]=2
        2
         ↓ nums[2]=4
        4
        ↓ nums[4]=2
        ...
        */
        slow = nums[slow];
        fast = nums[fast];
    }

    // Cycle entrance = duplicate number
    return slow;
}

int main()
{

    vector<int> nums = {1, 3, 4, 2, 2};

    cout << "Duplicate = "
         << findDuplicate(nums)
         << endl;

    return 0;
}