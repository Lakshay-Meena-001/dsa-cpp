#include<iostream>
#include<vector>
using namespace std;

// LC169 - Majority Element
// Pattern:
// Boyer-Moore Voting Algorithm
// Time : O(n)
// Space : O(1)

int majorityElement(vector<int>& nums)
{
    int candidate = 0;
    int count = 0;

    for(int num : nums)
    {
        // No current candidate
        if(count == 0)
        {
            candidate = num;
            count = 1;
        }
        // Same candidate
        else if(num == candidate)
        {
            count++;
        }
        // Different element -> cancel
        else
        {
            count--;
        }
    }

    return candidate;
}

int main()
{
    vector<int> nums =
    {2,2,1,1,1,2,2};

    cout<<"Majority Element = ";

    cout<<majorityElement(nums);

    return 0;
}