#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Hash map to store frequency
    unordered_map<int, int> freq;

    // Count frequency
    for (int i = 0; i < n; i++) {
        freq[arr[i]]++;
    }

    // Print result
    cout << "\nFrequency of each element:\n";
    for (auto it : freq) {
        cout << it.first << " -> " << it.second << endl;
    }

    return 0;
}

/*
================================================================================
                    HASHING — COUNT FREQUENCY OF ELEMENTS
================================================================================

1. INTUITION (Hinglish):
- Hume array ke har element ka count nikalna hai.
- Matlab:
  element kitni baar aa raha hai → frequency
- Hashing ka use isliye karte hain kyunki:
  har element ko ek "key" bana ke uska count store kar sakte hain.

Real-life analogy:
- Attendance register
- Har student ka naam ek key hai
- Har baar naam aaye → count +1

--------------------------------------------------------------------------------
2. WHY THIS PROBLEM EXISTS:
- Most common DSA + LeetCode problem
- Base for:
  - duplicates
  - majority element
  - anagrams
  - frequency sorting
  - map-based problems

--------------------------------------------------------------------------------
3. DATA STRUCTURE USED:
unordered_map<int, int>

Why?
- Key   → array element
- Value → frequency (count)
- Average time complexity O(1)

--------------------------------------------------------------------------------
4. STEP-BY-STEP LOGIC:
Example:
arr = [1, 2, 1, 3, 2, 1]

Step 1:
freq[1] = 1

Step 2:
freq[2] = 1

Step 3:
freq[1] = 2

Step 4:
freq[3] = 1

Step 5:
freq[2] = 2

Step 6:
freq[1] = 3

Final map:
1 -> 3
2 -> 2
3 -> 1

--------------------------------------------------------------------------------
5. EDGE CASES:
- Empty array → no output
- All elements same
- Negative numbers (unordered_map handles this)
- Large values

--------------------------------------------------------------------------------
6. TIME & SPACE COMPLEXITY:
Time:
- O(n) → one loop over array

Space:
- O(n) → hashmap stores elements

--------------------------------------------------------------------------------
7. 11-STEP PROBLEM SOLVING SYSTEM:

1) Understand question:
   Count how many times each element appears.

2) Constraints:
   Array of integers, size n.

3) Edge cases:
   Empty array, duplicates, negatives.

4) Brute force:
   For every element, loop again and count → O(n²)

5) Pattern:
   Frequency counting → HASHING

6) Optimal solution:
   Use unordered_map

7) Code:
   See above

8) Dry run:
   arr = [5,5,6]
   freq[5]=2, freq[6]=1

9) Interviewer explanation:
   "I used hashing to store frequency in O(1) average time."

10) Mistakes to avoid:
   - Using array hash for large values
   - Expecting sorted output from unordered_map

11) Variants:
   - Count frequency of characters
   - Find element with max frequency
   - Count distinct elements
   - Frequency sort
   - Majority element

--------------------------------------------------------------------------------
                    🔥 THIS IS THE CORE OF HASHING 🔥
================================================================================
*/
