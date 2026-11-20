#include <iostream>
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

    // bohot easy hai ye algorithm, bas 2 variable leke chalna hai, ek candidate aur ek count. and kaam kaise karta hai boyer moore algorithm, ye algorithm basically ye kaam karta hai ki agar kisi element ka count 0 ho jata hai to usko candidate bana do aur agar same element aata hai to count++ kar do aur agar different element aata hai to count-- kar do. and finally jo candidate bacha wo majority element hoga.

    for (int i = 0; i < n; i++)
    {
        // abhi koi element nahi select kiya means candidate hi nahi hai koi to count 0 hoga aur candidate ko arr[i] bana do.
        if (count == 0)
        {
            candidate = arr[i];
        }

        // ab same element mil gaya to count++ kar do aur agar different element mil gaya to count-- kar do.
        if (arr[i] == candidate)
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
    int arr[] = {2, 2, 1, 1, 1, 2, 2};

    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Majority Element = "
         << majorityElement(arr, n);

    return 0;
}