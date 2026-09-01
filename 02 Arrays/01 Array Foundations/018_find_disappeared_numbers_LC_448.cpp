#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution
{
public:

    vector<int> findDisappearedNumbers(int arr[], int n)
    {
        for(int i = 0; i < n; i++)
        {
            int index = abs(arr[i]) - 1;

            if(arr[index] > 0)
            {
                arr[index] = -arr[index];
            }
        }

        vector<int> answer;

        for(int i = 0; i < n; i++)
        {
            if(arr[i] > 0)
            {
                answer.push_back(i + 1);
            }
        }

        return answer;
    }
};

int main()
{
    int arr[] = {4,3,2,7,8,2,3,1};

    int n = sizeof(arr)/sizeof(arr[0]);

    Solution obj;

    vector<int> ans = obj.findDisappearedNumbers(arr,n);

    cout<<"Missing Numbers : ";

    for(int x : ans)
    {
        cout<<x<<" ";
    }

    return 0;
}