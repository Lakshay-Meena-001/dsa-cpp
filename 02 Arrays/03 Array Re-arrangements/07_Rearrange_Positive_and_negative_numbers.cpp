#include <iostream>
#include <vector>
using namespace std;

//--------------------------------------------------
// Brute / Optimal (Extra Space)
// Pattern : Stable Partition
// Time : O(n)
// Space: O(n)
//--------------------------------------------------

vector<int> rearrangeArray(vector<int> &nums)
{
    vector<int> positive;
    vector<int> negative;

    for (int num : nums)
    {
        if (num >= 0)
        {
            positive.push_back(num);
        }
        else
        {
            negative.push_back(num);
        }
    }

    vector<int> answer;

    int i = 0;
    int j = 0;

    // Alternate positives and negatives
    while (i < positive.size() && j < negative.size())
    {
        answer.push_back(positive[i++]);
        answer.push_back(negative[j++]);
    }

    // Remaining positives
    while (i < positive.size())
    {
        answer.push_back(positive[i++]);
    }

    // Remaining negatives
    while (j < negative.size())
    {
        answer.push_back(negative[j++]);
    }

    return answer;
}

//--------------------------------------------------
// Optimal (In-place Stable)
// Pattern : Stable Partition + Right Shift
// Time : O(n²)
// Space: O(1)
//--------------------------------------------------

void rearrangeInPlace(vector<int> &nums)
{
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        // Even index should contain positive number
        if (i % 2 == 0 && nums[i] >= 0)
        {
            continue;
        }

        // Odd index should contain negative number
        if (i % 2 == 1 && nums[i] < 0)
        {
            continue;
        }

        int j = i + 1;

        while (j < n)
        {
            // matlab ek out of place element mila hai, toh uske liye correct sign wala element search karna hai
            if ((i % 2 == 0 && nums[j] >= 0) || (i % 2 == 1 && nums[j] < 0))
            {
                break;
            }

            j++;
        }

        if (j == n)
        {
            break;
        }

        int temp = nums[j];

        // to relative order kharab n aho isliy eelements ko right shift karna hai
        while (j > i)
        {
            nums[j] = nums[j - 1];
            j--;
        }

        nums[i] = temp;
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

    vector<int> answer = rearrangeArray(nums);

    for (int num : answer)
    {
        cout << num << " ";
    }

    return 0;
}

/*
Problem:
Ek array diya hai jisme positive aur negative numbers hain.
Humein positive aur negative numbers ko alternatively arrange karna hai.
Dono ka original relative order maintain karna hai.
Agar kisi side ke elements bach jaayein, toh unhe end mein add karna hai.

Input:  [1, 2, -4, -5, 3, -6]
Output: [1, -4, 2, -5, 3, -6]

Approach: Extra Arrays + Two Pointers

Steps:
1. Do separate vectors banao: positive aur negative.
2. Original array traverse karke positive aur negative elements
   ko respective vectors mein store karo.
3. Ek empty answer vector banao.
4. i aur j ko 0 se initialize karo.
5. Jab tak dono vectors mein elements available hain:
   - Ek positive element answer mein add karo.
   - Ek negative element answer mein add karo.
6. Agar positive elements bach jaayein, toh unhe add karo.
7. Agar negative elements bach jaayein, toh unhe add karo.
8. Finally, answer return karo.

TC: O(n) - Array ko traverse aur elements ko answer mein add karte hain.
SC: O(n) - Positive, negative aur answer vectors use kiye hain.
*/

/*
Problem:
Positive aur negative numbers ko alternatively arrange karna hai.
Even index (0, 2, 4...) par positive aur odd index (1, 3, 5...) par
negative number hona chahiye.
Original relative order maintain karna hai.
Extra array use nahi karna.

Input:  [1, 2, -3, -4, 5, -6]
Output: [1, -3, 2, -4, 5, -6]

Approach: In-place + Shifting

Steps:
1. Array ko left se right traverse karo using i.
2. Check karo ki current index par correct sign hai ya nahi.
3. Agar even index par positive ya odd index par negative hai,
   toh continue karo.
4. Agar wrong element hai, toh i ke baad se correct sign wala
   element search karo using j.
5. Agar correct element nahi milta, toh loop stop kar do.
6. Correct element ko temp mein store karo.
7. Jahan correct element mila hai, wahan se i tak saare elements
   ko ek position right shift karo.
8. temp ko nums[i] par place karo.
9. Finally, array in-place rearrange ho jayega.

TC: O(n²) - Searching aur shifting dono karne pad sakte hain.
SC: O(1) - Sirf temp variable use kiya hai.
*/
