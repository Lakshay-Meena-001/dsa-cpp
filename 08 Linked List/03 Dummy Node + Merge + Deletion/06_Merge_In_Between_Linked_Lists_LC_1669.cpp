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

Node *mergeInBetween(Node *list1, int a, int b, Node *list2)
{
    // Step 1:
    // a ke just pehle wala node find karo
    Node *beforeA = list1;

    for (int i = 0; i < a - 1; i++)
    {
        beforeA = beforeA->next;
    }

    // Step 2:
    // b wale node tak jao
    Node *nodeB = list1;

    for (int i = 0; i < b; i++)
    {
        nodeB = nodeB->next;
    }

    // b ke baad wala node save karo
    Node *afterB = nodeB->next;

    // Step 3:
    // list2 ka tail find karo
    Node *list2Tail = list2;

    while (list2Tail->next != NULL)
    {
        list2Tail = list2Tail->next;
    }

    // Step 4:
    // list1 ke segment ko list2 se replace karo
    beforeA->next = list2;

    // Step 5:
    // list2 ke end ko list1 ke remaining part se connect karo
    list2Tail->next = afterB;

    return list1;
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
    // list1:
    // 0 -> 1 -> 2 -> 3 -> 4 -> 5
    Node *list1 = new Node(0);
    list1->next = new Node(1);
    list1->next->next = new Node(2);
    list1->next->next->next = new Node(3);
    list1->next->next->next->next = new Node(4);
    list1->next->next->next->next->next = new Node(5);

    // list2:
    // 1000000 -> 1000001 -> 1000002
    Node *list2 = new Node(1000000);
    list2->next = new Node(1000001);
    list2->next->next = new Node(1000002);

    int a = 2;
    int b = 4;

    cout << "List 1 Before:\n";
    printList(list1);

    cout << "\nList 2:\n";
    printList(list2);

    list1 = mergeInBetween(list1, a, b, list2);

    cout << "\nFinal List:\n";
    printList(list1);

    return 0;
}

/*
Input:

List 1:
0 -> 1 -> 2 -> 3 -> 4 -> 5

List 2:
1000000 -> 1000001 -> 1000002

a = 2
b = 4

Output:

0 -> 1 -> 1000000 -> 1000001 -> 1000002 -> 5

Debug:

beforeA = node 1
afterB = node 5
list2Tail = node 1000002

Connection 1:
1 -> list2

Connection 2:
1000002 -> 5

Time Complexity: O(n + m)
Space Complexity: O(1) auxiliary space
*/