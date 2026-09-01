#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

int maxAbsoluteSum(vector<int>& nums)
{
    // using Kadane's algorithm to find the maximum subarray sum and minimum subarray sum
    int currentMax = 0;
    int currentMin = 0;

    int answer = 0;

    for (int num : nums)
    {
        // kya mujhe max sum k liye current element ko add karn achahiye ya new element se ek new subarray start karna chahiye jo maximum sum provide kare 
        currentMax = max(0, currentMax + num);

         // kya mujhe min sum k liye current element ko add karn achahiye ya new element se ek new subarray start karna chahiye jo minimum sum provide kare 
        currentMin = min(0, currentMin + num);

        // dono m se maximum absolute sum ko answer m store karna hoga
        answer = max(answer, abs(currentMax));
        answer = max(answer, abs(currentMin));
    }

    return answer;
}

int main()
{
    vector<int> nums = {1, -3, 2, 3, -4};

    cout << maxAbsoluteSum(nums) << endl;

    return 0;
}