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

Node *sort012(Node *head)
{
    // Dummy nodes for three separate chains
    Node *zeroDummy = new Node(-1);
    Node *oneDummy = new Node(-1);
    Node *twoDummy = new Node(-1);

    Node *zero = zeroDummy;
    Node *one = oneDummy;
    Node *two = twoDummy;

    while (head != nullptr)
    {
        // Save next node before changing current node's link
        Node *nextNode = head->next;

        // Detach current node
        head->next = nullptr;

        if (head->data == 0)
        {
            zero->next = head;
            zero = zero->next;
        }
        else if (head->data == 1)
        {
            one->next = head;
            one = one->next;
        }
        else
        {
            two->next = head;
            two = two->next;
        }

        head = nextNode;
    }

    // Connect 0-chain → 1-chain
    zero->next = oneDummy->next;

    // Connect 1-chain → 2-chain
    one->next = twoDummy->next;

    // Real head
    Node *newHead = zeroDummy->next;

    // Dummy nodes no longer needed
    delete zeroDummy;
    delete oneDummy;
    delete twoDummy;

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
    Node *head = new Node(2);
    head->next = new Node(1);
    head->next->next = new Node(0);
    head->next->next->next = new Node(2);
    head->next->next->next->next = new Node(1);
    head->next->next->next->next->next = new Node(0);

    cout << "Before: ";
    printList(head);

    head = sort012(head);

    cout << "After:  ";
    printList(head);

    return 0;
}