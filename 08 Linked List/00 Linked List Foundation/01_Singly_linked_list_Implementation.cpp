#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;

    Node(int value)
    {
        data = value;
        next = nullptr;
    }
};

// -------------------- TRAVERSAL --------------------

void printList(Node* head)
{
    Node* temp = head;

    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << '\n';
}

// -------------------- LENGTH --------------------

int length(Node* head)
{
    int count = 0;

    Node* temp = head;

    while (temp != nullptr)
    {
        count++;
        temp = temp->next;
    }

    return count;
}

// -------------------- SEARCH --------------------

bool search(Node* head, int target)
{
    Node* temp = head;

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

// -------------------- INSERT HEAD --------------------

void insertAtHead(Node*& head, int value)
{
    Node* newNode = new Node(value);

    newNode->next = head;
    head = newNode;
}

// -------------------- INSERT TAIL --------------------

void insertAtTail(Node*& head, int value)
{
    Node* newNode = new Node(value);

    if (head == nullptr)
    {
        head = newNode;
        return;
    }

    Node* temp = head;

    while (temp->next != nullptr)
    {
        temp = temp->next;
    }

    temp->next = newNode;
}

// -------------------- INSERT POSITION --------------------

void insertAtPosition(Node*& head, int value, int pos)
{
    if (pos < 0)
    {
        return;
    }

    if (pos == 0)
    {
        insertAtHead(head, value);
        return;
    }

    Node* temp = head;

    for (int i = 0; i < pos - 1 && temp != nullptr; i++)
    {
        temp = temp->next;
    }

    if (temp == nullptr)
    {
        return;
    }

    Node* newNode = new Node(value);

    newNode->next = temp->next;
    temp->next = newNode;
}

// -------------------- DELETE HEAD --------------------

void deleteHead(Node*& head)
{
    if (head == nullptr)
    {
        return;
    }

    Node* temp = head;
    head = head->next;

    delete temp;
}

// -------------------- DELETE TAIL --------------------

void deleteTail(Node*& head)
{
    if (head == nullptr)
    {
        return;
    }

    if (head->next == nullptr)
    {
        delete head;
        head = nullptr;
        return;
    }

    Node* temp = head;

    while (temp->next->next != nullptr)
    {
        temp = temp->next;
    }

    Node* nodeToDelete = temp->next;

    temp->next = nullptr;

    delete nodeToDelete;
}

// -------------------- DELETE POSITION --------------------

void deleteAtPosition(Node*& head, int pos)
{
    if (head == nullptr || pos < 0)
    {
        return;
    }

    if (pos == 0)
    {
        deleteHead(head);
        return;
    }

    Node* temp = head;

    for (int i = 0; i < pos - 1 && temp != nullptr; i++)
    {
        temp = temp->next;
    }

    if (temp == nullptr || temp->next == nullptr)
    {
        return;
    }

    Node* nodeToDelete = temp->next;

    temp->next = nodeToDelete->next;

    delete nodeToDelete;
}

// -------------------- UPDATE --------------------

void updateValue(Node* head, int oldValue, int newValue)
{
    Node* temp = head;

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

// -------------------- DESTROY --------------------

void destroyList(Node*& head)
{
    while (head != nullptr)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

// -------------------- MAIN --------------------

int main()
{
    Node* head = nullptr;

    insertAtHead(head, 20);
    insertAtHead(head, 10);

    insertAtTail(head, 30);
    insertAtTail(head, 40);

    insertAtPosition(head, 25, 2);

    cout << "List: ";
    printList(head);

    cout << "Length: " << length(head) << '\n';

    cout << "Search 30: "
         << (search(head, 30) ? "Found" : "Not Found")
         << '\n';

    updateValue(head, 25, 27);

    cout << "After update: ";
    printList(head);

    deleteHead(head);

    cout << "After deleting head: ";
    printList(head);

    deleteTail(head);

    cout << "After deleting tail: ";
    printList(head);

    deleteAtPosition(head, 1);

    cout << "After deleting position 1: ";
    printList(head);

    destroyList(head);

    cout << "After destroying list: ";
    printList(head);

    return 0;
}