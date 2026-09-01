#include <iostream>
#include <vector>
using namespace std;

void duplicateZeros(vector<int> &arr)
{
    int n = arr.size();
    int zeros = 0;

    // Count zeros to be duplicated
    for (int x : arr)
    {
        if (x == 0)
        {
            zeros++;
        }
    }

    int i = n - 1;
    int j = n + zeros - 1;

    // Fill from the end
    while (i >= 0)
    {
        if (j < n)
        {
            arr[j] = arr[i];
        }

        if (arr[i] == 0)
        {
            j--;
            if (j < n)
            {
                arr[j] = 0;
            }
        }

        i--;
        j--;
    }
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    duplicateZeros(arr);

    for (int x : arr)
    {
        cout << x << " ";
    }

    return 0;
}