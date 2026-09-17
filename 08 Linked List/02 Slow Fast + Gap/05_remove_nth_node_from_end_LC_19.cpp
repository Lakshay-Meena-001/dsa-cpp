#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int value)
    {
        data = value;
        next = nullptr;
    }
};

Node *removeNthFromEnd(Node *head, int n)
{
   
    // agar head hi delete karna ho, to head ke previous node ki zarurat hoti hai.
    // Dummy us previous node ko provide karta hai.
    
    Node *dummy = new Node(0);
    dummy->next = head;

    Node *first = dummy;
    Node *second = dummy;

    // STEP 1: FIXED GAP CREATE KARO

    // first ko n nodes aage le jao. Ab first aur second ke beech fixed gap hai.

    for (int i = 0; i < n; i++)
    {
        first = first->next;
    }

    // STEP 2: DONO SAME SPEED SE MOVE

    // Jab first last node par hoga, second target node ke previous par hoga.

    while (first->next != nullptr)
    {
        first = first->next;
        second = second->next;
    }

    // STEP 3: TARGET DELETE KARO

    // second->next = target node
    // target->next = next node
    
    // Is assignment se target list se skip ho jayega.
    Node *nodeToDelete = second->next;

    second->next = second->next->next;

    delete nodeToDelete;

    Node *newHead = dummy->next;

    delete dummy;

    return newHead;
}

void printList(Node *head)
{
    while (head != nullptr)
    {
        cout << head->data << " -> ";
        head = head->next;
    }

    cout << "NULL\n";
}

int main()
{
    /*
        Linked List:

        1 -> 2 -> 3 -> 4 -> 5

        n = 2

        End se 2nd node = 4

        Output:

        1 -> 2 -> 3 -> 5
    */

    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    int n = 2;

    cout << "Original List: ";
    printList(head);

    head = removeNthFromEnd(head, n);

    cout << "After Deletion: ";
    printList(head);

    return 0;
}

/*
INPUT:

1 -> 2 -> 3 -> 4 -> 5
n = 2


OUTPUT:

1 -> 2 -> 3 -> 5


PATTERN:
Fixed Gap / Lead-Lag Pointers


CORE IDEA:

first  = lead pointer
second = lag pointer

Pehle first ko n steps aage le jao.

Isse dono pointers ke beech fixed gap
create ho jata hai.

Then dono ko same speed se move karo.

Jab first last node par pahunchta hai,
second target node ke PREVIOUS par hota hai.


WHY PREVIOUS?

Linked List mein node delete karne ke liye:

previous -> target -> next

ko:

previous -> next

banana hota hai.

Therefore:
second->next = target


WHY DUMMY?

Agar n == length hua,
to HEAD delete karna padega.

Example:

1 -> 2 -> 3
n = 3

Dummy:

D -> 1 -> 2 -> 3

Dummy head ke previous node ki tarah kaam karta hai.

Isse head deletion bhi normal deletion ban jata hai.


TIME COMPLEXITY:
O(n)

First pointer maximum n steps.
Then both pointers traverse at most n steps.

Overall = O(n)


SPACE COMPLEXITY:
O(1)

Only constant number of pointers use hue hain.


PATTERN TRANSFER:

Middle:
slow/fast speed difference

Cycle:
slow/fast speed difference

Nth From End:
fixed distance/gap between pointers

Main idea:
POINTERS KI RELATIVE POSITION SE
INFORMATION EXTRACT KARNA.
*/