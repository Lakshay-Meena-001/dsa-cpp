#include <iostream>
using namespace std;

// Running Sum

// Purpose : Find sum using Running Sum
// Pattern : Accumulator / Running State
// Used In : LC53, LC2256, LC1749
// Time    : O(n)
// Space   : O(1)


int runningSum(const int arr[], int n)
{
    int currentSum = 0;

    for(int i = 0; i < n; i++)
    {
        currentSum += arr[i];
    }

    return currentSum;
}

int main()
{
    int arr[] = {5,2,7,1,8,3};

    int n = sizeof(arr)/sizeof(arr[0]);

    cout<<"Running Sum = "<<runningSum(arr,n);

    return 0;
}