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

void printRecursive(ListNode *head)
{
    // base case
    if (head == nullptr)
    {
        return;
    }

    // pehle print karo then aage recursion
    cout << head->data << " ";

    printRecursive(head->next);
}

int main()
{
    ListNode *head = new ListNode(10);
    head->next = new ListNode(20);
    head->next->next = new ListNode(30);
    head->next->next->next = new ListNode(40);

    printRecursive(head);

    return 0;
}