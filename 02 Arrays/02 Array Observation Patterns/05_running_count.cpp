#include <iostream>
using namespace std;

// Running Count

// Purpose : Count elements satisfying a condition
// Pattern : Running State
// Used In : LC485 (Foundation)
// Time    : O(n)
// Space   : O(1)

int runningCountPositive(const int arr[], int n)
{
    int count = 0;

    for(int i = 0; i < n; i++)
    {
        if(arr[i] > 0)
        {
            count++;
        }
    }

    return count;
}

int main()
{
    int arr[] = {10,20,-5,0,20,-8,15,11};

    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "Positive Count = "
         << runningCountPositive(arr,n);

    return 0;
}