#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxRotateFunction(vector<int> &nums)
{
    int n = nums.size();

    long long totalSum = 0;
    long long currentF = 0;

    // Calculate total sum and F(0)
    for (int i = 0; i < n; i++)
    {
        totalSum += nums[i];
        currentF += 1LL * i * nums[i];
    }

    long long answer = currentF;

    // Derive F(k) from F(k - 1)
    for (int k = 1; k < n; k++)
    {
        int movedElement = nums[n - k];

        currentF = currentF + totalSum - 1LL * n * movedElement;

        answer = max(answer, currentF);
    }

    return answer;
}

int main()
{
    vector<int> nums = {4, 3, 2, 6};

    cout << maxRotateFunction(nums) << endl;

    return 0;
}