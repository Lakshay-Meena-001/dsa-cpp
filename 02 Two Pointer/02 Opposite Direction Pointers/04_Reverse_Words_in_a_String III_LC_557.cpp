#include <bits/stdc++.h>
using namespace std;

// Reverses the characters in the range [left, right].
void reverseRange(string &s, int left, int right)
{
    while (left < right)
    {
        swap(s[left], s[right]);
        ++left;
        --right;
    }
}

// Reverses every word in the string while keeping
// the order of the words unchanged.
string reverseWords(const string &input)
{
    string s = input;

    int wordStart = 0;
    int n = s.size();

    for (int i = 0; i <= n; ++i)
    {

        // A word ends at a space or at the end of the string.
        if (i == n || s[i] == ' ')
        {
            int wordEnd = i - 1;

            // Reverse only the current word.
            reverseRange(s, wordStart, wordEnd);

            // Next word starts after the space.
            wordStart = i + 1;
        }
    }

    return s;
}

int main()
{
    const string input = "Let's take LeetCode contest";

    const string result = reverseWords(input);

    cout << "Input:  " << input << '\n';
    cout << "Output: " << result << '\n';

    return 0;
}