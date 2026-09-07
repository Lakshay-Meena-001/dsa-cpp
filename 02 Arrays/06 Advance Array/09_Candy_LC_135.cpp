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

int main() {

    vector<int> ratings = {1, 3, 4, 5, 2, 1};

    cout << "Minimum candies = "
         << candy(ratings) << endl;

    return 0;
}