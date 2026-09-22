#include <iostream>
using namespace std;

struct ListNode
{
    int data;
    ListNode *next;

    ListNode(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

ListNode *reverseRecursive(ListNode *head)
{
    // Base case
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    // Reverse the remaining list
    ListNode *newHead = reverseRecursive(head->next);

    // Put current node after its next node
    head->next->next = head;

    // Break old forward link
    head->next = nullptr;

    return newHead;
}

void printList(ListNode *head)
{
    while (head != nullptr)
    {
        cout << head->data << " ";
        head = head->next;
    }

    cout << endl;
}

int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "Before: ";
    printList(head);

    head = reverseRecursive(head);

    cout << "After: ";
    printList(head);

    return 0;
}

/*
GOING DOWN
────────────────────────

1 → 2 → 3 → 4 → 5
↑
recursive calls


RETURNING UP
────────────────────────

5 → 4
    ↓
5 → 4 → 3
        ↓
5 → 4 → 3 → 2
            ↓
5 → 4 → 3 → 2 → 1
*/