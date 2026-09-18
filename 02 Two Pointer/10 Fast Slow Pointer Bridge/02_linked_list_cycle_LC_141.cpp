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

// Floyd's Cycle Detection
// slow -> 1 step
// fast -> 2 steps
bool hasCycle(Node *head)
{
    Node *slow = head;
    Node *fast = head;

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;       // 1 step
        fast = fast->next->next; // 2 steps

        // Agar dono same node par aa gaye,
        // iska matlab cycle ke andar fast ne slow ko catch kar liya.
        if (slow == fast)
        {
            return true;
        }
    }

    // fast NULL tak pahunch gaya,
    // therefore list mein cycle nahi hai.
    return false;
}

int main()
{
    // Creating:
    //
    // 1 -> 2 -> 3 -> 4 -> 5
    //          ^         |
    //          |_________|
    //
    // Cycle: 5 -> 3

    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    // Create cycle:
    head->next->next->next->next->next =
        head->next->next;

    cout << "Cycle Present: ";

    if (hasCycle(head))
        cout << "Yes\n";
    else
        cout << "No\n";

    return 0;
}

/*
INPUT:

1 -> 2 -> 3 -> 4 -> 5
          ^         |
          |_________|

5 points back to 3.

OUTPUT:

Cycle Present: Yes


PATTERN:
Slow + Fast Pointer
Floyd's Cycle Detection


CORE IDEA:

slow = 1 step
fast = 2 steps

CASE 1: NO CYCLE

1 -> 2 -> 3 -> 4 -> 5 -> NULL

fast eventually reaches NULL.
Therefore cycle nahi hai.


CASE 2: CYCLE

1 -> 2 -> 3 -> 4 -> 5
          ^         |
          |_________|
          
Dono cycle ke andar enter karte hain.

fast ki speed slow se zyada hai,
isliye fast eventually slow ko catch karega.

slow == fast
=> cycle exists.


IMPORTANT:
slow == fast means POINTERS same NODE par hain.

Hum:
slow->data == fast->data

compare nahi kar rahe.


TIME COMPLEXITY:
O(n)

SPACE COMPLEXITY:
O(1)


WHY O(1) SPACE?

Humne HashSet / vector / map use nahi kiya.
Sirf slow aur fast pointers use kiye.


ALGORITHM:

1. slow = head
2. fast = head
3. slow ko 1 step move karo
4. fast ko 2 steps move karo
5. Agar slow == fast -> cycle
6. Agar fast NULL ho gaya -> no cycle
*/