#include <bits/stdc++.h>
using namespace std;

int candy(vector<int>& ratings) {

    int n = ratings.size();

    vector<int> candies(n, 1);

    // Pass 1: Left -> Right
    for (int i = 1; i < n; i++) {

        if (ratings[i] > ratings[i - 1]) {
            candies[i] = candies[i - 1] + 1;
        }
    }

    // Pass 2: Right -> Left
    for (int i = n - 2; i >= 0; i--) {

        if (ratings[i] > ratings[i + 1]) {

            candies[i] = max(
                candies[i],
                candies[i + 1] + 1
            );
        }
    }

    int total = 0;

    for (int c : candies) {
        total += c;
    }

    return total;
}

int candyOptimal(vector<int>& ratings) {

    int n = ratings.size();

    if (n <= 1)
        return n;

    int total = 1;

    int up = 0;
    int down = 0;
    int peak = 0;

    for (int i = 1; i < n; i++) {

        if (ratings[i] > ratings[i - 1]) {

            // Increasing slope
            up++;
            down = 0;

            // Remember peak height
            peak = up;

            // New child gets up + 1 candies
            total += up + 1;
        }

        else if (ratings[i] < ratings[i - 1]) {

            // Decreasing slope
            down++;
            up = 0;

            // Add contribution of decreasing side
            total += down + 1;

            // If decreasing side is longer than
            // increasing side, peak needs one extra candy
            if (down > peak)
                total++;
        }

        else {

            // Equal ratings break the slope
            up = 0;
            down = 0;
            peak = 0;

            // New child gets minimum 1 candy
            total += 1;
        }
    }

    return total;
}

int main() {

    vector<int> ratings = {1, 3, 4, 5, 2, 1};

    cout << "Minimum candies = "
         << candy(ratings) << endl;

    return 0;
}