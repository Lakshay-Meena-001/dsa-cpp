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

Node *swapPairs(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    Node *dummy = new Node(0);
    dummy->next = head;

    Node *prev = dummy;

    while (prev->next != nullptr && prev->next->next != nullptr)
    {
        Node *first = prev->next;
        Node *second = first->next;

        // 1. Previous node ko second se connect karo
        prev->next = second;

        // 2. First node ko remaining list se connect karo
        first->next = second->next;

        // 3. Second node ko first se connect karo
        second->next = first;

        // Next pair ke just pehle aa jao
        prev = first;
    }

    return dummy->next;
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

    cout << "Original List:\n";
    printList(head);

    head = swapPairs(head);

    cout << "After Swapping Pairs:\n";
    printList(head);

    return 0;
}