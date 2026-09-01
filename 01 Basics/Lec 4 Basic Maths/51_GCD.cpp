#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b) {
    // Euclid's Algorithm
    while (b != 0) {
        long long temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

int main() {
    long long a, b;

    cout << "Enter two integers: ";
    cin >> a >> b;

    if (cin.fail()) {
        cout << "Error: Invalid input. Please enter valid integers.";
        return 0;
    }

    cout << "GCD / HCF = " << gcd(a, b);

    return 0;
}

/*
===========================================================
===================== FULL THEORY =========================
================== + 11 STEP SYSTEM =======================
===========================================================

TOPIC: GCD / HCF (Greatest Common Divisor)

-----------------------------------------------------------
1. INTUITION (Hinglish):
   - GCD matlab DO numbers ko kitna "equally" divide kar sakta hai —
     sabse bada common divisor.
   - Example: 12 and 18 → common divisors: 1,2,3,6 → GCD = 6.
   - Real life analogy:
     Do logon ka "maximum equal share" nikalna.

2. WHY THIS TOPIC EXISTS:
   - Number theory foundation
   - Required in LCM, fractions, ratios
   - Huge use in CP, cryptography, modular arithmetic
   - Classic interview question

3. PATTERNS:
   Pattern 1: Check divisors — O(n)
   Pattern 2: Check min(a,b) downward — O(min(a,b))
   Pattern 3: Euclid's Algorithm — BEST → O(log(min(a,b)))

4. VISUAL EXAMPLE (Euclid's Algorithm):
   GCD(48, 18)
   48 % 18 = 12  
   18 % 12 = 6  
   12 % 6  = 0  
   → Answer = 6

5. EDGE CASES:
   - GCD(0, n) = n
   - GCD(n, 0) = n
   - Negative numbers → take absolute
   - Both zero → undefined (handle separately if needed)

6. TIME + SPACE COMPLEXITY:
   Time: O(log(min(a, b)))  
   Space: O(1)

-----------------------------------------------------------
===================== 11-STEP SYSTEM ======================

1) UNDERSTAND QUESTION:
   Highest number that divides both a and b exactly.

2) CONSTRAINTS:
   - Input must be valid integers.
   - Must handle zero safely.

3) EDGE CASES:
   - gcd(0, n) = |n|
   - gcd(0, 0) = undefined (not asked here)

4) BRUTE FORCE:
   Check all numbers from 1 to min(a,b).

5) PATTERN:
   - Euclid’s modulo reduction.

6) OPTIMAL:
   - Repeated modulo using Euclid → O(log n).

7) CODE:
   (See above)

8) DRY RUN (Example: a=36, b=24):
   36 % 24 = 12  
   24 % 12 = 0  
   → GCD = 12

9) INTERVIEWER EXPLANATION:
   “I use Euclid’s Algorithm because it repeatedly reduces the problem using modulo, achieving log-time performance.”

10) MISTAKES TO AVOID:
   - Forgetting a % b order
   - Infinite loop if b is not updated
   - Using slow methods (checking all divisors)
   - Not handling zero case

11) VARIANTS:
   - LCM using GCD  
     LCM(a,b) = (a*b)/GCD
   - GCD of array  
   - Extended Euclid (for modular inverse)
   - Binary GCD (Stein's algorithm)

===================== END OF THEORY =======================
*/
