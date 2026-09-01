#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    // Approach 1 : Brute Force (O(n²), O(1))
    // Find final position of every element manually

    vector<int> bruteForce(vector<int> nums, int pivot)
    {
        int n = nums.size();

        vector<int> answer(n);

        vector<bool> filled(n, false);

        for (int i = 0; i < n; i++)
        {
            int position = 0;

            // Count elements smaller than current element
            if (nums[i] < pivot)
            {
                for (int j = 0; j < n; j++)
                {
                    if (nums[j] < pivot)
                        position++;
                }

                position = 0;

                for (int j = 0; j < i; j++)
                {
                    if (nums[j] < pivot)
                        position++;
                }
            }

            else if (nums[i] == pivot)
            {
                for (int j = 0; j < n; j++)
                {
                    if (nums[j] < pivot)
                        position++;
                }

                for (int j = 0; j < i; j++)
                {
                    if (nums[j] == pivot)
                        position++;
                }
            }

            else
            {
                for (int j = 0; j < n; j++)
                {
                    if (nums[j] <= pivot)
                        position++;
                }

                for (int j = 0; j < i; j++)
                {
                    if (nums[j] > pivot)
                        position++;
                }
            }

            answer[position] = nums[i];
        }

        return answer;
    }

    // Approach 2 : Better / Expected (O(n), O(n))
    // Three Arrays

    vector<int> better(vector<int> nums, int pivot)
    {
        vector<int> less;
        vector<int> equal;
        vector<int> greater;

        for (int x : nums)
        {
            if (x < pivot)
                less.push_back(x);

            else if (x == pivot)
                equal.push_back(x);

            else
                greater.push_back(x);
        }

        vector<int> answer;

        for (int x : less)
            answer.push_back(x);

        for (int x : equal)
            answer.push_back(x);

        for (int x : greater)
            answer.push_back(x);

        return answer;
    }

    // Approach 3 : Advanced Discussion

    void optimal(vector<int> nums, int pivot)
    {
        int left = 0;

        for (int right = 0; right < nums.size(); right++)
        {
            if (nums[right] < pivot)
            {
                swap(nums[left], nums[right]);
                left++;
            }
        }
    }

    void print(vector<int> &arr)
    {
        for (int x : arr)
            cout << x << " ";

        cout << endl;
    }
};

int main()
{
    Solution obj;

    vector<int> nums = {9, 12, 5, 10, 14, 3, 10};

    int pivot = 10;

    cout << "Original Array\n";

    obj.print(nums);

    cout << "\nApproach 1 : Brute Force\n";

    vector<int> ans1 = obj.bruteForce(nums, pivot);

    obj.print(ans1);

    cout << "\nApproach 2 : Better / Expected\n";

    vector<int> ans2 = obj.better(nums, pivot);

    obj.print(ans2);
    

    return 0;
}