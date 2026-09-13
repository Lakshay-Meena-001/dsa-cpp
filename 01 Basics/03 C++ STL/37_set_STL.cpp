#include <bits/stdc++.h>
using namespace std;

/*
===============================
C++ STL Set Complete Reference
===============================

Set:
- An associative container that stores unique elements following a specific order (by default ascending).
- Internally implemented as a balanced BST (usually Red-Black Tree).
- Duplicate elements are automatically ignored.

Common Use Cases:
1️⃣ Removing duplicates from an array.
2️⃣ Maintaining a sorted collection.
3️⃣ Searching, insertion, and deletion in O(log n) time.
4️⃣ Range queries (lower_bound, upper_bound).

Important Member Functions:
- insert(x): Inserts element x into the set.
- erase(x): Removes element x.
- find(x): Returns iterator to element x or set::end() if not found.
- count(x): Returns 1 if element exists, else 0.
- size(): Returns number of elements in the set.
- empty(): Check if set is empty.
- lower_bound(x): Iterator to first element >= x.
- upper_bound(x): Iterator to first element > x.
- begin(), end(): Iterators for traversal.

Differences between set and unordered_set:
- set: elements sorted, O(log n) operations.
- unordered_set: elements not sorted, O(1) average operations.

*/

void explainSetDSA() {
    cout << "========== STL Set for DSA/LeetCode ==========\n";

    // 1️⃣ Basic set operations
    set<int> s;
    s.insert(10);
    s.insert(5);
    s.insert(20);
    s.insert(10); // duplicate ignored

    cout << "Elements in set: ";
    for (auto x : s) cout << x << " "; // 5 10 20
    cout << "\n";

    // 2️⃣ Erase and find
    s.erase(10);
    cout << "After erase(10): ";
    for (auto x : s) cout << x << " "; // 5 20
    cout << "\n";

    auto it = s.find(20);
    if(it != s.end()) cout << "Found 20\n";
    else cout << "20 not found\n";

    cout << "Count of 5: " << s.count(5) << "\n"; // 1
    cout << "Count of 15: " << s.count(15) << "\n"; // 0

    // 3️⃣ Lower and upper bounds
    s.insert(15);
    auto lb = s.lower_bound(12); // first >= 12
    auto ub = s.upper_bound(15); // first > 15
    cout << "Lower bound of 12: " << *lb << "\n"; // 15
    cout << "Upper bound of 15: " << *ub << "\n"; // 20

    // 4️⃣ Reverse order traversal
    cout << "Reverse order: ";
    for(auto it = s.rbegin(); it != s.rend(); it++) cout << *it << " "; // 20 15 5
    cout << "\n";

    // 5️⃣ Multiset allows duplicates
    multiset<int> ms;
    ms.insert(10);
    ms.insert(10);
    ms.insert(20);
    cout << "Multiset elements: ";
    for(auto x : ms) cout << x << " "; // 10 10 20
    cout << "\n";

    // 6️⃣ LeetCode-style usage: Count distinct elements
    vector<int> nums = {1, 2, 2, 3, 3, 3};
    set<int> distinct(nums.begin(), nums.end());
    cout << "Number of distinct elements: " << distinct.size() << "\n"; // 3
}

int main() {
    explainSetDSA();
    return 0;
}
