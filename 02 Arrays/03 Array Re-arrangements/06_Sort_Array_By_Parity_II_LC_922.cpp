#include <iostream>
#include <vector>
using namespace std;

//--------------------------------------------------
// Optimal Approach
// Pattern : Fixed Position Placement
// Time : O(n)
// Space: O(n)
//--------------------------------------------------

vector<int> sortArrayByParityII(vector<int> &nums)
{
    int n = nums.size();

    vector<int> answer(n);

    int evenIndex = 0;
    int oddIndex = 1;

    for (int num : nums)
    {
        if (num % 2 == 0)
        {
            answer[evenIndex] = num;
            evenIndex += 2;
        }
        else
        {
            answer[oddIndex] = num;
            oddIndex += 2;
        }
    }

    return answer;
}

//--------------------------------------------------
// In-place Approach (Interview Follow-up)
// Pattern : Partition + Two Pointer
// Time : O(n)
// Space: O(1)
//--------------------------------------------------

void sortArrayByParityIIInPlace(vector<int> &nums)
{
    int evenIndex = 0;
    int oddIndex = 1;

    int n = nums.size();

    while (evenIndex < n && oddIndex < n)
    {
        if (nums[evenIndex] % 2 == 0)
        {
            evenIndex += 2;
        }
        else if (nums[oddIndex] % 2 == 1)
        {
            oddIndex += 2;
        }
        else
        {
            swap(nums[evenIndex], nums[oddIndex]);
            // Both wrong positions become correct after swap
        }
    }
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

    vector<int> answer = sortArrayByParityII(nums);

    for (int num : answer)
    {
        cout << num << " ";
    }

    return 0;
}