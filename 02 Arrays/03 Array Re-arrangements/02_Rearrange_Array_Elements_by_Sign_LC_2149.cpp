#include <iostream>
#include <vector>
using namespace std;

/*
nums = [3, 1, -2, -5, 2, -4]
ans = [3, -2, 1, -5, 2, -4]
*/
vector<int> rearrangeArray(vector<int> &nums)
{
    vector<int> answer(nums.size());

    int positiveIndex = 0;
    int negativeIndex = 1;

    for (int num : nums)
    {
        if (num > 0)
        {
            answer[positiveIndex] = num;
            positiveIndex += 2;
        }
        else
        {
            answer[negativeIndex] = num;
            negativeIndex += 2;
        }
    }

    return answer;
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

    vector<int> ans = rearrangeArray(nums);

    for (int x : ans)
    {
        cout << x << " ";
    }

    return 0;
}

/*
Problem:
Ek array diya hai jisme positive aur negative numbers hain.
Humein array ko rearrange karna hai such that:
- Positive number even index (0, 2, 4...) par ho.
- Negative number odd index (1, 3, 5...) par ho.
- Dono ka original relative order same rehna chahiye.

Input:  [3, 1, -2, -5, 2, -4]
Output: [3, -2, 1, -5, 2, -4]

Approach: Extra Array + Two Pointers

Steps:
1. Same size ka ek answer array banao.
2. positiveIndex = 0 rakho (positive numbers ke liye).
3. negativeIndex = 1 rakho (negative numbers ke liye).
4. Original array ko traverse karo.
5. Agar number positive hai:
   - answer[positiveIndex] par store karo.
   - positiveIndex += 2 karo.
6. Agar number negative hai:
   - answer[negativeIndex] par store karo.
   - negativeIndex += 2 karo.
7. Finally, answer array return karo.

TC: O(n) - Array ko ek baar traverse karte hain.
SC: O(n) - Extra answer array use kiya hai.
*/