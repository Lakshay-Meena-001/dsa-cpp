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

Node *oddEvenList(Node *head)
{
    // Empty ya single node
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    Node *odd = head;
    Node *even = head->next;

    // First even node ko save karna hai
    // kyunki even pointer aage move karega
    Node *evenHead = even;

    while (even != nullptr && even->next != nullptr)
    {
        // Next odd node ko odd chain mein attach karo
        odd->next = even->next;
        odd = odd->next;

        // Next even node ko even chain mein attach karo
        even->next = odd->next;
        even = even->next;
    }

    // Odd chain ke end ko even chain ke start se connect karo
    odd->next = evenHead;

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
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    cout << "Original List:\n";
    printList(head);

    head = oddEvenList(head);

    cout << "\nAfter Odd-Even Rearrangement:\n";
    printList(head);

    return 0;
}