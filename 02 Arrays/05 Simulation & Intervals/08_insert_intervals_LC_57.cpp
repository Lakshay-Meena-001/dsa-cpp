#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
{
    vector<vector<int>> result;

    int startingPoint = 0;
    int endPoint = 1;

    for (int i = 0; i < intervals.size(); i++)
    {
        // Case 1: current interval is smaller than new interval so we can add the current interval to the result 
        if (intervals[i][endPoint] < newInterval[startingPoint])
        {
            result.push_back(intervals[i]);
        }

        // Case 2: Current interval is greater than the new interval so we can add the new interval to te result and then add the rest of the intervals to the result.  
        else if (intervals[i][startingPoint] > newInterval[endPoint])
        {
            result.push_back(newInterval);

            for (int j = i; j < intervals.size(); j++)
            {
                result.push_back(intervals[j]);
            }

            return result;
        }

        // Case 3: current interval overlaps with the new interval so we can merge the two intervals and update the new interval to the merged interval
        else
        {
            newInterval[startingPoint] = min(newInterval[startingPoint], intervals[i][startingPoint]);

            newInterval[endPoint] = max(newInterval[endPoint], intervals[i][endPoint]);
        }
    }

    // New interval is still not added
    result.push_back(newInterval);

    return result;
}

int main()
{
    vector<vector<int>> intervals =
        {
            {1, 2},
            {3, 5},
            {6, 7},
            {8, 10},
            {12, 16}};

    vector<int> newInterval = {4, 8};

    vector<vector<int>> result =
        insert(intervals, newInterval);

    for (auto interval : result)
    {
        cout << "[" << interval[0]
             << "," << interval[1]
             << "] ";
    }

    cout << '\n';

    return 0;
}