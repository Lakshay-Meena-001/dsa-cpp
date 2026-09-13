#include <bits/stdc++.h>
using namespace std;

/*
===============================
C++ STL Priority Queue Complete Reference
===============================

Priority Queue:
- A container adapter that provides constant time retrieval of the largest (by default) element.
- Implements a Max-Heap by default.
- Elements are inserted in arbitrary order, but the largest element is always accessible at the top.

Common Use Cases:
1️⃣ Dijkstra's shortest path.
2️⃣ Prim's minimum spanning tree.
3️⃣ Sliding window maximum.
4️⃣ Top-K problems (e.g., top K frequent elements).

Important Member Functions:
- push(x): Insert element into the priority queue.
- emplace(args): Construct element in-place and insert (more efficient for complex objects).
- pop(): Remove the largest element (or smallest if min-heap).
- top(): Access the largest element (or smallest if min-heap).
- size(): Number of elements in the priority queue.
- empty(): Check if priority queue is empty.
- swap(pq2): Swap contents with another priority queue.

Differences between push() and emplace():
----------------------------------------
1. push(x): Takes an existing object and copies/moves it into the queue.
2. emplace(args...): Constructs the object directly in-place at the correct position.
   - More efficient for complex types.
   - Example:
       priority_queue<pair<int,int>> pq;
       pq.push(make_pair(1,2));  // creates pair then copies
       pq.emplace(1,2);           // constructs pair directly

Custom Comparators:
- By default, it's a Max-Heap.
- Min-Heap: priority_queue<int, vector<int>, greater<int>> pq;

*/

void explainPriorityQueueDSA()
{
    cout << "========== STL Priority Queue for DSA/LeetCode ==========\n";

    // 1️⃣ Max-Heap (default)
    priority_queue<int> pq;
    pq.push(10);
    pq.push(5);
    pq.emplace(20);                                    // in-place
    cout << "Top element (max): " << pq.top() << "\n"; // 20
    pq.pop();
    cout << "Top after pop: " << pq.top() << "\n"; // 10

    // 2️⃣ Size and empty check
    cout << "Size: " << pq.size() << ", Empty? " << (pq.empty() ? "Yes" : "No") << "\n";

    // 3️⃣ Min-Heap using greater<>
    priority_queue<int, vector<int>, greater<int>> minPQ;
    minPQ.push(30);
    minPQ.push(10);
    minPQ.push(20);
    cout << "Top element (min): " << minPQ.top() << "\n"; // 10

    // 4️⃣ Priority Queue of pairs
    priority_queue<pair<int, int>> pqPair; // Max-Heap based on first element
    pqPair.emplace(2, 100);
    pqPair.push({1, 200});
    cout << "Top pair: (" << pqPair.top().first << ", " << pqPair.top().second << ")\n";

    // 5️⃣ Custom comparator
    auto cmp = [](pair<int, int> a, pair<int, int> b)
    {
        return a.second > b.second; // min-heap based on second element
    };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> customPQ(cmp);
    customPQ.push({1, 100});
    customPQ.push({2, 50});
    customPQ.push({3, 150});
    cout << "Top of custom PQ (min by second): ("
         << customPQ.top().first << ", " << customPQ.top().second << ")\n";

    // 6️⃣ Iterating through a priority queue (requires copy)
    cout << "Elements in pq (max-heap order): ";
    priority_queue<int> temp = pq;
    while (!temp.empty())
    {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << "\n";

    // 7️⃣ LeetCode-style usage: Top-K frequent elements
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    unordered_map<int, int> freq;
    for (int x : nums)
        freq[x]++;
    priority_queue<pair<int, int>> maxHeap;
    for (auto &p : freq)
        maxHeap.push({p.second, p.first});
    cout << "Top K frequent elements: ";
    int K = 2;
    while (K-- && !maxHeap.empty())
    {
        cout << maxHeap.top().second << " ";
        maxHeap.pop();
    }
    cout << "\n";
}

int main()
{
    explainPriorityQueueDSA();
    return 0;
}
