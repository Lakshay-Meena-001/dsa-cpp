#include <bits/stdc++.h>
using namespace std;

/*
UNORDERED SET
- Stores **unique elements** in no particular order
- Underlying data structure: Hash table
- Average complexity: O(1) for insert, erase, find
- Use case: Fast lookup, checking existence

Common functions:
1️⃣ insert(val) / emplace(val)  : Add element
2️⃣ erase(val)                  : Remove element by value
3️⃣ erase(iterator)             : Remove element at iterator
4️⃣ find(val)                   : Returns iterator to element if found, else end()
5️⃣ count(val)                  : Returns 1 if present, 0 if not
6️⃣ size(), empty()             : Size of set and empty check
7️⃣ swap(set2)                  : Swap contents with another set
*/

void explainUnorderedSet() {
    unordered_set<int> us;

    // 1️⃣ Insert elements
    us.insert(10);
    us.emplace(20);
    us.insert(30);

    cout << "After insert/emplace: ";
    for (auto x : us) cout << x << " "; // Order not guaranteed
    cout << "\n";

    // 2️⃣ Check existence
    if (us.find(20) != us.end()) {
        cout << "20 is present\n";
    }

    cout << "Count of 10: " << us.count(10) << "\n"; // 1

    // 3️⃣ Remove element by value
    us.erase(10); 
    cout << "After erase(10): ";
    for (auto x : us) cout << x << " ";
    cout << "\n";

    // 4️⃣ Remove element by iterator
    auto it = us.find(20);
    if (it != us.end()) us.erase(it);
    cout << "After erase(iterator to 20): ";
    for (auto x : us) cout << x << " ";
    cout << "\n";

    // 5️⃣ Swap sets
    unordered_set<int> us2;
    us2.insert(100);
    us2.insert(200);
    cout << "us before swap: ";
    for (auto x : us) cout << x << " ";
    cout << "\nus2 before swap: ";
    for (auto x : us2) cout << x << " ";
    cout << "\n";

    us.swap(us2); 
    cout << "us after swap: ";
    for (auto x : us) cout << x << " ";
    cout << "\nus2 after swap: ";
    for (auto x : us2) cout << x << " ";
    cout << "\n";

    // 6️⃣ Size and empty
    cout << "Size of us: " << us.size() << "\n";
    cout << "Is us empty? " << (us.empty() ? "Yes" : "No") << "\n";
}

int main() {
    // Title: UNORDERED_SET STL Reference
    explainUnorderedSet();
    return 0;
}
