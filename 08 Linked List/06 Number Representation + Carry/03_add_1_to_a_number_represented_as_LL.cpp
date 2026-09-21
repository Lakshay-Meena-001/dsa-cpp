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
        ListNode *next = curr->next;

        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

// Approach 1: Reverse -> Add 1 -> Reverse back
ListNode *addOneReverse(ListNode *head)
{
    // Pehle list ko reverse kar diya taaki rightmost digit pehle mile
    head = reverseList(head);

    ListNode *curr = head;
    int carry = 1;

    while (curr != nullptr && carry != 0)
    {
        int sum = curr->val + carry;

        // Current digit store karo
        curr->val = sum % 10;

        // Next position ke liye carry
        carry = sum / 10;

        // Agar carry abhi bhi hai aur last node aa gayi hai
        // to extra node banani padegi
        if (carry != 0 && curr->next == nullptr)
        {
            curr->next = new ListNode(0);
        }

        curr = curr->next;
    }

    // Original order wapas lao
    head = reverseList(head);

    return head;
}

// Recursive function carry return karta hai
int addOneRecursiveHelper(ListNode *node)
{
    // List ke end tak pahunch gaye
    // Yahin se 1 carry ke form mein wapas jayega
    if (node == nullptr)
        return 1;

    // Pehle rightmost digit process hogi
    int carry = addOneRecursiveHelper(node->next);

    int sum = node->val + carry;

    // Current digit update karo
    node->val = sum % 10;

    // Agar sum 10 ya usse zyada hai to carry 1 hoga
    return sum / 10;
}

// Approach 2: Recursion
ListNode *addOneRecursive(ListNode *head)
{
    int carry = addOneRecursiveHelper(head);

    // Agar final carry bacha hai
    // jaise 999 + 1 = 1000
    if (carry != 0)
    {
        ListNode *newHead = new ListNode(carry);
        newHead->next = head;
        head = newHead;
    }

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

    cout << " -> NULL\n";
}

int main()
{
    ListNode *head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(9);

    cout << "Original: ";
    printList(head1);

    ListNode *result1 = addOneReverse(head1);

    cout << "Reverse Approach: ";
    printList(result1);

    ListNode *head2 = new ListNode(9);
    head2->next = new ListNode(9);
    head2->next->next = new ListNode(9);

    cout << "Original: ";
    printList(head2);

    ListNode *result2 = addOneRecursive(head2);

    cout << "Recursive Approach: ";
    printList(result2);

    return 0;
}

/*
Input 1:
1 -> 2 -> 9

129 + 1 = 130

Output:
1 -> 3 -> 0 -> NULL

Input 2:
9 -> 9 -> 9

999 + 1 = 1000

Output:
1 -> 0 -> 0 -> 0 -> NULL

Approach 1:
Reverse -> Add 1 -> Reverse

Time Complexity: O(n)
Auxiliary Space: O(1)

Approach 2:
Recursion

Time Complexity: O(n)
Auxiliary Space: O(n) because of recursion call stack

Important:
Carry rightmost digit se left ki taraf propagate hota hai.
*/