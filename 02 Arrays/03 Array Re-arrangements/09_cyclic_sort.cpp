#include <iostream>
#include <vector>
using namespace std;

//--------------------------------------------------
// Cyclic Sort
// Pattern : Correct Position
// Time : O(n)
// Space: O(1)
// Constraint : Values must be from 1...n
//--------------------------------------------------

void cyclicSort(vector<int> &nums)
{
    int i = 0;

    while (i < nums.size())
    {
        // element ka correct index calculate karo
        int correctIndex = nums[i] - 1;

        // agar current element apne correct index par nahi hai, toh swap karo
        if (nums[i] != nums[correctIndex])
        {
            swap(nums[i], nums[correctIndex]);
        }
        else
        {
            i++;
        }
    }
}

int main()
{
    int n;
    cout << "Enter size: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter elements (1 to n): ";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    cyclicSort(nums);

    cout << "Sorted Array: ";
    for (int x : nums)
    {
        cout << x << " ";
    }

    return 0;
}

/*
Problem:
Array mein numbers 1 se N tak diye gaye hain.
Array ko sort karna hai without using extra space.

Har number apne correct index par hona chahiye.

Correct Index = nums[i] - 1

Input:  [3, 5, 2, 1, 4]
Output: [1, 2, 3, 4, 5]

Approach: Cyclic Sort

Steps:
1. Initialize i = 0.
2. Loop chalao jab tak i < nums.size().
3. Current element ka correct index calculate karo:
   correctIndex = nums[i] - 1.
4. Check karo ki current element apne correct index par hai ya nahi.
5. Agar nums[i] != nums[correctIndex]:
   - nums[i] aur nums[correctIndex] ko swap karo.
   - i++ mat karo, kyunki current index par
     naya element aaya hai, jise process karna hai.
6. Agar nums[i] == nums[correctIndex]:
   - Element already correct position par hai
     ya duplicate hai.
   - i++ karo.
7. Loop complete hone par array sorted ho jayega.

TC: O(n) - Har element ko maximum constant number of times
swap kiya jata hai.

SC: O(1) - In-place sorting, extra array use nahi hota.

Important:
- Cyclic Sort tab use hota hai jab elements ka range
  generally 1 se N tak ho.
- Correct Index = nums[i] - 1
- Swap ke baad i++ nahi karna hai.
- Duplicate elements hone par infinite loop avoid karne ke liye
  nums[i] != nums[correctIndex] condition important hai.
*/

/*
| i   | Array     | Action                             |
| --- | --------- | ---------------------------------- |
| 0   | 3 5 2 1 4 | 3 ki correct index = 2 → swap(3,2) |
| 0   | 2 5 3 1 4 | 2 ki correct index = 1 → swap(2,5) |
| 0   | 5 2 3 1 4 | 5 ki correct index = 4 → swap(5,4) |
| 0   | 4 2 3 1 5 | 4 ki correct index = 3 → swap(4,1) |
| 0   | 1 2 3 4 5 | Ab correct hai → `i++`             |
| 1-4 | 1 2 3 4 5 | Sab correct → End                  |

*/
