#include <bits/stdc++.h>
using namespace std;

/*
===============================
C++ STL List Cheat Sheet
===============================

A list is a doubly linked list in C++ STL. 
It allows fast insertion and deletion anywhere in the list.
Unlike vectors, elements are not contiguous in memory, so random access is slower (no operator[]).

Common Uses:
1️⃣ When frequent insertions/deletions are needed.
2️⃣ Implementing deque, queue, stack manually.
3️⃣ Merging and splicing lists efficiently.
4️⃣ Maintaining sorted sequences with insertions.

Important Points:
- Supports bidirectional iterators.
- Operations like push_front, push_back, pop_front, pop_back are O(1).
- Insertion/deletion in the middle with iterator is O(1).

*/

void explainList() {
    cout << "========== STL List Examples ==========\n";

    // 1️⃣ Declare a list
    list<int> li;
    
    // 2️⃣ Insert elements
    li.push_back(10);      // Add at end
    li.emplace_back(20);   // Construct at end
    li.push_front(5);      // Add at front
    li.emplace_front(2);   // Construct at front

    cout << "List after push/emplace operations: ";
    for(int x : li) cout << x << " ";
    cout << "\n";

    // 3️⃣ Delete elements
    li.pop_back();         // Remove from end
    li.pop_front();        // Remove from front
    cout << "List after pop operations: ";
    for(int x : li) cout << x << " ";
    cout << "\n";

    // 4️⃣ Insert at specific position using iterator
    auto it = li.begin();
    advance(it, 1);        // Move iterator to second element
    li.insert(it, 15);     // Insert 15 at 2nd position
    cout << "List after insert at position 2: ";
    for(int x : li) cout << x << " ";
    cout << "\n";

    // 5️⃣ Erase element at iterator
    it = li.begin();
    advance(it, 1);
    li.erase(it);          // Remove 2nd element
    cout << "List after erase at position 2: ";
    for(int x : li) cout << x << " ";
    cout << "\n";

    // 6️⃣ Remove all elements with value 20
    li.push_back(20);
    li.push_back(20);
    li.remove(20);         // Remove all occurrences of 20
    cout << "List after remove(20): ";
    for(int x : li) cout << x << " ";
    cout << "\n";

    // 7️⃣ Reverse the list
    li.reverse();
    cout << "List after reverse: ";
    for(int x : li) cout << x << " ";
    cout << "\n";

    // 8️⃣ Sort the list
    li.push_back(8);
    li.push_back(1);
    li.sort();
    cout << "List after sort: ";
    for(int x : li) cout << x << " ";
    cout << "\n";

    // 9️⃣ Unique consecutive elements
    li.push_back(1);
    li.push_back(1);
    li.unique();  // Remove consecutive duplicates
    cout << "List after unique(): ";
    for(int x : li) cout << x << " ";
    cout << "\n";

    // 10️⃣ Merge two sorted lists
    list<int> l2 = {3, 4, 5};
    li.merge(l2); // li must be sorted; l2 is merged and emptied
    cout << "List after merge with l2: ";
    for(int x : li) cout << x << " ";
    cout << "\n";

    // 11️⃣ Splice: move elements from another list
    list<int> l3 = {100, 200};
    it = li.begin();
    advance(it, 2);
    li.splice(it, l3); // insert all elements of l3 at position 'it'; l3 becomes empty
    cout << "List after splice with l3: ";
    for(int x : li) cout << x << " ";
    cout << "\n";

    // 12️⃣ Size and empty
    cout << "Size of list: " << li.size() << "\n";
    cout << "Is list empty? " << (li.empty() ? "Yes" : "No") << "\n";
}

int main() {
    explainList();
    return 0;
}
