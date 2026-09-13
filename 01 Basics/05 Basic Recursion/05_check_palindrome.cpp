#include <bits/stdc++.h>
using namespace std;

/* FUNCTIONAL RECURSION
   Check characters at start & end.
   If equal → move inward.
   If mismatch → not palindrome.
*/

bool isPalindromeRec(string &s, int start, int end) {
    // Base case
    if (start >= end) return true;

    // If mismatch → not palindrome
    if (s[start] != s[end]) return false;

    // Recursive check for inner substring
    return isPalindromeRec(s, start + 1, end - 1);
}

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s; // takes continuous string

    if (cin.fail()) {
        cout << "Error: Invalid input.";
        return 0;
    }

    if (isPalindromeRec(s, 0, s.size() - 1))
        cout << s << " is a Palindrome.";
    else
        cout << s << " is NOT a Palindrome.";

    return 0;
}

/*
================================================================================
                         FULL THEORY + 11-STEP SYSTEM
                     CHECK PALINDROME USING RECURSION
================================================================================

1. INTUITION (Hinglish):
   - Palindrome matlab same from left and right.
   - Real-life analogy:
        Jaise mirror image — dono sides same dikhna chahiye.
   - Recursion ka approach:
        Start aur End characters compare karo.
        Agar same ho → andar jao.
        Agar different ho → palindrome nahi.

2. WHY THIS TOPIC EXISTS:
   - String manipulation basics
   - Recursion thinking: two-pointer + shrinking window
   - Foundation for checking symmetry problems

3. PATTERNS:
   Pattern A: Two-pointer symmetric check
   Pattern B: Shrinking recursion window (start++, end--)
   Pattern C: Character comparison before recursive call

4. VISUAL EXAMPLE:
   s = "madam"
   Compare m == m → yes  
   Compare a == a → yes  
   Compare d == d → yes (center reached)  
   → palindrome

5. EDGE CASES:
   - Single char → palindrome
   - Empty string → palindrome
   - Case sensitivity ("Madam" vs "madam")
   - Continuous input only (cin >> s)
   - Spaces not included unless getline used

6. TIME + SPACE COMPLEXITY:
   Time:  O(n)
   Space: O(n) (recursion stack)

================================================================================
                         FUNCTIONAL vs PARAMETERIZED
================================================================================
Functional recursion:
   - Clean, natural: return comparison result.
   - Easy to use inside logical expressions.

Parameterized recursion:
   - Rare for palindrome checks.
   - Suited for accumulating data.

⭐ For palindrome:
→ **Functional recursion is the best and cleanest.**

================================================================================
                       11-STEP PROBLEM SOLVING SYSTEM
================================================================================

1) Understand question:
   Check if string reads same from both ends.

2) Constraints:
   Only alphabetic/normal string, no spaces here.

3) Edge cases:
   "", "a", "aa", odd-length strings, even-length strings

4) Brute force:
   Reverse string & compare.

5) Pattern:
   Two-pointer shrinking window.

6) Optimal solution:
   Functional recursion comparing s[start] & s[end].

7) Code:
   Provided above.

8) Dry run (s = "aba"):
   compare a == a → ok  
   compare b == b → ok  
   start >= end → true  
   → palindrome

9) Interviewer explanation:
   “I use a two-pointer recursive check.  
    If characters at both ends match,  
    I shrink the window inward.”

10) Mistakes to avoid:
   - Missing base case start >= end
   - Off-by-one errors in end index
   - Not returning recursive result

11) Variants:
   - Palindrome for full sentence (ignoring spaces & case)
   - Palindrome using only one pointer
   - Palindrome check for linked list
   - Longest palindromic substring (advanced)

================================================================================
*/
