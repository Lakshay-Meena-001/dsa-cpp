#include <iostream>
using namespace std;

class Solution
{
public:

    bool isSorted(const int arr[], int n)
    {
        for(int i = 0; i < n - 1; i++)
        {
            if(arr[i] > arr[i + 1])
            {
                return false;
            }
        }

        return true;
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
    int arr[] = {1,2,3,4,5};

    int n = sizeof(arr)/sizeof(arr[0]);

    Solution obj;

    cout << "Array : ";
    obj.printArray(arr,n);

    if(obj.isSorted(arr,n))
    {
        cout << "Array is Sorted";
    }
    else
    {
        cout << "Array is NOT Sorted";
    }

    return 0;
}