#include <bits/stdc++.h>
using namespace std;

int jump(vector<int>& nums) {
    int jumps = 0;

    // End of the range reachable using current number of jumps
    int currentEnd = 0;

    // Farthest position we can reach from current range
    int farthest = 0;

    // We don't need to process the last index.
    // Once we reach it, answer is already determined.
    for (int i = 0; i < nums.size() - 1; i++) {

        // Find the farthest position reachable
        // from all indices in the current range.
        farthest = max(farthest, i + nums[i]);

        // Current jump's range is exhausted.
        if (i == currentEnd) {
            jumps++;

            // For the next jump, we can reach up to
            // the farthest position discovered so far.
            currentEnd = farthest;
        }
    }

    return jumps;
}

int main() {
    vector<int> nums = {2, 3, 1, 1, 4};

    cout << "Minimum jumps = " << jump(nums) << endl;

    return 0;
}