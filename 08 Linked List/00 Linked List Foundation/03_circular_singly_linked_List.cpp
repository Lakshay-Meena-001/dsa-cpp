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

// TRAVERSAL

void printList(Node *head)
{
    if (head == nullptr)
    {
        cout << "Empty\n";
        return;
    }

    Node *temp = head;

    do
    {
        cout << temp->data << " ";
        temp = temp->next;

    } while (temp != head);

    cout << '\n';
}

// LENGTH

int length(Node *head)
{
    if (head == nullptr)
    {
        return 0;
    }

    int count = 0;

    Node *temp = head;

    do
    {
        count++;
        temp = temp->next;

    } while (temp != head);

    return count;
}

// SEARCH

bool search(Node *head, int target)
{
    if (head == nullptr)
    {
        return false;
    }

    Node *temp = head;

    do
    {
        if (temp->data == target)
        {
            return true;
        }

        temp = temp->next;

    } while (temp != head);

    return false;
}

// INSERT AT HEAD

void insertAtHead(Node *&head, Node *&tail, int value)
{
    Node *newNode = new Node(value);

    // Empty list
    if (head == nullptr)
    {
        head = tail = newNode;
        newNode->next = head;
        return;
    }

    newNode->next = head;
    tail->next = newNode;
    head = newNode;
}

// INSERT AT TAIL

void insertAtTail(Node *&head, Node *&tail, int value)
{
    Node *newNode = new Node(value);

    // Empty list
    if (head == nullptr)
    {
        head = tail = newNode;
        newNode->next = head;
        return;
    }

    newNode->next = head;
    tail->next = newNode;
    tail = newNode;
}

// INSERT AT POSITION
// 0-based indexing

void insertAtPosition(
    Node *&head,
    Node *&tail,
    int value,
    int pos)
{
    if (pos < 0)
    {
        return;
    }

    if (pos == 0)
    {
        insertAtHead(head, tail, value);
        return;
    }

    Node *temp = head;

    // Find node at position pos - 1
    for (int i = 0; i < pos - 1 && temp != nullptr; i++)
    {
        temp = temp->next;

        // Prevent infinite traversal
        if (temp == head)
        {
            break;
        }
    }

    if (temp == nullptr)
    {
        return;
    }

    // If position is after current tail
    if (temp == tail)
    {
        insertAtTail(head, tail, value);
        return;
    }

    Node *newNode = new Node(value);

    newNode->next = temp->next;
    temp->next = newNode;
}

// DELETE HEAD

void deleteHead(Node *&head, Node *&tail)
{
    if (head == nullptr)
    {
        return;
    }

    // Single node
    if (head == tail)
    {
        delete head;

        head = nullptr;
        tail = nullptr;

        return;
    }

    Node *nodeToDelete = head;

    head = head->next;

    tail->next = head;

    delete nodeToDelete;
}

// DELETE TAIL

void deleteTail(Node *&head, Node *&tail)
{
    if (head == nullptr)
    {
        return;
    }

    // Single node
    if (head == tail)
    {
        delete tail;

        head = nullptr;
        tail = nullptr;

        return;
    }

    Node *temp = head;

    // Find node before tail
    while (temp->next != tail)
    {
        temp = temp->next;
    }

    Node *nodeToDelete = tail;

    temp->next = head;
    tail = temp;

    delete nodeToDelete;
}

// DELETE AT POSITION
// 0-based indexing

void deleteAtPosition(
    Node *&head,
    Node *&tail,
    int pos)
{
    if (head == nullptr || pos < 0)
    {
        return;
    }

    if (pos == 0)
    {
        deleteHead(head, tail);
        return;
    }

    Node *temp = head;

    // Find predecessor
    for (int i = 0; i < pos - 1; i++)
    {
        temp = temp->next;

        if (temp == head)
        {
            return;
        }
    }

    Node *nodeToDelete = temp->next;

    // Position does not exist
    if (nodeToDelete == head)
    {
        return;
    }

    // If deleting tail
    if (nodeToDelete == tail)
    {
        deleteTail(head, tail);
        return;
    }

    temp->next = nodeToDelete->next;

    delete nodeToDelete;
}

// UPDATE

void updateValue(
    Node *head,
    int oldValue,
    int newValue)
{
    if (head == nullptr)
    {
        return;
    }

    Node *temp = head;

    do
    {
        if (temp->data == oldValue)
        {
            temp->data = newValue;
            return;
        }

        temp = temp->next;

    } while (temp != head);
}

// DESTROY

void destroyList(Node *&head, Node *&tail)
{
    if (head == nullptr)
    {
        return;
    }

    Node *current = head;

    while (current != tail)
    {
        Node *nextNode = current->next;

        delete current;

        current = nextNode;
    }

    // Delete final node
    delete tail;

    head = nullptr;
    tail = nullptr;
}

// MAIN

int main()
{
    Node *head = nullptr;
    Node *tail = nullptr;

    // INSERT

    insertAtHead(head, tail, 20);
    insertAtHead(head, tail, 10);

    insertAtTail(head, tail, 30);
    insertAtTail(head, tail, 40);

    cout << "List: ";
    printList(head);

    // LENGTH

    cout << "Length: "
         << length(head)
         << '\n';

    // SEARCH

    cout << "Search 30: "
         << (search(head, 30) ? "Found" : "Not Found")
         << '\n';

    cout << "Search 50: "
         << (search(head, 50) ? "Found" : "Not Found")
         << '\n';

    // INSERT POSITION

    insertAtPosition(head, tail, 25, 2);

    cout << "After inserting 25 at position 2: ";
    printList(head);

    // UPDATE

    updateValue(head, 25, 27);

    cout << "After updating 25 -> 27: ";
    printList(head);

    // DELETE HEAD

    deleteHead(head, tail);

    cout << "After deleting head: ";
    printList(head);

    // DELETE TAIL

    deleteTail(head, tail);

    cout << "After deleting tail: ";
    printList(head);

    // DELETE POSITION

    deleteAtPosition(head, tail, 1);

    cout << "After deleting position 1: ";
    printList(head);

    // DESTROY

    destroyList(head, tail);

    cout << "After destroying list: ";
    printList(head);

    return 0;
}