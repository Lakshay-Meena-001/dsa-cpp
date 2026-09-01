#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals)
{
    if (intervals.empty())
    {
        return {};
    }

    sort(intervals.begin(), intervals.end());

    vector<vector<int>> result;

    vector<int> current = intervals[0];

    for (int i = 1; i < intervals.size(); i++)
    {
        vector<int> next = intervals[i];

        if (next[0] <= current[1])
        {
            current[1] = max(current[1], next[1]);
        }
        else
        {
            result.push_back(current);
            current = next;
        }
    }

    result.push_back(current);

    return result;
}

int main()
{
    vector<vector<int>> intervals =
    {
        {1, 3},
        {2, 6},
        {8, 10},
        {15, 18}
    };

    vector<vector<int>> result = merge(intervals);

    for (auto interval : result)
    {
        cout << "[" << interval[0]
             << "," << interval[1]
             << "] ";
    }

    cout << '\n';

    return 0;
}