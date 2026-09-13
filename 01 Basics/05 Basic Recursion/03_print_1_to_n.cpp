#include <bits/stdc++.h>
using namespace std;

void printReverse(int n) {
    // Base Case
    if (n == 0) return;

    // Work before recursive call (prints while going down)
    cout << n << " ";

    // Recursive Call
    printReverse(n - 1);
}

int main() {
    long long n;
    cout << "Enter a positive integer: ";
    cin >> n;

    if (cin.fail() || n < 0) {
        cout << "Error: Please enter a valid positive integer.";
        return 0;
    }

    printReverse(n);
    return 0;
}

/*
================================================================================
                         FULL THEORY + 11-STEP SYSTEM
                       PRINT NUMBERS FROM n DOWN TO 1
================================================================================

1. INTUITION (Hinglish):
   - Recursion ka matlab hai function ka khud ko call karna.
   - Yahan hum n se start karke 1 tak numbers print karenge.
   - Real-life analogy: 
       Jaise tum stairs se neeche jaa rahe ho — har step ek number hai.
       Start at top (n), phir neeche (n-1), phir neeche (n-2)... until 1.

2. WHY THIS TOPIC EXISTS (Use-cases):
   - Recursion understanding ka first step.
   - Foundation for future recursion topics (tree, backtracking).
   - Helps in printing sequences, patterns, tracking states.

3. PATTERNS USED:
   Pattern 1: Work → Recursive call (PRINT FIRST, THEN RECURSE)
   Pattern 2: Reduce n by 1 each time
   Pattern 3: Single base case (n == 0)

4. VISUAL EXAMPLE (n = 5):
   Call stack:
       printReverse(5)
          print 5
          → printReverse(4)
             print 4
             → printReverse(3)
                print 3
                → printReverse(2)
                   print 2
                   → printReverse(1)
                      print 1
                      → printReverse(0) STOP

   Output:
     5 4 3 2 1

5. IMPORTANT EDGE CASES:
   - n = 0 → output empty
   - n < 0 → invalid input
   - Large n → deep recursion but safe for typical constraints

6. TIME + SPACE COMPLEXITY:
   Time:  O(n)
   Space: O(n) (due to recursion call stack)

================================================================================
                        11-STEP PROBLEM SOLVING SYSTEM
================================================================================

1) UNDERSTAND THE QUESTION:
   Print numbers from n down to 1 using recursion only.

2) CONSTRAINTS:
   n must be >= 0
   Input should be a valid integer

3) EDGE CASES:
   n = 0  → print nothing
   n = 1  → prints 1
   negative → not allowed

4) BRUTE FORCE:
   Use a loop for (int i=n; i>=1; i--) print i;

5) PATTERN:
   Recursion decreasing pattern:
       print n → recursive call with (n-1)

6) OPTIMAL SOLUTION:
   Recursive solution (cleaner and good for learning)

7) CODE:
   Provided above.

8) DRY RUN (n = 3):
   printReverse(3) → prints 3
       → printReverse(2) → prints 2
           → printReverse(1) → prints 1
               → printReverse(0) stop

9) INTERVIEWER EXPLANATION:
   “I print the number first, then recursively print from n-1 to 1.  
    Base case is when n becomes 0.”

10) MISTAKES TO AVOID:
   - Base case missing → infinite recursion
   - Printing after recursion → gives 1 to n instead
   - Not validating negative input

11) VARIANTS:
   - Print 1 to n (reverse order of work)
   - Print n to 1 using tail recursion
   - Print using loops
   - Parameterized recursion

================================================================================
*/
