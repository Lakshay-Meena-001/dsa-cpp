#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:

    void rotate(int arr[], int n, int k)
    {
        if(n == 0)
        {
            return;
        }

        // agar 100 times boldiya to divide by n reduce karega operatiions ko 
        k %= n;

        reverse(arr, arr + n);

        reverse(arr, arr + k);

        reverse(arr + k, arr + n);
    }

    void printArray(const int arr[], int n)
    {
        for(int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }

        cout << endl;
    }
};

int main()
{
    int arr[] = {1,2,3,4,5,6,7};

    int n = sizeof(arr) / sizeof(arr[0]);

    int k = 3;

    Solution obj;

    cout << "Original Array : ";

    obj.printArray(arr,n);

    obj.rotate(arr,n,k);

    cout << "Rotated Array  : ";

    obj.printArray(arr,n);

    return 0;
}
/*
void reverseArray(int arr[], int left, int right)
{
    while(left < right)
    {
        swap(arr[left], arr[right]);
        left++;
        right--;
    }
}

void rotate(int arr[], int n, int k)
{
    if(n == 0)
        return;

    k %= n;

    // Reverse first (n-k) elements
    reverseArray(arr, 0, n - k - 1);

    // Reverse last k elements
    reverseArray(arr, n - k, n - 1);

    // Reverse complete array
    reverseArray(arr, 0, n - 1);
}
*/