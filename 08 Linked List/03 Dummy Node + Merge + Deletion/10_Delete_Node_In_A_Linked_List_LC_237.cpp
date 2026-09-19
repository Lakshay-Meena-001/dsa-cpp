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

// Delete the given node.
// Constraint: node is guaranteed NOT to be the tail.
void deleteNode(ListNode *node)
{
    if (node == nullptr || node->next == nullptr)
    {
        return;
    }

    // Copy next node's value into current node
    node->val = node->next->val;

    // Skip the next node
    node->next = node->next->next;
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
    // 4 -> 5 -> 1 -> 9
    ListNode *head = new ListNode(4);
    head->next = new ListNode(5);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(9);

    cout << "Before deletion: ";
    printList(head);

    // We are given pointer to node 5
    ListNode *nodeToDelete = head->next;

    deleteNode(nodeToDelete);

    cout << "After deletion:  ";
    printList(head);

    return 0;
}

/*
Input:
4 -> 5 -> 1 -> 9
Given node = 5

Output:
4 -> 1 -> 9

Debug:
node = 5
node->next = 1

Step 1:
node->val = node->next->val

5 becomes 1

4 -> 1 -> 1 -> 9

Step 2:
node->next = node->next->next

4 -> 1 -> 9

Time Complexity: O(1)
Space Complexity: O(1)

Important:
The given node must NOT be the tail because
a tail node has no next node to copy from.
*/