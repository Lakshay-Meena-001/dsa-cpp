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

int main() {
    long long num;

    cout << "Enter an integer: ";
    cin >> num;

    // Input validation using cin.fail()
    if (cin.fail()) {
        cout << "Error: Invalid input. Please enter a valid integer.";
        return 0;
    }

    cout << "Reversed number: " << reverseNumber(num);
    return 0;
}

/*
===========================================================
===================== FULL THEORY =========================
================== + 11 STEP SYSTEM =======================
===========================================================

TOPIC: Reverse a Number

1. INTUITION (Hinglish):
   - Last digit n%10 se milta hai.
   - Reverse = reverse * 10 + lastDigit
   - n = n / 10 se last digit remove ho jaata hai.
   - Exactly as reading a number from right to left.

2. WHY THIS TOPIC EXISTS:
   - Palindrome check
   - Digit extraction
   - Math + logical reasoning
   - CP fundamentals
   - Interview warm-up

3. PATTERNS:
   Pattern 1: %10 + /10 → BEST
   Pattern 2: String reverse
   Pattern 3: Recursive (rare)

4. VISUAL EXAMPLE (Number = 456):
   Step 1: digit=6, rev=6
   Step 2: digit=5, rev=65
   Step 3: digit=4, rev=654

5. EDGE CASES:
   - n = 0
   - negative numbers
   - long long overflow in extreme cases
   - invalid (non-integer) input → handled using cin.fail()

6. TIME + SPACE COMPLEXITY:
   - Time: O(digits)
   - Space: O(1)

===================== 11-STEP SYSTEM =====================

1) UNDERSTAND QUESTION:
   - Reverse an integer and maintain sign.

2) CONSTRAINTS:
   - Must accept only valid integer input.
   - Must work for negative numbers & large values.

3) EDGE CASES:
   - 0
   - -123
   - invalid input via cin.fail()

4) BRUTE FORCE:
   - Convert to string, reverse string.

5) PATTERN:
   - Digit extraction pattern using %10 and /10.

6) OPTIMAL:
   - Math-based extraction using mod and division.

7) CODE:
   - Included above.

8) DRY RUN (Input: 708):
   rev = 0
   take 8 → rev = 8
   take 0 → rev = 80
   take 7 → rev = 807

9) INTERVIEWER EXPLANATION:
   “I reverse by repeatedly extracting digits using modulo and building the reversed number using multiplication by 10.”

10) MISTAKES TO AVOID:
   - cin.fail() not checked → garbage input crashes
   - forgetting negative handling
   - int overflow (use long long)

11) VARIANTS:
   - Reverse bits
   - Reverse only specific digits
   - Remove leading zeros
   - Reverse large number stored as string

===================== END OF THEORY =======================
*/
