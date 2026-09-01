#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int minimumAverageDifference(vector<int> &nums)
{
    int n = nums.size();

    long long totalSum = 0;

    for (int x : nums)
    {
        totalSum += x;
    }

    long long leftSum = 0;

    long long minimumDifference = LLONG_MAX;

    int answerIndex = 0;

    for (int i = 0; i < n; i++)
    {
        leftSum += nums[i];

        long long rightSum = totalSum - leftSum;

        long long leftAverage = leftSum / (i + 1);

        long long rightAverage;

        if (i == n - 1)
        {
            rightAverage = 0;
        }
        else
        {
            rightAverage = rightSum / (n - i - 1);
        }

        long long difference = abs(leftAverage - rightAverage);

        if (difference < minimumDifference)
        {
            minimumDifference = difference;
            answerIndex = i;
        }
    }

    return answerIndex;
}

int main()
{
    vector<int> nums =
        {2, 5, 3, 9, 5, 3};

    cout << minimumAverageDifference(nums);

    return 0;
}