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

// Merge two sorted linked lists
ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
{
    // Dummy node: final list ka fake starting point
    ListNode *dummy = new ListNode(0);

    // Tail final merged list ke last node ko track karega
    ListNode *tail = dummy;

    while (l1 != NULL && l2 != NULL)
    {
        // Jo node chhota hai usko attach karo
        if (l1->data <= l2->data)
        {
            tail->next = l1;
            l1 = l1->next;
        }
        else
        {
            tail->next = l2;
            l2 = l2->next;
        }

        // Tail ko newly attached node par move karo
        tail = tail->next;
    }

    // Ek list mein nodes bach gaye hain
    // Remaining part already sorted hai
    if (l1 != NULL)
    {
        tail->next = l1;
    }
    else
    {
        tail->next = l2;
    }

    // Dummy ke baad actual answer hai
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
    // List 1: 1 -> 3 -> 5
    ListNode *l1 = new ListNode(1);
    l1->next = new ListNode(3);
    l1->next->next = new ListNode(5);

    // List 2: 2 -> 4 -> 6
    ListNode *l2 = new ListNode(2);
    l2->next = new ListNode(4);
    l2->next->next = new ListNode(6);

    ListNode *merged = mergeTwoLists(l1, l2);

    cout << "Merged List:\n";
    printList(merged);

    return 0;
}

/*
Input:
List 1 = 1 -> 3 -> 5
List 2 = 2 -> 4 -> 6

Output:
1 -> 2 -> 3 -> 4 -> 5 -> 6

Debug:
1 vs 2  -> take 1
3 vs 2  -> take 2
3 vs 4  -> take 3
5 vs 4  -> take 4
5 vs 6  -> take 5
List 1 ends -> attach remaining 6

Time Complexity: O(n + m)
Space Complexity: O(1) auxiliary space
*/