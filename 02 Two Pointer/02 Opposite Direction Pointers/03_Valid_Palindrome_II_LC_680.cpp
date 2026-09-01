#include <bits/stdc++.h>
using namespace std;

// Checks whether the substring s[left...right] is a palindrome.
bool isPalindrome(const string &s, int left, int right)
{
    while (left < right)
    {
        if (s[left] != s[right])
        {
            return false;
        }

        ++left;
        --right;
    }

    return true;
}

// Returns true if the string is already a palindrome
// or can become one after deleting at most one character.
bool validPalindrome(const string &s)
{
    int left = 0;
    int right = static_cast<int>(s.size()) - 1;

    while (left < right)
    {
        if (s[left] == s[right])
        {
            ++left;
            --right;
            continue;
        }

        // First mismatch:
        // Option 1: delete s[left]
        // Option 2: delete s[right]
        return isPalindrome(s, left + 1, right) || isPalindrome(s, left, right - 1);
    }

    // No mismatch found, so the string is already a palindrome.
    return true;
}

int main()
{
    vector<string> testCases = {
        "aba",
        "abca",
        "abc",
        "deeee",
        "eccer",
        "abcdef"};

    for (const string &s : testCases)
    {
        cout << "Input: " << s << '\n';
        cout << "Can become palindrome: "
             << boolalpha
             << validPalindrome(s)
             << "\n\n";
    }

    return 0;
}