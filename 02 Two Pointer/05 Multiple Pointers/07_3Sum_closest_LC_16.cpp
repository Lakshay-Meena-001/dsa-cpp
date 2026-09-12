#include <bits/stdc++.h>
using namespace std;

int threeSumClosest(vector<int> &nums, int target)
{

    // to index ki need nahi ki in place chahiye ho to sort kar sktehai two pointer sk liye
    sort(nums.begin(), nums.end());

    int n = nums.size();

    // pehli 3 value k sum ko hi closest maan k chal rahe hai
    int closestSum = nums[0] + nums[1] + nums[2];

    for (int i = 0; i < n - 2; i++)
    {

        // left hoga i matlab first element ka next and right element last ka
        int left = i + 1;
        int right = n - 1;

        while (left < right)
        {

            // jo abhi 3 pointers hai wo lys sum de rahe hai
            int currentSum = nums[i] + nums[left] + nums[right];

            // Check whether current sum
            // is closer to target.
            if (abs(currentSum - target) < abs(closestSum - target))
            {

                closestSum = currentSum;
            }

            // Exact target found.
            // Distance = 0, cannot improve.
            if (currentSum == target)
            {
                return currentSum;
            }

            // Need a bigger sum.
            if (currentSum < target)
            {
                left++;
            }

            // Need a smaller sum.
            else
            {
                right--;
            }
        }
    }

    return closestSum;
}

int main()
{

    vector<int> nums = {
        -1, 2, 1, -4};

    int target = 1;

    cout << threeSumClosest(nums, target);

    return 0;
}