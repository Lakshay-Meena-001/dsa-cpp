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

class Solution
{
public:
    // Merge two sorted linked lists
    ListNode *merge(ListNode *left, ListNode *right)
    {
        ListNode dummy(0);
        ListNode *tail = &dummy;

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

    // Find middle and split the list
    ListNode *getMiddle(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *prev = nullptr;

        while (fast != nullptr && fast->next != nullptr)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // Break the list into two halves
        if (prev != nullptr)
            prev->next = nullptr;

        return slow;
    }

    ListNode *sortList(ListNode *head)
    {
        // Base case
        if (head == nullptr || head->next == nullptr)
            return head;

        // Split
        ListNode *right = getMiddle(head);

        // Sort both halves
        ListNode *leftSorted = sortList(head);
        ListNode *rightSorted = sortList(right);

        // Merge
        return merge(leftSorted, rightSorted);
    }
};

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
    ListNode *head = new ListNode(4);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(3);

    Solution obj;

    cout << "Before sorting: ";
    printList(head);

    head = obj.sortList(head);

    cout << "After sorting: ";
    printList(head);

    return 0;
}