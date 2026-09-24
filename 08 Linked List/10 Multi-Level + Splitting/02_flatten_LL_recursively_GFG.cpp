#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *bottom;

    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
        this->bottom = nullptr;
    }
};

Node *merge(Node *a, Node *b)
{
    if (a == nullptr)
    {
        return b;
    }

    if (b == nullptr)
    {
        return a;
    }

    if (a->data <= b->data)
    {
        a->bottom = merge(a->bottom, b);
        return a;
    }
    else
    {
        b->bottom = merge(a, b->bottom);
        return b;
    }
}

Node *flatten(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    // Flatten remaining lists
    Node *flattenedRest = flatten(head->next);

    // Merge current list with flattened rest
    head = merge(head, flattenedRest);

    return head;
}

void printFlattenedList(Node *head)
{
    while (head != nullptr)
    {
        cout << head->data << " ";

        head = head->bottom;
    }

    cout << endl;
}

int main()
{
    Node *head = new Node(5);
    head->next = new Node(10);
    head->next->next = new Node(19);
    head->next->next->next = new Node(28);

    head->bottom = new Node(7);
    head->bottom->bottom = new Node(8);
    head->bottom->bottom->bottom = new Node(30);

    head->next->bottom = new Node(20);

    head->next->next->bottom = new Node(22);
    head->next->next->bottom->bottom = new Node(50);

    head->next->next->next->bottom = new Node(35);
    head->next->next->next->bottom->bottom = new Node(40);
    head->next->next->next->bottom->bottom->bottom = new Node(45);

    head = flatten(head);

    printFlattenedList(head);

    return 0;
}