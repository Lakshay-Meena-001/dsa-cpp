#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int> &nums, int target)
{

    vector<vector<int>> ans;

    sort(nums.begin(), nums.end());

    int n = nums.size();

    // Fix first element
    for (int i = 0; i < n - 3; i++)
    {

        // Skip duplicate i
        if (i > 0 && nums[i] == nums[i - 1])
        {
            continue;
        }

        // Fix second element
        for (int j = i + 1; j < n - 2; j++)
        {

            // Skip duplicate j
            if (j > i + 1 && nums[j] == nums[j - 1])
            {
                continue;
            }

            int left = j + 1;
            int right = n - 1;

            while (left < right)
            {

                long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];

                // Found a quadruplet
                if (sum == target)
                {

                    ans.push_back({nums[i], nums[j], nums[left], nums[right]});

                    // Skip duplicate left values
                    while (left < right && nums[left] == nums[left + 1])
                    {
                        left++;
                    }

                    // Skip duplicate right values
                    while (left < right && nums[right] == nums[right - 1])
                    {
                        right--;
                    }

                    left++;
                    right--;
                }

                // Need a bigger sum
                else if (sum < target)
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
    }

    return ans;
}

int main()
{

    vector<int> nums = {
        1, 0, -1, 0, -2, 2};

    int target = 0;

    vector<vector<int>> result =
        fourSum(nums, target);

    for (const auto &quad : result)
    {

        cout << "[ ";

        for (int x : quad)
        {
            cout << x << " ";
        }

        cout << "]\n";
    }

    return 0;
}