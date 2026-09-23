#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

// Linked List Node

struct ListNode
{
    int val;
    ListNode *next;

    ListNode(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};

// Approach 1: Vector / Array

class RandomNodeVector
{
private:
    vector<int> arr;

public:
    // Constructor
    // Linked list ke saare values vector me store karenge
    RandomNodeVector(ListNode *head)
    {
        while (head != NULL)
        {
            arr.push_back(head->val);
            head = head->next;
        }
    }

    // Random node return karo
    int getRandom()
    {
        int index = rand() % arr.size();

        return arr[index];
    }
};

// Approach 2: Length + Random Index

class RandomNodeLength
{
private:
    ListNode *head;
    int length;

public:
    // Constructor
    // Pehle linked list ki length calculate karenge
    RandomNodeLength(ListNode *head)
    {
        this->head = head;

        length = 0;

        ListNode *curr = head;

        while (curr != NULL)
        {
            length++;
            curr = curr->next;
        }
    }

    // Random node return karo
    int getRandom()
    {
        // 0 se length-1 ke beech random index
        int index = rand() % length;

        ListNode *curr = head;

        // Random index tak traverse karo
        while (index > 0)
        {
            curr = curr->next;
            index--;
        }

        return curr->val;
    }
};

// Helper: Linked List Print

void printList(ListNode *head)
{
    ListNode *curr = head;

    while (curr != NULL)
    {
        cout << curr->val;

        if (curr->next != NULL)
        {
            cout << " -> ";
        }

        curr = curr->next;
    }

    cout << endl;
}

// Helper: Delete Linked List

void deleteList(ListNode *head)
{
    while (head != NULL)
    {
        ListNode *temp = head;
        head = head->next;

        delete temp;
    }
}

// MAIN

int main()
{
    // Same random sequence ke liye optional
    srand(time(0));

    // Linked List:
    //
    // 1 -> 2 -> 3 -> 4 -> 5

    ListNode *head = new ListNode(1);

    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "Linked List: ";
    printList(head);

    cout << endl;

    // APPROACH 1
    // Vector / Array

    cout << "===== Approach 1: Vector =====" << endl;

    RandomNodeVector solution1(head);

    cout << "Random Node: " << solution1.getRandom() << endl;
    cout << "Random Node: " << solution1.getRandom() << endl;
    cout << "Random Node: " << solution1.getRandom() << endl;

    cout << endl;

    // APPROACH 2
    // Length + Random Index

    cout << "===== Approach 2: Length + Random Index =====" << endl;

    RandomNodeLength solution2(head);

    cout << "Random Node: " << solution2.getRandom() << endl;
    cout << "Random Node: " << solution2.getRandom() << endl;
    cout << "Random Node: " << solution2.getRandom() << endl;

    // Cleanup

    deleteList(head);

    return 0;
}