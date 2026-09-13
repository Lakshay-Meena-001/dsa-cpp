#include <bits/stdc++.h>
using namespace std;

int threeSumClosest(vector<int> &nums, int target)
{

    sort(nums.begin(), nums.end());

    int n = nums.size();

    // First possible triplet kyuki 0 nahi rakh skte nahi to 0 to already best answer hai 
    int bestSum = nums[0] + nums[1] + nums[2];

    for (int i = 0; i < n - 2; i++)
    {

        // Two pointers
        int left = i + 1;
        int right = n - 1;

        while (left < right)
        {

            // sum nikal lo current pointers par
            int sum = nums[i] + nums[left] + nums[right];

            // Is this sum closer to target?
            if (abs(sum - target) < abs(bestSum - target))
            {
                bestSum = sum;
            }

            // Exact target: cannot do better
            if (sum == target)
            {
                return target;
            }

            // Need a bigger sum
            if (sum < target)
            {
                left++;
            }

            // Need a smaller sum
            else
            {
                right--;
            }
        }
    }

    return bestSum;
}

int main()
{

    vector<int> nums = {-1, 2, 1, -4};

    int target = 1;

    cout << "Closest Sum = "
         << threeSumClosest(nums, target)
         << endl;

    return 0;
}