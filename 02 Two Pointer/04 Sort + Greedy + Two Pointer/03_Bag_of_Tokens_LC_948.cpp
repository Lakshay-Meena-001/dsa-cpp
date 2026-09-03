#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int bagOfTokensScore(vector<int> &tokens, int power)
{
    sort(tokens.begin(), tokens.end());

    int left = 0;
    int right = tokens.size() - 1;

    int score = 0;
    int maxScore = 0;

    while (left <= right)
    {
        // Face up:
        // Use the smallest token to gain score.
        if (power >= tokens[left])
        {
            power -= tokens[left];
            score++;
            maxScore = max(maxScore, score);

            left++;
        }

        // If we cannot afford the smallest token,
        // try to recover power by sacrificing one score.
        else if (score > 0)
        {
            power += tokens[right];
            score--;

            right--;
        }

        // Cannot gain score and cannot sacrifice score.
        else
        {
            break;
        }
    }

    return maxScore;
}

int main()
{
    vector<int> tokens = {100, 200, 300, 400};
    int power = 200;

    cout << bagOfTokensScore(tokens, power) << endl;

    return 0;
}