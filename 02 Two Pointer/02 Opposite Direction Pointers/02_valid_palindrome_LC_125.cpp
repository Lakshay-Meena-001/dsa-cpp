#include <iostream>
#include <string>
#include <cctype>
using namespace std;

class Solution
{
public:
    bool isPalindrome(string s)
    {
        int L = 0;
        int R = s.size() - 1;

        while (L < R)
        {

            // Skip non-alphanumeric characters from left
            if (!isalnum(s[L]))
            {
                L++;
                continue;
            }

            // Skip non-alphanumeric characters from right
            if (!isalnum(s[R]))
            {
                R--;
                continue;
            }

            // Compare characters ignoring case
            if (tolower(s[L]) != tolower(s[R]))
            {
                return false;
            }

            // Current pair is verified
            L++;
            R--;
        }

        return true;
    }
};

int main()
{
    Solution obj;

    string s;
    cout << "Enter a string: ";
    getline(cin, s);

    if (obj.isPalindrome(s))
    {
        cout << "Palindrome" << endl;
    }
    else
    {
        cout << "Not a Palindrome" << endl;
    }

    return 0;
}