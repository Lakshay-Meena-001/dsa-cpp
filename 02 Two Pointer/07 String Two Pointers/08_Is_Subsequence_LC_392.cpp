// 08_Is_Subsequence_LC_392.cpp
// Pattern: Two Pointers + Greedy Matching
// Goal: Check karo s, t ka subsequence hai ya nahi

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        int i = 0; // s pointer
        int j = 0; // t pointer

        while (i < s.size() && j < t.size())
        {

            // Match mila → s pointer aage badhao
            if (s[i] == t[j])
            {
                i++;
            }

            // t ka current character consume/skip karo
            j++;
        }

        // Pura s match ho gaya?
        return i == s.size();
    }
};

int main()
{
    string s = "abc";
    string t = "ahbgdc";

    Solution obj;

    cout << boolalpha << obj.isSubsequence(s, t);

    return 0;
}