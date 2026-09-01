#include <bits/stdc++.h>
using namespace std;

/*
UNORDERED MAP
- Stores key-value pairs
- **Keys are unique**
- Elements are **not sorted** (hash table based)
- Average complexity: O(1) for insert, find, erase
- Worst case: O(n) in case of hash collisions

Common functions:
1️⃣ insert({key, value}) / emplace(key, value) : Add element
2️⃣ erase(key) or erase(iterator)              : Remove element
3️⃣ find(key)                                  : Returns iterator to key
4️⃣ count(key)                                 : 0 or 1 (existence check)
5️⃣ size(), empty()                            : Size and empty check
6️⃣ swap(umap2)                               : Swap contents with another unordered_map
*/

void explainUnorderedMap() {
    unordered_map<int, string> umap;

    // 1️⃣ Insert elements
    umap.insert({1, "one"});
    umap.emplace(2, "two");
    umap[3] = "three"; // operator[] works in unordered_map
    umap[4] = "four";

    cout << "After inserts:\n";
    for (auto &p : umap) cout << p.first << " -> " << p.second << "\n";

    // 2️⃣ Find elements
    auto it = umap.find(2);
    if (it != umap.end()) cout << "Found key 2 -> " << it->second << "\n";

    // 3️⃣ Count elements (existence)
    cout << "Count of key 1: " << umap.count(1) << "\n"; // 1
    cout << "Count of key 10: " << umap.count(10) << "\n"; // 0

    // 4️⃣ Erase elements
    umap.erase(2); // remove key 2
    cout << "After erase(2):\n";
    for (auto &p : umap) cout << p.first << " -> " << p.second << "\n";

    // Erase using iterator
    auto it2 = umap.find(3);
    if (it2 != umap.end()) umap.erase(it2); // remove key 3
    cout << "After erase(iterator to 3):\n";
    for (auto &p : umap) cout << p.first << " -> " << p.second << "\n";

    // 5️⃣ Swap unordered maps
    unordered_map<int, string> umap2;
    umap2.emplace(100, "hundred");
    umap2.emplace(200, "two hundred");
    umap.swap(umap2);
    cout << "umap after swap:\n";
    for (auto &p : umap) cout << p.first << " -> " << p.second << "\n";

    // 6️⃣ Size and empty
    cout << "Size of umap: " << umap.size() << "\n";
    cout << "Is umap empty? " << (umap.empty() ? "Yes" : "No") << "\n";
}

int main() {
    // Title: UNORDERED MAP STL Reference
    explainUnorderedMap();
    return 0;
}
