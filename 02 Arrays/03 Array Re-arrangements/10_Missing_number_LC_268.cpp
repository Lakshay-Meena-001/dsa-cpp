#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Problem: _Missing_number_LC_268.cpp
// Pattern : Correct Position (Cyclic Sort)
// Time : O(n)
// Space: O(1)

int missingNumberOptimal(vector<int> &nums)
{
    int i = 0;
    int n = nums.size();

    while (i < n)
    {
        if (nums[i] < n && nums[i] != nums[nums[i]])
        {
            swap(nums[i], nums[nums[i]]);
        }
        else
        {
            i++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (nums[i] != i)
        {
            return i;
        }
    }

    return n;
}

vector<int> findDisappearedNumbersMap(vector<int> &nums)
{
    int n = nums.size();

    unordered_map<int, int> mp;

    // Store frequency of each number
    for (int num : nums)
    {
        mp[num]++;
    }

    vector<int> answer;

    // Numbers not present in map are missing
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
    cout << "Enter size: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter elements (0 to n with one missing): ";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    int ans = missingNumberOptimal(nums);

    cout << "Missing Number: " << ans << endl;

    return 0;
}

/*
Problem:
Array mein [0, N] range ke numbers diye gaye hain.
Array mein exactly ek number missing hai.
Missing number find karna hai.

Input:  [3, 0, 1]
Output: 2

Approach: Cyclic Sort (Index Placement)

Steps:
1. Initialize i = 0 and n = nums.size().
2. Loop chalao jab tak i < n.
3. Check karo ki nums[i] apni correct index par hai ya nahi.
4. Agar nums[i] < n aur nums[i] != nums[nums[i]]:
   - nums[i] ko uske correct index nums[i] par place karo.
   - Swap karo.
   - i++ mat karo, kyunki current index par naya element aaya hai.
5. Otherwise, i++ karo.
6. Ab array traverse karo.
7. Agar nums[i] != i:
   - i hi missing number hai.
   - Return i karo.
8. Agar saare elements correct index par hain:
   - Return n karo.

TC: O(n) - Har element ko maximum constant number of times
swap kiya jata hai. Final traversal bhi O(n) hai.

SC: O(1) - In-place rearrangement, extra array use nahi hota.

Important:
- Correct Index = nums[i]
- Valid range = [0, N]
- nums[i] < n check zaroori hai, kyunki N ka
  koi corresponding array index nahi hota.
- nums[i] != nums[nums[i]] duplicate values ke saath
  unnecessary swapping aur infinite loop prevent karta hai.
*/

/*
Problem:
Array mein N size ke numbers diye gaye hain.
Numbers ki range [1, N] hai.
Kuch numbers duplicate ho sakte hain aur kuch missing hain.

Saare missing numbers find karne hain.

Input:  [4, 3, 2, 7, 8, 2, 3, 1]
Output: [5, 6]

Approach: Hash Map (Frequency Counting)

Steps:
1. Array ka size n calculate karo.
2. Ek unordered_map initialize karo.
3. Array traverse karke har number ki frequency
   map mein store karo.
4. Ek empty answer vector banao.
5. 1 se N tak loop chalao.
6. Har number ke liye check karo ki woh map mein present hai ya nahi.
7. Agar number map mein present nahi hai:
   - Us number ko answer vector mein push karo.
8. Finally, answer vector return kar do.

TC: O(n) - Map mein insertion aur lookup average O(1) hai.
     N numbers ko check karne mein O(n) time lagega.

SC: O(n) - Unordered_map mein maximum N elements store ho sakte hain.
     Answer vector ki extra space bhi O(n) ho sakti hai.

Important:
- unordered_map number ki frequency store karta hai.
- mp.find(i) == mp.end() ka matlab number map mein present nahi hai.
- Missing numbers ko ascending order mein answer vector mein store karte hain.
*/