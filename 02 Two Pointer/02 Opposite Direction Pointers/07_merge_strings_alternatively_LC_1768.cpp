#include <bits/stdc++.h>
using namespace std;

string mergeAlternately(const string &word1, const string &word2)
{
    string result;

    int i = 0;
    int j = 0;

    while (i < word1.size() || j < word2.size())
    {

        if (i < word1.size())
        {
            result += word1[i];
            ++i;
        }

        if (j < word2.size())
        {
            result += word2[j];
            ++j;
        }
    }

    return result;
}

int main()
{
    vector<pair<string, string>> testCases = {
        {"abc", "pqr"},
        {"ab", "pqrs"},
        {"abcd", "pq"},
        {"", "abc"},
        {"abc", ""}};

    for (const auto &[word1, word2] : testCases)
    {
        cout << "word1: " << word1 << '\n';
        cout << "word2: " << word2 << '\n';
        cout << "Result: "
             << mergeAlternately(word1, word2)
             << "\n\n";
    }

    return 0;
}