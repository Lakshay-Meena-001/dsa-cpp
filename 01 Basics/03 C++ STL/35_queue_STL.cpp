#include <bits/stdc++.h>
using namespace std;

/*
===============================
C++ STL Queue Complete Reference
===============================

Queue:
- A container adapter that implements FIFO (First In First Out) principle.
- Underlying container: deque (default), can also use list.
- Elements are inserted at the back and removed from the front.
- Random access is NOT allowed.

Common Use Cases:
1️⃣ BFS (Breadth-First Search) in graphs and trees.
2️⃣ Sliding window problems.
3️⃣ Job scheduling / task management.
4️⃣ Level order traversal in trees.

Important Member Functions:
- push(x): Insert element at the back.
- emplace(args): Construct element in-place at the back.
- pop(): Remove element from the front.
- front(): Access the first element.
- back(): Access the last element.
- size(): Number of elements in the queue.
- empty(): Check if queue is empty.
- swap(q2): Swap contents with another queue.

Difference between push() and emplace():
----------------------------------------
1. push(x): Takes an existing object and copies/moves it to the queue.
2. emplace(args...): Constructs the element directly at the back without extra copy/move.
   - More efficient for complex objects.
   - Example:
       queue<pair<int,int>> q;
       q.push(make_pair(1,2));  // Creates pair then copies to queue
       q.emplace(1,2);           // Constructs pair directly in-place
*/

void explainQueueDSA() {
    cout << "========== STL Queue for DSA/LeetCode ==========\n";

    // 1️⃣ Declare a queue
    queue<int> q;

    // 2️⃣ Insert elements using push() and emplace()
    q.push(10);           // push element
    q.push(20);
    q.emplace(30);        // construct in-place

    cout << "Front element: " << q.front() << "\n";
    cout << "Back element: " << q.back() << "\n";

    // 3️⃣ Remove element from front
    q.pop();
    cout << "Front after pop: " << q.front() << "\n";

    // 4️⃣ Size and empty check
    cout << "Size of queue: " << q.size() << "\n";
    cout << "Is queue empty? " << (q.empty() ? "Yes" : "No") << "\n";

    // 5️⃣ Swap queues
    queue<int> q2;
    q2.push(100);
    q.swap(q2);
    cout << "Front of q after swap: " << (q.empty() ? -1 : q.front()) << "\n";
    cout << "Front of q2 after swap: " << (q2.empty() ? -1 : q2.front()) << "\n";

    // 6️⃣ Queue with complex objects
    queue<pair<int,int>> qPair;
    qPair.push(make_pair(1,2));   // copy
    qPair.emplace(3,4);           // in-place
    cout << "Front of queue<pair>: (" << qPair.front().first << "," << qPair.front().second << ")\n";

    // 7️⃣ Iterating through a queue (requires copy)
    cout << "Elements in q2 (front to back): ";
    queue<int> temp = q2;
    while (!temp.empty()) {
        cout << temp.front() << " ";
        temp.pop();
    }
    cout << "\n";

    // 8️⃣ Use in LeetCode-style problems
    // Example: BFS traversal in a binary tree (simplified)
    struct Node {
        int val;
        Node* left;
        Node* right;
        Node(int v): val(v), left(nullptr), right(nullptr) {}
    };

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    queue<Node*> bfs;
    bfs.push(root);
    cout << "BFS Traversal: ";
    while(!bfs.empty()) {
        Node* node = bfs.front();
        bfs.pop();
        cout << node->val << " ";
        if(node->left) bfs.push(node->left);
        if(node->right) bfs.push(node->right);
    }
    cout << "\n";
}

int main() {
    explainQueueDSA();
    return 0;
}
