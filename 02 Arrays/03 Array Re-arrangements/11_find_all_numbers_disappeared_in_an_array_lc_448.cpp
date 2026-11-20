#include <iostream>
#include <vector>
#include <map>
using namespace std;

//--------------------------------------------------
// Problem: find_all_numbers_disappeared_in_an_array_lc_448.cpp
// Pattern : Correct Position (Cyclic Sort)
// Constraint:
// 1. Values are in range [1...n]
// 2. Some values may appear twice
// Time : O(n)
// Space: O(1) (excluding answer vector)
//--------------------------------------------------

vector<int> findDisappearedNumbers(vector<int> &nums)
{
    int i = 0;
    int n = nums.size();

    while (i < n)
    {
        int correctIndex = nums[i] - 1;

        // Place current number at its correct position.
        if (nums[i] != nums[correctIndex])
        {
            swap(nums[i], nums[correctIndex]);

            // Don't increment i.
            // New value at current index may also be incorrect.
        }
        else
        {
            i++;
        }
    }

    vector<int> answer;

    for (int i = 0; i < n; i++)
    {
        // Value should be (index + 1)
        if (nums[i] != i + 1)
        {
            answer.push_back(i + 1);
        }
    }

    return answer;
}

vector<int> findDisappearedNumbersMap(vector<int> &nums)
{
    int n = nums.size();

    map<int, int> mp;

    // Store frequency of each number
    for (int num : nums)
    {
        mp[num]++;
    }

    vector<int> answer;

    // Check which numbers are missing
    for (int i = 1; i <= n; i++)
    {
        if (mp.find(i) == mp.end())
        {
            answer.push_back(i);
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

    vector<int> answer = findDisappearedNumbers(nums);

    for (int num : answer)
    {
        cout << num << " ";
    }

    return 0;
}

/*
Problem:
Array mein N size ke numbers diye gaye hain.
Numbers ki range [1, N] hai.
Kuch numbers duplicate ho sakte hain aur kuch missing hain.

Saare missing numbers find karne hain.

Input:  [4, 3, 2, 7, 8, 2, 3, 1]
Output: [5, 6]

Approach: Cyclic Sort

Steps:
1. Array ka size n calculate karo.
2. Ek variable i = 0 initialize karo.
3. Jab tak i < n hai, tab tak while loop chalao.
4. Current number ki correct index calculate karo:
   - correctIndex = nums[i] - 1
   - Kyunki number 1 ka index 0, number 2 ka index 1 hona chahiye.
5. Check karo ki current number apni correct position par hai ya nahi.
6. Agar nums[i] != nums[correctIndex] hai:
   - Dono elements ko swap kar do.
   - i increment mat karo.
   - Kyunki swap ke baad current index par naya number aayega,
     jise bhi correct position par place karna hai.
7. Agar nums[i] == nums[correctIndex] hai:
   - i++ kar do.
   - Iska matlab current number already correct position par hai
     ya duplicate number hai.
8. Ek empty answer vector banao.
9. Array ko dobara traverse karo (0 se n-1 tak).
10. Har index par check karo:
    - Agar nums[i] != i + 1 hai:
      - i + 1 number missing hai.
      - Use answer vector mein push kar do.
11. Finally, answer vector return kar do.

TC: O(n) - Cyclic Sort mein har number apni correct position par place hota hai.
     Har successful swap kisi number ko correct position par pahunchata hai.
     Second loop bhi O(n) time leta hai.
     Overall Time Complexity O(n) hai.

SC: O(n) - Answer vector mein maximum N-1 missing numbers store ho sakte hain.
     Sorting ke liye koi extra data structure use nahi hua.
     Auxiliary Space Complexity O(1) hai.

Important:
- Ye approach Cyclic Sort concept par based hai.
- correctIndex = nums[i] - 1 se number ki correct position milti hai.
- swap(nums[i], nums[correctIndex]) se number ko correct position par place karte hain.
- Swap ke baad i increment nahi karna hai, kyunki naye number ko bhi check karna zaroori hai.
- nums[i] == nums[correctIndex] duplicate number ko handle karta hai.
- Final loop mein nums[i] != i + 1 check karke missing numbers find karte hain.
- Missing numbers ascending order mein answer vector mein store hote hain.
- Array modify ho jaata hai (In-place rearrangement).
*/

/*
Problem:
Array mein N size ke numbers diye gaye hain.
Numbers ki range [1, N] hai.
Kuch numbers duplicate ho sakte hain aur kuch missing hain.

Saare missing numbers find karne hain.

Input:  [4, 3, 2, 7, 8, 2, 3, 1]
Output: [5, 6]

Approach: Hash Map (Frequency Counting using Map)

Steps:
1. Array ka size n calculate karo.
2. Ek map<int, int> initialize karo.
3. Array ko traverse karo using range-based for loop.
4. Har number ki frequency map mein store karo:
   - mp[num]++
   - Agar number pehle se map mein present hai,
     toh uski frequency increase ho jayegi.
   - Agar present nahi hai, toh new entry create ho jayegi.
5. Ek empty answer vector banao.
6. 1 se N tak loop chalao.
7. Har number ke liye check karo ki woh map mein present hai ya nahi.
8. Agar mp.find(i) == mp.end() hai:
   - Iska matlab number map mein present nahi hai.
   - Number missing hai.
   - Use answer vector mein push kar do.
9. Finally, answer vector return kar do.

TC: O(n log n) - Map mein insertion aur lookup dono O(log n) time lete hain.
     N elements ko map mein insert karne mein O(n log n) time lagega.
     1 se N tak lookup karne mein bhi O(n log n) time lagega.
     Overall Time Complexity O(n log n) hai.

SC: O(n) - Map mein maximum N unique elements store ho sakte hain.
     Answer vector mein maximum N-1 missing numbers store ho sakte hain.
     Overall Auxiliary Space Complexity O(n) hai.

Important:
- map<int, int> key-value pairs store karta hai.
- Key number hota hai aur value uski frequency hoti hai.
- mp[num]++ number ki frequency increase karta hai.
- map internally sorted order mein keys store karta hai.
- map mein insertion aur lookup ki Time Complexity O(log n) hoti hai.
- mp.find(i) == mp.end() ka matlab number map mein present nahi hai.
- Missing numbers ko ascending order mein answer vector mein store karte hain.
- Original array modify nahi hota.
*/