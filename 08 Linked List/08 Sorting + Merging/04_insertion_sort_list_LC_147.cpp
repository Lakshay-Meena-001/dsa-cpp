#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

class Solution
{
public:
    Node *insertionSortList(Node *head)
    {
        Node dummy(0);

        Node *curr = head;

        while (curr != nullptr)
        {
            Node *nextNode = curr->next;

            Node *prev = &dummy;

            // Find position for curr
            while (prev->next != nullptr &&
                   prev->next->data <= curr->data)
            {
                prev = prev->next;
            }

            // Insert curr between prev and prev->next
            curr->next = prev->next;
            prev->next = curr;

            curr = nextNode;
        }

        return dummy.next;
    }
};

void printList(Node *head)
{
    while (head != nullptr)
    {
        cout << head->data << " ";
        head = head->next;
    }

    cout << endl;
}

int main()
{
    Node *head = new Node(4);
    head->next = new Node(2);
    head->next->next = new Node(1);
    head->next->next->next = new Node(3);

    Solution obj;

    cout << "Before sorting: ";
    printList(head);

    head = obj.insertionSortList(head);

    cout << "After sorting: ";
    printList(head);

    return 0;
}