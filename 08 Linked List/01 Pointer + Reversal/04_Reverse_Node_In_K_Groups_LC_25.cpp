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

Node *reverseKGroup(Node *head, int k)
{
    // Check whether k nodes are available
    Node *temp = head;

    for (int i = 0; i < k; i++)
    {
        if (temp == nullptr)
        {
            return head;
        }

        temp = temp->next;
    }

    // Reverse first k nodes
    Node *prev = nullptr;
    Node *curr = head;

    for (int i = 0; i < k; i++)
    {
        Node *next = curr->next;

        curr->next = prev;
        prev = curr;
        curr = next;
    }

    // Recursively process remaining groups
    head->next = reverseKGroup(curr, k);

    return prev;
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
    // 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> NULL

    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);
    head->next->next->next->next->next->next = new Node(7);
    head->next->next->next->next->next->next->next = new Node(8);

    int k = 3;

    cout << "Original List:\n";
    printList(head);

    head = reverseKGroup(head, k);

    cout << "After Reversing in Groups of " << k << ":\n";
    printList(head);

    return 0;
}

/*
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;

    Node(int value)
    {
        data = value;
        next = nullptr;
    }
};

Node* reverseKGroup(Node* head, int k)
{
    if (head == nullptr || k <= 1)
        return head;

    Node* dummy = new Node(0);
    dummy->next = head;

    Node* groupPrev = dummy;

    while (true)
    {
        // Step 1: Check whether k nodes are available
        Node* kth = groupPrev;

        for (int i = 0; i < k; i++)
        {
            kth = kth->next;

            if (kth == nullptr)
                return dummy->next;
        }

        // Step 2: Save the node after the group
        Node* groupNext = kth->next;

        // Step 3: Reverse this group
        Node* prev = groupNext;
        Node* curr = groupPrev->next;

        while (curr != groupNext)
        {
            Node* next = curr->next;

            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // Step 4: Connect previous part to reversed group
        Node* oldGroupStart = groupPrev->next;

        groupPrev->next = kth;

        // Step 5: Move groupPrev to next group
        groupPrev = oldGroupStart;
    }
}

void printList(Node* head)
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
    // 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> NULL

    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);
    head->next->next->next->next->next->next = new Node(7);
    head->next->next->next->next->next->next->next = new Node(8);

    int k = 3;

    cout << "Original List:\n";
    printList(head);

    head = reverseKGroup(head, k);

    cout << "After Reversing in Groups of " << k << ":\n";
    printList(head);

    return 0;
}
*/