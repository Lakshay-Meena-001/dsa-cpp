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

// BACKWARD TRAVERSAL

void printBackward(Node *tail)
{
    if (tail == nullptr)
    {
        cout << "Empty\n";
        return;
    }

    Node *temp = tail;

    do
    {
        cout << temp->data << " ";
        temp = temp->prev;

    } while (temp != tail);

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

        newNode->next = newNode;
        newNode->prev = newNode;

        return;
    }

    newNode->next = head;
    newNode->prev = tail;

    head->prev = newNode;
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

        newNode->next = newNode;
        newNode->prev = newNode;

        return;
    }

    newNode->prev = tail;
    newNode->next = head;

    tail->next = newNode;
    head->prev = newNode;

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

    // Find node at pos - 1
    for (int i = 0; i < pos - 1; i++)
    {
        temp = temp->next;

        if (temp == head)
        {
            return;
        }
    }

    // Insert after tail
    if (temp == tail)
    {
        insertAtTail(head, tail, value);
        return;
    }

    Node *newNode = new Node(value);

    Node *nextNode = temp->next;

    newNode->prev = temp;
    newNode->next = nextNode;

    temp->next = newNode;
    nextNode->prev = newNode;
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

    head->prev = tail;
    tail->next = head;

    delete nodeToDelete;
}

// DELETE TAIL

void deleteTail(Node *&head, Node *&tail)
{
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

    tail = tail->prev;

    tail->next = head;
    head->prev = tail;

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

    // Find target
    for (int i = 0; i < pos; i++)
    {
        temp = temp->next;

        if (temp == head)
        {
            return;
        }
    }

    // Target is tail
    if (temp == tail)
    {
        deleteTail(head, tail);
        return;
    }

    Node *prevNode = temp->prev;
    Node *nextNode = temp->next;

    prevNode->next = nextNode;
    nextNode->prev = prevNode;

    delete temp;
}

// DELETE KNOWN NODE

void deleteNode(
    Node *&head,
    Node *&tail,
    Node *target)
{
    if (target == nullptr)
    {
        return;
    }

    if (target == head)
    {
        deleteHead(head, tail);
        return;
    }

    if (target == tail)
    {
        deleteTail(head, tail);
        return;
    }

    Node *prevNode = target->prev;
    Node *nextNode = target->next;

    prevNode->next = nextNode;
    nextNode->prev = prevNode;

    delete target;
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

    // INSERT POSITION

    insertAtPosition(head, tail, 25, 2);

    cout << "After inserting 25: ";
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