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

int main()
{
    Node* first = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);

    first->next = second;
    second->next = third;

    Node* head = first;

    printList(head);

    cout << "Length: " << length(head) << '\n';

    cout << "Search 20: " << search(head, 20) << '\n';
    cout << "Search 50: " << search(head, 50) << '\n';

    return 0;
}