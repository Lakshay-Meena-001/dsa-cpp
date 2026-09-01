#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int eraseOverlapIntervals(vector<vector<int>> &intervals)
{
    // Sort by ending point
    sort(intervals.begin(), intervals.end(),[](const vector<int> &a, const vector<int> &b)
         {
             return a[1] < b[1];
         });

    int removed = 0;

    // End of the last interval we kept
    int lastEnd = intervals[0][1];

    for (int i = 1; i < intervals.size(); i++)
    {
        int start = intervals[i][0];
        int end = intervals[i][1];

        // Overlap
        if (start < lastEnd)
        {
            removed++;
        }
        else
        {
            // No overlap, keep this interval
            lastEnd = end;
        }
    }

    return removed;
}

int main()
{
    vector<vector<int>> intervals =
        {
            {1, 2},
            {2, 3},
            {3, 4},
            {1, 3}};

    cout << eraseOverlapIntervals(intervals) << '\n';

    return 0;
}