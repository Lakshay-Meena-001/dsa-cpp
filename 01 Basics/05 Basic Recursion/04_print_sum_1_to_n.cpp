#include <bits/stdc++.h>
using namespace std;

/* ---------------- PARAMETERIZED RECURSION ----------------
   We pass the running sum as a parameter.
   sumParam(n, currentSum)
*/
void sumParam(long long n, long long sum) {
    if (n == 0) {
        cout << "Sum (Parameterized): " << sum << endl;
        return;
    }
    sumParam(n - 1, sum + n);
}

/* ---------------- FUNCTIONAL RECURSION ----------------
   Function returns the final result.
   sumFunc(n) returns: n + sumFunc(n-1)
*/
long long sumFunc(long long n) {
    if (n == 0) return 0; 
    return n + sumFunc(n - 1);
}

int main() {
    long long n;
    cout << "Enter a positive integer: ";
    cin >> n;

    if (cin.fail() || n < 0) {
        cout << "Error: Please enter a valid positive integer.";
        return 0;
    }

    // Method 1: Parameterized
    sumParam(n, 0);

    // Method 2: Functional
    cout << "Sum (Functional): " << sumFunc(n) << endl;

    return 0;
}

/*
================================================================================
                     FULL THEORY + 11-STEP SYSTEM (RECURSION)
                           SUM OF NUMBERS FROM 1 TO n
================================================================================

1. INTUITION (Hinglish):
   - 1 se n tak saare numbers ko add karna hai.
   - Recursion mein hum problem ko chhote hisso mein todte hain:
        n + (n-1) + (n-2) ... + 1
   - Real-life analogy:
        Jaise ek ladder chadhte waqt tum ek step chadte ho,
        phir usse chhota step, phir usse chhota step — end tak.

2. WHY THIS TOPIC EXISTS:
   - Basic introduction to recursion thinking.
   - Shows how problems can be solved:
       → using a returning function (functional recursion)
       → using parameters (parameterized recursion)
   - Helps understand problem-breaking.

3. PATTERNS:
   Pattern A: Functional Recursion
       return n + f(n-1)

   Pattern B: Parameterized Recursion
       carry sum in arguments → sum += n

4. VISUAL EXAMPLE (n = 4):
   Functional:
       f(4) = 4 + f(3)
       f(3) = 3 + f(2)
       f(2) = 2 + f(1)
       f(1) = 1 + f(0)
       f(0) = 0
       Final = 10

   Parameterized:
       sumParam(4, 0)
         → sumParam(3, 4)
           → sumParam(2, 7)
             → sumParam(1, 9)
               → sumParam(0, 10) → print 10

5. EDGE CASES:
   - n = 0 → sum = 0
   - n < 0 → invalid
   - Large n → recursion depth limit

6. TIME + SPACE COMPLEXITY:
   Time:  O(n)
   Space: O(n) due to recursion stack

================================================================================
                          WHICH METHOD IS BETTER & WHY?
================================================================================

✔ Parameterized Recursion  
   - Pros:
       → No extra return stack cost  
       → Very good for problems needing accumulation  
       → Easy to print final output  
   - Cons:
       → Harder to use in expressions  
       → Must handle printing inside recursion  

✔ Functional Recursion  
   - Pros:
       → Clean, mathematical, elegant  
       → Easy to use inside formulas  
       → Good for competitive programming  
   - Cons:
       → More return overhead  
       → Slightly slower because returning values  

⭐ BEST METHOD?
→ **Functional recursion** is usually preferred  
       because it directly returns the computed value  
       and fits naturally into recursion patterns.

→ **Parameterized recursion** is better  
       when you need to *accumulate* state,  
       like printing intermediate states or building paths.

Both are important for developing recursion thinking.

================================================================================
                          11-STEP PROBLEM SOLVING SYSTEM
================================================================================

1) Understand the question:
   1 to n tak saare numbers ka sum recursively find karo.

2) Constraints:
   n >= 0
   integer input only

3) Edge cases:
   n = 0  
   large n → stack depth issue

4) Brute force:
   Loop from 1 to n and sum.

5) Pattern:
   Number reduction pattern:
      n + f(n-1)

6) Optimal solution:
   Functional recursion OR parameterized both O(n)

7) Code:
   (see above)

8) Dry Run (n = 3):
   Functional:
       f(3) = 3 + f(2)
       f(2) = 2 + f(1)
       f(1) = 1 + f(0)
       Final = 6

9) Interviewer explanation:
   “I break the problem using the relation:  
        sum(n) = n + sum(n-1)  
    Base case at n = 0.”

10) Mistakes to avoid:
   - Missing base case
   - Using wrong return for functional
   - Not updating sum in parameterized call
   - Handling negative n incorrectly

11) Variants:
   - Sum of even numbers from 1 to n
   - Sum of digits using recursion
   - Sum of array using recursion
   - Multiplying numbers from 1 to n (factorial)

================================================================================
*/
