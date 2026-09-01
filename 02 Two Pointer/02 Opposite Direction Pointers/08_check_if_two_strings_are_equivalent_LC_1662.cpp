#include <bits/stdc++.h>
using namespace std;

bool arrayStringsAreEqual(const vector<string> &word1, const vector<string> &word2)
{
    int i = 0; // Current string in word1
    int j = 0; // Current character in word1[i]

    int x = 0; // Current string in word2
    int y = 0; // Current character in word2[x]

    while (i < word1.size() && x < word2.size())
    {

        // Move to the next non-empty/exhausted chunk.
        while (i < word1.size() && j == word1[i].size())
        {
            ++i;
            j = 0;
        }

        while (x < word2.size() && y == word2[x].size())
        {
            ++x;
            y = 0;
        }

        // If either logical string has ended, stop comparing.
        if (i == word1.size() || x == word2.size())
        {
            break;
        }

        // Compare the current logical characters.
        if (word1[i][j] != word2[x][y])
        {
            return false;
        }

        ++j;
        ++y;
    }

    // Skip any remaining exhausted chunks.
    while (i < word1.size() && j == word1[i].size())
    {
        ++i;
        j = 0;
    }

    while (x < word2.size() && y == word2[x].size())
    {
        ++x;
        y = 0;
    }

    // Both logical streams must be completely consumed.
    return i == word1.size() && x == word2.size();
}

int main()
{
    vector<pair<vector<string>, vector<string>>> testCases = {
        {{"ab", "c"}, {"a", "bc"}},
        {{"a", "cb"}, {"ab", "c"}},
        {{"abc", "d", "defg"}, {"abcddefg"}},
        {{"hello"}, {"h", "e", "l", "l", "o"}},
        {{"abc"}, {"abd"}}};

    for (const auto &[word1, word2] : testCases)
    {
        cout << "word1: ";
        for (const string &s : word1)
        {
            cout << '"' << s << "\" ";
        }

        cout << "\nword2: ";
        for (const string &s : word2)
        {
            cout << '"' << s << "\" ";
        }

        cout << "\nEqual: "
             << boolalpha
             << arrayStringsAreEqual(word1, word2)
             << "\n\n";
    }

    return 0;
}