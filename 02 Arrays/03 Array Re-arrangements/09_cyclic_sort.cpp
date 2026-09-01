#include <iostream>
#include <vector>
using namespace std;

//--------------------------------------------------
// Cyclic Sort
// Pattern : Correct Position
// Time : O(n)
// Space: O(1)
// Constraint : Values must be from 1...n
//--------------------------------------------------

void cyclicSort(vector<int> &nums)
{
    int i = 0;

    while (i < nums.size())
    {
        int correctIndex = nums[i] - 1;

        if (nums[i] != nums[correctIndex])
        {
            swap(nums[i], nums[correctIndex]);
        }
        else
        {
            i++;
        }
    }
}

int main()
{
    int n;
    cout << "Enter size: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter elements (1 to n): ";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    cyclicSort(nums);

    cout << "Sorted Array: ";
    for (int x : nums)
    {
        cout << x << " ";
    }

    return 0;
}
/*
| i   | Array     | Action                             |
| --- | --------- | ---------------------------------- |
| 0   | 3 5 2 1 4 | 3 ki correct index = 2 → swap(3,2) |
| 0   | 2 5 3 1 4 | 2 ki correct index = 1 → swap(2,5) |
| 0   | 5 2 3 1 4 | 5 ki correct index = 4 → swap(5,4) |
| 0   | 4 2 3 1 5 | 4 ki correct index = 3 → swap(4,1) |
| 0   | 1 2 3 4 5 | Ab correct hai → `i++`             |
| 1-4 | 1 2 3 4 5 | Sab correct → End                  |

*/