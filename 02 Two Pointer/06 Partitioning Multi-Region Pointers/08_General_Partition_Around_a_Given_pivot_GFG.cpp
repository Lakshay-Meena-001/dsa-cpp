#include <bits/stdc++.h>
using namespace std;

void partitionAroundPivot(vector<int> &nums, int pivot)
{

    int left = 0;
    int right = nums.size() - 1;

    while (left <= right)
    {

        // Jab tak left wala element already < pivot hai,
        // woh correct region mein hai.
        while (left <= right && nums[left] < pivot)
        {
            left++;
        }

        // Jab tak right wala element already > pivot hai,
        // woh correct region mein hai.
        while (left <= right && nums[right] > pivot)
        {
            right--;
        }

        // Ab dono pointers aise elements par rukenge
        // jo apni desired side par nahi hain.
        if (left <= right)
        {

            swap(nums[left], nums[right]);

            left++;
            right--;
        }
    }
}

int main()
{

    vector<int> nums = {9, 12, 3, 5, 14, 10, 10};
    int pivot = 10;

    partitionAroundPivot(nums, pivot);

    for (int x : nums)
    {
        cout << x << " ";
    }

    return 0;
}