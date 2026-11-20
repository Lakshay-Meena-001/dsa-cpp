#include <iostream>
#include <vector>
using namespace std;

// Problem: can_place_flowers_lc_605.cpp
// Pattern : Greedy Simulation
// Constraint:
// 1. Adjacent flowers are not allowed
// 2. Modify flowerbed while traversing
// Time : O(n)
// Space: O(1)

bool canPlaceFlowersOptimal(vector<int> &flowerbed, int n)
{
    // count isliye rakha hai ki humne kitne flowers plant kiye hain
    int count = 0;
    int size = flowerbed.size();

    for (int i = 0; i < size; i++)
    {
        // hum har position m plant karne k liy echeck karna hai ki left m flower hai ya nahi aur right m flower hai ya nahi
        // to i=0 k liy eleft = 0, i=size-1 k liy right = 0 first ka left koi nahi hai and last ko right koi nahi hai
        int left = (i == 0) ? 0 : flowerbed[i - 1];
        int right = (i == size - 1) ? 0 : flowerbed[i + 1];

        // Plant only if both neighbours are empty.
        if (flowerbed[i] == 0 && left == 0 && right == 0)
        {
            flowerbed[i] = 1; // Update immediately to avoid future conflicts.
            count++;

            if (count >= n)
            {
                return true;
            }
        }
    }

    return count >= n;
}

int main()
{
    int size;
    cin >> size;

    vector<int> flowerbed(size);

    for (int i = 0; i < size; i++)
    {
        cin >> flowerbed[i];
    }

    int n;
    cin >> n;

    cout << (canPlaceFlowersOptimal(flowerbed, n) ? "true" : "false");

    return 0;
}

/*
Problem:
Ek flowerbed array diya gaya hai jisme:
- 0 ka matlab empty plot hai.
- 1 ka matlab flower already planted hai.

Humein n new flowers plant karne hain.
Condition ye hai ki kisi bhi do flowers ko adjacent plots mein
plant nahi kar sakte.

Input:  flowerbed = [1, 0, 0, 0, 1], n = 1
Output: true

Approach: Greedy + In-place Modification

Steps:
1. Ek count variable banao jo planted flowers ko count kare.
2. Array ka size store karo.
3. Loop ke through har index par iterate karo.
4. Har index ke left aur right neighbours check karo.
   - Agar first index hai, toh left = 0.
   - Agar last index hai, toh right = 0.
5. Check karo ki:
   - Current plot empty ho.
   - Left neighbour empty ho.
   - Right neighbour empty ho.
6. Agar teeno conditions satisfy hoti hain:
   - Current position par flower plant karo.
   - count increment karo.
7. Agar count >= n ho jaye, toh true return karo.
8. Loop complete hone ke baad count >= n return karo.

TC: O(n) - Flowerbed array ko ek baar traverse kiya hai.
SC: O(1) - Koi extra array ya data structure use nahi kiya.

Note: Greedy approach mein hum har valid position par
immediately flower plant kar dete hain, taaki future mein
adjacent flowers ka conflict na ho.
*/