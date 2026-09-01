#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int maxRotateFunction(vector<int> &nums)
{
    int n = nums.size();

    long long totalSum = 0;
    long long currentRotation = 0;

    for (int i = 0; i < n; i++)
    {
        totalSum += nums[i];
        currentRotation += 1LL * i * nums[i]; //f(0) needs only first will calculate from this 
    }

    long long maximumRotation = currentRotation;

    for (int k = 1; k < n; k++)
    {
        currentRotation = currentRotation + totalSum - 1LL * n * nums[n - k];

        maximumRotation = max(maximumRotation, currentRotation);
    }

    return maximumRotation;
}

int main()
{
    vector<int> nums = {4, 3, 2, 6};

    cout << "Maximum Rotate Function = ";

    cout << maxRotateFunction(nums);

    return 0;
}