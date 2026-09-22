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

ListNode *mergeRecursive(ListNode *list1, ListNode *list2)
{
    // Base cases
    if (list1 == nullptr)
    {
        return list2;
    }

    if (list2 == nullptr)
    {
        return list1;
    }

    // Choose smaller Listnode
    if (list1->data <= list2->data)
    {
        list1->next = mergeRecursive(list1->next, list2);
        return list1;
    }
    else
    {
        list2->next = mergeRecursive(list1, list2->next);
        return list2;
    }
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
    ListNode *list1 = new ListNode(1);
    list1->next = new ListNode(3);
    list1->next->next = new ListNode(5);

    ListNode *list2 = new ListNode(2);
    list2->next = new ListNode(4);
    list2->next->next = new ListNode(6);

    ListNode *head = mergeRecursive(list1, list2);

    printList(head);

    return 0;
}