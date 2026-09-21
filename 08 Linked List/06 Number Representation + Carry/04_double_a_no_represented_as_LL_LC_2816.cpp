#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;

    ListNode(int x)
    {
        val = x;
        next = nullptr;
    }
};

ListNode *reverseList(ListNode *head)
{
    ListNode *prev = nullptr;
    ListNode *curr = head;

    while (curr != nullptr)
    {
        ListNode *nextNode = curr->next;

        curr->next = prev;

        prev = curr;
        curr = nextNode;
    }

    return prev;
}

ListNode *doubleIt(ListNode *head)
{
    if (head == nullptr)
    {
        return nullptr;
    }

    // Right-to-left processing ke liye list reverse kar rahe hain
    head = reverseList(head);

    int carry = 0;

    ListNode *curr = head;
    ListNode *prev = nullptr;

    while (curr != nullptr)
    {
        // Current digit ko 2 se multiply + previous carry
        int sum = curr->val * 2 + carry;

        // Current digit
        curr->val = sum % 10;

        // Next position ke liye carry
        carry = sum / 10;

        prev = curr;
        curr = curr->next;
    }

    // Agar last mein carry bacha haito ye new most-significant digit banega
    if (carry != 0)
    {
        prev->next = new ListNode(carry);
    }

    // Original direction restore
    head = reverseList(head);

    return head;
}

void printList(ListNode *head)
{
    while (head != nullptr)
    {
        cout << head->val;

        if (head->next != nullptr)
            cout << " -> ";

        head = head->next;
    }

    cout << endl;
}

int main()
{
    // 129
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(9);

    cout << "Original: ";
    printList(head);

    head = doubleIt(head);

    cout << "After doubling: ";
    printList(head);

    return 0;
}