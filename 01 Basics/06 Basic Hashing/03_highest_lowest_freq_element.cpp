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

    // Step 1: Count frequency using hashing
    unordered_map<int, int> freq;
    for (int i = 0; i < n; i++) {
        freq[arr[i]]++;
    }

    // Step 2: Find highest and lowest frequency
    int maxFreq = INT_MIN, minFreq = INT_MAX;
    int maxElement = 0, minElement = 0;

    for (auto it : freq) {
        if (it.second > maxFreq) {
            maxFreq = it.second;
            maxElement = it.first;
        }
        if (it.second < minFreq) {
            minFreq = it.second;
            minElement = it.first;
        }
    }

    // Output results
    cout << "\nHighest Frequency Element: " << maxElement
         << " (Frequency = " << maxFreq << ")";

    cout << "\nLowest Frequency Element: " << minElement
         << " (Frequency = " << minFreq << ")";

    return 0;
}

/*
================================================================================
            HASHING — HIGHEST & LOWEST FREQUENCY ELEMENT
================================================================================

1. INTUITION (Hinglish):
- Pehle hum har element ka count nikalte hain.
- Phir un counts me:
  - sabse zyada count → highest frequency
  - sabse kam count → lowest frequency

Real-life analogy:
- Class attendance:
  - Jo student sabse zyada present → highest frequency
  - Jo sabse kam present → lowest frequency

--------------------------------------------------------------------------------
2. WHY THIS PROBLEM EXISTS:
- Common interview question
- Base for:
  - majority element
  - frequency sorting
  - top-k frequent elements
  - statistics problems

--------------------------------------------------------------------------------
3. APPROACH:
Step 1:
- Use unordered_map to store frequency

Step 2:
- Traverse map
- Track:
  maxFreq & maxElement
  minFreq & minElement

--------------------------------------------------------------------------------
4. VISUAL EXAMPLE:
arr = [1, 2, 2, 3, 1, 1]

Frequency:
1 -> 3
2 -> 2
3 -> 1

Highest frequency:
1 (3 times)

Lowest frequency:
3 (1 time)

--------------------------------------------------------------------------------
5. EDGE CASES:
- All elements same
- Multiple elements having same frequency
- Single element array
- Negative values
- Empty array (not allowed here)

Note:
- If multiple elements have same highest/lowest frequency,
  this code returns ANY ONE of them.

--------------------------------------------------------------------------------
6. TIME & SPACE COMPLEXITY:
Time:
- O(n) for frequency count
- O(n) for scanning map
Overall: O(n)

Space:
- O(n) for hashmap

--------------------------------------------------------------------------------
7. 11-STEP PROBLEM SOLVING SYSTEM:

1) Understand question:
   Find element with max and min occurrence.

2) Constraints:
   Integer array.

3) Edge cases:
   Single element, duplicates.

4) Brute force:
   For each element, count again → O(n²)

5) Pattern:
   Frequency hashing

6) Optimal solution:
   Hash map + single scan

7) Code:
   See above

8) Dry run:
   arr = [4,4,5]
   freq[4]=2, freq[5]=1

9) Interviewer explanation:
   "I stored frequency using hashing and tracked max/min."

10) Mistakes to avoid:
   - Initializing minFreq to 0
   - Using array hash for large values
   - Forgetting multiple-frequency condition

11) Variants:
   - Print all elements with max frequency
   - Print top-k frequent elements
   - Majority element (> n/2)
   - Mode of array

--------------------------------------------------------------------------------
                    🔥 HASHING CORE CONCEPT MASTERED 🔥
================================================================================
*/
