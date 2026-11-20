#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// LC152 - Maximum Product Subarray
// Pattern:
// Running Maximum Product
// Running Minimum Product
// Time : O(n)
// Space : O(1)

int maxProduct(vector<int> &nums)
{
    // to is problem ka algorith kya hai ki humko maximum product subarray chahiye aur array me negative numbers bhi ho sakte hai.
    // so humko maximum product ke liye running maximum product aur running minimum product dono maintain karna padega kyuki negative number ke sath multiply karne se minimum product maximum product me convert ho sakta hai.
    int currentMax = nums[0];
    int currentMin = nums[0];

    int answer = nums[0];

    for (int i = 1; i < nums.size(); i++)
    {
        // Save previous state kyuki currentMax and currentMin will be updated
        int prevMax = currentMax;
        int prevMin = currentMin;

        // Maximum Product ending at index i
        currentMax = max({nums[i], prevMax * nums[i], prevMin * nums[i]});

        // Minimum Product ending at index i
        currentMin = min({nums[i], prevMax * nums[i], prevMin * nums[i]});

        // Update overall answer
        answer = max(answer, currentMax);
    }

    return answer;
}

int main()
{
    vector<int> nums =
        {-2, 3, -4};

    cout << "Maximum Product = ";

    cout << maxProduct(nums);

    return 0;
}