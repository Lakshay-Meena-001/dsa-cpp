#include <iostream>
using namespace std;

class Solution
{
public:

    int findMaximum(const int arr[], int n)
    {
        int maximum = arr[0];

        for(int i = 1; i < n; i++)
        {
            if(arr[i] > maximum)
            {
                maximum = arr[i];
            }
        }

        return maximum;
    }

    int findMinimum(const int arr[], int n)
    {
        int minimum = arr[0];

        for(int i = 1; i < n; i++)
        {
            if(arr[i] < minimum)
            {
                minimum = arr[i];
            }
        }

        return minimum;
    }

    void findMaximumMinimum(const int arr[], int n)
    {
        int maximum = arr[0];
        int minimum = arr[0];

        for(int i = 1; i < n; i++)
        {
            if(arr[i] > maximum)
            {
                maximum = arr[i];
            }

            if(arr[i] < minimum)
            {
                minimum = arr[i];
            }
        }

        cout << "Maximum : " << maximum << endl;
        cout << "Minimum : " << minimum << endl;
    }
};

int main()
{
    int arr[] = {10,20,-5,0,20,-8,15,11};

    int n = sizeof(arr)/sizeof(arr[0]);

    Solution obj;

    cout << "Maximum : " << obj.findMaximum(arr,n) << endl;

    cout << "Minimum : " << obj.findMinimum(arr,n) << endl;

    cout << endl;

    obj.findMaximumMinimum(arr,n);

    return 0;
}