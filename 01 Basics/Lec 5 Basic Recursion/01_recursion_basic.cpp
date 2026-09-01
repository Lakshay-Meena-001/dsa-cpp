#include <iostream>
using namespace std;

void printNumbers(int n) {
    // Base Case
    if (n == 0) {
        return;
    }

    // Recursive Case
    printNumbers(n - 1);

    // Work after recursion (prints while returning)
    cout << n << " ";
}

int main() {
    int n;
    cout << "Enter a positive integer: ";
    cin >> n;

    if (n < 0) {
        cout << "Please enter a non-negative integer.";
        return 0;
    }

    printNumbers(n);
    return 0;
}

/*
------------------------------------------
        RECURSION — COMPLETE THEORY
------------------------------------------

1. What is Recursion?
   - Recursion is when a function calls itself.
   - It breaks a big problem into smaller, similar problems.

2. Every recursive function has two parts:
   a) Base Case
      - The stopping condition.
      - Without this, recursion becomes infinite.

   b) Recursive Case
      - Where the function calls itself with a smaller input.

3. Example Logic Used in This Program:
   - To print numbers from 1 to n:
        printNumbers(n) calls printNumbers(n-1)
        until n becomes 0.

4. Flow:
   printNumbers(5)
       → printNumbers(4)
           → printNumbers(3)
               → printNumbers(2)
                   → printNumbers(1)
                       → printNumbers(0)   -> stops here
   After stopping, values print while coming back:
   1 2 3 4 5

5. Why recursion works?
   - Each step reduces the problem.
   - When the smallest problem is solved (base case),
     all previous calls complete while returning.

6. Key Points:
   - Base case is always mandatory.
   - Input must move towards the base case.
   - Helps simplify complex problems.

------------------------------------------
*/
