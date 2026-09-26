#include <iostream>
#include <unordered_map>
using namespace std;

class LRUCache
{
private:
    struct Node
    {
        int key;
        int value;

        Node *prev;
        Node *next;

        Node(int k, int v)
        {
            key = k;
            value = v;
            prev = NULL;
            next = NULL;
        }
    };

    unordered_map<int, Node *> mp;

    int capacity;

    // Dummy nodes
    Node *head;
    Node *tail;

    // Remove a node from DLL
    void deleteNode(Node *node)
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    // Insert node immediately after dummy head
    void insertAtHead(Node *node)
    {
        node->next = head->next;
        node->prev = head;

        head->next->prev = node;
        head->next = node;
    }

public:
    // Constructor
    LRUCache(int cap)
    {
        capacity = cap;

        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        head->next = tail;
        tail->prev = head;
    }

    int get(int key)
    {
        // Key doesn't exist
        if (mp.find(key) == mp.end())
        {
            return -1;
        }

        // Get node from HashMap
        Node *node = mp[key];

        // This node was just used,
        // so make it most recently used
        deleteNode(node);
        insertAtHead(node);

        return node->value;
    }

    void put(int key, int value)
    {
        // Case 1:
        // Key already exists
        if (mp.find(key) != mp.end())
        {
            Node *node = mp[key];

            // Update value
            node->value = value;

            // Make it most recently used
            deleteNode(node);
            insertAtHead(node);

            return;
        }

        // Case 2:
        // New key + cache is full
        if (mp.size() == capacity)
        {
            // Least Recently Used node
            Node *lru = tail->prev;

            // Remove from DLL
            deleteNode(lru);

            // Remove from HashMap
            mp.erase(lru->key);

            // Free memory
            delete lru;
        }

        // Create new node
        Node *newNode = new Node(key, value);

        // Insert at front
        insertAtHead(newNode);

        // Add to HashMap
        mp[key] = newNode;
    }

    // Display cache from MRU → LRU
    void display()
    {
        Node *curr = head->next;

        cout << "MRU -> ";

        while (curr != tail)
        {
            cout << "[" << curr->key
                 << ":" << curr->value << "] ";

            curr = curr->next;
        }

        cout << "<- LRU" << endl;
    }

    // Destructor
    ~LRUCache()
    {
        Node *curr = head;

        while (curr != NULL)
        {
            Node *nextNode = curr->next;

            delete curr;

            curr = nextNode;
        }
    }
};

int main()
{
    LRUCache cache(2);

    cout << "put(1, 10)" << endl;
    cache.put(1, 10);
    cache.display();

    cout << "\nput(2, 20)" << endl;
    cache.put(2, 20);
    cache.display();

    cout << "\nget(1)" << endl;
    cout << "Value = " << cache.get(1) << endl;
    cache.display();

    cout << "\nput(3, 30)" << endl;
    cache.put(3, 30);
    cache.display();

    cout << "\nget(2)" << endl;
    cout << "Value = " << cache.get(2) << endl;

    cout << "\nget(3)" << endl;
    cout << "Value = " << cache.get(3) << endl;
    cache.display();

    cout << "\nput(4, 40)" << endl;
    cache.put(4, 40);
    cache.display();

    return 0;
}