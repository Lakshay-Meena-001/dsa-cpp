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

void printRecursive(Node *head)
{
    // base case
    if (head == nullptr)
    {
        return;
    }

    // pehle recursion hume last node tak le jyga then wapis aate hue print 
    printRecursive(head->next);

    // pehle recursion then print
    cout << head->data << " ";
}

int main()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);

    printRecursive(head);

    return 0;
}