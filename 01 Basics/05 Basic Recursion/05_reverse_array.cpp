#include <bits/stdc++.h>
using namespace std;

/* FUNCTIONAL RECURSION
   We return nothing, but use swapping + recursive calls.
   Functional style: recursion controls the process (no extra parameters needed).
*/

void reverseArray(vector<int> &arr, int start, int end) {
    // Base Case
    if (start >= end) return;

    // Swap the values
    swap(arr[start], arr[end]);

    // Functional recursive call
    reverseArray(arr, start + 1, end - 1);
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    if (cin.fail() || n < 0) {
        cout << "Error: Please enter a valid array size.";
        return 0;
    }

    vector<int> arr(n);
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    reverseArray(arr, 0, n - 1);

    cout << "Reversed Array: ";
    for (int x : arr) cout << x << " ";

    return 0;
}

/*
================================================================================
                         FULL THEORY + 11-STEP SYSTEM
                      REVERSE ARRAY USING FUNCTIONAL RECURSION
================================================================================

1. INTUITION (Hinglish):
   - Array ko reverse karna matlab pehla element last mein, last element pehle.
   - Real-life analogy:
       Jaise ek line mein log khade hain,
       tum unke positions swap karte jao — front wala last jata hai, last wala front.
   - Functional recursion:
       Hum bas recursion ko work karne dete hain.
       Start pointer aage badhta hai, end pointer peeche aata hai.

2. WHY THIS TOPIC EXISTS:
   - Array manipulation + recursion thinking
   - Index-based transformation
   - Foundation for advanced recursion like:
       backtracking
       reverse linked list
       recursive sorting

3. PATTERNS INSIDE:
   Pattern A: Two-pointer swap pattern  
   Pattern B: Recursive shrinking — (start++, end--)  
   Pattern C: Functional recursion (no extra state)

4. VISUAL EXAMPLE:
   arr = [1, 2, 3, 4, 5]
   start=0, end=4 → swap → [5,2,3,4,1]
   start=1, end=3 → swap → [5,4,3,2,1]
   start=2, end=2 → stop

5. EDGE CASES:
   - n = 0 → empty array
   - n = 1 → already reversed
   - all equal values
   - odd-length and even-length arrays

6. TIME + SPACE COMPLEXITY:
   Time:  O(n)
   Space: O(n) (recursion stack)

================================================================================
                     FUNCTIONAL vs PARAMETERIZED (Quick Insight)
================================================================================
Functional recursion:
   - Recursion drives the logic naturally.
   - Cleaner, mathematical.
   - Works great for symmetric operations (like reversing).

Parameterized recursion:
   - You pass extra variables (like index, sum).
   - Better when accumulating results.

⭐ For array reversing:
→ **Functional recursion is cleaner, easier, and more natural.**

================================================================================
                       11-STEP PROBLEM SOLVING SYSTEM
================================================================================

1) Understand question:
   Reverse the array using recursion only.

2) Constraints:
   - n >= 0
   - valid integer inputs

3) Edge cases:
   - n = 0
   - n = 1
   - odd/even sizes

4) Brute force:
   - Use loop from 0 to n/2 and swap.

5) Pattern:
   - Two-pointer & shrinking pattern.

6) Optimal solution:
   - Recursive swapping (functional recursion).

7) Code:
   Provided above.

8) Dry run (arr = [1,2,3]):
   swap(1,3) → [3,2,1]
   recurse(start=1, end=1) → stop

9) Interviewer explanation:
   “I swap the first and last elements, then recursively move inward.”

10) Mistakes to avoid:
   - Missing base case start >= end
   - Using end--, start++ incorrectly
   - Forgetting reference (&)

11) Variants:
   - Reverse array using one pointer + size
   - Reverse string recursively
   - Reverse linked list recursively
   - Reverse only part of the array

================================================================================
*/
