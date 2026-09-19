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

Node *rotateRight(Node *head, int k)
{
    // Empty ya single node
    if (head == nullptr || head->next == nullptr || k == 0)
    {
        return head;
    }

    // Step 1: Find length and last node
    int n = 1;
    Node *tail = head;

    while (tail->next != nullptr)
    {
        tail = tail->next;
        n++;
    }

    // Step 2: Extra full rotations remove karo
    k = k % n;

    // k == 0 means list unchanged
    if (k == 0)
    {
        return head;
    }

    // Step 3: Make the list circular
    tail->next = head;

    // Step 4: Find new tail
    int steps = n - k - 1;

    Node *newTail = head;

    while (steps--)
    {
        newTail = newTail->next;
    }

    // Step 5: New head is after new tail
    Node *newHead = newTail->next;

    // Step 6: Break the circle
    newTail->next = nullptr;

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

    int k = 2;

    head = rotateRight(head, k);

    cout << "\nAfter Right Rotation by " << k << ":\n";
    printList(head);

    return 0;
}