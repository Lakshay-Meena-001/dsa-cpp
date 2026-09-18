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

ListNode *removeDuplicates(ListNode *head)
{
    ListNode *current = head;

    while (current != NULL && current->next != NULL)
    {
        // Agar current aur next ki value same hai,
        // to next node duplicate hai
        if (current->data == current->next->data)
        {
            // Duplicate node ko bypass karo
            current->next = current->next->next;
        }
        else
        {
            // Duplicate nahi mila, aage move karo
            current = current->next;
        }
    }

    return head;
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
    // 1 -> 1 -> 2 -> 3 -> 3 -> 3 -> 4
    ListNode *head = new ListNode(1);
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(3);
    head->next->next->next->next->next = new ListNode(3);
    head->next->next->next->next->next->next = new ListNode(4);

    cout << "Original List:\n";
    printList(head);

    head = removeDuplicates(head);

    cout << "\nAfter Removing Duplicates:\n";
    printList(head);

    return 0;
}

/*
Input:
1 -> 1 -> 2 -> 3 -> 3 -> 3 -> 4

Output:
1 -> 2 -> 3 -> 4

Debug:
1 == 1 -> delete duplicate
1 != 2 -> move
2 != 3 -> move
3 == 3 -> delete duplicate
3 == 3 -> delete duplicate
3 != 4 -> move

Time Complexity: O(n)
Space Complexity: O(1) auxiliary space
*/