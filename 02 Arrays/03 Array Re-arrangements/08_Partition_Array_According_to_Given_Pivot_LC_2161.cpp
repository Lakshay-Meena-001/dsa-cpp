#include <iostream>
#include <vector>
using namespace std;

// Brute / Optimal (Extra Space)
// Pattern : Stable Three-Way Partition
// Time : O(n)
// Space: O(n)

vector<int> pivotArray(vector<int> &nums, int pivot)
{
    vector<int> less;
    vector<int> equal;
    vector<int> greater;

    for (int num : nums)
    {
        if (num < pivot)
        {
            less.push_back(num);
        }

        else if (num == pivot)
        {
            equal.push_back(num);
        }

        else
        {
            greater.push_back(num);
        }
    }

    vector<int> answer;

    for (int x : less)
    {
        answer.push_back(x);
    }

    for (int x : equal)
    {
        answer.push_back(x);
    }

    for (int x : greater)
    {
        answer.push_back(x);
    }

    return answer;
}

// Optimal Approach (Dutch National Flag)
// Pattern : Three-Way Partition (Unstable)
// Time : O(n)
// Space: O(1)
// Constraint : Relative order is NOT preserved

void pivotPartition(vector<int> &nums, int pivot)
{
    int low = 0;
    int mid = 0;
    int high = nums.size() - 1;

    while (mid <= high)
    {
        if (nums[mid] < pivot)
        {
            swap(nums[low], nums[mid]);
            low++;
            mid++;
        }
        else if (nums[mid] == pivot)
        {
            mid++;
        }
        else
        {
            swap(nums[mid], nums[high]);
            high--;

            // Don't do mid++
            // Swapped element from high is still unprocessed.
        }
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

    int pivot;
    cin >> pivot;

    vector<int> answer = pivotArray(nums, pivot);

    for (int x : answer)
        cout << x << " ";

    return 0;
}

/*
Problem:
Array ko 3 parts mein partition karna hai using a given pivot.

1. Pivot se chhote elements left side par hone chahiye.
2. Pivot ke equal elements middle mein hone chahiye.
3. Pivot se bade elements right side par hone chahiye.

Input:  [4, 2, 7, 2, 5, 1, 8]
Pivot:  4

Output: [2, 2, 1, 4, 7, 5, 8]

Approach: Dutch National Flag Algorithm (3 Pointers)

Steps:
1. Three pointers initialize karo:
   low = 0, mid = 0, high = n - 1.

2. Array ko traverse karo jab tak mid <= high.

3. Agar nums[mid] < pivot:
   - nums[low] aur nums[mid] ko swap karo.
   - low++ aur mid++ karo.

4. Agar nums[mid] == pivot:
   - Element already correct partition mein hai.
   - Sirf mid++ karo.

5. Agar nums[mid] > pivot:
   - nums[mid] aur nums[high] ko swap karo.
   - high-- karo.
   - mid++ mat karo, kyunki swapped element abhi
     process nahi hua hai.

6. Loop complete hone par array 3 partitions mein
   divide ho jayega.

TC: O(n) - Har element ko maximum constant times process karte hain.
SC: O(1) - In-place rearrangement, extra array use nahi hota.

Note:
- low se pehle: Elements < pivot
- low se mid - 1: Elements == pivot
- high ke baad: Elements > pivot

Important:
Jab high ke saath swap hota hai, mid ko increment nahi karna hai.
*/