#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int value)
    {
        data = value;
        next = NULL;
    }
};

// Merge two sorted linked lists
Node *mergeTwoLists(Node *l1, Node *l2)
{
    // Dummy node: final list ka fake starting point
    Node *dummy = new Node(0);

    // Tail final merged list ke last node ko track karega
    Node *tail = dummy;

    while (l1 != NULL && l2 != NULL)
    {
        // Jo node chhota hai usko attach karo
        if (l1->data <= l2->data)
        {
            tail->next = l1;
            l1 = l1->next;
        }
        else
        {
            tail->next = l2;
            l2 = l2->next;
        }

        // Tail ko newly attached node par move karo
        tail = tail->next;
    }

    // Ek list mein nodes bach gaye hain
    // Remaining part already sorted hai
    if (l1 != NULL)
    {
        tail->next = l1;
    }
    else
    {
        tail->next = l2;
    }

    // Dummy ke baad actual answer hai
    Node *result = dummy->next;

    delete dummy;

    return result;
}

void printList(Node *head)
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
    // List 1: 1 -> 3 -> 5
    Node *l1 = new Node(1);
    l1->next = new Node(3);
    l1->next->next = new Node(5);

    // List 2: 2 -> 4 -> 6
    Node *l2 = new Node(2);
    l2->next = new Node(4);
    l2->next->next = new Node(6);

    Node *merged = mergeTwoLists(l1, l2);

    cout << "Merged List:\n";
    printList(merged);

    return 0;
}

/*
Input:
List 1 = 1 -> 3 -> 5
List 2 = 2 -> 4 -> 6

Output:
1 -> 2 -> 3 -> 4 -> 5 -> 6

Debug:
1 vs 2  -> take 1
3 vs 2  -> take 2
3 vs 4  -> take 3
5 vs 4  -> take 4
5 vs 6  -> take 5
List 1 ends -> attach remaining 6

Time Complexity: O(n + m)
Space Complexity: O(1) auxiliary space
*/