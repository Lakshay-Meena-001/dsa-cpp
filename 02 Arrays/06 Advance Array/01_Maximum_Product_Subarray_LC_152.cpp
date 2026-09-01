#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxProduct(vector<int> &nums)
{
    int maxProduct = nums[0];
    int minProduct = nums[0];

    int answer = nums[0];

    for (int i = 1; i < nums.size(); i++)
    {
        int num = nums[i];

        // Store previous states because both
        // new max and new min need old values.
        int oldMax = maxProduct;
        int oldMin = minProduct;

        maxProduct = max({num, num * oldMax, num * oldMin});

        minProduct = min({num, num * oldMax, num * oldMin});

        answer = max(answer, maxProduct);
    }

    return answer;
}

int main()
{
    vector<int> nums = {-2, 3, -4};

    cout << maxProduct(nums) << endl;

    return 0;
}