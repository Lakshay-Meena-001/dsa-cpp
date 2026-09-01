#include <iostream>
using namespace std;

class Solution
{
public:

    void reverseArray(int arr[], int n)
    {
        int left = 0;
        int right = n - 1;

        while(left < right)
        {
            int temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;

            left++;
            right--;
        }
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
    int arr[] = {10,20,30,40,50};

    int n = sizeof(arr) / sizeof(arr[0]);

    Solution obj;

    cout << "Original Array : ";
    obj.printArray(arr, n);

    obj.reverseArray(arr, n);

    cout << "Reversed Array : ";
    obj.printArray(arr, n);

    return 0;
}