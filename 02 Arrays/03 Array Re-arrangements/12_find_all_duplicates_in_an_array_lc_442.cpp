#include <iostream>
#include <vector>
#include <map>
using namespace std;

//--------------------------------------------------
// Problem: find_all_duplicates_in_an_array_lc_442.cpp
// Pattern : Correct Position (Cyclic Sort)
// Constraint:
// 1. Values are in range [1...n]
// 2. Some values appear twice
// Time : O(n)
// Space: O(1) (excluding answer vector)
//--------------------------------------------------

vector<int> findDuplicatesOptimal(vector<int> &nums)
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

    vector<int> answer;

    for (int i = 0; i < n; i++)
    {
        // Correct value at index i should be (i + 1).
        // If not, current value is a duplicate.
        if (nums[i] != i + 1)
        {
            answer.push_back(nums[i]);
        }
    }

    return answer;
}

vector<int> findDuplicatesMap(vector<int> &nums)
{
    map<int, int> mp;

    // Store frequency of each number
    for (int num : nums)
    {
        mp[num]++;
    }

    vector<int> answer;

    // Numbers with frequency > 1 are duplicates
    for (auto it : mp)
    {
        if (it.second > 1)
        {
            answer.push_back(it.first);
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

    vector<int> answer = findDuplicatesOptimal(nums);

    for (int x : answer)
    {
        cout << x << " ";
    }

    return 0;
}

/*
Problem:
Array mein N size ke numbers diye gaye hain.
Numbers ki range [1, N] hai.
Kuch numbers duplicate ho sakte hain aur kuch unique hain.

Saare duplicate numbers find karne hain.

Input:  [4, 3, 2, 7, 8, 2, 3, 1]
Output: [3, 2]

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
   - nums[i] aur nums[correctIndex] ko swap kar do.
   - i increment mat karo.
   - Kyunki swap ke baad current index par naya number aayega,
     jise bhi correct position par check karna zaroori hai.
7. Agar nums[i] == nums[correctIndex] hai:
   - i++ kar do.
   - Iska matlab current number already correct position par hai
     ya duplicate number hai.
8. Ek empty answer vector banao.
9. Array ko dobara traverse karo (0 se n-1 tak).
10. Har index par check karo:
    - Correct value nums[i] mein i + 1 honi chahiye.
    - Agar nums[i] != i + 1 hai:
      - Current value duplicate hai.
      - Use answer vector mein push kar do.
11. Finally, answer vector return kar do.

TC: O(n) - Cyclic Sort mein har successful swap kisi number ko
     uski correct position par place karta hai.
     Har index ko process karne mein overall O(n) time lagta hai.
     Second loop bhi O(n) time leta hai.
     Overall Time Complexity O(n) hai.

SC: O(n) - Answer vector mein maximum O(n) duplicate elements
     store ho sakte hain.
     Sorting ke liye koi extra data structure use nahi hua.
     Auxiliary Space Complexity O(1) hai.

Important:
- Ye approach Cyclic Sort concept par based hai.
- correctIndex = nums[i] - 1 se number ki correct position milti hai.
- swap(nums[i], nums[correctIndex]) number ko correct position par place karta hai.
- Swap ke baad i increment nahi karna hai.
- nums[i] == nums[correctIndex] duplicate numbers ko handle karta hai.
- Final loop mein nums[i] != i + 1 check karte hain.
- Agar current value apni correct position par nahi hai,
  toh woh duplicate number hota hai.
- Original array modify ho jaata hai (In-place rearrangement).
- Duplicate elements answer vector mein ascending order mein
  zaroori nahi hain.
*/


/*
Problem:
Array mein N size ke numbers diye gaye hain.
Numbers ki range [1, N] hai.
Kuch numbers duplicate ho sakte hain aur kuch unique hain.

Saare duplicate numbers find karne hain.

Input:  [4, 3, 2, 7, 8, 2, 3, 1]
Output: [2, 3]

Approach: Hash Map (Frequency Counting using Map)

Steps:
1. Ek map<int, int> initialize karo.
2. Array ko traverse karo using range-based for loop.
3. Har number ki frequency map mein store karo:
   - mp[num]++
   - Agar number pehle se map mein present hai,
     toh uski frequency increase ho jayegi.
   - Agar present nahi hai, toh new entry create ho jayegi.
4. Ek empty answer vector banao.
5. Map ko traverse karo using range-based for loop.
6. Har map entry ke liye check karo:
   - Agar it.second > 1 hai:
     - Iska matlab number ek se zyada baar present hai.
     - Number duplicate hai.
     - it.first ko answer vector mein push kar do.
7. Finally, answer vector return kar do.

TC: O(n log n) - Map mein insertion ki Time Complexity O(log n) hoti hai.
     N elements insert karne mein O(n log n) time lagega.
     Map mein stored unique elements ko traverse karne mein O(n) time lagega.
     Overall Time Complexity O(n log n) hai.

SC: O(n) - Map mein maximum N unique elements store ho sakte hain.
     Answer vector mein maximum O(n) duplicate numbers store ho sakte hain.
     Overall Auxiliary Space Complexity O(n) hai.

Important:
- map<int, int> key-value pairs store karta hai.
- it.first mein number (key) store hota hai.
- it.second mein number ki frequency store hoti hai.
- mp[num]++ number ki frequency increase karta hai.
- it.second > 1 ka matlab number duplicate hai.
- map internally keys ko sorted order mein store karta hai.
- Isliye duplicate numbers answer vector mein ascending order mein milte hain.
- Har duplicate number sirf ek baar answer vector mein store hota hai.
- Original array modify nahi hota.
*/
