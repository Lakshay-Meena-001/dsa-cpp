#include <iostream>
#include <unordered_set>

using namespace std;

struct Node
{
    int data;
    Node* next;

    Node(int value)
    {
        data = value;
        next = NULL;
    }
};

Node* removeDuplicates(Node* head)
{
    unordered_set<int> s;

    Node* current = head;
    Node* previous = NULL;

    while (current != NULL)
    {
        // Agar value pehle aa chuki hai
        if (s.find(current->data) != s.end())
        {
            // Current node ko skip/delete karo
            previous->next = current->next;

            Node* nodeToDelete = current;
            current = current->next;

            delete nodeToDelete;
        }
        else
        {
            // First occurrence hai, retain karo
            s.insert(current->data);

            previous = current;
            current = current->next;
        }
    }

    return head;
}

void printList(Node* head)
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
    // 3 -> 1 -> 2 -> 3 -> 4 -> 1
    Node* head = new Node(3);
    head->next = new Node(1);
    head->next->next = new Node(2);
    head->next->next->next = new Node(3);
    head->next->next->next->next = new Node(4);
    head->next->next->next->next->next = new Node(1);

    cout << "Original List:\n";
    printList(head);

    head = removeDuplicates(head);

    cout << "\nAfter Removing Duplicates:\n";
    printList(head);

    return 0;
}

/*
Input:
3 -> 1 -> 2 -> 3 -> 4 -> 1

Output:
3 -> 1 -> 2 -> 4

Debug:
3 -> new value -> keep
1 -> new value -> keep
2 -> new value -> keep
3 -> already s -> delete
4 -> new value -> keep
1 -> already s -> delete

Time Complexity: O(n) average
Space Complexity: O(n)
*/