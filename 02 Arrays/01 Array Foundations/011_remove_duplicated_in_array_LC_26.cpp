#include <iostream>
using namespace std;

class Solution
{
public:

    int removeDuplicates(int arr[], int n)
    {
        if(n == 0)
        {
            return 0;
        }

        int uniqueIndex = 0;

        for(int current = 1; current < n; current++)
        {
            if(arr[current] != arr[uniqueIndex])
            {
                uniqueIndex++;
                arr[uniqueIndex] = arr[current];
            }
        }

        return uniqueIndex + 1;
    }

    void printArray(const int arr[], int length)
    {
        for(int i = 0; i < length; i++)
        {
            cout << arr[i] << " ";
        }

        cout << endl;
    }
};

int main()
{
    int arr[] = {0,0,1,1,1,2,2,3,3,4};

    int n = sizeof(arr) / sizeof(arr[0]);

    Solution obj;

    cout << "Original Array : ";

    obj.printArray(arr, n);

    int k = obj.removeDuplicates(arr, n);

    cout << "\nUnique Count : " << k << endl;

    cout << "Modified Array : ";

    obj.printArray(arr, k);

    return 0;
}