#include <iostream>
using namespace std;

// Running Best Answer

// Purpose : Maintain best answer seen so far
// Pattern : Running Best Answer
// Used In : LC121, LC53, LC1014, LC1749
// Time    : O(n)
// Space   : O(1)

int runningBestMaximum(const int arr[], int n)
{
    int bestAnswer = arr[0];

    for(int i = 1; i < n; i++)
    {
        if(arr[i] > bestAnswer)
        {
            bestAnswer = arr[i];
        }
    }

    return bestAnswer;
}

int main()
{
    int arr[] = {5,2,7,1,8,3};

    int n = sizeof(arr)/sizeof(arr[0]);

    cout<<"Best Answer = "<<runningBestMaximum(arr,n);

    return 0;
}