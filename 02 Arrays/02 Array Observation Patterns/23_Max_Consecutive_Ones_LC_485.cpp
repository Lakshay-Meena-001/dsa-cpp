#include <iostream>
#include <vector>
using namespace std;

int findMaxConsecutiveOnes(vector<int>& nums)
{
    int currentCount = 0;
    int maximumCount = 0;

    for(int value : nums)
    {
        if(value == 1)
        {
            currentCount++;
        }
        else
        {
            currentCount = 0;
        }

        maximumCount = max(maximumCount, currentCount);
    }

    return maximumCount;
}

int main()
{
    vector<int> nums = {1,1,0,1,1,1};

    cout << "Maximum Consecutive Ones = ";

    cout << findMaxConsecutiveOnes(nums);

    return 0;
}