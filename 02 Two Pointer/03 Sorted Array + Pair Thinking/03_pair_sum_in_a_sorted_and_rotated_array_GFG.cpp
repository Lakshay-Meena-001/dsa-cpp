#include <iostream>
#include <vector>
using namespace std;

bool pairInSortedRotatedArray(vector<int> &arr, int target)
{
    int n = arr.size();

    // Find the index of the smallest element.
    // This is the logical starting point of the sorted order.

    // int left = 0;
    // int i = 1;

    // while (i < n)
    // {
    //     if (arr[i] < arr[left])
    //     {
    //         left = i;
    //     }

    //     i++;
    // }
    
    int left = 0;

    for (int i = 1; i < n; i++)
    {
        if (arr[i] < arr[left])
        {
            left = i;
        }
    }

    // Largest element is immediately before the smallest
    // element in the circular sorted order.
    int right = (left - 1 + n) % n;

    while (left != right)
    {
        int sum = arr[left] + arr[right];

        if (sum == target)
        {
            return true;
        }
        else if (sum < target)
        {
            left = (left + 1) % n;
        }
        else
        {
            right = (right - 1 + n) % n;
        }
    }

    return false;
}

int main()
{
    vector<int> arr = {11, 15, 2, 5, 7, 9};
    int target = 14;

    cout << (pairInSortedRotatedArray(arr, target)
                 ? "Pair exists"
                 : "Pair does not exist")
         << '\n';

    return 0;
}