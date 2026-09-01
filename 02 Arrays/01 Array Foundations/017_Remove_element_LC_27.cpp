#include <iostream>
using namespace std;

class Solution
{
public:

    int removeElement(int arr[], int n, int val)
    {
        int write = 0;

        for(int current = 0; current < n; current++)
        {
            if(arr[current] != val)
            {
                arr[write] = arr[current];

                write++;
            }
        }

        return write;
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
    int arr[] = {3,2,2,3};

    int n = sizeof(arr)/sizeof(arr[0]);

    int val = 3;

    Solution obj;

    cout << "Original Array : ";

    obj.printArray(arr,n);

    int k = obj.removeElement(arr,n,val);

    cout << "Remaining Elements : ";

    obj.printArray(arr,k);

    cout << "Count : " << k;

    return 0;
}