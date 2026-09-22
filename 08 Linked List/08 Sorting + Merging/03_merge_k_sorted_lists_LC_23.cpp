#include <iostream>
#include <vector>
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
    ListNode *mergeTwoLists(ListNode *a, ListNode *b)
    {
        ListNode dummy(0);
        ListNode *tail = &dummy;

        while (a != nullptr && b != nullptr)
        {
            if (a->data <= b->data)
            {
                tail->next = a;
                a = a->next;
            }
            else
            {
                tail->next = b;
                b = b->next;
            }

            tail = tail->next;
        }

        if (a != nullptr)
        {
            tail->next = a;
        }

        if (b != nullptr)
        {
            tail->next = b;
        }

        return dummy.next;
    }

    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        ListNode *result = nullptr;

        for (ListNode *list : lists)
        {
            result = mergeTwoLists(result, list);
        }

        return result;
    }
};