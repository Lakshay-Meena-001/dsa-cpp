#include<iostream>
#include<vector>
using namespace std;

// LC136 - Single Number

// Pattern:
// XOR State
// Time : O(n)
// Space : O(1)

int singleNumber(vector<int>& nums)
{
    int answer = 0;

    for(int num : nums)
    {
        answer ^= num;
    }

    return answer;
}

int main()
{
    vector<int> nums =
    {4,1,2,1,2};

    cout<<"Single Number = ";

    cout<<singleNumber(nums);

    return 0;
}