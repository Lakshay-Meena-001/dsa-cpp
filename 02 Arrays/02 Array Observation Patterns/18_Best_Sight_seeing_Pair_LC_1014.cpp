#include <iostream>
#include <vector>
#include <climits>
using namespace std;


int maxScoreSightseeingPair(vector<int>& values)
{
    int n = values.size();

    // Initially first element is the best left candidate.
    int bestLeft = values[0] + 0;

    int maximumScore = INT_MIN;

    // Start from second element.
    for (int j = 1; j < n; j++)
    {
        // Calculate score using best previous candidate.
        int currentScore = bestLeft + values[j] - j;

        maximumScore = max(maximumScore, currentScore);

        // Update best candidate for future indices.
        bestLeft = max(bestLeft, values[j] + j);
    }

    return maximumScore;
}

int main()
{
    vector<int> values = {8,1,5,2,6};

    cout << "Maximum Sightseeing Score = ";

    cout << maxScoreSightseeingPair(values);

    return 0;
}