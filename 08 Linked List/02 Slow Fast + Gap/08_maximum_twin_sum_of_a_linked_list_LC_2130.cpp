#include <iostream>
#include <algorithm>
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

// Reverse a linked list and return new head
Node *reverseList(Node *head)
{
    Node *prev = nullptr;
    Node *curr = head;

    while (curr != nullptr)
    {
        Node *nextNode = curr->next;

        // Direction reverse kar rahe hain
        curr->next = prev;

        prev = curr;
        curr = nextNode;
    }

    return prev;
}

int maximumTwinSum(Node *head)
{
    // STEP 1: Find middle using Slow/Fast pointers

    Node *slow = head;
    Node *fast = head;

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node *secondHalf = reverseList(slow);

    // First half head se start karega
    Node *firstHalf = head;

    // STEP 3: Calculate twin sums

    int maxSum = 0;

    while (secondHalf != nullptr)
    {
        int twinSum = firstHalf->data + secondHalf->data;

        maxSum = max(maxSum, twinSum);

        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }

    return maxSum;
}

void printList(Node *head)
{
    while (head != nullptr)
    {
        cout << head->data;

        if (head->next != nullptr)
            cout << " -> ";

        head = head->next;
    }

    cout << endl;
}

int main()
{
    // Example:
    // 4 -> 2 -> 2 -> 3
    Node *head = new Node(4);
    head->next = new Node(2);
    head->next->next = new Node(2);
    head->next->next->next = new Node(3);

    cout << "Input: ";
    printList(head);

    int answer = maximumTwinSum(head);

    cout << "Maximum Twin Sum: " << answer << endl;

    return 0;
}

/*
INPUT:
4 -> 2 -> 2 -> 3

Twin pairs:
4 + 3 = 7
2 + 2 = 4

OUTPUT:
Maximum Twin Sum: 7

DEBUG:
1. Slow/Fast se middle find kiya.
2. Second half ko reverse kiya.
3. First half aur reversed second half ko parallel traverse kiya.
4. Har pair ka sum nikala.
5. Maximum sum maintain kiya.

PATTERN:
Slow/Fast
    ↓
Middle
    ↓
Reverse Second Half
    ↓
Parallel Traversal
    ↓
Twin Pair Calculation

TIME COMPLEXITY:
O(n)

SPACE COMPLEXITY:
O(1) extra space

IMPORTANT:
LC 2130 mein number of nodes even hota hai,
isliye list naturally equal two halves mein divide hoti hai.
*/