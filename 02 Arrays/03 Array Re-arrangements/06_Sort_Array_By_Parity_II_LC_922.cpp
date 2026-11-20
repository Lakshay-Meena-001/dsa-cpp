#include <iostream>
#include <vector>
using namespace std;

//--------------------------------------------------
// Optimal Approach
// Pattern : Fixed Position Placement
// Time : O(n)
// Space: O(n)
//--------------------------------------------------

vector<int> sortArrayByParityII(vector<int> &nums)
{
    int n = nums.size();

    vector<int> answer(n);

    int evenIndex = 0;
    int oddIndex = 1;

    for (int num : nums)
    {
        if (num % 2 == 0)
        {
            answer[evenIndex] = num;
            evenIndex += 2;
        }
        else
        {
            answer[oddIndex] = num;
            oddIndex += 2;
        }
    }

    return answer;
}

//--------------------------------------------------
// In-place Approach (Interview Follow-up)
// Pattern : Partition + Two Pointer
// Time : O(n)
// Space: O(1)
//--------------------------------------------------

void sortArrayByParityIIInPlace(vector<int> &nums)
{
    int evenIndex = 0;
    int oddIndex = 1;

    int n = nums.size();

    while (evenIndex < n && oddIndex < n)
    {
        if (nums[evenIndex] % 2 == 0)
        {
            evenIndex += 2;
        }
        else if (nums[oddIndex] % 2 == 1)
        {
            oddIndex += 2;
        }
        else
        {
            swap(nums[evenIndex], nums[oddIndex]);
            // Both wrong positions become correct after swap
        }
    }
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

    vector<int> answer = sortArrayByParityII(nums);

    for (int num : answer)
    {
        cout << num << " ";
    }

    return 0;
}

/*
Problem:
Ek array diya hai jisme equal number of even aur odd elements hain.
Humein array ko rearrange karna hai such that:
- Even numbers even indices (0, 2, 4...) par hon.
- Odd numbers odd indices (1, 3, 5...) par hon.
- Extra array use nahi karna.

Input:  [4, 2, 5, 7]
Output: [4, 5, 2, 7]

Approach: Two Pointers + In-place Swapping

Steps:
1. evenIndex = 0 rakho (even positions check karne ke liye).
2. oddIndex = 1 rakho (odd positions check karne ke liye).
3. Jab tak dono indices array ke andar hain, loop chalao.
4. Agar evenIndex par even number hai, toh evenIndex += 2 karo.
5. Agar oddIndex par odd number hai, toh oddIndex += 2 karo.
6. Otherwise, dono positions par numbers galat hain.
   Swap karo, jisse dono correct positions par aa jayenge.
7. Finally, array in-place rearrange ho jayega.

TC: O(n) - Dono pointers array ko traverse karte hain.
SC: O(1) - Extra array use nahi kiya.
*/