#include<iostream>
using namespace std;

// Boyer Moore Voting State

// Purpose : Find Majority Element

// Used In : LC169

// Time : O(n)
// Space : O(1)

int majorityElement(const int arr[], int n)
{
    int candidate = 0;

    int count = 0;

    for(int i=0;i<n;i++)
    {
        if(count == 0)
        {
            candidate = arr[i];
        }

        if(arr[i] == candidate)
        {
            count++;
        }
        else
        {
            count--;
        }
    }

    return candidate;
}

int main()
{
    int arr[] = {2,2,1,1,1,2,2};

    int n = sizeof(arr)/sizeof(arr[0]);

    cout<<"Majority Element = "
        <<majorityElement(arr,n);

    return 0;
}