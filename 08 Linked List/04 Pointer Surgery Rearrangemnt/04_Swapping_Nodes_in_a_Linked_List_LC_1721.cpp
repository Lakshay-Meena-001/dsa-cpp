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

Node *swapKthNodes(Node *head, int k)
{
    if (head == nullptr)
    {
        return head;
    }

    // STEP 1: Find kth node from start

    Node *firstK = head;

    //first k already first node par hai and isliye ek less step 
    for (int i = 1; i < k; i++)
    {
        firstK = firstK->next;
    }

    // STEP 2: Find kth node from end

    Node *slow = head;
    Node *fast = head;

    // Create a gap of k nodes
    for (int i = 0; i < k; i++)
    {
        fast = fast->next;
    }

    // Move both together
    while (fast != nullptr)
    {
        slow = slow->next;
        fast = fast->next;
    }

    Node *lastK = slow;

    // STEP 3: Swap values

    swap(firstK->data, lastK->data);

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

    int k = 2;

    head = swapKthNodes(head, k);

    cout << "\nAfter Swapping kth Nodes:\n";
    printList(head);

    return 0;
}