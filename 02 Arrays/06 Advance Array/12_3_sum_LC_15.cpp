#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int> &nums)
{

    // vector of vector kyuki permutations chahiye
    vector<vector<int>> answer;

    // Sorting gives us the two-pointer property.
    sort(nums.begin(), nums.end());

    int n = nums.size();

    // to outer loop har ek element fix baher ka and n-2 tak chalega
    for (int i = 0; i < n - 2; i++)
    {

        // shuru se sabhi values same hai to har bar same array ka ans banta jyga same permutation to new ya unique k liye jabtk different element nahi milta skip karo
        if (i > 0 && nums[i] == nums[i - 1])
        {
            continue;
        }

        // left ko i k next par rakh diya and right ko last element par
        int left = i + 1;
        int right = n - 1;

        while (left < right)
        {

            // current element fixed par har left and right k element k indexes ka sum
            long long sum = (long long)nums[i] + nums[left] + nums[right];

            if (sum == 0)
            {

                // to ek ansewr mil gaya
                answer.push_back({nums[i], nums[left], nums[right]});

                // Skip duplicate left values.
                while (left < right && nums[left] == nums[left + 1])
                {
                    left++;
                }

                // Skip duplicate right values.
                while (left < right && nums[right] == nums[right - 1])
                {
                    right--;
                }

                // Move both after finding answer.
                left++;
                right--;
            }

            else if (sum < 0)
            {
                // Need a bigger sum.
                left++;
            }

            else
            {
                // Need a smaller sum.
                right--;
            }
        }
    }

    return answer;
}

int main()
{

    vector<int> nums = {-1, 0, 1, 2, -1, -4};

    vector<vector<int>> answer = threeSum(nums);

    for (auto &triplet : answer)
    {

        cout << "[";

        for (int x : triplet)
        {
            cout << x << " ";
        }

        cout << "] ";
    }

    return 0;
}