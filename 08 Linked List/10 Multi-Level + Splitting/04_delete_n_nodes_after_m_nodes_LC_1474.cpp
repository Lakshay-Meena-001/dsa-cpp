#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

Node *deleteNAfterM(Node *head, int M, int N)
{
    if (head == NULL)
    {
        return NULL;
    }

    if (M == 0)
    {
        return NULL;
    }

    Node *curr = head;

    while (curr != NULL)
    {
        // STEP 1: KEEP M NODES

        for (int i = 1; i < M && curr != NULL; i++)
        {
            curr = curr->next;
        }

        // If list ended
        if (curr == NULL)
        {
            break;
        }

        // STEP 2: DELETE / SKIP N NODES

        Node *temp = curr->next;

        for (int i = 1; i <= N && temp != NULL; i++)
        {
            temp = temp->next;
        }

        // STEP 3: RECONNECT

        curr->next = temp;

        // Move to next kept block
        curr = temp;
    }

    return head;
}

void printList(Node *head)
{
    Node *curr = head;

    while (curr != NULL)
    {
        cout << curr->data << " ";

        curr = curr->next;
    }

    cout << endl;
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
    head->next->next->next->next->next->next->next->next = new Node(9);

    int M = 2;
    int N = 2;

    cout << "Original List: ";
    printList(head);

    head = deleteNAfterM(head, M, N);

    cout << "After Deletion: ";
    printList(head);

    return 0;
}