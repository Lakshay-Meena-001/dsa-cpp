// 06_Valid_Word_Abbreviation_Interview.cpp
// Pattern: Two Pointers + Number Parsing
// Goal: Abbreviation ko word ke against directly validate karna

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool validWordAbbreviation(string word, string abbr)
    {
        int i = 0; // word pointer
        int j = 0; // abbr pointer

        while (j < abbr.size())
        {

            // Digit mila → number of characters skip karne hain
            if (isdigit(abbr[j]))
            {

                // Leading zero invalid hai
                if (abbr[j] == '0')
                {
                    return false;
                }

                int num = 0;

                // Complete number parse karo
                while (j < abbr.size() && isdigit(abbr[j]))
                {
                    num = num * 10 + (abbr[j] - '0');
                    j++;
                }

                i += num; // Word mein utne characters skip karo

                if (i > word.size())
                {
                    return false;
                }
            }
            else
            {
                // Letter hai → direct comparison
                if (i >= word.size() || word[i] != abbr[j])
                {
                    return false;
                }

                i++;
                j++;
            }
        }

        // Pura word bhi consume hona chahiye
        return i == word.size();
    }
};

int main()
{
    string word = "substitution";
    string abbr = "s10n";

    Solution obj;

    cout << boolalpha << obj.validWordAbbreviation(word, abbr);

    return 0;
}