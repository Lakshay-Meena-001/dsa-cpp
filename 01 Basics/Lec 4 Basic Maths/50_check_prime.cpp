#include <bits/stdc++.h>
using namespace std;

bool isPrime(long long n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;

    for (long long i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    long long num;
    cout << "Enter an integer: ";
    cin >> num;

    if (cin.fail()) {
        cout << "Error: Invalid input. Please enter a valid integer.";
        return 0;
    }

    if (isPrime(num)) {
        cout << num << " is a Prime number.";
    } else {
        cout << num << " is NOT a Prime number.";
    }

    return 0;
}

/*
===========================================================
===================== FULL THEORY =========================
================== + 11 STEP SYSTEM =======================
===========================================================

TOPIC: Check if a Number is Prime  
A prime number is a number > 1 that has EXACTLY two divisors: 1 and itself.

-----------------------------------------------------------
1. INTUITION (Hinglish):
   - Prime number wo hota hai jisko sirf 1 aur khud divide kar sake.
   - Example: 7 → sirf 1 aur 7 se divide hota hai.
   - Real life analogy:
     Ek “VIP member” jisko sirf limited log (1 & itself) hi access kar sakte hain.

2. WHY THIS TOPIC EXISTS:
   - Foundation of number theory
   - Required in sieve, factorization, cryptography
   - One of the most asked interview warm-up questions

3. PATTERNS:
   Pattern 1: Check divisibility from 1 to n (slow)
   Pattern 2: Check from 2 to sqrt(n) (BEST)
   Pattern 3: Skip all even numbers except 2

4. VISUAL EXAMPLE (n = 29):
   Check divisors up to √29 ≈ 5.38  
   Try 2 → not divisible  
   Try 3 → not divisible  
   Try 5 → not divisible  
   No divisor found → prime.

5. EDGE CASES:
   - n <= 1 → NOT prime
   - n = 2 → prime
   - even numbers > 2 → NOT prime
   - input validation needed

6. TIME + SPACE COMPLEXITY:
   Time: O(√N)
   Space: O(1)

-----------------------------------------------------------
===================== 11-STEP SYSTEM ======================

1) UNDERSTAND QUESTION:
   Determine whether the given integer is prime.

2) CONSTRAINTS:
   Only valid integer input.
   Negative values and 0,1 are not prime.

3) EDGE CASES:
   n = 0, 1 → not prime  
   n = 2 → prime  
   any even number → not prime

4) BRUTE FORCE:
   Check all numbers from 1 to n → O(n)

5) PATTERN:
   √N divisor check pattern.

6) OPTIMAL:
   - Check only till sqrt(n)
   - Skip even numbers

7) CODE:
   Provided above.

8) DRY RUN (n = 31):
   √31 ≈ 5.56  
   Check 2 → not divisible  
   Check 3 → not divisible  
   Check 5 → not divisible  
   No divisor found → prime.

9) INTERVIEWER EXPLANATION:
   “I check divisors only till sqrt(n).  
    If no divisor is found, n is prime.  
    This reduces time from O(n) to O(√n).”

10) MISTAKES TO AVOID:
   - Treating 1 as prime
   - Looping till n instead of sqrt(n)
   - Forgetting to skip even numbers
   - Missing cin.fail() validation

11) VARIANTS:
   - Print all primes up to N (Sieve of Eratosthenes)
   - Count primes in a range
   - Next prime after N
   - Prime factorization
   - Segmented sieve (advanced)

===================== END OF THEORY =======================
*/
