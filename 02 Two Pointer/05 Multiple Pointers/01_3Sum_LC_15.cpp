#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int> &nums)
{
    vector<vector<int>> ans;

    // to pehle sort kardo array ko 
    sort(nums.begin(), nums.end());

    int n = nums.size();

    // bhai 3 pointers hai sorted array par ek i start second j jo ki i ka next and last k pointer last m k par
    //to sum 0 chahiye to sorted hai ek bar i fix karo j and k use kareneg agar abhi i j and k ka sum mila kar 0 se ham hai to j ko badha do zyada hai to k ko kam kardo 
    for (int i = 0; i < n - 2; i++)
    {

        // to multiple ya duplicate values hai or sorted bhi hai but ab jo bhi pointer move kar rahe hai i j and k to 
        // to agar maan lo pichle i j and k ki fixed value se ans mil gaya tha , ab i move hua but jo pichli i ki value thi and jo current i hai wo sam ehai to same permutation bana hoga but sam eto chahiey nahi to iskiye agar i ki current value piche k equal hai to skip same j and k ki value k liye bhi 
        if (i > 0 && nums[i] == nums[i - 1])
        {
            continue;
        }

        int left = i + 1;
        int right = n - 1;

        while (left < right)
        {
            //sum nikal liya current i j k 
            long long sum = (long long)nums[i] + nums[left] + nums[right];

            // agar sum 0 hai to haan ek ans mil gaya 
            if (sum == 0)
            {
                ans.push_back({nums[i], nums[left], nums[right]});

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

            else if (sum < 0)
            {
                left++;
            }

            else
            {
                right--;
            }
        }
    }

    return ans;
}

int main()
{

    vector<int> nums = {
        -1, 0, 1, 2, -1, -4};

    vector<vector<int>> result = threeSum(nums);

    for (auto &triplet : result)
    {
        cout << "[ ";
        for (int x : triplet)
        {
            cout << x << " ";
        }
        cout << "]\n";
    }

    return 0;
}