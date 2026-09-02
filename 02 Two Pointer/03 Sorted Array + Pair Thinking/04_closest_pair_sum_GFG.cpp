#include <bits/stdc++.h>
using namespace std;

pair<int, int> closestPairSum(vector<int>& arr, int target) {

    int left = 0;
    int right = arr.size() - 1;

    int bestDiff = INT_MAX;
    pair<int, int> answer;

    while (left < right) {

        int sum = arr[left] + arr[right];

        int diff = abs(sum - target);

        // Current pair is better
        if (diff < bestDiff) {
            bestDiff = diff;
            answer = {arr[left], arr[right]};
        }

        // Exact target: cannot get better than difference 0
        if (sum == target) {
            return {arr[left], arr[right]};
        }

        // Current sum is too small
        if (sum < target) {
            left++;
        }

        // Current sum is too large
        else {
            right--;
        }
    }

    return answer;
}

int main() {

    vector<int> arr = {1, 4, 7, 10, 14};

    int target = 12;

    pair<int, int> answer =
        closestPairSum(arr, target);

    cout << "Closest pair: "
         << answer.first << " "
         << answer.second << endl;

    cout << "Closest sum: "
         << answer.first + answer.second << endl;

    return 0;
}