#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int> &nums, int target)
{

    vector<vector<int>> answer;

    sort(nums.begin(), nums.end());

    int n = nums.size();

    for (int i = 0; i < n - 3; i++)
    {

        // Skip duplicate first values
        if (i > 0 && nums[i] == nums[i - 1])
        {
            continue;
        }

        for (int j = i + 1; j < n - 2; j++)
        {

            // Skip duplicate second values
            if (j > i + 1 && nums[j] == nums[j - 1])
            {
                continue;
            }

            int left = j + 1;
            int right = n - 1;

            while (left < right)
            {

                long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];

                if (sum == target)
                {

                    answer.push_back({nums[i], nums[j], nums[left], nums[right]});

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

                else if (sum < target)
                {
                    // Need a bigger sum
                    left++;
                }

                else
                {
                    // Need a smaller sum
                    right--;
                }
            }
        }
    }

    return answer;
}

int main()
{

    vector<int> nums = {
        1, 0, -1, 0, -2, 2};

    int target = 0;

    vector<vector<int>> answer =
        fourSum(nums, target);

    for (auto &quad : answer)
    {

        cout << "[";

        for (int x : quad)
            cout << x << " ";

        cout << "] ";
    }

    return 0;
}