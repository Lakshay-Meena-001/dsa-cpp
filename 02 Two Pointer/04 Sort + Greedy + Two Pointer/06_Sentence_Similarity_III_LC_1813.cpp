#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

vector<string> splitWords(const string &sentence)
{
    vector<string> words;
    string word;

    // string stream sentence ko words me todta hai
    stringstream ss(sentence);

    // to ye kya kar raha hai ki stream me se words ko extract kar raha hai aur unhe vector me push_back kar raha hai
    while (ss >> word)
    {
        words.push_back(word);
    }

    return words;
}

bool areSentencesSimilar(string sentence1, string sentence2)
{
    vector<string> a = splitWords(sentence1);
    vector<string> b = splitWords(sentence2);

    // Always make 'a' the shorter sentence.
    if (a.size() > b.size())
    {
        swap(a, b);
    }

    int n = a.size();
    int m = b.size();

    // Match common prefix.
    int left = 0;

    while (left < n && a[left] == b[left])
    {
        left++;
    }

    // Match common suffix.
    int rightA = n - 1;
    int rightB = m - 1;

    while (rightA >= left && rightB >= left && a[rightA] == b[rightB])
    {
        rightA--;
        rightB--;
    }

    // Every word of the shorter sentence
    // must be covered by prefix or suffix.
    return rightA < left;
}

int main()
{
    string sentence1 = "My name is Lakshay";
    string sentence2 = "My handsome name is Lakshay";

    cout << boolalpha
         << areSentencesSimilar(sentence1, sentence2)
         << endl;

    return 0;
}