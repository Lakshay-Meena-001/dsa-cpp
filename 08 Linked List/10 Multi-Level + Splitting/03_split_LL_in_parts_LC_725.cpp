#include <iostream>
#include <vector>
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

vector<Node *> splitListToParts(Node *head, int k)
{
    vector<Node *> result(k, NULL);

    // Step 1: Count nodes
    int n = 0;

    Node *curr = head;

    while (curr != NULL)
    {
        n++;
        curr = curr->next;
    }

    // Step 2: Calculate base size and extra nodes
    int base = n / k;
    int extra = n % k;

    // Step 3: Create each part
    curr = head;

    for (int i = 0; i < k; i++)
    {
        if (curr == NULL)
        {
            break;
        }

        result[i] = curr;

        int partSize = base;

        if (extra > 0)
        {
            partSize++;
            extra--;
        }

        // Move to last node of current part
        for (int j = 1; j < partSize; j++)
        {
            curr = curr->next;
        }

        // Save beginning of next part
        Node *nextPart = curr->next;

        // Cut current part
        curr->next = NULL;

        // Move to next part
        curr = nextPart;
    }

    return result;
}

void printPart(Node *head)
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
    head->next->next->next->next->next->next->next->next->next = new Node(10);

    int k = 3;

    vector<Node *> parts = splitListToParts(head, k);

    cout << "Split Linked List:" << endl;

    for (int i = 0; i < k; i++)
    {
        cout << "Part " << i + 1 << ": ";

        printPart(parts[i]);
    }

    return 0;
}