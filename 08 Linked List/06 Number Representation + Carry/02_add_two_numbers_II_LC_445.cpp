#include <iostream>
#include <stack>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;

    ListNode(int value)
    {
        val = value;
        next = nullptr;
    }
};
// reverse list 2 using revere input lists
ListNode *reverseList(ListNode *head)
{
    ListNode *prev = nullptr;
    ListNode *curr = head;

    while (curr != nullptr)
    {
        ListNode *next = curr->next;

        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

ListNode *addTwoNumbersReverse(ListNode *l1, ListNode *l2)
{
    // Reverse input lists
    l1 = reverseList(l1);
    l2 = reverseList(l2);

    ListNode *dummy = new ListNode(0);
    ListNode *temp = dummy;

    int carry = 0;

    while (l1 != nullptr || l2 != nullptr || carry != 0)
    {
        int x = (l1 != nullptr) ? l1->val : 0;
        int y = (l2 != nullptr) ? l2->val : 0;

        int sum = x + y + carry;

        temp->next = new ListNode(sum % 10);
        temp = temp->next;

        carry = sum / 10;

        if (l1 != nullptr)
            l1 = l1->next;

        if (l2 != nullptr)
            l2 = l2->next;
    }

    // Reverse result back
    ListNode *result = reverseList(dummy->next);

    delete dummy;

    // NOTE:
    // Input lists were modified by reversing them.
    return result;
}

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    stack<int> s1;
    stack<int> s2;

    // Put digits into stacks
    while (l1 != nullptr)
    {
        s1.push(l1->val);
        l1 = l1->next;
    }

    while (l2 != nullptr)
    {
        s2.push(l2->val);
        l2 = l2->next;
    }

    int carry = 0;
    ListNode *result = nullptr;

    while (!s1.empty() || !s2.empty() || carry != 0)
    {
        int x = 0;
        int y = 0;

        if (!s1.empty())
        {
            x = s1.top();
            s1.pop();
        }

        if (!s2.empty())
        {
            y = s2.top();
            s2.pop();
        }

        int sum = x + y + carry;

        int digit = sum % 10;
        carry = sum / 10;

        // Insert at front
        ListNode *newNode = new ListNode(digit);

        // hum new nod eko fromt par jod rahe hai
        // default(result)
        // newNode--oldNode0(result)
        // newNode(result)--oldNode0
        // newNode(result)--oldNode1--oldNode0

        newNode->next = result;
        result = newNode;
    }

    return result;
}

void printList(ListNode *head)
{
    while (head != nullptr)
    {
        cout << head->val;

        if (head->next != nullptr)
        {
            cout << " -> ";
        }

        head = head->next;
    }

    cout << " -> NULL\n";
}

int main()
{
    ListNode *l1 = new ListNode(7);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(4);
    l1->next->next->next = new ListNode(3);

    ListNode *l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    ListNode *result = addTwoNumbers(l1, l2);

    cout << "Result: ";
    printList(result);

    return 0;
}