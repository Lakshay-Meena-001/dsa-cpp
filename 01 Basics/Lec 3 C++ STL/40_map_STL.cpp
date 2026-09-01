#include <bits/stdc++.h>
using namespace std;

/*
MAP (Ordered Map)
- Stores key-value pairs as (key, value)
- Keys are **unique** and **sorted in ascending order**
- Underlying data structure: Balanced BST (usually Red-Black Tree)
- Average complexity: O(log n) for insert, erase, find

Common functions:
1️⃣ insert({key, value}) / emplace(key, value) : Add element
2️⃣ erase(key) or erase(iterator)              : Remove element
3️⃣ find(key)                                  : Returns iterator to element if found, else end()
4️⃣ count(key)                                 : 1 if key exists, 0 if not
5️⃣ operator[]                                 : Access or insert elements
6️⃣ size(), empty()                            : Size and empty check
7️⃣ swap(map2)                                 : Swap contents with another map
*/

void explainMap() {
    map<int, string> mp;

    // 1️⃣ Insert elements
    mp.insert({1, "one"});
    mp.emplace(2, "two");
    mp[3] = "three"; // also works
    cout << "After inserts: \n";
    for (auto &p : mp) cout << p.first << " -> " << p.second << "\n";

    // 2️⃣ Access elements
    cout << "Element with key 2: " << mp[2] << "\n"; // "two"
    cout << "Element with key 4 (not present, auto-inserted): " << mp[4] << "\n";

    // 3️⃣ Check existence
    if (mp.find(3) != mp.end()) cout << "Key 3 is present\n";
    cout << "Count of key 1: " << mp.count(1) << "\n"; // 1
    cout << "Count of key 5: " << mp.count(5) << "\n"; // 0

    // 4️⃣ Remove elements
    mp.erase(4); // remove by key
    cout << "After erase(4): \n";
    for (auto &p : mp) cout << p.first << " -> " << p.second << "\n";

    // Erase using iterator
    auto it = mp.find(2);
    if (it != mp.end()) mp.erase(it);
    cout << "After erase(iterator to 2): \n";
    for (auto &p : mp) cout << p.first << " -> " << p.second << "\n";

    // 5️⃣ Swap maps
    map<int, string> mp2;
    mp2[100] = "hundred";
    mp2[200] = "two hundred";
    cout << "mp before swap: \n";
    for (auto &p : mp) cout << p.first << " -> " << p.second << "\n";
    cout << "mp2 before swap: \n";
    for (auto &p : mp2) cout << p.first << " -> " << p.second << "\n";

    mp.swap(mp2);

    cout << "mp after swap: \n";
    for (auto &p : mp) cout << p.first << " -> " << p.second << "\n";
    cout << "mp2 after swap: \n";
    for (auto &p : mp2) cout << p.first << " -> " << p.second << "\n";

    // 6️⃣ Size and empty
    cout << "Size of mp: " << mp.size() << "\n";
    cout << "Is mp empty? " << (mp.empty() ? "Yes" : "No") << "\n";
}

int main() {
    // Title: MAP STL Reference
    explainMap();
    return 0;
}
