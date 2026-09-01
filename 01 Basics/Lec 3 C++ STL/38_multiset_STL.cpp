#include <bits/stdc++.h>
using namespace std;

/*
===============================
C++ STL Multiset Complete Reference
===============================

Multiset:
- An associative container that stores **elements in sorted order**.
- **Duplicates are allowed** (unlike set).
- Internally implemented as a balanced BST (usually Red-Black Tree).

Common Use Cases:
1️⃣ Counting frequency of elements while maintaining order.
2️⃣ Sliding window maximum/minimum problems.
3️⃣ Keeping a dynamic sorted collection of numbers.
4️⃣ Efficient insertion, deletion, and searching (O(log n)).

Important Member Functions:
- insert(x): Inserts element x.
- erase(x): Removes **all occurrences** of x. To erase one occurrence, use iterator version.
- find(x): Returns iterator to an element x or end() if not found.
- count(x): Returns the number of occurrences of x.
- size(): Returns number of elements.
- empty(): Checks if multiset is empty.
- lower_bound(x): Iterator to first element >= x.
- upper_bound(x): Iterator to first element > x.
- begin(), end(): Iterators for traversal.

Differences between set and multiset:
- set: unique elements only
- multiset: allows duplicates

*/

void explainMultisetDSA() {
    cout << "========== STL Multiset for DSA/LeetCode ==========\n";

    // 1️⃣ Basic multiset operations
    multiset<int> ms;
    ms.insert(10);
    ms.insert(5);
    ms.insert(20);
    ms.insert(10); // duplicates allowed

    cout << "Elements in multiset: ";
    for (auto x : ms) cout << x << " "; // 5 10 10 20
    cout << "\n";

    // 2️⃣ Erase
    ms.erase(10); // removes all 10s
    cout << "After erase(10): ";
    for (auto x : ms) cout << x << " "; // 5 20
    int cnt = ms.count(10);
    cout << "\nCount of 10 after erase: " << cnt; // 0
    ms.erase(ms.find(10));
    cout << "\n";

    // To erase only **one occurrence**
    ms.insert(10);
    ms.insert(10);
    auto it = ms.find(10);
    if (it != ms.end()) ms.erase(it); // removes **one 10**
    cout << "After erasing one 10: ";
    for (auto x : ms) cout << x << " "; // 5 10 20
    cout << "\n";

    // 3️⃣ Count occurrences
    ms.insert(10);
    ms.insert(10);
    cout << "Count of 10: " << ms.count(10) << "\n"; // 3

    // 4️⃣ Lower and upper bounds
    auto lb = ms.lower_bound(10); // first >= 10
    auto ub = ms.upper_bound(10); // first > 10
    cout << "Lower bound of 10: " << *lb << "\n"; // 10
    cout << "Upper bound of 10: " << *ub << "\n"; // 20

    // 5️⃣ Reverse traversal
    cout << "Reverse order: ";
    for(auto it = ms.rbegin(); it != ms.rend(); it++) cout << *it << " "; // 20 10 10 10 5
    cout << "\n";

    // 6️⃣ LeetCode-style usage: Sliding window or duplicate counting
    vector<int> nums = {1, 2, 2, 3, 3, 3};
    multiset<int> freq(nums.begin(), nums.end());
    cout << "Count of 2 in vector: " << freq.count(2) << "\n"; // 2
    cout << "Count of 3 in vector: " << freq.count(3) << "\n"; // 3
}

int main() {
    explainMultisetDSA();
    return 0;
}
