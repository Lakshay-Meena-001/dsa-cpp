#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> shuffle(vector<int>& nums, int n)
    {
        vector<int> answer;

        // Reserve memory to avoid repeated reallocations.
        answer.reserve(2 * n);

        // Take one element from first half,
        // then one from second half.
        for (int i = 0; i < n; i++)
        {
            answer.push_back(nums[i]);
            answer.push_back(nums[i + n]);
        }

        return answer;
    }
};

int main()
{
    int n;

    cout << "Enter n: ";
    cin >> n;

    vector<int> nums(2 * n);

    cout << "Enter " << 2 * n << " elements: ";
    for (int i = 0; i < 2 * n; i++)
    {
        cin >> nums[i];
    }

    Solution obj;
    vector<int> result = obj.shuffle(nums, n);

    cout << "Shuffled Array: ";
    for (int x : result)
    {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}