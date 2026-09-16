// 07_Merge_Strings_Alternately_LC_1768.cpp
// Pattern: Two Independent String Pointers
// Goal: Dono strings ke characters ko alternate merge karna

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string mergeAlternately(string word1, string word2)
    {
        int i = 0; // word1 pointer
        int j = 0; // word2 pointer

        string result;

        while (i < word1.size() || j < word2.size())
        {

            // word1 ka character available hai
            if (i < word1.size())
            {
                result += word1[i];
                i++;
            }

            // word2 ka character available hai
            if (j < word2.size())
            {
                result += word2[j];
                j++;
            }
        }

        return result;
    }
};

int main()
{
    string word1 = "abc";
    string word2 = "pqr";

    Solution obj;

    cout << obj.mergeAlternately(word1, word2);

    return 0;
}