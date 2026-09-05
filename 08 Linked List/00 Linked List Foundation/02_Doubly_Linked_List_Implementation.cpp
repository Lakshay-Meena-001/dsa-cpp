#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;

    Node(int value)
    {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};

// FORWARD TRAVERSAL

void printForward(Node *head)
{
    Node *temp = head;

    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << '\n';
}

// BACKWARD TRAVERSAL

void printBackward(Node *tail)
{
    Node *temp = tail;

    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->prev;
    }

    cout << '\n';
}

// LENGTH

int length(Node *head)
{
    int count = 0;

    Node *temp = head;

    while (temp != nullptr)
    {
        count++;
        temp = temp->next;
    }

    return count;
}

// SEARCH

bool search(Node *head, int target)
{
    Node *temp = head;

    while (temp != nullptr)
    {
        if (temp->data == target)
        {
            return true;
        }

        temp = temp->next;
    }

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
        return;
    }

    // New node points forward to old head
    newNode->next = head;

    // Old head points backward to new node
    head->prev = newNode;

    // Move head
    head = newNode;
}

// INSERT AT TAIL

void insertAtTail(Node *&head, Node *&tail, int value)
{
    Node *newNode = new Node(value);

    // Empty list
    if (tail == nullptr)
    {
        head = tail = newNode;
        return;
    }

    // New node points backward to old tail
    newNode->prev = tail;

    // Old tail points forward to new node
    tail->next = newNode;

    // Move tail
    tail = newNode;
}

// INSERT AT POSITION
// 0-based indexing

void insertAtPosition(Node *&head, Node *&tail, int value, int pos)
{
    if (pos < 0)
    {
        return;
    }

    // Position 0 = insert at head
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
    }

    // Position is out of range
    if (temp == nullptr)
    {
        return;
    }

    // If temp is current tail,
    // insertion happens at tail
    if (temp == tail)
    {
        insertAtTail(head, tail, value);
        return;
    }

    Node *newNode = new Node(value);

    Node *nextNode = temp->next;

    // Connect new node with both neighbours
    newNode->prev = temp;
    newNode->next = nextNode;

    // Connect previous node to new node
    temp->next = newNode;

    // Connect next node back to new node
    nextNode->prev = newNode;
}

// DELETE HEAD

void deleteHead(Node *&head, Node *&tail)
{
    // Empty list
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

    // Move head
    head = head->next;

    // New head has no previous node
    head->prev = nullptr;

    // Delete old head
    delete nodeToDelete;
}

// DELETE TAIL

void deleteTail(Node *&head, Node *&tail)
{
    // Empty list
    if (tail == nullptr)
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

    Node *nodeToDelete = tail;

    // Move tail backward
    tail = tail->prev;

    // New tail has no next node
    tail->next = nullptr;

    // Delete old tail
    delete nodeToDelete;
}

// DELETE AT POSITION
// 0-based indexing

void deleteAtPosition(Node *&head, Node *&tail, int pos)
{
    if (head == nullptr || pos < 0)
    {
        return;
    }

    // Position 0 = delete head
    if (pos == 0)
    {
        deleteHead(head, tail);
        return;
    }

    Node *temp = head;

    // Find target node
    for (int i = 0; i < pos && temp != nullptr; i++)
    {
        temp = temp->next;
    }

    // Position out of range
    if (temp == nullptr)
    {
        return;
    }

    // Target is tail
    if (temp == tail)
    {
        deleteTail(head, tail);
        return;
    }

    // Middle node
    Node *prevNode = temp->prev;
    Node *nextNode = temp->next;

    // Bypass target in forward direction
    prevNode->next = nextNode;

    // Bypass target in backward direction
    nextNode->prev = prevNode;

    // Delete target
    delete temp;
}

// UPDATE FIRST OCCURRENCE

void updateValue(Node *head, int oldValue, int newValue)
{
    Node *temp = head;

    while (temp != nullptr)
    {
        if (temp->data == oldValue)
        {
            temp->data = newValue;
            return;
        }

        temp = temp->next;
    }
}

// DELETE A KNOWN NODE

void deleteNode(Node *&head, Node *&tail, Node *target)
{
    if (target == nullptr)
    {
        return;
    }

    // Target is head
    if (target == head)
    {
        deleteHead(head, tail);
        return;
    }

    // Target is tail
    if (target == tail)
    {
        deleteTail(head, tail);
        return;
    }

    // Target is a middle node
    Node *prevNode = target->prev;
    Node *nextNode = target->next;

    prevNode->next = nextNode;
    nextNode->prev = prevNode;

    delete target;
}

// DESTROY ENTIRE LIST

void destroyList(Node *&head, Node *&tail)
{
    while (head != nullptr)
    {
        Node *temp = head;

        head = head->next;

        delete temp;
    }

    // After all nodes are deleted
    tail = nullptr;
}

// MAIN

int main()
{
    Node *head = nullptr;
    Node *tail = nullptr;

    // CREATE USING INSERTION

    insertAtHead(head, tail, 20);
    insertAtHead(head, tail, 10);

    insertAtTail(head, tail, 30);
    insertAtTail(head, tail, 40);

    cout << "Forward: ";
    printForward(head);

    cout << "Backward: ";
    printBackward(tail);

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

    // INSERT AT POSITION

    insertAtPosition(head, tail, 25, 2);

    cout << "After inserting 25 at position 2: ";
    printForward(head);

    cout << "Backward: ";
    printBackward(tail);

    // UPDATE

    updateValue(head, 25, 27);

    cout << "After updating 25 -> 27: ";
    printForward(head);

    // DELETE HEAD

    deleteHead(head, tail);

    cout << "After deleting head: ";
    printForward(head);

    // DELETE TAIL

    deleteTail(head, tail);

    cout << "After deleting tail: ";
    printForward(head);

    // DELETE POSITION

    deleteAtPosition(head, tail, 1);

    cout << "After deleting position 1: ";
    printForward(head);

    // DESTROY

    destroyList(head, tail);

    cout << "After destroying list: ";
    printForward(head);

    return 0;
}