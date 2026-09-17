#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void nextPermutation(vector<int>& nums) {

    int n = nums.size();

    // Step 1: Right se first increasing pair find karo why i-2 kyuki i ko uske pichle element se compare karna hai reverse direction m jaate hue
    int i = n - 2;

    while (i >= 0 && nums[i] >= nums[i + 1])
     {
        i--;
    }

    // Pivot mila
    if (i >= 0) {

        // Step 2: Right se pivot se just-greater element
        int j = n - 1;

        while (nums[j] <= nums[i]) {
            j--;
        }

        swap(nums[i], nums[j]);
    }

    // Step 3: Suffix ko smallest order mein lao
    reverse(nums.begin() + i + 1, nums.end());
}

int main()
{
    vector<int> nums = {1, 2, 7, 4, 3, 1};

    nextPermutation(nums);

    cout << "Next Permutation: ";

    for (int x : nums) {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}

/*
Input:
[1,2,7,4,3,1]

Output:
[1,3,1,2,4,7]

Core Pattern:
Next Permutation

Steps:
1. Find pivot from right.
2. Find smallest greater element in suffix.
3. Swap them.
4. Reverse suffix.

TC: O(n)
SC: O(1)
*/