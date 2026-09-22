#include <iostream>
using namespace std;

struct ListNode
{
    int data;
    ListNode *next;

    ListNode(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

ListNode *insertRecursive(ListNode *current, int pos, int value)
{
    //remember ki recursion m LL ki indexing 0 se start hoti hai
    // Base case
    if (pos == 0)
    {
        ListNode *newListNode = new ListNode(value);

        newListNode->next = current;

        return newListNode;
    }

    // Invalid position
    if (current == nullptr)
    {
        return current;
    }

    // Move to next Listnode
    current->next = insertRecursive(current->next, pos - 1, value);

    return current;
}

void printList(ListNode *head)
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
    ListNode *head = new ListNode(10);
    head->next = new ListNode(20);
    head->next->next = new ListNode(30);
    head->next->next->next = new ListNode(40);

    cout << "Before: ";
    printList(head);

    head = insertRecursive(head, 2, 25);

    cout << "After: ";
    printList(head);

    return 0;
}