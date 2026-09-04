#include <iostream>
#include <string>
using namespace std;

int minimumLength(string s)
{
    int left = 0;
    int right = s.size() - 1;

    while (left < right && s[left] == s[right])
    {
        char current = s[left];

        // Remove the entire matching block from the left.
        while (left <= right && s[left] == current)
        {
            left++;
        }

        // Remove the entire matching block from the right.
        while (left <= right && s[right] == current)
        {
            right--;
        }
    }

    // Remaining characters are [left ... right].
    return right - left + 1;
}

int main()
{
    string s = "cabaabac";

    cout << minimumLength(s) << endl;

    return 0;
}