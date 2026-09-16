#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void reverseString(vector<char> &s)
    {

        int left = 0;
        int right = s.size() - 1;

        while (left < right)
        {
            // swap first and last element
            swap(s[left], s[right]);

            left++;
            right--;
        }
    }
};

int main()
{
    vector<char> s = {'h', 'e', 'l', 'l', 'o'};

    Solution obj;
    obj.reverseString(s);

    for (char ch : s)
    {
        cout << ch << " ";
    }

    return 0;
}