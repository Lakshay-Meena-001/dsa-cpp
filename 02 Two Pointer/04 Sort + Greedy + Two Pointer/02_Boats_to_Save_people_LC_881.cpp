#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int numRescueBoats(vector<int> &people, int limit)
{   
    // to simple pointer isliye us ekar rahe hai ki minimum number of boats chahiye
    sort(people.begin(), people.end());

    int left = 0;
    int right = people.size() - 1;
    int boats = 0;

    while (left <= right)
    {
        // If lightest + heaviest can share a boat
        if (people[left] + people[right] <= limit)
        {
            left++;
        }

        // Heaviest person always gets a boat
        right--;
        boats++;
    }

    return boats;
}

int main()
{
    vector<int> people = {3, 2, 2, 1};
    int limit = 3;

    cout << numRescueBoats(people, limit) << endl;

    return 0;
}