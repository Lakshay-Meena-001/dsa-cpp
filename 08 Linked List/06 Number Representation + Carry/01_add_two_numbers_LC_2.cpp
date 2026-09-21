#include <iostream>
using namespace std;

struct ListNode
{
    int data;
    ListNode *next;

    ListNode(int value)
    {
        data = value;
        next = nullptr;
    }
};

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode dummy(0);
    ListNode *tail = &dummy;

    int carry = 0;

    // jabtak inme se koi end nahi hota
    while (l1 != nullptr || l2 != nullptr || carry != 0)
    {
        int x = (l1 != nullptr) ? l1->data : 0;
        int y = (l2 != nullptr) ? l2->data : 0;

        int sum = x + y + carry;

        int digit = sum % 10;
        carry = sum / 10;

        tail->next = new ListNode(digit);
        tail = tail->next;

        if (l1 != nullptr)
        {
            l1 = l1->next;
        }

        if (l2 != nullptr)
        {
            l2 = l2->next;
        }
    }

    return dummy.next;
}

void printList(ListNode *head)
{
    while (head != nullptr)
    {
        cout << head->data;

        if (head->next != nullptr)
            cout << " -> ";

        head = head->next;
    }

    cout << " -> NULL\n";
}

int main()
{
    ListNode *l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    ListNode *l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    ListNode *result = addTwoNumbers(l1, l2);

    cout << "Result: ";
    printList(result);

    return 0;
}

/*
Input:
l1 = 2 -> 4 -> 3
l2 = 5 -> 6 -> 4

Numbers:
342 + 465 = 807

Output:
7 -> 0 -> 8 -> NULL

Pattern:
Linked List as Number + Carry Simulation

Time Complexity:
O(max(n, m))

Space Complexity:
O(max(n, m)) for the result list.
Extra auxiliary space = O(1).

Key idea:
sum = digit1 + digit2 + carry
digit = sum % 10
carry = sum / 10
*/