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

Node *reverseList(Node *head)
{
    Node *prev = nullptr;
    Node *curr = head;

    while (curr != nullptr)
    {
        // 1. Save the remaining list
        Node *next = curr->next;

        // 2. Reverse current link
        curr->next = prev;

        // 3. Move prev forward
        prev = curr;

        // 4. Move curr forward
        curr = next;
    }

    // prev is the new head
    return prev;
}

Node *reverseRecursive(Node *head)
{
    // Base case
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    // Recursively reverse the remaining list
    Node *newHead = reverseRecursive(head->next);

    // Reverse current connection
    head->next->next = head;

    // Remove old connection
    head->next = nullptr;

    return newHead;
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

    head = reverseList(head);

    cout << "Reversed List:\n";
    printList(head);

    return 0;
}