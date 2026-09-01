#include <iostream>
using namespace std;

class Solution
{
public:

    int pivotIndex(int arr[], int n)
    {
        int totalSum = 0;

        for(int i = 0; i < n; i++)
        {
            totalSum += arr[i];
        }

        int leftSum = 0;

        for(int i = 0; i < n; i++)
        {
            int rightSum = totalSum - leftSum - arr[i];

            if(leftSum == rightSum)
            {
                return i;
            }

            leftSum += arr[i];
        }

        return -1;
    }
};

int main()
{
    int arr[] = {1,7,3,6,5,6};

    int n = sizeof(arr)/sizeof(arr[0]);

    Solution obj;

    cout << obj.pivotIndex(arr,n);

    return 0;
}