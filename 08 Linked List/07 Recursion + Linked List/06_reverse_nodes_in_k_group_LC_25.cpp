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

ListNode *reverseKGroup(ListNode *head, int k)
{
    if (head == nullptr || k <= 1)
    {
        return head;
    }

    // Check whether k nodes are available
    ListNode *temp = head;

    for (int i = 0; i < k; i++)
    {
        if (temp == nullptr)
        {
            return head;
        }

        temp = temp->next;
    }

    // Reverse current k nodes
    ListNode *prev = nullptr;
    ListNode *curr = head;

    for (int i = 0; i < k; i++)
    {
        ListNode *nextNode = curr->next;

        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }

    // head is now the tail of the reversed group
    head->next = reverseKGroup(curr, k);

    // prev is the new head of this group
    return prev;
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
    head->next->next->next->next->next = new ListNode(6);

    cout << "Before: ";
    printList(head);

    head = reverseKGroup(head, 3);

    cout << "After: ";
    printList(head);

    return 0;
}