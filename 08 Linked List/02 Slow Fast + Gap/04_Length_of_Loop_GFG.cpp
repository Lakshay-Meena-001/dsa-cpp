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

// Returns the length of the cycle. If no cycle exists, returns 0.

int lengthOfLoop(Node *head)
{
    Node *slow = head;
    Node *fast = head;

    // PHASE 1: DETECT CYCLE

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;       // 1 step
        fast = fast->next->next; // 2 steps

        if (slow == fast)
        {
            // Cycle found. Ab slow aur fast same cycle ke, kisi node par mil gaye hain.

            // PHASE 2: COUNT CYCLE LENGTH

            int count = 1;

            // Meeting node ko already count kar liya.
            Node *current = slow->next;

            // Cycle complete karke wapas
            // meeting point par aane tak count karo.
            while (current != slow)
            {
                count++;
                current = current->next;
            }

            return count;
        }
    }

    // fast NULL tak pahunch gaya,
    // therefore cycle exist nahi karti.
    return 0;
}

int main()
{
    /*
        Linked List:

        1 -> 2 -> 3 -> 4 -> 5
                  ^         |
                  |_________|

        Cycle:
        3 -> 4 -> 5 -> 3

        Cycle length = 3
    */

    Node *head = new Node(1);

    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    // Create cycle:
    // 5 -> 3
    head->next->next->next->next->next =
        head->next->next;

    int length = lengthOfLoop(head);

    cout << "Length of Loop: " << length << endl;

    return 0;
}

/*
INPUT:

1 -> 2 -> 3 -> 4 -> 5
          ^         |
          |_________|

Cycle:
3 -> 4 -> 5 -> 3


OUTPUT:

Length of Loop: 3


PATTERN:
Slow + Fast Pointer
+
Cycle Detection
+
Cycle Traversal


PHASE 1:
Floyd's Cycle Detection

slow = 1 step
fast = 2 steps

If:
slow == fast

then cycle exists.


PHASE 2:
Meeting point se cycle length count karte hain.

Example:

3 -> 4 -> 5 -> 3

Agar meeting point = 4:

4 -> 5 -> 3 -> 4

count:
4 = 1
5 = 2
3 = 3

Again 4 mil gaya.
Therefore cycle length = 3.


WHY MEETING POINT SE COUNT KAR SAKTE HAIN?

Meeting point guaranteed cycle ke andar hai.

Cycle ke kisi bhi node se start karke
ek complete round lagane par
same node par wapas aayenge.

Total visited nodes = cycle length.


TIME COMPLEXITY:
O(n)

Cycle detection = O(n)
Cycle counting = O(n)

Overall = O(n)


SPACE COMPLEXITY:
O(1)

Only slow, fast and current pointers use hue hain.


NO CYCLE:
Return 0.


IMPORTANT:
Cycle length nikalne ke liye cycle ENTRY
find karna necessary nahi hai.

Meeting point hi sufficient hai.
*/