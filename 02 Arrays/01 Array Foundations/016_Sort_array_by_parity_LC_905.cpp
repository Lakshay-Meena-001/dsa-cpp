#include <iostream>
using namespace std;

class Solution
{
public:

    void sortByParity(int arr[], int n)
    {
        int left = 0;

        for(int current = 0; current < n; current++)
        {
            if(arr[current] % 2 == 0)
            {
                swap(arr[left], arr[current]);

                left++;
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
    int arr[] = {3,1,2,4};

    int n = sizeof(arr)/sizeof(arr[0]);

    Solution obj;

    cout << "Original Array : ";

    obj.printArray(arr,n);

    obj.sortByParity(arr,n);

    cout << "After Partition : ";

    obj.printArray(arr,n);

    return 0;
}