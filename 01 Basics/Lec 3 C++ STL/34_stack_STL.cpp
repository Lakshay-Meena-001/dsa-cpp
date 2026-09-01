#include <bits/stdc++.h>
using namespace std;

/*
===============================
C++ STL Stack Complete Reference
===============================

Stack:
- A container adapter that implements LIFO (Last In First Out) principle.
- Underlying container: deque (default), can also use vector or list.
- Operations allowed only at the top.
- Random access is NOT allowed.

Common Use Cases:
1️⃣ Backtracking problems (DFS, maze, n-queens).
2️⃣ Expression evaluation (infix, postfix, prefix).
3️⃣ Undo/Redo functionality in editors.
4️⃣ Call stack simulation.

Important Member Functions:
- push(x): Insert element on top.
- emplace(args): Construct element in-place on top.
- pop(): Remove top element.
- top(): Access the top element.
- size(): Number of elements.
- empty(): Check if stack is empty.
- swap(s2): Swap contents with another stack.

Difference between push() and emplace():
----------------------------------------
1. push(x): Takes an existing object and copies/moves it to the stack.
2. emplace(args...): Constructs the element directly on top of the stack without extra copy/move.
   - More efficient when creating complex objects.
   - Example:
       stack<pair<int,int>> s;
       s.push(make_pair(1,2));  // Creates pair then copies to stack
       s.emplace(1,2);           // Constructs pair directly in-place
*/

void explainStackDSA() {
    cout << "========== STL Stack for DSA/LeetCode ==========\n";

    // 1️⃣ Declare a stack
    stack<int> s;

    // 2️⃣ Insert elements using push() and emplace()
    s.push(10);           // push element
    s.push(20);
    s.emplace(30);        // construct in-place

    cout << "Top element after push/emplace: " << s.top() << "\n";

    // 3️⃣ Remove element
    s.pop();
    cout << "Top element after pop: " << s.top() << "\n";

    // 4️⃣ Stack size and emptiness check
    cout << "Size of stack: " << s.size() << "\n";
    cout << "Is stack empty? " << (s.empty() ? "Yes" : "No") << "\n";

    // 5️⃣ Swap stacks
    stack<int> s2;
    s2.push(100);
    s.swap(s2);
    cout << "Top of s after swap: " << (s.empty() ? -1 : s.top()) << "\n";
    cout << "Top of s2 after swap: " << (s2.empty() ? -1 : s2.top()) << "\n";

    // 6️⃣ Stack with complex objects
    stack<pair<int,int>> stPair;
    stPair.push(make_pair(1,2));   // copy
    stPair.emplace(3,4);           // in-place
    cout << "Top of stack<pair>: (" << stPair.top().first << "," << stPair.top().second << ")\n";

    // 7️⃣ Iterating through a stack (requires copy)
    cout << "Elements in s2 (top to bottom): ";
    stack<int> temp = s2;
    while (!temp.empty()) {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << "\n";

    // 8️⃣ Use in LeetCode-style problems
    // Example: Reverse a string using stack
    string str = "HELLO";
    stack<char> sChar;
    for(char c : str) sChar.push(c);

    string reversed = "";
    while(!sChar.empty()) {
        reversed += sChar.top();
        sChar.pop();
    }
    cout << "Original: " << str << ", Reversed using stack: " << reversed << "\n";
}

int main() {
    explainStackDSA();
    return 0;
}
