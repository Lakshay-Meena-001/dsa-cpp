#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int value)
    {
        data = value;
        next = nullptr;
    }
};

// Returns the new head of the reversed list.
Node *reverseList(Node *head)
{
    Node *prev = nullptr;
    Node *curr = head;

    while (curr != nullptr)
    {
        Node *nextNode = curr->next;

        // Current node ko previous node se connect karo.
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }

    return prev;
}

bool isPalindrome(Node *head)
{
    // Empty list ya single node
    // automatically palindrome hoti hai.
    if (head == nullptr || head->next == nullptr)
    {
        return true;
    }

    Node *slow = head;
    Node *fast = head;

    // STEP 1: FIND MIDDLE

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Odd length mein slow middle node par hoga.
    // Middle ko comparison mein include karna
    // necessary nahi hai, isliye ek step skip.
    if (fast != nullptr)
    {
        slow = slow->next;
    }

    // STEP 2: REVERSE SECOND HALF

    Node *secondHalf = reverseList(slow);

    // STEP 3: COMPARE

    Node *firstHalf = head;
    Node *second = secondHalf;

    while (second != nullptr)
    {
        if (firstHalf->data != second->data)
        {
            return false;
        }

        firstHalf = firstHalf->next;
        second = second->next;
    }

    return true;
}

void printList(Node *head)
{
    while (head != nullptr)
    {
        cout << head->data << " -> ";
        head = head->next;
    }

    cout << "NULL\n";
}

int main()
{
    /*
        Palindrome:

        1 -> 2 -> 3 -> 2 -> 1
    */

    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(2);
    head->next->next->next->next = new Node(1);

    cout << "Linked List: ";
    printList(head);

    if (isPalindrome(head))
        cout << "Palindrome: Yes\n";
    else
        cout << "Palindrome: No\n";

    return 0;
}

/*
INPUT:

1 -> 2 -> 3 -> 2 -> 1


OUTPUT:

Palindrome: Yes


PATTERN:
Slow + Fast
+
Reverse Second Half
+
Two-Pointer Comparison


CORE IDEA:

Palindrome check ko 3 steps mein divide karo:

1. Middle find karo
2. Second half reverse karo
3. First half aur reversed second half compare karo


WHY SLOW + FAST?

Hume list ka middle/second-half starting point
find karna hai.

slow = 1 step
fast = 2 steps


ODD LENGTH:

1 -> 2 -> 3 -> 2 -> 1

slow initially middle (3) par aata hai.

fast != NULL hota hai,
which tells us list odd length ki hai.

Middle ko skip:

slow = slow->next

Then second half:

2 -> 1


EVEN LENGTH:

1 -> 2 -> 2 -> 1

slow second half ke start par hota hai.

fast == NULL.

So directly:
secondHalf = slow


SECOND HALF REVERSE:

2 -> 1

becomes:

1 -> 2


COMPARE:

First:
1 -> 2 -> 3

Second:
1 -> 2

Har corresponding value compare karo.

Mismatch mila:
return false

Otherwise:
return true


TIME COMPLEXITY:
O(n)

Middle finding = O(n)
Reversal = O(n)
Comparison = O(n)

Sequential operations:
O(n) + O(n) + O(n)
= O(n)


SPACE COMPLEXITY:
O(1)

No vector/array/hash set.

Only pointers use hue.


IMPORTANT:

Hum list ke nodes ko physically copy nahi kar rahe.

Second half ke links ko temporarily reverse kar rahe hain.

This is why extra space O(1) hai.


DEEP PATTERN:

Find boundary
    ↓
Transform one side
    ↓
Compare both sides

Ye pattern future linked-list problems mein
bahut useful hai.
*/