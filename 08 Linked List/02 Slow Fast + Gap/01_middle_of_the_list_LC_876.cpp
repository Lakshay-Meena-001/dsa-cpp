#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int value)
    {
        data = value;
        next = nullptr;
    }
};

// Slow + Fast Pointer
// slow -> 1 step
// fast -> 2 steps
Node *middleNode(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    
    // agar hume first middle chahiye in even to ek bar fast ko ek step aag ekardo taaki wo ek step pehl ehi finish ho jaye 
    // Node *slow = head;
    // Node *fast = head->next;


    // fast ko 2 steps safely move karna hai,
    // isliye fast aur fast->next dono check karenge.
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;       // 1 step
        fast = fast->next->next; // 2 steps
    }

    // Odd  -> exact middle
    // Even -> second middle
    return slow;
}

void printList(Node *head)
{
    while (head != nullptr)
    {
        cout << head->data << " -> ";
        head = head->next;
    }

    cout << "NULL\n";
}

int main()
{
    // 1 -> 2 -> 3 -> 4 -> 5 -> NULL
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    cout << "Linked List: ";
    printList(head);

    Node *middle = middleNode(head);

    cout << "Middle Node: " << middle->data << endl;

    return 0;
}

/*
INPUT:
1 -> 2 -> 3 -> 4 -> 5

OUTPUT:
Middle Node: 3

PATTERN:
Slow + Fast Pointer

IDEA:
slow = 1 step
fast = 2 steps

Jab fast list ke end tak pahunchta hai,
slow approximately half distance cover kar chuka hota hai.
Isliye slow middle node par hota hai.

EVEN LENGTH:
1 -> 2 -> 3 -> 4

Answer = 3
because LC 876 second middle return karta hai.

TIME COMPLEXITY:
O(n)

Reason:
Fast pointer 2 steps move karta hai,
but total traversal still proportional to n.

SPACE COMPLEXITY:
O(1)

Reason:
Sirf slow aur fast pointers use kiye hain.
Koi extra array/vector nahi.

IMPORTANT:
while (fast != nullptr && fast->next != nullptr)

Ye check zaroori hai kyunki fast->next->next access
karne se pehle fast aur fast->next valid hone chahiye.
*/