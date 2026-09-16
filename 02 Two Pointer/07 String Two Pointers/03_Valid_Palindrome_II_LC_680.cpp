// 03_Valid_Palindrome_II_LC_680.cpp
// Pattern: Two Pointers + One Mismatch Branch
// Goal: Max 1 character delete karke palindrome check karna

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isPalindrome(string &s, int left, int right)
    {
        while (left < right)
        {
            if (s[left] != s[right])
            {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }

    bool validPalindrome(string s)
    {
        int left = 0;
        int right = s.size() - 1;

        while (left < right)
        {
            if (s[left] != s[right])
            {
                // Mismatch: left ya right me se ek delete karo
                return isPalindrome(s, left + 1, right) || isPalindrome(s, left, right - 1);
            }

            left++;
            right--;
        }

        return true;
    }
};

int main()
{
    string s = "abca";

    Solution obj;

    cout << boolalpha << obj.validPalindrome(s);

    return 0;
}