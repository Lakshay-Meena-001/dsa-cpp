#include <iostream>
using namespace std;

// Running Maximum

// Purpose : Find maximum element using Running Maximum
// Pattern : Running State
// Used In : LC1014, LC414
// Time    : O(n)
// Space   : O(1)


int runningMaximum(const int arr[], int n)
{
    // Assume first element is maximum
    int maxTillNow = arr[0];

    // Traverse remaining elements
    for(int i = 1; i < n; i++)
    {
        // Update maximum if current element is larger
        if(arr[i] > maxTillNow)
        {
            maxTillNow = arr[i];
        }
    }

    return maxTillNow;
}

int main()
{
    int arr[] = {5,2,7,1,8,3};

    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Maximum = " << runningMaximum(arr,n);

    return 0;
}