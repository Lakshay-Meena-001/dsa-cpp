#include <iostream>
#include <unordered_map>
using namespace std;

// Node structure
struct Node
{
    int val;
    Node *next;
    Node *random;

    Node(int val)
    {
        this->val = val;
        next = NULL;
        random = NULL;
    }
};

// APPROACH 1: HASHMAP
// Time  : O(n)
// Space : O(n)

Node *copyRandomListHashMap(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }

    unordered_map<Node *, Node *> mp;

    // Step 1: Create copy of every node
    Node *curr = head;

    while (curr != NULL)
    {
        // jo current node(address not value, Node* ->Node*) hai uski maping new node k sath
        mp[curr] = new Node(curr->val);
        curr = curr->next;
    }

    // Step 2: Connect next and random pointers
    curr = head;

    while (curr != NULL)
    {
        // Connect next
        // A'->next = B'
        mp[curr]->next = mp[curr->next];

        // Connect random
        if (curr->random != NULL)
        {
            mp[curr]->random = mp[curr->random];
        }
        else
        {
            mp[curr]->random = NULL;
        }

        curr = curr->next;
    }

    return mp[head];
}

// APPROACH 2: INTERWEAVING
// Time  : O(n)
// Space : O(1) extra space

Node *copyRandomListInterweaving(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }

    // Step 1: Create copy nodes and place them immediately after their original nodes.

    // Original:
    // A -> B -> C

    // Becomes:
    // A -> A' -> B -> B' -> C -> C'

    Node *curr = head;

    while (curr != NULL)
    {
        Node *copy = new Node(curr->val);

        // to avoid list
        copy->next = curr->next;
        curr->next = copy;

        curr = copy->next;
    }

    // Step 2: Set random pointers

    // Since:
    // original->next = copy

    // Therefore:
    // original->random->next = copy of random node

    curr = head;

    while (curr != NULL)
    {
        Node *copy = curr->next;

        if (curr->random != NULL)
        {
            copy->random = curr->random->next;
        }
        else
        {
            copy->random = NULL;
        }

        curr = copy->next;
    }

    // Step 3: Separate original and copied lists
    
    // A -> A' -> B -> B' -> C -> C'
    
    // Becomes:
    
    // Original: A -> B -> C
    // Copy:     A' -> B' -> C'

    curr = head;

    Node *copyHead = head->next;

    while (curr != NULL)
    {
        Node *copy = curr->next;

        // Restore original list
        curr->next = copy->next;

        // Connect copied list
        if (copy->next != NULL)
            copy->next = copy->next->next;
        else
            copy->next = NULL;

        curr = curr->next;
    }

    return copyHead;
}

// ============================================================
// PRINT LINKED LIST
// ============================================================

void printList(Node *head)
{
    Node *curr = head;

    while (curr != NULL)
    {
        cout << "Node: " << curr->val;

        if (curr->random != NULL)
            cout << ", Random: " << curr->random->val;
        else
            cout << ", Random: NULL";

        cout << endl;

        curr = curr->next;
    }

    cout << endl;
}

// ============================================================
// DELETE LINKED LIST
// ============================================================

void deleteList(Node *head)
{
    while (head != NULL)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
}

// ============================================================
// MAIN
// ============================================================

int main()
{
    // --------------------------------------------------------
    // Create original linked list
    //
    // 1 -> 2 -> 3 -> NULL
    //
    // Random:
    // 1 -> 3
    // 2 -> 1
    // 3 -> 2
    // --------------------------------------------------------

    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);

    head->random = head->next->next;       // 1 -> 3
    head->next->random = head;             // 2 -> 1
    head->next->next->random = head->next; // 3 -> 2

    cout << "Original List:\n";
    printList(head);

    // --------------------------------------------------------
    // APPROACH 1: HASHMAP
    // --------------------------------------------------------

    Node *copy1 = copyRandomListHashMap(head);

    cout << "Copy using HashMap:\n";
    printList(copy1);

    // --------------------------------------------------------
    // APPROACH 2: INTERWEAVING
    // --------------------------------------------------------

    Node *copy2 = copyRandomListInterweaving(head);

    cout << "Copy using Interweaving:\n";
    printList(copy2);

    // --------------------------------------------------------
    // Cleanup
    // --------------------------------------------------------

    deleteList(head);
    deleteList(copy1);
    deleteList(copy2);

    return 0;
}