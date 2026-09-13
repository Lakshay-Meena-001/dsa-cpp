#include <bits/stdc++.h>
using namespace std;

/*
MULTIMAP
- Stores key-value pairs as (key, value)
- **Keys can be repeated** (unlike map)
- Keys are **sorted in ascending order**
- Underlying data structure: Balanced BST (usually Red-Black Tree)
- Average complexity: O(log n) for insert, erase, find

Common functions:
1️⃣ insert({key, value}) / emplace(key, value) : Add element
2️⃣ erase(key) or erase(iterator)              : Remove elements
3️⃣ find(key)                                  : Returns iterator to first element with key
4️⃣ count(key)                                 : Number of elements with given key
5️⃣ equal_range(key)                           : Returns pair of iterators for the range of that key
6️⃣ size(), empty()                            : Size and empty check
7️⃣ swap(multimap2)                            : Swap contents with another multimap
*/

void explainMultimap() {
    multimap<int, string> mm;

    // 1️⃣ Insert elements (duplicates allowed)
    mm.insert({1, "one"});
    mm.emplace(2, "two");
    mm.insert({2, "dos"});
    //mm[3] = "three"; // ❌ multimap does NOT support operator[], use insert/emplace
    mm.emplace(1, "uno"); // duplicate key
    cout << "After inserts:\n";
    for (auto &p : mm) cout << p.first << " -> " << p.second << "\n";

    // 2️⃣ Find elements
    auto it = mm.find(2); // returns iterator to first element with key 2
    if (it != mm.end()) cout << "Found key 2 -> " << it->second << "\n";

    // 3️⃣ Count elements with a key
    cout << "Count of key 1: " << mm.count(1) << "\n"; // 2

    // 4️⃣ Range of elements for a key
    auto range = mm.equal_range(1); // returns pair<iterator, iterator>
    cout << "All elements with key 1:\n";
    for (auto it = range.first; it != range.second; ++it)
        cout << it->first << " -> " << it->second << "\n";

    // 5️⃣ Erase elements
    mm.erase(2); // removes all elements with key 2
    cout << "After erase(2):\n";
    for (auto &p : mm) cout << p.first << " -> " << p.second << "\n";

    // Erase using iterator
    auto it2 = mm.find(1);
    if (it2 != mm.end()) mm.erase(it2); // removes only one element with key 1
    cout << "After erase(iterator to 1):\n";
    for (auto &p : mm) cout << p.first << " -> " << p.second << "\n";

    // 6️⃣ Swap multimaps
    multimap<int, string> mm2;
    mm2.emplace(100, "hundred");
    mm2.emplace(200, "two hundred");
    mm.swap(mm2);
    cout << "mm after swap:\n";
    for (auto &p : mm) cout << p.first << " -> " << p.second << "\n";

    // 7️⃣ Size and empty
    cout << "Size of mm: " << mm.size() << "\n";
    cout << "Is mm empty? " << (mm.empty() ? "Yes" : "No") << "\n";
}

int main() {
    // Title: MULTIMAP STL Reference
    explainMultimap();
    return 0;
}
