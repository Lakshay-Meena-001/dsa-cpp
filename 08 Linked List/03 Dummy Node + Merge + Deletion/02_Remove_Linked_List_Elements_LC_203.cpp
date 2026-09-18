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

Node *removeElements(Node *head, int val)
{
    // Dummy node: head deletion ko normal deletion bana deta hai
    Node *dummy = new Node(0);
    dummy->next = head;

    // Current previous node ko represent karega
    Node *current = dummy;

    while (current->next != NULL)
    {
        // Agar next node target value hai
        if (current->next->data == val)
        {
            // Next node ko bypass karo
            current->next = current->next->next;
        }
        else
        {
            // Agar deletion nahi hui to current aage move karega
            current = current->next;
        }
    }

    Node *result = dummy->next;

    delete dummy;

    return result;
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
    // 1 -> 2 -> 6 -> 3 -> 4 -> 6 -> 5
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(6);
    head->next->next->next = new Node(3);
    head->next->next->next->next = new Node(4);
    head->next->next->next->next->next = new Node(6);
    head->next->next->next->next->next->next = new Node(5);

    int val = 6;

    cout << "Original List:\n";
    printList(head);

    head = removeElements(head, val);

    cout << "\nAfter Removing " << val << ":\n";
    printList(head);

    return 0;
}

/*
Input:
1 -> 2 -> 6 -> 3 -> 4 -> 6 -> 5
val = 6

Output:
1 -> 2 -> 3 -> 4 -> 5

Debug:
- current = dummy
- 1 != 6 -> move
- 2 != 6 -> move
- 6 == 6 -> delete
- 3 != 6 -> move
- 4 != 6 -> move
- 6 == 6 -> delete
- 5 != 6 -> move

Time Complexity: O(n)
Space Complexity: O(1) auxiliary space
*/