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

Node *deleteMiddle(Node *head)
{
    // Empty list ya single-node list mein middle node actually head hi hai. Usko delete karne par list empty ho jayegi.
    if (head == nullptr || head->next == nullptr)
    {
        return nullptr;
    }

    Node *slow = head;

    // fast ko 2 nodes ahead se start kar rahe hain. kyuki,slow ko MIDDLE ke previous node par stop karwana hai.
    Node *fast = head->next->next;

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    // slow->next = middle node
    Node *middle = slow->next;

    slow->next = middle->next;

    delete middle;

    return head;
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
    /*
        Original:

        1 -> 2 -> 3 -> 4 -> 5

        Middle = 3

        After deletion:

        1 -> 2 -> 4 -> 5
    */

    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    cout << "Original List: ";
    printList(head);

    head = deleteMiddle(head);

    cout << "After Deleting Middle: ";
    printList(head);

    return 0;
}

/*
INPUT:

1 -> 2 -> 3 -> 4 -> 5


OUTPUT:

1 -> 2 -> 4 -> 5


PATTERN:
Slow + Fast Pointer
+
Pointer Position Control
+
Linked List Deletion


CORE IDEA:

LC 876 mein:

slow -> middle

LC 2095 mein:

slow -> middle ka PREVIOUS

Then:

slow->next = slow->next->next;

Middle node list se remove ho jata hai.


WHY fast = head->next->next?

Hume slow ko middle ke previous node par stop karna hai.

Is initial offset ki wajah se fast thoda ahead se start karta hai.

Isse:

ODD:
1 -> 2 -> 3 -> 4 -> 5

slow -> 2
slow->next -> 3 (middle)


EVEN:
1 -> 2 -> 3 -> 4

slow -> 2
slow->next -> 3 (second middle)


EDGE CASE:

1-node list:

1

Middle = 1

Delete karne ke baad:
NULL

Isliye directly:
return nullptr;


DELETION:

slow -> middle -> next

becomes:

slow -> next

using:

slow->next = middle->next;


TIME COMPLEXITY:
O(n)

Fast pointer list ko linear traversal mein cover karta hai.


SPACE COMPLEXITY:
O(1)

Only constant number of pointers use hue hain.


IMPORTANT:
Ye problem sirf "middle find" nahi hai.

Actual learning:
Pointer ko EXACT desired position par stop karwana.

Yahi pointer-position control aage
bahut saare linked-list problems mein kaam aayega.
*/