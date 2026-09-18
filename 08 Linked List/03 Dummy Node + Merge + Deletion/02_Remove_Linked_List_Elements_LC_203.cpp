#include <iostream>
using namespace std;

struct ListNode
{
    int data;
    ListNode *next;

    ListNode(int value)
    {
        data = value;
        next = NULL;
    }
};

ListNode *removeElements(ListNode *head, int val)
{
    // Dummy node: head deletion ko normal deletion bana deta hai
    ListNode *dummy = new ListNode(0);
    dummy->next = head;

    // Current previous node ko represent karega
    ListNode *current = dummy;

    while (current->next != NULL)
    {
        // Agar next node target value hai
        if (current->next->data == val)
        {
            // Next node ko bypass karo
            current->next = current->next->next;
        }
        else
        {
            // Agar deletion nahi hui to current aage move karega
            current = current->next;
        }
    }

    ListNode *result = dummy->next;

    delete dummy;

    return result;
}

void printList(ListNode *head)
{
    while (head != NULL)
    {
        cout << head->data << " -> ";
        head = head->next;
    }

    cout << "NULL\n";
}

int main()
{
    // 1 -> 2 -> 6 -> 3 -> 4 -> 6 -> 5
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(6);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next = new ListNode(6);
    head->next->next->next->next->next->next = new ListNode(5);

    int val = 6;

    cout << "Original List:\n";
    printList(head);

    head = removeElements(head, val);

    cout << "\nAfter Removing " << val << ":\n";
    printList(head);

    return 0;
}

/*
Input:
1 -> 2 -> 6 -> 3 -> 4 -> 6 -> 5
val = 6

Output:
1 -> 2 -> 3 -> 4 -> 5

Debug:
- current = dummy
- 1 != 6 -> move
- 2 != 6 -> move
- 6 == 6 -> delete
- 3 != 6 -> move
- 4 != 6 -> move
- 6 == 6 -> delete
- 5 != 6 -> move

Time Complexity: O(n)
Space Complexity: O(1) auxiliary space
*/