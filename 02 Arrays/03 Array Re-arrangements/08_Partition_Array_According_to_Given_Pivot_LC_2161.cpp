#include <iostream>
#include <vector>
using namespace std;

// Brute / Optimal (Extra Space)
// Pattern : Stable Three-Way Partition
// Time : O(n)
// Space: O(n)

vector<int> pivotArray(vector<int> &nums, int pivot)
{
    vector<int> less;
    vector<int> equal;
    vector<int> greater;

    for (int num : nums)
    {
        if (num < pivot)
        {
            less.push_back(num);
        }

        else if (num == pivot)
        {
            equal.push_back(num);
        }

        else
        {
            greater.push_back(num);
        }
    }

    vector<int> answer;

    for (int x : less)
    {
        answer.push_back(x);
    }

    for (int x : equal)
    {
        answer.push_back(x);
    }

    for (int x : greater)
    {
        answer.push_back(x);
    }

    return answer;
}

// Optimal Approach (Dutch National Flag)
// Pattern : Three-Way Partition (Unstable)
// Time : O(n)
// Space: O(1)
// Constraint : Relative order is NOT preserved

void pivotPartition(vector<int> &nums, int pivot)
{
    int low = 0;
    int mid = 0;
    int high = nums.size() - 1;

    while (mid <= high)
    {
        if (nums[mid] < pivot)
        {
            swap(nums[low], nums[mid]);
            low++;
            mid++;
        }
        else if (nums[mid] == pivot)
        {
            mid++;
        }
        else
        {
            swap(nums[mid], nums[high]);
            high--;

            // Don't do mid++
            // Swapped element from high is still unprocessed.
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

    int pivot;
    cin >> pivot;

    vector<int> answer = pivotArray(nums, pivot);

    for (int x : answer)
        cout << x << " ";

    return 0;
}