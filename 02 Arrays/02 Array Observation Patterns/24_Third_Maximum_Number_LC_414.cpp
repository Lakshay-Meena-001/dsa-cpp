#include <iostream>
#include <vector>
#include <climits>
using namespace std;


int thirdMax(vector<int>& nums)
{
    long long firstMaximum = LLONG_MIN;
    long long secondMaximum = LLONG_MIN;
    long long thirdMaximum = LLONG_MIN;

    for(int number : nums)
    {
        // Ignore duplicate values
        if(number == firstMaximum ||
           number == secondMaximum ||
           number == thirdMaximum)
        {
            continue;
        }

        // New largest number
        if(number > firstMaximum)
        {
            thirdMaximum = secondMaximum;
            secondMaximum = firstMaximum;
            firstMaximum = number;
        }

        // New second largest number
        else if(number > secondMaximum)
        {
            thirdMaximum = secondMaximum;
            secondMaximum = number;
        }

        // New third largest number
        else if(number > thirdMaximum)
        {
            thirdMaximum = number;
        }
    }

    // Third maximum doesn't exist
    if(thirdMaximum == LLONG_MIN)
        return firstMaximum;

    return thirdMaximum;
}

int main()
{
    vector<int> nums = {2,2,3,1};

    cout << "Third Maximum = ";

    cout << thirdMax(nums);

    return 0;
}