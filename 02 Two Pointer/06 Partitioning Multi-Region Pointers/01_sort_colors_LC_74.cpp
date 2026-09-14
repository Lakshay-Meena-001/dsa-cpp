#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {

        // low = next position where a 0 should go.
        int low = 0;

        // mid = current element of the UNKNOWN region.
        int mid = 0;

        // high = next position where a 2 should go.
        int high = nums.size() - 1;

        // Jab tak UNKNOWN region exist karta hai,
        // tab tak processing continue karni hai.
        while (mid <= high) {

            // Current unknown element check karo.
            if (nums[mid] == 0) {

                // 0 ko left/0-region mein bhejo.
                swap(nums[low], nums[mid]);

                // low ke left mein ab ek aur 0 permanently placed hai.
                low++;

                // mid par bhi ab known element aa gaya,
                // isliye next unknown element par move kar sakte hain.
                mid++;

            }
            else if (nums[mid] == 1) {

                // 1 already middle region mein belong karta hai.
                // Isliye sirf unknown scanner ko aage badhao.
                mid++;

            }
            else { // nums[mid] == 2

                // 2 ko right/2-region mein bhejo.
                swap(nums[mid], nums[high]);

                // high ke right mein ab ek aur 2 permanently placed hai.
                high--;

                // IMPORTANT:
                // mid ko move nahi karna.
                //
                // Kyunki high se jo element mid par aaya hai,
                // woh UNKNOWN hai. Pehle usko inspect karenge.
            }
        }
    }
};

int main() {

    vector<int> nums = {2, 0, 2, 1, 1, 0};

    Solution obj;
    obj.sortColors(nums);

    // Final sorted array print karo.
    for (int x : nums) {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}