#include <bits/stdc++.h>
using namespace std;

long long reverseNumber(long long n) {
    long long rev = 0;
    bool isNeg = (n < 0);
    n = llabs(n);

    while (n > 0) {
        int digit = n % 10;
        rev = rev * 10 + digit;
        n /= 10;
    }
    return isNeg ? -rev : rev;
}

bool isPalindrome(long long n) {
    if (n < 0) return false; // Negative numbers are never palindrome
    return n == reverseNumber(n);
}

int main() {
    long long num;

    cout << "Enter an integer: ";
    cin >> num;

    if (cin.fail()) {
        cout << "Error: Invalid input. Please enter a valid integer.";
        return 0;
    }

    if (isPalindrome(num)) {
        cout << num << " is a Palindrome number.";
    } else {
        cout << num << " is NOT a Palindrome number.";
    }

    return 0;
}

/*
===========================================================
===================== FULL THEORY =========================
================== + 11 STEP SYSTEM =======================
===========================================================

TOPIC: Palindrome Number

1. INTUITION (Hinglish):
   - Palindrome matlab number ko aage se padhoge ya peeche se,
     dono same milna chahiye.
   - Example: 121 → reverse bhi 121.
   - Real life analogy: Mirror image — dono side same.

2. WHY THIS TOPIC EXISTS:
   - Basic logic building
   - Introduction to digit manipulation
   - Interview warm-up
   - Palindromic patterns are common in CP

3. PATTERNS:
   Pattern 1: Reverse number and compare
   Pattern 2: Compare first and last digits (not used here)
   Pattern 3: String reverse method

4. VISUAL EXAMPLE (Number = 1221):
   Forward:  1 2 2 1
   Reverse:  1 2 2 1
   → Palindrome

5. EDGE CASES:
   - n = 0 → palindrome
   - negative numbers are NOT palindrome
   - large values (use long long)
   - input validation required

6. TIME + SPACE COMPLEXITY:
   - Time: O(digits)
   - Space: O(1)

===================== 11-STEP SYSTEM =====================

1) UNDERSTAND QUESTION:
   - Check if number is same when reversed.

2) CONSTRAINTS:
   - Only valid integer input.
   - Negative numbers → automatically not palindrome.

3) EDGE CASES:
   - 0
   - single digit numbers (all are palindrome)
   - invalid input via cin.fail()

4) BRUTE FORCE:
   - Convert to string and compare with reversed string.

5) PATTERN:
   - Reversing number using mod/divide pattern.

6) OPTIMAL:
   - Reverse digits using math and compare.

7) CODE:
   - Provided above.

8) DRY RUN (Input: 1331):
   reverse = 1331 → matches original → palindrome.

9) INTERVIEWER EXPLANATION:
   "I reverse the number mathematically and compare with original.
    Time complexity is O(digits), space O(1)."

10) MISTAKES TO AVOID:
   - Considering negative numbers as palindrome.
   - Not using long long.
   - Forgetting cin.fail() validation.

11) VARIANTS:
   - Palindrome string
   - Palindrome linked list
   - Palindrome using two-pointer
   - Palindrome without converting to string

===================== END OF THEORY =======================
*/
