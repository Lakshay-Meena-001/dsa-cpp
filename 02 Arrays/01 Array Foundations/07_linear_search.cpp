#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int linearSearch(const vector<int>& arr, int target)
    {
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] == target)
            {
                return i;
            }
        }

        return -1;
    }
};

int main()
{
    vector<int> arr = {12, 8, 15, 20, 5};
    int target = 20;

    Solution obj;

    int index = obj.linearSearch(arr, target);

    if (index != -1)
    {
        cout << "Target found at index : " << index << endl;
    }
    else
    {
        cout << "Target not found." << endl;
    }

    return 0;
}