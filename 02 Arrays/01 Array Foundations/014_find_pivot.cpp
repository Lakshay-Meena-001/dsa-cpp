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

        // pehla element means 0th index left sum kuch nahi hai to 0
        int leftSum = 0;

        for(int i = 0; i < n; i++)
        {
            // just thoda mathemtical trick, right sum = total sum - left sum - current element
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