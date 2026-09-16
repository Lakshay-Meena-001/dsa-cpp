// 12_Find_First_Palindromic_String_in_the_Array_LC_2108.cpp
// Pattern: Array Traversal + Palindrome Two Pointers
// Goal: Array mein pehli palindrome string return karna

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPalindrome(string &s)
    {
        int left = 0;             // String ka start
        int right = s.size() - 1; // String ka end

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

    string firstPalindrome(vector<string> &words)
    {
        for (string &word : words)
        {

            // Har word ko two pointers se check karo
            if (isPalindrome(word))
            {
                return word; // Pehli palindrome mil gayi
            }
        }

        return "";
    }
};

int main()
{
    vector<string> words = {
        "abc", "car", "ada", "racecar", "cool"};

    Solution obj;

    cout << obj.firstPalindrome(words);

    return 0;
}