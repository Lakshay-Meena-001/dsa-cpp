// 04_Reverse_Words_in_a_String_III_LC_557.cpp
// Pattern: Two Pointers inside each word
// Goal: Har word reverse karna, word order same rakhna

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        int start = 0;

        for (int i = 0; i <= s.size(); i++)
        {

            // Space ya string end = current word ka end
            if (i == s.size() || s[i] == ' ')
            {
                int left = start;
                int right = i - 1;

                // Current word ko in-place reverse karo
                while (left < right)
                {
                    swap(s[left], s[right]);
                    left++;
                    right--;
                }

                start = i + 1; // Next word ka start
            }
        }

        return s;
    }
};

int main()
{
    string s = "Let's take LeetCode contest";

    Solution obj;

    cout << obj.reverseWords(s);

    return 0;
}