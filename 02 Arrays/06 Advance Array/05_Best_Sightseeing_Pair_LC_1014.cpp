#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int maxScoreSightseeingPair(vector<int> &values)
{
    int bestLeft = values[0]; // values[i] + i, i = 0
    int answer = INT_MIN;

    for (int j = 1; j < values.size(); j++)
    {
        // Current right contribution:
        // values[j] - j
        int currentRight = values[j] - j;

        // Combine with the best previous left contribution
        answer = max(answer, bestLeft + currentRight);

        // Current index can become the left index
        // for future positions.
        bestLeft = max(bestLeft, values[j] + j);
    }

    return answer;
}

int main()
{
    vector<int> values = {8, 1, 5, 2, 6};

    cout << maxScoreSightseeingPair(values) << endl;

    return 0;
}