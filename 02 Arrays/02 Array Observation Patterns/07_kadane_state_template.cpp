#include<iostream>
#include<climits>
using namespace std;


// Kadane State Template

// Purpose : Learn the two memory variables used by Kadane

// Pattern : Running State + Running Best Answer

// Used In :
// LC53
// LC1749
// LC152 (Idea Extension)

// Time : O(n)
// Space : O(1)


int kadaneStateDemo(const int arr[], int n)
{
    int currentSum = 0;

    int bestSum = INT_MIN;

    for(int i=0;i<n;i++)
    {
        // Running Sum
        currentSum += arr[i];

        // Running Best
        if(currentSum > bestSum)
        {
            bestSum = currentSum;
        }
    }

    return bestSum;
}

int main()
{
    int arr[] = {2,5,-3,4};

    int n = sizeof(arr)/sizeof(arr[0]);

    cout<<"Best Sum = "<<kadaneStateDemo(arr,n);

    return 0;
}