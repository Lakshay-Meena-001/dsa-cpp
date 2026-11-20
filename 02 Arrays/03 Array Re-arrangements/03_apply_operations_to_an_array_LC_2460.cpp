#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> applyOperations(vector<int> &nums)
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

/*
Problem:
Array mein adjacent equal elements ko double karna hai
aur next element ko 0 banana hai. Finally, saare zeroes
ko end mein shift karna hai, without changing non-zero order.

Input:  [1, 2, 2, 1, 1, 0]
Output: [1, 4, 2, 0, 0, 0]

Approach: Two Passes (Apply Operations + Move Zeroes)

Steps:
1. Array traverse karo aur adjacent elements compare karo.
2. Agar dono equal hain, toh first ko double aur second ko 0 karo.
3. insertPosition = 0 rakho, jo next non-zero element ki position batayega.
4. Current pointer se array traverse karo.
5. Agar element non-zero hai, toh insertPosition ke saath swap karo
   aur insertPosition++ kar do.
6. Finally, modified array return karo.

TC: O(n) - Array ko 2 baar traverse karte hain.
SC: O(1) - In-place operation, koi extra array nahi.

*/