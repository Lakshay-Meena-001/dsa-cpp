#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Problem: next_permutation_lc_31.cpp
// Pattern : Pivot + Reverse
// Constraint:
// 1. Modify array in-place
// 2. Return next lexicographical permutation
// Time : O(n)
// Space: O(1)

void nextPermutationOptimal(vector<int> &nums)
{
    int n = nums.size();

    int pivot = -1;

    // Find first decreasing element from right.
    for (int i = n - 2; i >= 0; i--)
    {
        if (nums[i] < nums[i + 1])
        {
            pivot = i;
            break;
        }
    }

    // Already largest permutation.
    if (pivot == -1)
    {
        reverse(nums.begin(), nums.end());
        return;
    }

    // Find next greater element from right.
    for (int i = n - 1; i > pivot; i--)
    {
        if (nums[i] > nums[pivot])
        {
            swap(nums[i], nums[pivot]);
            break;
        }
    }

    // Right side is in descending order.
    // Reverse it to get the smallest possible suffix.
    reverse(nums.begin() + pivot + 1, nums.end());
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

    nextPermutationOptimal(nums);

    for (int x : nums)
    {
        cout << x << " ";
    }

    return 0;
}

/*
Problem:
Ek integer array diya gaya hai.
Array ka next lexicographically greater permutation find karna hai.

Agar current permutation already largest permutation hai,
toh array ko smallest permutation mein convert karna hai.

Input:
[1, 2, 3]

Output:
[1, 3, 2]

Example 2:
Input:
[3, 2, 1]

Output:
[1, 2, 3]

Example 3:
Input:
[1, 1, 5]

Output:
[1, 5, 1]

Approach: Optimal (Pivot + Swap + Reverse)

Steps:
1. Array ka size n calculate karo.
2. Ek variable pivot = -1 initialize karo.
   - Ye array mein pehle decreasing element ka index store karega.
3. Array ko right se left traverse karo:
   - i = n-2 se 0 tak.
4. Har index par check karo:
   - Agar nums[i] < nums[i+1] hai:
     - pivot = i set karo.
     - Loop break kar do.
5. Agar pivot == -1 hai:
   - Iska matlab array already descending order mein hai.
   - Ye array ki largest permutation hai.
   - Complete array ko reverse kar do.
   - Function se return kar jao.
6. Ab pivot ke right side se array ko traverse karo:
   - i = n-1 se pivot+1 tak.
7. Pehla aisa element find karo jo nums[pivot] se greater ho.
   - Condition: nums[i] > nums[pivot]
8. Jaise hi aisa element mile:
   - nums[i] aur nums[pivot] ko swap kar do.
   - Loop break kar do.
9. Ab pivot ke right side wale complete subarray ko reverse kar do.
   - reverse(nums.begin() + pivot + 1, nums.end())
10. Isse right side ka descending order ascending order mein convert ho jayega.
11. Finally, array ka next lexicographically greater permutation mil jayega.

TC: O(n)
     First traversal mein pivot find karne ke liye O(n) time lagta hai.
     Second traversal mein next greater element find karne ke liye O(n) time lagta hai.
     Suffix reverse karne mein O(n) time lagta hai.
     Overall Time Complexity O(n) hai.

SC: O(1)
     Koi extra array ya data structure use nahi hota.
     Sirf pivot variable use hota hai.
     Reverse aur swap in-place perform hote hain.
     Auxiliary Space Complexity O(1) hai.

Important:
- Pivot right se left pehla aisa element hota hai jiske liye nums[i] < nums[i+1] ho.
- Pivot ke right side ke elements descending order mein hote hain.
- Pivot ke right side se pehla greater element find karte hain.
- Right se pehla greater element hi smallest possible greater element hota hai.
- Pivot aur next greater element ko swap karte hain.
- Swap ke baad suffix ko reverse karte hain.
- Reverse karne se suffix ascending order mein aa jata hai.
- Agar pivot nahi milta, toh array ko reverse kar dete hain.
- Ye approach in-place next permutation calculate karti hai.
- Overall Time Complexity O(n) aur Auxiliary Space O(1) hai.
*/