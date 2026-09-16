// 11_Sentence_Similarity_III_LC_1813.cpp
// Pattern: Prefix + Suffix Two Pointers
// Goal: Check karo kya longer sentence mein continuous middle words inserted hain

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> split(string s)
    {
        stringstream ss(s);
        vector<string> words;
        string word;

        while (ss >> word)
        {
            words.push_back(word);
        }

        return words;
    }

    bool areSentencesSimilar(string sentence1, string sentence2)
    {
        vector<string> a = split(sentence1);
        vector<string> b = split(sentence2);

        // a ko shorter sentence rakho
        if (a.size() > b.size())
        {
            swap(a, b);
        }

        int left = 0;

        // Prefix match karo
        while (left < a.size() && a[left] == b[left])
        {
            left++;
        }

        int rightA = a.size() - 1;
        int rightB = b.size() - 1;

        // Suffix match karo
        while (rightA >= left &&
               a[rightA] == b[rightB])
        {
            rightA--;
            rightB--;
        }

        // Shorter sentence completely match ho gaya
        return rightA < left;
    }
};

int main()
{
    string sentence1 = "My name is Haley";
    string sentence2 = "My Haley";

    Solution obj;

    cout << boolalpha
         << obj.areSentencesSimilar(sentence1, sentence2);

    return 0;
}
