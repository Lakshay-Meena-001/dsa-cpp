#include <bits/stdc++.h>
using namespace std;

/*
===============================
C++ STL Deque Cheat Sheet
===============================

Deque (Double Ended Queue) is a sequence container with dynamic sizes that can be expanded or contracted on both ends (front & back). 
It supports fast insertion and deletion at both ends, unlike vector which is efficient only at the back.

Common Uses:
1️⃣ Implementing queue, stack, or double-ended queue.
2️⃣ Sliding window problems.
3️⃣ Frequent insertions/deletions at both ends.

Important Points:
- Supports random access using operator[] and at().
- push_front/pop_front/push_back/pop_back are O(1) on average.
- Insertions in the middle are slower than at ends (O(n)).

*/

void explainDeque() {
    cout << "========== STL Deque Examples ==========\n";

    // 1️⃣ Declare a deque
    deque<int> dq;

    // 2️⃣ Insert elements
    dq.push_back(10);      // Add at back
    dq.emplace_back(20);   // Construct at back
    dq.push_front(5);      // Add at front
    dq.emplace_front(2);   // Construct at front

    cout << "Deque after push/emplace operations: ";
    for(int x : dq) cout << x << " ";
    cout << "\n";

    // 3️⃣ Delete elements
    dq.pop_back();         // Remove from back
    dq.pop_front();        // Remove from front
    cout << "Deque after pop operations: ";
    for(int x : dq) cout << x << " ";
    cout << "\n";

    // 4️⃣ Access elements
    cout << "First element: " << dq.front() << "\n";
    cout << "Last element: " << dq.back() << "\n";
    cout << "Element at index 1: " << dq[1] << "\n"; // or dq.at(1)

    // 5️⃣ Insert at specific position using iterator
    auto it = dq.begin();
    advance(it, 1);        // Move iterator to 2nd element
    dq.insert(it, 15);     // Insert 15 at 2nd position
    cout << "Deque after insert at position 2: ";
    for(int x : dq) cout << x << " ";
    cout << "\n";

    // 6️⃣ Erase element at iterator
    it = dq.begin();
    advance(it, 1);
    dq.erase(it);          // Remove 2nd element
    cout << "Deque after erase at position 2: ";
    for(int x : dq) cout << x << " ";
    cout << "\n";

    // 7️⃣ Size and empty
    cout << "Size of deque: " << dq.size() << "\n";
    cout << "Is deque empty? " << (dq.empty() ? "Yes" : "No") << "\n";

    // 8️⃣ Clear deque
    dq.clear();
    cout << "Size after clear(): " << dq.size() << "\n";
}

int main() {
    explainDeque();
    return 0;
}
