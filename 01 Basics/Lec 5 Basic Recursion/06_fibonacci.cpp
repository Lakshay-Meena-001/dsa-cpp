#include <bits/stdc++.h>
using namespace std;

/* FUNCTIONAL RECURSION
   fib(n) = fib(n-1) + fib(n-2)
   Classic mathematical recursive definition.
*/

long long fib(long long n) {
    if (n == 0) return 0;   // Base Case 1
    if (n == 1) return 1;   // Base Case 2
    return fib(n - 1) + fib(n - 2);
}

int main() {
    long long n;
    cout << "Enter n (index of Fibonacci): ";
    cin >> n;

    if (cin.fail() || n < 0) {
        cout << "Error: Please enter a valid non-negative integer.";
        return 0;
    }

    cout << "Fibonacci(" << n << ") = " << fib(n);
    return 0;
}

/*
================================================================================
                         FULL THEORY + 11-STEP SYSTEM
                             FIBONACCI RECURSION
================================================================================

1. INTUITION (Hinglish):
   Fibonacci series ka pattern bahut simple hai:
       Next number = Previous two numbers ka sum
   Example:
       0, 1, 1, 2, 3, 5, 8, 13...
   Real-life analogy:
       Jaise staircase combinations — ek step aage badhne ke 
       2 tareeke: ek step ya do steps. 
       Total ways = sum of previous two ways.

2. WHY THIS TOPIC EXISTS:
   - One of the most classic recursion problems.
   - Teaches branching recursion.
   - Basis for DP (Dynamic Programming).

3. PATTERNS:
   Pattern A: fib(n) = fib(n-1) + fib(n-2)
   Pattern B: Two base cases (0 and 1)
   Pattern C: Exponential tree recursion

4. VISUAL EXAMPLE (n = 4):
           fib(4)
        /          \
     fib(3)       fib(2)
     /    \        /   \
  fib(2) fib(1) fib(1) fib(0)
   /   \
fib(1) fib(0)

Result = 3

5. EDGE CASES:
   - n = 0 → output 0
   - n = 1 → output 1
   - negative input → invalid
   - very large n → recursion slow

6. TIME + SPACE COMPLEXITY (Naive recursion):
   Time:  O(2^n)   (exponential)
   Space: O(n)     (call-stack depth)

   NOTE: Efficient methods: DP, memoization, iterative.

================================================================================
                PARAMETERIZED vs FUNCTIONAL RECURSION (Important!)
================================================================================

Functional recursion:
   ✔ Clear, matches definition  
   ✔ Best for learning  
   ❌ Slow (exponential time)

Parameterized recursion:
   ✔ Can compute entire series  
   ✔ Useful for printing sequence  
   ❌ Not suitable for computing single fib(n) directly

⭐ Best method for understanding concept:
→ **Functional recursion**

⭐ Best for real-world / fast computation:
→ DP (tabulation) or memoized recursion

================================================================================
                       11-STEP PROBLEM SOLVING SYSTEM
================================================================================

1) Understand question:
   Find nth Fibonacci number using recursion.

2) Constraints:
   Input must be non-negative.
   n should not be too large due to recursion cost.

3) Edge cases:
   n = 0, n = 1
   negative input

4) Brute force:
   Loop and compute iteratively.

5) Pattern:
   Two-branch recursive tree pattern.

6) Optimal:
   Not naive recursion → DP is optimal, but here we use recursion.

7) Code:
   Provided above.

8) Dry Run (n = 5):
   fib(5)
   = fib(4) + fib(3)
   = (3) + (2)
   → Output = 5

9) Interviewer explanation:
   “I use the classical recurrence:
       fib(n) = fib(n-1) + fib(n-2)
    Base cases: fib(0)=0, fib(1)=1.”

10) Mistakes to avoid:
   - Missing base case → infinite recursion
   - Using naive recursion for large n
   - Stack overflow for very large input

11) Variants:
   - Print Fibonacci series
   - Fibonacci using memoization
   - Fibonacci using DP
   - Fibonacci using matrix exponentiation
   - Fibonacci using Binet formula

================================================================================
*/
