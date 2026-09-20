#include <iostream>
#include <unordered_set>
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

// 1. Length Alignment Method

Node *intersectionUsingLength(Node *headA, Node *headB)
{
    int lenA = 0;
    int lenB = 0;

    // Find length of A
    Node *tempA = headA;

    while (tempA != nullptr)
    {
        lenA++;
        tempA = tempA->next;
    }

    // Find length of B
    Node *tempB = headB;

    while (tempB != nullptr)
    {
        lenB++;
        tempB = tempB->next;
    }

    // Start pointers from heads
    Node *pA = headA;
    Node *pB = headB;

    // Longer list ko difference jitna advance karo

    if (lenA > lenB)
    {
        int diff = lenA - lenB;

        while (diff--)
        {
            pA = pA->next;
        }
    }
    else
    {
        int diff = lenB - lenA;

        while (diff--)
        {
            pB = pB->next;
        }
    }

    // Ab dono same level par hain

    while (pA != pB)
    {
        pA = pA->next;
        pB = pB->next;
    }

    return pA;
}

Node *intersectionUsingHashSet(Node *headA, Node *headB)
{
    unordered_set<Node *> visited;

    // Store every NODE of A
    Node *temp = headA;

    while (temp != nullptr)
    {
        visited.insert(temp);
        temp = temp->next;
    }

    // Traverse B
    temp = headB;

    while (temp != nullptr)
    {
        // Same NODE mila
        if (visited.find(temp) != visited.end())
        {
            return temp;
        }

        temp = temp->next;
    }

    return nullptr;
}

// 3. TWO POINTER SWITCHING

Node *intersectionUsingSwitching(Node *headA, Node *headB)
{
    Node *pA = headA;
    Node *pB = headB;

    // Ye actual linked-list loop nahi hai, Pointers lists ko dobara traverse kar rahe hain, lekin finite path par.
    //Dono same total distance travel karte hain. Isliye: pA → NULL, pB → NULL ek hi point par milenge.
    
    while (pA != pB)
    {
        // A khatam hua → B ke head par switch
        if (pA == nullptr)
        {
            pA = headB;
        }
        else
        {
            pA = pA->next;
        }

        // B khatam hua → A ke head par switch
        if (pB == nullptr)
        {
            pB = headA;
        }
        else
        {
            pB = pB->next;
        }
    }

    return pA;
}

// MAIN

int main()
{
    /*
        Common part create kar rahe hain:

                 7 → 8 → NULL
                ↑
        A ------|
                |
        B -------

        Important:
        7 aur 8 SAME physical nodes hain.
    */

    Node *common1 = new Node(7);
    Node *common2 = new Node(8);

    common1->next = common2;

    // ---------------- LIST A ----------------

    Node *headA = new Node(1);

    headA->next = new Node(2);
    headA->next->next = new Node(3);
    headA->next->next->next = common1;

    // A:
    // 1 → 2 → 3 → 7 → 8

    // ---------------- LIST B ----------------

    Node *headB = new Node(4);

    headB->next = new Node(5);
    headB->next->next = common1;

    // B:
    // 4 → 5 → 7 → 8

    // METHOD 1: LENGTH ALIGNMENT

    Node *ans1 = intersectionUsingLength(headA, headB);

    if (ans1 != nullptr)
    {
        cout << "Length Alignment: " << ans1->data << endl;
    }
    else
    {
        cout << "Length Alignment: No Intersection" << endl;
    }

    // METHOD 2: HASHSET

    Node *ans2 = intersectionUsingHashSet(headA, headB);

    if (ans2 != nullptr)
    {
        cout << "HashSet: " << ans2->data << endl;
    }
    else
    {
        cout << "HashSet: No Intersection" << endl;
    }

    // METHOD 3: TWO POINTER SWITCHING

    Node *ans3 = intersectionUsingSwitching(headA, headB);

    if (ans3 != nullptr)
    {
        cout << "Switching: " << ans3->data << endl;
    }
    else
    {
        cout << "Switching: No Intersection" << endl;
    }

    return 0;
}