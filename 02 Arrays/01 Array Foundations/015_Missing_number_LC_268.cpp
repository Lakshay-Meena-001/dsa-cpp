#include <iostream>
using namespace std;

class Solution
{
public:

    int missingNumber(int arr[], int n)
    {
        // ye sirf 1 missing number ke liye kaam karega, agar 2 ya usse zyada missing number hai to ye kaam nahi karega
        // apna basic math formula use karenge, sum of first n natural numbers = n*(n+1)/2
        int expectedSum = n * (n + 1) / 2;

        int actualSum = 0;

        for(int i = 0; i < n; i++)
        {
            actualSum += arr[i];
        }

        return expectedSum - actualSum;
    }
};

int main()
{
    int arr[] = {3,0,1};

    int n = sizeof(arr)/sizeof(arr[0]);

    Solution obj;

    cout << obj.missingNumber(arr,n);

    return 0;
}