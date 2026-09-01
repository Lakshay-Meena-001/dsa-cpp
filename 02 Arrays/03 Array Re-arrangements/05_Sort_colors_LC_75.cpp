#include <iostream>
#include <vector>
using namespace std;

//--------------------------------------------------
// Brute / Better Approach (Counting Sort)
// Time : O(n)
// Space: O(1)
//--------------------------------------------------
void sortColorsBrute(vector<int> &nums)
{
    int zero = 0;
    int one = 0;
    int two = 0;

    for (int num : nums)
    {
        if (num == 0)
        {
            zero++;
        }
        else if (num == 1)
        {
            one++;
        }
        else
        {
            two++;
        }
    }

    int index = 0;

    while (zero--)
    {
        nums[index++] = 0;
    }

    while (one--)
    {
        nums[index++] = 1;
    }

    while (two--)
    {
        nums[index++] = 2;
    }
}

// Optimal Approach (Dutch National Flag Algorithm)
// Time : O(n)
// Space: O(1)

void sortColorsOptimal(vector<int> &nums)
{
    int low = 0;
    int mid = 0;
    int high = nums.size() - 1;

    while (mid <= high)
    {
        if (nums[mid] == 0)
        {
            swap(nums[low], nums[mid]);
            low++;
            mid++;
        }
        else if (nums[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(nums[mid], nums[high]);
            high--;
            //why not mid++ here ? because we dont know what we swaped from high index
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

    // Copy for both approaches
    vector<int> brute = nums;
    vector<int> optimal = nums;

    sortColorsBrute(brute);
    sortColorsOptimal(optimal);

    cout << "Brute : ";
    for (int x : brute)
        cout << x << " ";
    cout << endl;

    cout << "Optimal : ";
    for (int x : optimal)
        cout << x << " ";
    cout << endl;

    return 0;
}