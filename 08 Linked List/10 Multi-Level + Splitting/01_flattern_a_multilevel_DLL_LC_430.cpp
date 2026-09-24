#include <iostream>
#include <stack>
using namespace std;

struct Node
{
    int data;
    Node *prev;
    Node *next;
    Node *child;

    Node(int data)
    {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
        this->child = NULL;
    }
};

// ITERATIVE STACK VERSION

Node *flattenStack(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }

    stack<Node *> st;

    Node *curr = head;

    while (curr != NULL)
    {
        // If child exists
        if (curr->child != NULL)
        {
            // Save original next in stack
            if (curr->next != NULL)
            {
                st.push(curr->next);
            }

            // Attach child after curr
            curr->next = curr->child;
            curr->child->prev = curr;

            // Child pointer no longer needed
            curr->child = NULL;
        }

        // Current chain ended
        if (curr->next == NULL && !st.empty())
        {
            Node *next = st.top();
            st.pop();

            curr->next = next;
            next->prev = curr;
        }

        curr = curr->next;
    }

    return head;
}

// OPTIMIZED RECURSIVE VERSION

// Returns the tail of the flattened list
Node *flattenHelper(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }

    Node *curr = head;
    Node *tail = head;

    while (curr != NULL)
    {
        // If child exists
        if (curr->child != NULL)
        {
            // Save original next
            Node *next = curr->next;

            // Save child head
            Node *childHead = curr->child;

            // Flatten child and get its tail
            Node *childTail = flattenHelper(childHead);

            // Attach child after curr
            curr->next = childHead;
            childHead->prev = curr;

            // Remove child pointer
            curr->child = NULL;

            // Reconnect original next
            if (next != NULL)
            {
                childTail->next = next;
                next->prev = childTail;
            }

            // Child tail is now part of current chain
            tail = childTail;

            // Continue from child tail
            curr = childTail;
        }
        else
        {
            tail = curr;
            curr = curr->next;
        }
    }

    return tail;
}

// Wrapper function
Node *flattenRecursive(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }

    flattenHelper(head);

    return head;
}

// PRINT FORWARD

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

// CREATE SAME MULTILEVEL LIST
//
//        1 <-> 2 <-> 3
//              |
//              4 <-> 5
//                    |
//                    6
//
// Expected:
// 1 <-> 2 <-> 4 <-> 5 <-> 6 <-> 3

Node *createList()
{
    Node *n1 = new Node(1);
    Node *n2 = new Node(2);
    Node *n3 = new Node(3);

    Node *n4 = new Node(4);
    Node *n5 = new Node(5);

    Node *n6 = new Node(6);

    // Main list
    n1->next = n2;
    n2->prev = n1;

    n2->next = n3;
    n3->prev = n2;

    // Child list of 2
    n2->child = n4;

    n4->next = n5;
    n5->prev = n4;

    // Child list of 5
    n5->child = n6;

    return n1;
}

// MAIN

int main()
{
    // 1. ITERATIVE STACK

    cout << "Iterative Stack Version:" << endl;

    Node *head1 = createList();

    cout << "Before Flatten: ";
    printList(head1);

    head1 = flattenStack(head1);

    cout << "After Flatten:  ";
    printList(head1);

    cout << endl;

    // 2. RECURSIVE

    cout << "Recursive Version:" << endl;

    Node *head2 = createList();

    cout << "Before Flatten: ";
    printList(head2);

    head2 = flattenRecursive(head2);

    cout << "After Flatten:  ";
    printList(head2);

    return 0;
}