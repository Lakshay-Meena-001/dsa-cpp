#include <iostream>
using namespace std;

class MyLinkedList
{
private:
    struct Node
    {
        int val;
        Node *next;

        Node(int v)
        {
            val = v;
            next = NULL;
        }
    };

    Node *head;
    int size;

public:
    // Constructor
    MyLinkedList()
    {
        head = NULL;
        size = 0;
    }

    // Get value at index
    int get(int index)
    {
        // Invalid index
        if (index < 0 || index >= size)
            return -1;

        Node *curr = head;

        for (int i = 0; i < index; i++)
        {
            curr = curr->next;
        }

        return curr->val;
    }

    // Add node at head
    void addAtHead(int val)
    {
        Node *newNode = new Node(val);

        newNode->next = head;
        head = newNode;

        size++;
    }

    // Add node at tail
    void addAtTail(int val)
    {
        Node *newNode = new Node(val);

        // Empty list
        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            Node *curr = head;

            while (curr->next != NULL)
            {
                curr = curr->next;
            }

            curr->next = newNode;
        }

        size++;
    }

    // Add node at given index
    void addAtIndex(int index, int val)
    {
        // Invalid index
        if (index < 0 || index > size)
            return;

        // Insert at head
        if (index == 0)
        {
            addAtHead(val);
            return;
        }

        Node *curr = head;

        // Move to previous node
        for (int i = 0; i < index - 1; i++)
        {
            curr = curr->next;
        }

        Node *newNode = new Node(val);

        // Connect new node to next node
        newNode->next = curr->next;

        // Connect previous node to new node
        curr->next = newNode;

        size++;
    }

    // Delete node at given index
    void deleteAtIndex(int index)
    {
        // Invalid index
        if (index < 0 || index >= size)
            return;

        // Delete head
        if (index == 0)
        {
            Node *temp = head;

            head = head->next;

            delete temp;

            size--;

            return;
        }

        Node *curr = head;

        // Move to previous node
        for (int i = 0; i < index - 1; i++)
        {
            curr = curr->next;
        }

        Node *temp = curr->next;

        // Bypass target node
        curr->next = temp->next;

        // Free memory
        delete temp;

        size--;
    }
};

int main()
{
    MyLinkedList list;

    list.addAtHead(1);
    list.addAtTail(3);
    list.addAtIndex(1, 2);

    cout << list.get(1) << endl;

    list.deleteAtIndex(1);

    cout << list.get(1) << endl;

    return 0;
}