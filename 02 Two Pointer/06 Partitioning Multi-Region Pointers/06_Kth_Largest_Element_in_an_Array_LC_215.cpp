#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int partition(vector<int> &nums, int left, int right)
    {

        // Last element ko pivot bana rahe hain.
        int pivot = nums[right];

        // i = next position jahan pivot se chhota/equal
        // element place hoga.
        int i = left;

        for (int j = left; j < right; j++)
        {

            // j and i dono sath sath m chal rah ehai check karte hue ki hum pivot se chhote hai na jab kkoi bad aelement mil gay ausko pivot se swap kar denge 
            if (nums[j] <= pivot)
            {

                // Smaller/equal element ko left region mein bhejo.
                swap(nums[i], nums[j]);

                i++;
            }
        }

        // Ab pivot ko uski correct partition position par rakho.
        swap(nums[i], nums[right]);

        return i;
    }

    int findKthLargest(vector<int> &nums, int k)
    {

        int n = nums.size();

        // Kth largest = ascending sorted array ka (n-k)th index.
        int target = n - k;

        int left = 0;
        int right = n - 1;

        while (left <= right)
        {

            int pivotIndex = partition(nums, left, right);

            // Pivot exactly target position par aa gaya.
            if (pivotIndex == target)
            {
                return nums[pivotIndex];
            }

            // Target pivot ke RIGHT side mein hai.
            else if (pivotIndex < target)
            {
                left = pivotIndex + 1;
            }

            // Target pivot ke LEFT side mein hai.
            else
            {
                right = pivotIndex - 1;
            }
        }

        return -1; // Valid input mein yahan nahi aayega.
    }
};

int main()
{

    Solution sol;

    vector<int> nums = {3, 2, 1, 5, 6, 4};
    int k = 2;

    cout << sol.findKthLargest(nums, k);

    return 0;
}


/*

 */