#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

Node *insertRecursive(Node *head, int pos, int value)
{
    // Base case remember ki recursion m LL ki indexing 0 se start hoti hai 
    if (pos == 0)
    {
        Node *newNode = new Node(value);
        newNode->next = head;
        return newNode;
    }

    // Invalid position
    if (head == nullptr)
    {
        return head;
    }

    // Recursive case
    head->next = insertRecursive(head->next, pos - 1, value);

    return head;
}

void printList(Node *head)
{
    while (head != nullptr)
    {
        cout << head->data << " ";
        head = head->next;
    }

    cout << endl;
}

int main()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);

    cout << "Before: ";
    printList(head);

    head = insertRecursive(head, 2, 25);

    cout << "After: ";
    printList(head);

    return 0;
}