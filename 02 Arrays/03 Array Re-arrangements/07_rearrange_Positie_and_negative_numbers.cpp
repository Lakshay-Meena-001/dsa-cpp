#include <iostream>
#include <vector>
using namespace std;

//--------------------------------------------------
// Brute / Optimal (Extra Space)
// Pattern : Stable Partition
// Time : O(n)
// Space: O(n)
//--------------------------------------------------

vector<int> rearrangeArray(vector<int> &nums)
{
    vector<int> positive;
    vector<int> negative;

    for (int num : nums)
    {
        if (num >= 0)
        {
            positive.push_back(num);
        }
        else
        {
            negative.push_back(num);
        }
    }

    vector<int> answer;

    int i = 0;
    int j = 0;

    // Alternate positives and negatives
    while (i < positive.size() && j < negative.size())
    {
        answer.push_back(positive[i++]);
        answer.push_back(negative[j++]);
    }

    // Remaining positives
    while (i < positive.size())
    {
        answer.push_back(positive[i++]);
    }

    // Remaining negatives
    while (j < negative.size())
    {
        answer.push_back(negative[j++]);
    }

    return answer;
}

//--------------------------------------------------
// Optimal (In-place Stable)
// Pattern : Stable Partition + Right Shift
// Time : O(n²)
// Space: O(1)
//--------------------------------------------------

void rearrangeInPlace(vector<int> &nums)
{
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        // Even index should contain positive number
        if (i % 2 == 0 && nums[i] >= 0)
        {
            continue;
        }

        // Odd index should contain negative number
        if (i % 2 == 1 && nums[i] < 0)
        {
            continue;
        }

        int j = i + 1;

        while (j < n)
        {
            if ((i % 2 == 0 && nums[j] >= 0) || (i % 2 == 1 && nums[j] < 0))
            {
                break;
            }

            j++;
        }

        if (j == n)
        {
            break;
        }

        int temp = nums[j];

        // Preserve relative order by shifting
        while (j > i)
        {
            nums[j] = nums[j - 1];
            j--;
        }

        nums[i] = temp;
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

    vector<int> answer = rearrangeArray(nums);

    for (int num : answer)
    {
        cout << num << " ";
    }

    return 0;
}