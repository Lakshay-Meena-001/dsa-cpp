#include <bits/stdc++.h>
using namespace std;

int countDigits(long long n) {
    if (n == 0) return 1;
    n = llabs(n);
    int count = 0;
    while (n > 0) {
        n /= 10;
        count++;
    }
    return count;
}

bool isArmstrong(long long n) {
    if (n < 0) return false; // Armstrong only defined for non-negative numbers

    long long original = n;
    int digits = countDigits(n);
    long long sum = 0;

    while (n > 0) {
        int digit = n % 10;
        sum += pow(digit, digits);
        n /= 10;
    }

    return sum == original;
}

int main() {
    long long num;
    cout << "Enter an integer: ";
    cin >> num;

    if (cin.fail()) {
        cout << "Error: Invalid input. Please enter a valid integer.";
        return 0;
    }

    if (isArmstrong(num)) {
        cout << num << " is an Armstrong number.";
    } else {
        cout << num << " is NOT an Armstrong number.";
    }

    return 0;
}

/*
===========================================================
===================== FULL THEORY =========================
================== + 11 STEP SYSTEM =======================
===========================================================

TOPIC: Armstrong Number  
Definition:  
A number is Armstrong if:
   Sum of (each digit ^ number of digits) == original number.

Example: 153  
Digits = 3  
1^3 + 5^3 + 3^3 = 153 → Armstrong.

-----------------------------------------------------------
1. INTUITION (Hinglish):
   - Tum number ke har digit ko uthao.
   - Us digit ko total digits ki power mein uthao.
   - Saare power ka sum banao.
   - Agar sum original ke equal ho → Armstrong.
   - Real life analogy: 
     Har element ko uski "strength" (power) dekar total score banana.

2. WHY THIS TOPIC EXISTS:
   - Classic math + logic building
   - Strong base for digit manipulation
   - Interview favorite
   - Perfect example of patterns using modulo/division + power sums

3. PATTERNS:
   Pattern 1: Extract digits → sum digit^count  
   Pattern 2: Convert to string and loop (not used here)  
   Pattern 3: Precompute powers (for optimization)

4. VISUAL EXAMPLE (9474):
   Digits = 4  
   9^4 = 6561  
   4^4 = 256  
   7^4 = 2401  
   4^4 = 256  
   Sum = 9474 → Armstrong.

5. EDGE CASES:
   - 0 → Armstrong
   - negative numbers → NOT Armstrong
   - large values → use long long
   - invalid input → handle with cin.fail()

6. TIME + SPACE COMPLEXITY:
   Time: O(digits)  
   Space: O(1)

-----------------------------------------------------------
===================== 11-STEP SYSTEM ======================

1) UNDERSTAND QUESTION:
   Check if sum of each digit raised to total number of digits equals the number.

2) CONSTRAINTS:
   Only non-negative integers.  
   Input must be valid integer.

3) EDGE CASES:
   0 → Armstrong  
   -153 → not Armstrong  
   Large long long values

4) BRUTE FORCE:
   Convert to string → count digits → loop → pow.

5) PATTERN:
   Same pattern as digit extraction using %10 and /10.

6) OPTIMAL:
   Mathematical extraction + countDigits + pow.

7) CODE:
   Provided above.

8) DRY RUN (Example: 153):
   digits = 3  
   1^3 = 1  
   5^3 = 125  
   3^3 = 27  
   sum = 153 → Armstrong.

9) INTERVIEWER EXPLANATION:
   “I count digits, extract digits using modulo, raise each digit to that power, sum them, and compare with original.”

10) MISTAKES TO AVOID:
   - Forgetting to count digits correctly  
   - Ignoring negative numbers  
   - Overflow when using int instead of long long  
   - Using pow without casting (pow returns double)

11) VARIANTS:
   - n-digit general Armstrong check  
   - Strong number  
   - Factorion problem  
   - Sum of powered digits problems

===================== END OF THEORY =======================
*/
