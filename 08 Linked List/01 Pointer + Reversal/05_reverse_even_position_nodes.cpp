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

Node *reverseEvenPositions(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    // odd points to odd-position nodes
    // even points to even-position nodes
    Node *odd = head;
    Node *even = head->next;

    Node *evenHead = even;

    // Separate odd and even position nodes
    while (odd->next != nullptr && even->next != nullptr)
    {
        odd->next = even->next;
        odd = odd->next;

        if (odd->next != nullptr)
        {
            even->next = odd->next;
            even = even->next;
        }
    }

    // Terminate odd-position list
    odd->next = nullptr;

    // Reverse even-position list
    Node *prev = nullptr;
    Node *curr = evenHead;

    while (curr != nullptr)
    {
        Node *next = curr->next;

        curr->next = prev;
        prev = curr;
        curr = next;
    }

    // Merge odd and reversed-even lists
    odd = head;
    even = prev;

    while (even != nullptr)
    {
        Node *oddNext = odd->next;
        Node *evenNext = even->next;

        odd->next = even;
        even->next = oddNext;

        odd = oddNext;
        even = evenNext;
    }

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
    // 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> NULL

    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);

    cout << "Original List:\n";
    printList(head);

    head = reverseEvenPositions(head);

    cout << "After Reversing Even-Position Nodes:\n";
    printList(head);

    return 0;
}