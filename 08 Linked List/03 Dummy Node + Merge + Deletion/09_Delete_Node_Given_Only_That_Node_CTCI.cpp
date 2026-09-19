#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int value)
    {
        data = value;
        next = NULL;
    }
};

// Sirf given node ke pointer se deletion
// Assumption: node last node nahi hai
void deleteNode(Node *node)
{
    if (node == NULL || node->next == NULL)
    {
        return;
    }

    // Next node ka data current node mein copy karo
    node->data = node->next->data;

    // Next node ko bypass karo
    node->next = node->next->next;
}

void printList(Node *head)
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
    // 1 -> 2 -> 3 -> 4 -> 5

    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    // Sirf target node ka pointer hai
    Node *nodeToDelete = head->next->next; // Node 3

    cout << "Original List:\n";
    printList(head);

    deleteNode(nodeToDelete);

    cout << "\nAfter Deleting Node 3:\n";
    printList(head);

    return 0;
}

/*
Input:
1 -> 2 -> 3 -> 4 -> 5

Target:
Node containing 3

Output:
1 -> 2 -> 4 -> 5

Logic:
3 ka data = next node 4 ka data
3 -> 4
becomes
4 -> 4

Then:
current->next = current->next->next

Final:
1 -> 2 -> 4 -> 5

Time Complexity: O(1)
Space Complexity: O(1)
*/