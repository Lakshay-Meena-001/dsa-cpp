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

Node *deleteNAfterM(Node *head, int M, int N)
{
    if (head == nullptr || M <= 0)
        return nullptr;

    if (N <= 0)
        return head;

    Node *current = head;

    while (current != nullptr)
    {
        // Step 1: Keep M nodes
        for (int i = 1; i < M && current != nullptr; i++)
        {
            current = current->next;
        }

        // M nodes keep karne ke baad list khatam
        if (current == nullptr)
            break;

        // Step 2: Next N nodes skip/delete
        Node *temp = current->next;

        for (int i = 0; i < N && temp != nullptr; i++)
        {
            Node *deleteNode = temp;
            temp = temp->next;

            delete deleteNode;
        }

        // Step 3: Reconnect
        current->next = temp;

        // Step 4: Move to next surviving node
        current = temp;
    }

    return head;
}

void printList(Node *head)
{
    while (head != nullptr)
    {
        cout << head->data << " -> ";
        head = head->next;
    }

    cout << "NULL\n";
}

int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);
    head->next->next->next->next->next->next = new Node(7);
    head->next->next->next->next->next->next->next = new Node(8);

    int M = 2;
    int N = 2;

    cout << "Before: ";
    printList(head);

    head = deleteNAfterM(head, M, N);

    cout << "After:  ";
    printList(head);

    return 0;
}