#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:

    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {

        int i = m - 1;     // Last actual element of nums1
        int j = n - 1;     // Last element of nums2
        int k = m + n - 1; // Last position of nums1

        while (j >= 0)
        {
            if (i >= 0 && nums1[i] > nums2[j])
            {
                nums1[k] = nums1[i];
                i--;
            }
            else
            {
                nums1[k] = nums2[j];
                j--;
            }

            k--;
        }
    }
};

int main()
{

    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2 = {2, 5, 6};

    Solution solution;

    solution.merge(nums1, 3, nums2, 3);

    cout << "Merged array: ";

    for (int num : nums1)
    {
        cout << num << " ";
    }

    cout << endl;

    return 0;
}