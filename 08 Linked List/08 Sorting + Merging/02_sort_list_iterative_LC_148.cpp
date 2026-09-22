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
    // Merge two sorted lists
    Node *merge(Node *left, Node *right)
    {
        Node dummy(0);
        Node *tail = &dummy;

        while (left != nullptr && right != nullptr)
        {
            if (left->data <= right->data)
            {
                tail->next = left;
                left = left->next;
            }
            else
            {
                tail->next = right;
                right = right->next;
            }

            tail = tail->next;
        }

        if (left != nullptr)
            tail->next = left;

        if (right != nullptr)
            tail->next = right;

        return dummy.next;
    }

    // Return the first 'size' nodes and move head forward
    Node *split(Node *head, int size)
    {
        Node *curr = head;

        for (int i = 1; curr != nullptr && i < size; i++)
        {
            curr = curr->next;
        }

        if (curr == nullptr)
            return nullptr;

        Node *second = curr->next;
        curr->next = nullptr;

        return second;
    }

    Node *sortList(Node *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;

        int length = 0;
        Node *curr = head;

        while (curr != nullptr)
        {
            length++;
            curr = curr->next;
        }

        Node dummy(0);
        dummy.next = head;

        for (int size = 1; size < length; size *= 2)
        {
            Node *curr = dummy.next;
            Node *tail = &dummy;

            while (curr != nullptr)
            {
                Node *left = curr;

                Node *right = split(left, size);

                curr = split(right, size);

                Node *merged = merge(left, right);

                tail->next = merged;

                while (tail->next != nullptr)
                {
                    tail = tail->next;
                }
            }
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

    head = obj.sortList(head);

    cout << "After sorting: ";
    printList(head);

    return 0;
}