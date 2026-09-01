#include <iostream>
#include <vector>
using namespace std;

vector<int> rearrangeArray(vector<int>& nums)
{
    vector<int> answer(nums.size());

    int positiveIndex = 0;
    int negativeIndex = 1;

    for (int num : nums)
    {
        if (num > 0)
        {
            answer[positiveIndex] = num;
            positiveIndex += 2;
        }
        else
        {
            answer[negativeIndex] = num;
            negativeIndex += 2;
        }
    }

    return answer;
}

int main()
{
    int n;
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    vector<int> ans = rearrangeArray(nums);

    for (int x : ans)
    {
        cout << x << " ";
    }

    return 0;
}