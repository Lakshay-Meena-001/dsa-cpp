#include<iostream>
#include<vector>
using namespace std;

// LC238 - Product of Array Except Self
// Pattern:
// Prefix Product + Suffix Product
// Time : O(n)
// Space : O(1) Extra Space


vector<int> productExceptSelf(vector<int>& nums)
{
    int n = nums.size();

    vector<int> answer(n);

    int prefix = 1;

    // Prefix Pass to calculate the prefix product for each index except the current index
    for(int i = 0; i < n; i++)
    {
        answer[i] = prefix;
        prefix *= nums[i];
    }

    int suffix = 1;

    // Suffix Pass to calculate the suffix product for each index except the current index and multiply it with the prefix product
    for(int i = n - 1; i >= 0; i--)
    {
        answer[i] *= suffix;
        suffix *= nums[i];
    }

    return answer;
}

int main()
{
    vector<int> nums = {1,2,3,4};

    vector<int> ans = productExceptSelf(nums);

    for(int x : ans)
        cout << x << " ";

    return 0;
}