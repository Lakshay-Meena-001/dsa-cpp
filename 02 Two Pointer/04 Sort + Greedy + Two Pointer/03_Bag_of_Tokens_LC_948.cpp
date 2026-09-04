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
        // to score badhana hai to best way hai sbse chhota token pick karna 
        if (power >= tokens[left])
        {   
            // power me se token jitni power chali gyi 
            power -= tokens[left];
            score++;
            maxScore = max(maxScore, score);

            left++;
        }

        // to agar enough power nahi hai to score kam karna padega aur power recover karna padega
        // to koshish karo ki maximum power recover ho aur score kam se kam use ho and jo token power recover k liye liya wo token wapis nahi le skte 
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