#include <iostream>
#include <map>
#include <vector>
using namespace std;

// Problem: set_mismatch_lc_645.cpp
// Pattern : Correct Position (Cyclic Sort)
// Constraint:
// 1. Values are in range [1...n]
// 2. One value is duplicated
// 3. One value is missing
// Time : O(n)
// Space: O(1)

vector<int> findErrorNumsOptimal(vector<int> &nums)
{
    int i = 0;
    int n = nums.size();

    while (i < n)
    {
        int correctIndex = nums[i] - 1;

        if (nums[i] != nums[correctIndex])
        {
            // Place current value at its correct position.
            swap(nums[i], nums[correctIndex]);

            // Don't increment i.
            // Swapped value may still be at the wrong position.
        }
        else
        {
            i++;
        }
    }

    // Mismatch gives both answers.
    for (int i = 0; i < n; i++)
    {
        if (nums[i] != i + 1)
        {
            // nums[i]  -> Duplicate
            // i + 1    -> Missing
            return {nums[i], i + 1};
        }
    }

    return {};
}

vector<int> findErrorNumsMap(vector<int> &nums)
{
    int n = nums.size();

    map<int, int> mp;

    // Store frequency of each number
    for (int num : nums)
    {
        mp[num]++;
    }

    int duplicate = -1;
    int missing = -1;

    for (int i = 1; i <= n; i++)
    {
        if (mp[i] == 2)
        {
            duplicate = i;
        }
        else if (mp[i] == 0)
        {
            missing = i;
        }
    }

    return {duplicate, missing};
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

    vector<int> answer = findErrorNumsOptimal(nums);

    cout << answer[0] << " " << answer[1];

    return 0;
}

/*
Problem:
Array mein N size ke numbers diye gaye hain.
Numbers ki range [1, N] hai.
Ek number duplicate hai aur ek number missing hai.

Duplicate aur Missing dono numbers find karne hain.

Input:  [1, 2, 2, 4]
Output: [2, 3]

Approach: Cyclic Sort

Steps:
1. Array ka size n calculate karo.
2. Ek variable i = 0 initialize karo.
3. Jab tak i < n hai, while loop chalao.
4. Current number ki correct index calculate karo:
   - correctIndex = nums[i] - 1
5. Check karo ki current number apni correct position par hai ya nahi.
6. Agar nums[i] != nums[correctIndex] hai:
   - Dono elements ko swap kar do.
   - i increment mat karo.
   - Kyunki swap ke baad current index par naya number aayega,
     jise bhi check karna zaroori hai.
7. Agar nums[i] == nums[correctIndex] hai:
   - i++ kar do.
   - Iska matlab current number correct position par hai
     ya duplicate number hai.
8. Array ko dobara traverse karo.
9. Har index par check karo:
   - Agar nums[i] != i + 1 hai:
     - nums[i] duplicate number hai.
     - i + 1 missing number hai.
10. Dono numbers ko vector mein return kar do.

TC: O(n) - Cyclic Sort mein har successful swap number ko
     uski correct position par place karta hai.
     First while loop O(n) aur second for loop O(n) leta hai.
     Overall Time Complexity O(n) hai.

SC: O(1) - Sorting ke liye koi extra data structure use nahi hua.
     Sirf kuch variables use kiye hain.
     Auxiliary Space Complexity O(1) hai.

Important:
- Ye approach Cyclic Sort par based hai.
- correctIndex = nums[i] - 1 se correct position milti hai.
- Swap ke baad i increment nahi karna hai.
- nums[i] == nums[correctIndex] duplicate ko handle karta hai.
- Final loop mein nums[i] != i + 1 check karte hain.
- Mismatch hone par nums[i] duplicate aur i + 1 missing hota hai.
- Original array modify ho jaata hai.
- return {nums[i], i + 1} mein pehle Duplicate aur phir Missing return hota hai.
*/

/*
Problem:
Array mein N size ke numbers diye gaye hain.
Numbers ki range [1, N] hai.
Ek number duplicate hai aur ek number missing hai.

Duplicate aur Missing dono numbers find karne hain.

Input:  [1, 2, 2, 4]
Output: [2, 3]

Approach: Map (Frequency Counting)

Steps:
1. Array ka size n calculate karo.
2. Ek map<int, int> initialize karo.
3. Array traverse karke har number ki frequency store karo:
   - mp[num]++
4. Do variables initialize karo:
   - duplicate = -1
   - missing = -1
5. 1 se N tak loop chalao.
6. Har number ki frequency check karo.
7. Agar mp[i] == 2 hai:
   - Number exactly 2 baar present hai.
   - duplicate = i assign kar do.
8. Agar mp[i] == 0 hai:
   - Number array mein present nahi hai.
   - missing = i assign kar do.
9. Finally, {duplicate, missing} return kar do.

TC: O(n log n) - Map mein N elements insert karne mein
     O(n log n) time lagta hai.
     1 se N tak frequency check karne mein O(n log n)
     time lagta hai.
     Overall Time Complexity O(n log n) hai.

SC: O(n) - Map mein maximum N unique elements store ho sakte hain.
     Duplicate aur missing variables O(1) space lete hain.
     Overall Auxiliary Space Complexity O(n) hai.

Important:
- map<int, int> number ki frequency store karta hai.
- mp[num]++ frequency increase karta hai.
- mp[i] == 2 ka matlab number duplicate hai.
- mp[i] == 0 ka matlab number missing hai.
- duplicate aur missing ko alag-alag variables mein store karte hain.
- return {duplicate, missing} mein pehle Duplicate
  aur phir Missing number return hota hai.
- Original array modify nahi hota.
*/