#include <iostream>
using namespace std;

class Solution
{
public:

    void moveZeroes(int arr[], int n)
    {
        int write = 0;

        for(int current = 0; current < n; current++)
        {
            if(arr[current] != 0)
            {
                swap(arr[write], arr[current]);

                write++;
            }
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
    int arr[] = {0,1,0,3,12};

    int n = sizeof(arr)/sizeof(arr[0]);

    Solution obj;

    cout << "Original Array : ";

    obj.printArray(arr,n);

    obj.moveZeroes(arr,n);

    cout << "After MoveZeroes : ";

    obj.printArray(arr,n);

    return 0;
}