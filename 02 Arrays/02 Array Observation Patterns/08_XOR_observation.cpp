#include <iostream>
using namespace std;

// XOR Observation Template

// Purpose : Find unique element when every other element appears exactly twice.

// Used In : LC136
// Time  : O(n)
// Space : O(1)
//---------------------------------------------------------

int xorObservation(const int arr[], int n)
{
    int answer = 0;

    for(int i = 0; i < n; i++)
    {
        answer ^= arr[i];
    }

    return answer;
}

int main()
{
    int arr[] = {2,1,2};

    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "Unique Element = "
         << xorObservation(arr, n);

    return 0;
}