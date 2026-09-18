#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    // Current index se next index find karega
    int nextIndex(int i, vector<int> &nums)
    {
        int n = nums.size();

        return ((i + nums[i]) % n + n) % n;
    }

    bool circularArrayLoop(vector<int> &nums)
    {
        int n = nums.size();

        // Har index ko starting point maan kar check karenge
        for (int start = 0; start < n; start++)
        {
            // Starting direction
            bool forward = nums[start] > 0;

            int slow = start;
            int fast = start;

            while (true)
            {
                // Direction change → invalid path
                if ((nums[slow] > 0) != forward)
                {
                    break;
                }

                int nextSlow = nextIndex(slow, nums);

                // Self-loop → cycle length = 1, invalid
                if (nextSlow == slow)
                {
                    break;
                }

                // Fast pointer ki direction check
                if ((nums[fast] > 0) != forward)
                {
                    break;
                }

                // Fast pointer: first move
                int nextFast = nextIndex(fast, nums);

                // Self-loop → invalid
                if (nextFast == fast)
                {
                    break;
                }

                // Fast pointer ki second move se pehle direction check
                if ((nums[nextFast] > 0) != forward)
                {
                    break;
                }

                // Fast pointer: second move
                int nextFast2 = nextIndex(nextFast, nums);

                // Self-loop → invalid
                if (nextFast2 == nextFast)
                {
                    break;
                }

                // Pointers move
                slow = nextSlow;
                fast = nextFast2;

                // Same position → valid cycle found
                if (slow == fast)
                {
                    return true;
                }
            }
        }

        return false;
    }
};

int main()
{
    Solution sol;

    // Test Case 1
    vector<int> nums1 = {2, -1, 1, 2, 2};

    cout << "Test Case 1: ";

    if (sol.circularArrayLoop(nums1))
        cout << "true\n";
    else
        cout << "false\n";

    // Test Case 2
    vector<int> nums2 = {-1, 2};

    cout << "Test Case 2: ";

    if (sol.circularArrayLoop(nums2))
        cout << "true\n";
    else
        cout << "false\n";

    // Test Case 3
    vector<int> nums3 = {-2, 1, -1, -2, -2};

    cout << "Test Case 3: ";

    if (sol.circularArrayLoop(nums3))
        cout << "true\n";
    else
        cout << "false\n";

    // Test Case 4
    vector<int> nums4 = {1, 1, 1, 1};

    cout << "Test Case 4: ";

    if (sol.circularArrayLoop(nums4))
        cout << "true\n";
    else
        cout << "false\n";

    return 0;
}