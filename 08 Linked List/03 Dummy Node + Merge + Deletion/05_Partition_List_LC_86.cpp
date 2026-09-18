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

Node *partitionList(Node *head, int x)
{
    // Small values ke liye dummy + tail
    Node *smallDummy = new Node(0);
    Node *smallTail = smallDummy;

    // Greater/equal values ke liye dummy + tail
    Node *largeDummy = new Node(0);
    Node *largeTail = largeDummy;

    Node *current = head;

    while (current != NULL)
    {
        // Next node pehle save karo, kyunki current ko detach karenge
        Node *nextNode = current->next;

        // Current node ko original list se detach karo
        current->next = NULL;

        if (current->data < x)
        {
            // x se chhoti value -> small chain
            smallTail->next = current;
            smallTail = smallTail->next;
        }
        else
        {
            // x se badi/equal value -> large chain
            largeTail->next = current;
            largeTail = largeTail->next;
        }

        // Original list mein aage move karo
        current = nextNode;
    }

    // Small chain ko large chain ke beginning se connect karo
    smallTail->next = largeDummy->next;

    Node *result = smallDummy->next;

    delete smallDummy;
    delete largeDummy;

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
    // 1 -> 4 -> 3 -> 2 -> 5 -> 2
    Node *head = new Node(1);
    head->next = new Node(4);
    head->next->next = new Node(3);
    head->next->next->next = new Node(2);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(2);

    int x = 3;

    cout << "Original List:\n";
    printList(head);

    head = partitionList(head, x);

    cout << "\nPartitioned List:\n";
    printList(head);

    return 0;
}

/*
Input:
1 -> 4 -> 3 -> 2 -> 5 -> 2
x = 3

Output:
1 -> 2 -> 2 -> 4 -> 3 -> 5

Debug:
1 < 3  -> small chain
4 >= 3 -> large chain
3 >= 3 -> large chain
2 < 3  -> small chain
5 >= 3 -> large chain
2 < 3  -> small chain

Finally:
small chain -> large chain

Time Complexity: O(n)
Space Complexity: O(1) auxiliary space
(excluding the dummy nodes themselves)
*/