// 10_Check_If_Two_String_Arrays_Are_Equivalent_LC_1662.cpp
// Pattern: Two Pointers across Multiple Strings
// Goal: Dono string arrays ka character-by-character comparison

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool arrayStringsAreEqual(vector<string> &word1, vector<string> &word2)
    {
        int i = 0, j = 0; // word1: string + character pointer
        int k = 0, l = 0; // word2: string + character pointer

        while (i < word1.size() && k < word2.size())
        {

            // Current characters compare karo
            if (word1[i][j] != word2[k][l])
            {
                return false;
            }

            j++;
            l++;

            // word1 ki current string khatam
            if (j == word1[i].size())
            {
                i++;
                j = 0;
            }

            // word2 ki current string khatam
            if (l == word2[k].size())
            {
                k++;
                l = 0;
            }
        }

        // Dono arrays completely consume hone chahiye
        return i == word1.size() && k == word2.size();
    }
};

int main()
{
    vector<string> word1 = {"ab", "c"};
    vector<string> word2 = {"a", "bc"};

    Solution obj;

    cout << boolalpha
         << obj.arrayStringsAreEqual(word1, word2);

    return 0;
}