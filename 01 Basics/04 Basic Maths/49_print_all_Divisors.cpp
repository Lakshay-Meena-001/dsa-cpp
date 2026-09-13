#include <bits/stdc++.h>
using namespace std;

vector<long long> getDivisors(long long n)
{
   vector<long long> divisors;

   for (long long i = 1; i * i <= n; i++)
   {
      if (n % i == 0)
      {
         divisors.push_back(i);
         if (i != n / i)
         {
            divisors.push_back(n / i);
         }
      }
   }

   sort(divisors.begin(), divisors.end());
   return divisors;
}

int main()
{
   long long num;
   cout << "Enter an integer: ";
   cin >> num;

   if (cin.fail() || num <= 0)
   {
      cout << "Error: Please enter a valid positive integer.";
      return 0;
   }

   vector<long long> result = getDivisors(num);

   cout << "Divisors of " << num << " are: ";
   for (auto d : result)
      cout << d << " ";

   return 0;
}

/*
===========================================================
===================== FULL THEORY =========================
================== + 11 STEP SYSTEM =======================
===========================================================

TOPIC: Print All Divisors of a Number

-----------------------------------------------------------
1. INTUITION (Hinglish):
   - Divisor wo hota hai jo number ko bilkul evenly divide kare.
   - Example: 12 ke divisors → 1,2,3,4,6,12.
   - Real life analogy:
     Ek group ko equal teams me baantna — jitne tareekon me equally divide ho sake, wo hi divisors.

2. WHY THIS TOPIC EXISTS:
   - Number theory foundation
   - Perfect for understanding factors
   - Used in GCD, LCM, prime checks
   - Common DSA interview problem

3. PATTERNS:
   Pattern 1: Check all numbers from 1 to N (O(N))
   Pattern 2: Check from 1 to √N and push both divisors (O(√N)) → BEST
   Pattern 3: Precompute divisors for all numbers (sieve patterns)

4. VISUAL EXAMPLE (n = 28):
   i = 1 → divisor: 1 and 28
   i = 2 → divisor: 2 and 14
   i = 4 → divisor: 4 and 7
   √28 ≈ 5.29 → stop.
   Sorted divisors: 1,2,4,7,14,28

5. EDGE CASES:
   - n = 1 → divisor is 1
   - n = 0 → not allowed
   - negative values → reject
   - very large values → use long long

6. TIME + SPACE COMPLEXITY:
   Time: O(√N)
   Space: O(k) where k = number of divisors

-----------------------------------------------------------
===================== 11-STEP SYSTEM ======================

1) UNDERSTAND QUESTION:
   - Print all numbers that divide n perfectly.

2) CONSTRAINTS:
   - Only positive integers.
   - Input must be valid integer.

3) EDGE CASES:
   - n = 1 → divisor only 1
   - n = prime → divisors = 1 and n

4) BRUTE FORCE:
   - Loop 1 to n and check n%i==0 (slow)

5) PATTERN:
   - √N divisor pair technique.

6) OPTIMAL:
   - Check only till sqrt(n) and push both divisors.

7) CODE:
   - Provided above.

8) DRY RUN (Example: n = 36):
   i=1 → 1,36
   i=2 → 2,18
   i=3 → 3,12
   i=4 → 4,9
   i=6 → 6
   Sorted: 1 2 3 4 6 9 12 18 36

9) INTERVIEWER EXPLANATION:
   “I iterate till sqrt(n). For every divisor i, I also include n/i. This reduces complexity from O(n) to O(√n).”

10) MISTAKES TO AVOID:
   - Forgetting to add the pair (n/i)
   - Duplicate when i == n/i
   - Not sorting at end
   - Wrong loop: using i < sqrt(n) instead of i*i <= n

11) VARIANTS:
   - Count divisors
   - Sum of divisors
   - Print divisors in sorted order (done)
   - Check if perfect number
   - Highly composite numbers
   - Divisors for all numbers (sieve)

===================== END OF THEORY =======================
*/
