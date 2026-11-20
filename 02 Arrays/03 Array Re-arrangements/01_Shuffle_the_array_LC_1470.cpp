#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    /*
    First half: [2, 5, 1]
    Second half: [3, 4, 7]

    Expected answer: [2, 3, 5, 4, 1, 7]

    */
    vector<int> shuffle(vector<int> &nums, int n)
    {
        vector<int> answer;

        // Reserve memory to avoid repeated reallocations.
        answer.reserve(2 * n);

        // Take one element from first half,
        // then one from second half.
        for (int i = 0; i < n; i++)
        {
            answer.push_back(nums[i]);
            answer.push_back(nums[i + n]);
        }

        return answer;
    }
};

int main()
{
    int n;

    cout << "Enter n: ";
    cin >> n;

    vector<int> nums(2 * n);

    cout << "Enter " << 2 * n << " elements: ";
    for (int i = 0; i < 2 * n; i++)
    {
        cin >> nums[i];
    }

    Solution obj;
    vector<int> result = obj.shuffle(nums, n);

    cout << "Shuffled Array: ";
    for (int x : result)
    {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}

/*
Problem:
Ek array diya hai jisme 2n elements hain.
Array ke first half aur second half ke elements ko
alternatively arrange karna hai.

Input:  [2, 5, 1, 3, 4, 7], n = 3
Output: [2, 3, 5, 4, 1, 7]

Approach: Extra Array + Two Pointers (Indexing)

Steps:
1. Ek empty answer vector banao.
2. answer.reserve(2*n) se pehle hi memory allocate karo,
   taaki baar-baar memory reallocate na ho.
3. Loop 0 se n-1 tak chalao.
4. Har iteration mein:
   - First half se nums[i] add karo.
   - Second half se nums[i+n] add karo.
5. Finally, answer vector return karo.

TC: O(n) - Loop n times chalta hai.
SC: O(n) - Answer ke liye extra vector use kiya hai.
*/