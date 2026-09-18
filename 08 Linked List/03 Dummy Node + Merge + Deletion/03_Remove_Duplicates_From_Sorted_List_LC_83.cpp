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

Node *removeDuplicates(Node *head)
{
    Node *current = head;

    while (current != NULL && current->next != NULL)
    {
        // Agar current aur next ki value same hai,
        // to next node duplicate hai
        if (current->data == current->next->data)
        {
            // Duplicate node ko bypass karo
            current->next = current->next->next;
        }
        else
        {
            // Duplicate nahi mila, aage move karo
            current = current->next;
        }
    }

    return head;
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
    // 1 -> 1 -> 2 -> 3 -> 3 -> 3 -> 4
    Node *head = new Node(1);
    head->next = new Node(1);
    head->next->next = new Node(2);
    head->next->next->next = new Node(3);
    head->next->next->next->next = new Node(3);
    head->next->next->next->next->next = new Node(3);
    head->next->next->next->next->next->next = new Node(4);

    cout << "Original List:\n";
    printList(head);

    head = removeDuplicates(head);

    cout << "\nAfter Removing Duplicates:\n";
    printList(head);

    return 0;
}

/*
Input:
1 -> 1 -> 2 -> 3 -> 3 -> 3 -> 4

Output:
1 -> 2 -> 3 -> 4

Debug:
1 == 1 -> delete duplicate
1 != 2 -> move
2 != 3 -> move
3 == 3 -> delete duplicate
3 == 3 -> delete duplicate
3 != 4 -> move

Time Complexity: O(n)
Space Complexity: O(1) auxiliary space
*/