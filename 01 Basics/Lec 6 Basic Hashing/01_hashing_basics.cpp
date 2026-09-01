#include <bits/stdc++.h>
using namespace std;

/*
===========================================================================================
                                🔥 HASHING — MASTER THEORY
                           (Complete Detailed Notes for LeetCode + DSA)
===========================================================================================

----------------------------------------
1. INTUITION
----------------------------------------
Hashing ka matlab hota hai:
    -> Value ko ek index (hash value) se map karna
    -> Fast lookup, fast insert, fast delete

Real-life analogy:
    - Jaise tumhare ghar mein lockers numbered 1 to 100.
    - Tum koi saman locker 37 mein rakhte ho.
    - Baad mein tum directly locker 37 khol kar saman nikaal sakte ho.
    - Tumhe har locker check nahi karna padta.

Hashing gives:
    ✔ O(1) average insertion  
    ✔ O(1) average lookup  
    ✔ O(1) average deletion  


----------------------------------------
2. WHY HASHING EXISTS (Use-Cases)
----------------------------------------
Hashing sabse zyada use hota hai:
    ✔ Frequency counting  
    ✔ Duplicate detection  
    ✔ Finding missing / extra elements  
    ✔ Two-sum  
    ✔ Prefix sum problems  
    ✔ Set operations  
    ✔ String hashing (advanced)  
    ✔ Fast searching (no need for binary search)  


----------------------------------------
3. BASIC HASHING TYPES
----------------------------------------

A) **Array-based hashing**  
   - Fixed size  
   - Only for small keys (0–1e6)  

B) **Map-based hashing**  
   - Handles any integer  
   - Slower than array but very flexible  

C) **Unordered_map / Unordered_set**  
   - Uses hashing internally  
   - O(1) average  
   - Best for LeetCode  

D) **Ordered map (map / set)**  
   - Uses Red-Black Tree  
   - O(log n) time  
   - Sorted keys needed  

----------------------------------------
4. MOST IMPORTANT LEETCODE HASHING PATTERNS
----------------------------------------

Pattern 1 — Frequency Count  
    Example: Count occurrences of numbers  
Pattern 2 — First unique / first repeating  
Pattern 3 — Check if two arrays are equal  
Pattern 4 — Two sum  
Pattern 5 — Subarray with sum k  
Pattern 6 — Longest substring without repeating characters  
Pattern 7 — Hashset for duplicates  
Pattern 8 — Pair hashing (store pair<int,int>)  

----------------------------------------
5. BASIC HASHING OPERATIONS (unordered_map)
----------------------------------------

unordered_map<int,int> mp;

Insert: mp[x]++;  
Check: if(mp.count(x))  
Erase: mp.erase(x);  
Size: mp.size();  

unordered_set<int> st;

Insert: st.insert(x);  
Check: if(st.count(x))  
Erase: st.erase(x);  

----------------------------------------
6. VISUAL EXAMPLE — Frequency Count
----------------------------------------

Arr = [1, 2, 1, 3, 2, 1]

Hash:
1 -> 3
2 -> 2
3 -> 1

----------------------------------------
7. EDGE CASES
----------------------------------------

✔ Large keys (use unordered_map instead of array)  
✔ Negative keys  
✔ String keys  
✔ Collisions (handled internally)  
✔ Unordered_map NOT sorted  
✔ Do not iterate expecting order  

----------------------------------------
8. TIME / SPACE COMPLEXITY  
----------------------------------------

unordered_map / unordered_set:

    Insert      -> O(1) avg  
    Search      -> O(1) avg  
    Delete      -> O(1) avg  
    Worst case  -> O(n) (rare)  

Space complexity: O(n)


===========================================================================================
                🔥 NOW WE IMPLEMENT 3 MOST IMPORTANT HASHING BASICS WITH CODE
===========================================================================================
*/


// -----------------------------------------------------------------------------------------
// 1) FREQUENCY HASHING (Most Important)
// -----------------------------------------------------------------------------------------
void frequencyHashing(vector<int> &arr) {
    unordered_map<int,int> freq;
    for(int x : arr) freq[x]++;

    cout << "\nFrequency of elements:\n";
    for(auto &p : freq) {
        cout << p.first << " -> " << p.second << "\n";
    }
}


// -----------------------------------------------------------------------------------------
// 2) CHECK IF ARRAY HAS DUPLICATES
// -----------------------------------------------------------------------------------------
bool hasDuplicate(vector<int> &arr) {
    unordered_set<int> st;
    for(int x: arr) {
        if(st.count(x)) return true;
        st.insert(x);
    }
    return false;
}


// -----------------------------------------------------------------------------------------
// 3) TWO SUM USING HASHING (LeetCode #1)
// -----------------------------------------------------------------------------------------
vector<int> twoSum(vector<int> &arr, int target) {
    unordered_map<int,int> mp; // value -> index

    for(int i=0; i<arr.size(); i++) {
        int need = target - arr[i];
        if(mp.count(need)) {
            return { mp[need], i };
        }
        mp[arr[i]] = i;
    }
    return {}; // no solution
}


// -----------------------------------------------------------------------------------------
// MAIN FUNCTION (For testing hashing basics)
// -----------------------------------------------------------------------------------------
int main() {

    int n;
    cout << "Enter array size: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter array: ";
    for(int i=0; i<n; i++) cin >> arr[i];

    frequencyHashing(arr);

    cout << "\nHas duplicate? " << (hasDuplicate(arr) ? "YES" : "NO") << "\n";

    int target;
    cout << "\nEnter target for Two Sum: ";
    cin >> target;

    vector<int> ans = twoSum(arr, target);

    if(ans.size()) {
        cout << "Two sum indices: " << ans[0] << ", " << ans[1];
    } else {
        cout << "No two sum found.";
    }

    return 0;
}


/*
===========================================================================================
                         🔥 11-STEP PROBLEM SOLVING SYSTEM (HASHING)
===========================================================================================

1) Understand the question  
   - Kya store karna hai?  
   - Kya quickly find karna hai?  

2) Constraints  
   - Values kitni badi ho sakti hain?  
   - Negative values allowed?  
   - Strings allowed?  

3) Edge cases  
   - Duplicate elements  
   - Empty array  
   - Single element  

4) Brute force  
   - Mostly O(n^2) comparisons  

5) Pattern  
   - Frequency table?  
   - Set?  
   - Map for key-value?  

6) Optimal solution  
   - unordered_map / unordered_set  

7) Code  
   - Clean, efficient hashing  

8) Dry run  
   - Example values  

9) Interviewer explanation  
   “I used hashing to achieve O(1) lookups.”  

10) Mistakes to avoid  
   - Expecting unordered_map to be sorted  
   - Forgetting negative index for array hashing  
   - Using array hash when values > 1e7  

11) Variants  
   - Two-sum  
   - Count distinct elements  
   - K-frequency problems  
   - Anagram check  
   - Subarray sum problems  

===========================================================================================
                            🔥 HASHING COMPLETE — MASTERED 🔥
===========================================================================================
*/

