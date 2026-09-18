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

ListNode *deleteDuplicates(ListNode *head)
{
    // Dummy node head duplicate case ko bhi handle karega
    ListNode *dummy = new ListNode(0);
    dummy->next = head;

    // Current = duplicate group se pehle wala node
    ListNode *current = dummy;

    while (current->next != NULL && current->next->next != NULL)
    {
        // Duplicate group mila
        if (current->next->data == current->next->next->data)
        {
            int duplicateValue = current->next->data;

            // Runner duplicate group ke end tak jayega
            ListNode *runner = current->next;

            while (runner != NULL && runner->data == duplicateValue)
            {
                runner = runner->next;
            }

            // Entire duplicate group ko skip karo
            current->next = runner;
        }
        else
        {
            // Current node unique hai
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
    // 1 -> 2 -> 3 -> 3 -> 4 -> 4 -> 5
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next->next = new ListNode(5);

    cout << "Original List:\n";
    printList(head);

    head = deleteDuplicates(head);

    cout << "\nAfter Removing All Duplicates:\n";
    printList(head);

    return 0;
}

/*
Input:
1 -> 2 -> 3 -> 3 -> 4 -> 4 -> 5

Output:
1 -> 2 -> 5

Debug:
1 -> unique, move current
2 -> unique, move current
3 -> duplicate group found, remove all 3s
4 -> duplicate group found, remove all 4s
5 -> unique

Time Complexity: O(n)
Space Complexity: O(1) auxiliary space
*/