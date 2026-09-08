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

Node *reverseBetween(Node *head, int left, int right)
{
    if (head == nullptr || left == right)
    {
        return head;
    }

    // dummy isliye maan lo start hi first element se ho gaya uska prev dummy kaam ayga
    Node *dummy = new Node(0);
    dummy->next = head;

    //to sb dummy se start karo left-1 element tak traverse
    Node *prev = dummy;

    // left and right k beech ka reverse karna hai just left se ek pehle
    for (int i = 1; i < left; i++)
    {
        prev = prev->next;
    }

    Node *curr = prev->next;

    // Reverse the required portion
    for (int i = 0; i < right - left; i++)
    {
        Node *next = curr->next;

        // Remove next from its current position
        curr->next = next->next;

        // Insert next at the beginning of reversed portion
        next->next = prev->next;

        // Connect previous part with next
        prev->next = next;
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
    // Create:
    // 1 -> 2 -> 3 -> 4 -> 5 -> NULL

    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    int left = 2;
    int right = 4;

    cout << "Original List:\n";
    printList(head);

    head = reverseBetween(head, left, right);

    cout << "After Reversing Positions "
         << left << " to " << right << ":\n";

    printList(head);

    return 0;
}