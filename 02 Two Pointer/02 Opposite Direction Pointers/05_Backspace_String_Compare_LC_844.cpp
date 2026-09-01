#include <bits/stdc++.h>
using namespace std;

// Moves the pointer to the next character that remains
// after applying all backspaces encountered so far.
//
// Returns:
// - index of the next valid character
// - -1 if no valid character remains
int nextValidIndex(const string &s, int index)
{
    int backspaces = 0;

    while (index >= 0)
    {
        if (s[index] == '#')
        {
            ++backspaces;
            --index;
        }
        else if (backspaces > 0)
        {
            --backspaces;
            --index;
        }
        else
        {
            // This character survives.
            return index;
        }
    }

    return -1;
}

// Compares two strings after applying backspace operations.
bool backspaceCompare(const string &s, const string &t)
{
    int i = s.size() - 1;
    int j = t.size() - 1;

    while (true)
    {
        i = nextValidIndex(s, i);
        j = nextValidIndex(t, j);

        // Both strings have no remaining characters.
        if (i == -1 && j == -1)
        {
            return true;
        }

        // One string has characters left, the other doesn't.
        if (i == -1 || j == -1)
        {
            return false;
        }

        // Compare the next characters that actually survive.
        if (s[i] != t[j])
        {
            return false;
        }

        --i;
        --j;
    }
}

int main()
{
    vector<pair<string, string>> testCases = {
        {"ab#c", "ad#c"},
        {"ab##", "c#d#"},
        {"a#c", "b"},
        {"ab#d", "ac#d"},
        {"a##c", "#a#c"},
        {"abc", "abc"},
        {"abc", "abd"}};

    for (const auto &[s, t] : testCases)
    {
        cout << "s = \"" << s << "\"\n";
        cout << "t = \"" << t << "\"\n";
        cout << "Equal after backspaces: "
             << boolalpha
             << backspaceCompare(s, t)
             << "\n\n";
    }

    return 0;
}