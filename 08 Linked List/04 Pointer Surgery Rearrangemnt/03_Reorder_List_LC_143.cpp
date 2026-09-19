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
        Node *nextNode = curr->next;

        curr->next = prev;

        prev = curr;
        curr = nextNode;
    }

    return prev;
}

void reorderList(Node *head)
{
    // Empty ya single node
    if (head == nullptr || head->next == nullptr)
    {
        return;
    }

    // STEP 1: Find middle

    Node *slow = head;
    Node *fast = head;

    while (fast->next != nullptr && fast->next->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    // STEP 2: Split into two halves

    Node *second = slow->next;

    slow->next = nullptr;

    // STEP 3: Reverse second half

    second = reverseList(second);

    // STEP 4: Alternate merge

    Node *first = head;

    while (second != nullptr)
    {
        // taki pointer vonnect karne par list lost na ho to aage k pointers ko save karo
        Node *firstNext = first->next;
        Node *secondNext = second->next;

        first->next = second;
        second->next = firstNext;

        // pointers ko new values par daldo same operation k liye
        first = firstNext;
        second = secondNext;
    }
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

    reorderList(head);

    cout << "\nReordered List:\n";
    printList(head);

    return 0;
}