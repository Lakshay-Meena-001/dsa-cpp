#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> applyOperations(vector<int>& nums)
{
    int n = nums.size();

    // Phase 1 : Apply Operations
    for (int i = 0; i < n - 1; i++)
    {
        if (nums[i] == nums[i + 1])
        {
            nums[i] *= 2;
            nums[i + 1] = 0;
        }
    }

    // Phase 2 : Move Zeroes
    int insertPosition = 0;

    for (int current = 0; current < n; current++)
    {
        if (nums[current] != 0)
        {
            swap(nums[insertPosition], nums[current]);
            insertPosition++;
        }
    }

    return nums;
}

int main()
{
    int n;
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    vector<int> ans = applyOperations(nums);

    for (int x : ans)
    {
        cout << x << " ";
    }

    return 0;
}