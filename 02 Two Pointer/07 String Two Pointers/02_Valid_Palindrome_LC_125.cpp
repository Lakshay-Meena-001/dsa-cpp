// 02_Valid_Palindrome_LC_125.cpp
// Pattern: Opposite-direction Two Pointers
// Goal: Alphanumeric characters compare karke palindrome check karna

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;              // Left pointer → start
        int right = s.size() - 1; // Right pointer → end

        while (left < right) {

            // Non-alphanumeric characters ko skip karo
            while (left < right && !isalnum(s[left])) {
                left++;
            }

            while (left < right && !isalnum(s[right])) {
                right--;
            }

            // Case ignore karke characters compare karo
            if (tolower(s[left]) != tolower(s[right])) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }
};

int main() {
    string s = "A man, a plan, a canal: Panama";

    Solution obj;

    cout << boolalpha << obj.isPalindrome(s);

    return 0;
}