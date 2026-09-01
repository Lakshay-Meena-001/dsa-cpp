#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const vector<int>& a, const vector<int>& b)
{
    // Same start:
    // Bigger end should come first
    if (a[0] == b[0])
    {
        return a[1] > b[1];
    }

    // Otherwise:
    // Smaller start comes first
    return a[0] < b[0];
}

int removeCoveredIntervals(vector<vector<int>>& intervals)
{
    sort(intervals.begin(), intervals.end(), compare);

    int count = 0;
    int maxEnd = -1;

    for (auto& interval : intervals)
    {
        int end = interval[1];

        // Current interval is covered
        if (end <= maxEnd)
        {
            continue;
        }

        // Current interval is not covered
        count++;

        // Update farthest end
        maxEnd = end;
    }

    return count;
}

int main()
{
    vector<vector<int>> intervals =
    {
        {1,2},
        {1,3},
        {1,4}
    };

    cout << removeCoveredIntervals(intervals) << '\n';

    return 0;
}