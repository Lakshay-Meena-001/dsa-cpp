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

// Floyd's Cycle Detection + Cycle Entry
Node *detectCycle(Node *head)
{
    Node *slow = head;
    Node *fast = head;

    // PHASE 1: Find Meeting Point

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;

        // Same node par aa gaye => cycle exists
        if (slow == fast)
        {
            break;
        }
    }

    // Agar fast NULL tak pahunch gaya, to cycle exist hi nahi karti.
    if (fast == nullptr || fast->next == nullptr)
    {
        return nullptr;
    }

    // PHASE 2: Find Cycle Entry

    // Ek pointer ko head par reset karo.
    // Doosra meeting point par hi rahega.
    slow = head;

    // Ab dono same speed se chalenge. Mathematical relation ki wajah se dono cycle ke entry node par milenge.
    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
}

int main()
{
    /*
        Creating:

        1 -> 2 -> 3 -> 4 -> 5
                  ^         |
                  |_________|

        5 -> 3

        Cycle Entry = 3
    */

    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    // Create cycle: 5 -> 3
    head->next->next->next->next->next =
        head->next->next;

    Node *entry = detectCycle(head);

    if (entry != nullptr)
    {
        cout << "Cycle Entry Node: "
             << entry->data << endl;
    }
    else
    {
        cout << "No Cycle\n";
    }

    return 0;
}

/*
INPUT:

1 -> 2 -> 3 -> 4 -> 5
          ^         |
          |_________|

5 points back to 3.


OUTPUT:

Cycle Entry Node: 3


PATTERN:
Floyd's Cycle Detection
+
Cycle Entry Detection


PHASE 1:
slow = 1 step
fast = 2 steps

Agar slow == fast:
    cycle exists.

Agar fast NULL ho gaya:
    cycle nahi hai.


PHASE 2:

slow ko head par reset karo.

fast ko meeting point par rehne do.

Ab dono 1-1 step move karenge.

Jahan dono milenge:
    wahi cycle ka entry node hai.


WHY?

Let:

a = head -> cycle entry
b = entry -> meeting
L = cycle length

Floyd's meeting relation se:

a + b = kL

Therefore:

a = kL - b

Matlab head se entry tak ki distance
aur meeting point se cycle mein appropriate
forward distance mathematically aligned hain.

Isliye head aur meeting point se equal-speed
movement karne par cycle entry par meeting hoti hai.


TIME COMPLEXITY:
O(n)

PHASE 1 = O(n)
PHASE 2 = O(n)

Total = O(n)


SPACE COMPLEXITY:
O(1)

Sirf pointers use kiye gaye hain.
HashSet / extra array nahi.


IMPORTANT:
slow == fast ka matlab sirf:
    "cycle ke andar meeting hui"

Ye zaroori nahi ki:
    meeting point == cycle entry

Entry nikalne ke liye:
    slow = head
    fast = meeting point

phir dono ko 1-1 step move karo.
*/