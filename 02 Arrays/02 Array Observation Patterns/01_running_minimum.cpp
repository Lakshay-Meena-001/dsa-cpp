#include <iostream>
using namespace std;


// Running Minimum

// Purpose : Find minimum element using Running Minimum
// Pattern : Running State
// Time    : O(n)
// Space   : O(1)


int runningMinimum(const int arr[], int n)
{
    int minTillNow = arr[0];

    for(int i = 1; i < n; i++)
    {
        if(arr[i] < minTillNow)
        {
            minTillNow = arr[i];
        }
    }

    return minTillNow;
}

int main()
{
    int arr[] = {5,2,7,1,8,3};

    int n = sizeof(arr)/sizeof(arr[0]);

    cout<<"Minimum = "<<runningMinimum(arr,n);

    return 0;
}