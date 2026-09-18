#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;

    Node(int value)
    {
        data = value;
        next = NULL;
    }
};

Node* mergeNodes(Node* head)
{
    // Result list ke liye dummy node
    Node* dummy = new Node(0);

    // Result list ka last node
    Node* tail = dummy;

    // Current segment ka sum
    int sum = 0;

    Node* current = head;

    while (current != NULL)
    {
        if (current->data == 0)
        {
            // Segment complete ho gaya
            // Sum ko ek new node mein store karo
            if (sum != 0)
            {
                tail->next = new Node(sum);
                tail = tail->next;

                // Next segment ke liye reset
                sum = 0;
            }
        }
        else
        {
            // Current segment ki value add karo
            sum += current->data;
        }

        current = current->next;
    }

    Node* result = dummy->next;

    delete dummy;

    return result;
}

void printList(Node* head)
{
    while (head != NULL)
    {
        cout << head->data << " -> ";
        head = head->next;
    }

    cout << "NULL\n";
}

int main()
{
    // 0 -> 3 -> 1 -> 0 -> 4 -> 5 -> 2 -> 0
    Node* head = new Node(0);
    head->next = new Node(3);
    head->next->next = new Node(1);
    head->next->next->next = new Node(0);
    head->next->next->next->next = new Node(4);
    head->next->next->next->next->next = new Node(5);
    head->next->next->next->next->next->next = new Node(2);
    head->next->next->next->next->next->next->next = new Node(0);

    cout << "Original List:\n";
    printList(head);

    head = mergeNodes(head);

    cout << "\nMerged Nodes List:\n";
    printList(head);

    return 0;
}

/*
Input:
0 -> 3 -> 1 -> 0 -> 4 -> 5 -> 2 -> 0

Output:
4 -> 11

Debug:
Segment 1:
3 + 1 = 4

Segment 2:
4 + 5 + 2 = 11

Time Complexity: O(n)
Space Complexity: O(k)
where k = number of zero-delimited segments,
because we create one output node per segment.
*/