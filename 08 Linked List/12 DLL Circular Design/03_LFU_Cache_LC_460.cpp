#include <iostream>
#include <unordered_map>

using namespace std;

class LFUCache
{
private:
    // NODE
    struct Node
    {
        int key;
        int value;
        int freq;

        Node *prev;
        Node *next;

        Node(int k, int v)
        {
            key = k;
            value = v;
            freq = 1;

            prev = NULL;
            next = NULL;
        }
    };

    // key -> actual node
    unordered_map<int, Node *> keyTable;

    // frequency -> {dummyHead, dummyTail}
    unordered_map<int, pair<Node *, Node *>> freqTable;

    // Current minimum frequency
    int minFreq;

    int capacity;

    // CREATE DLL FOR A FREQUENCY IF NOT EXISTS
    void createList(int freq)
    {
        if (freqTable.find(freq) != freqTable.end())
        {
            return;
        }

        Node *head = new Node(-1, -1);
        Node *tail = new Node(-1, -1);

        head->next = tail;
        tail->prev = head;

        freqTable[freq] = {head, tail};
    }

    // REMOVE NODE FROM ITS CURRENT DLL
    void removeNode(Node *node)
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    // INSERT NODE AT FRONT OF FREQUENCY DLL
    void insertAtFront(Node *node, int freq)
    {
        createList(freq);

        Node *head = freqTable[freq].first;

        node->next = head->next;
        node->prev = head;

        head->next->prev = node;
        head->next = node;
    }

    // REMOVE LRU NODE FROM A FREQUENCY
    Node *removeLRU(int freq)
    {
        Node *tail = freqTable[freq].second;

        Node *lru = tail->prev;

        removeNode(lru);

        return lru;
    }

    // INCREASE FREQUENCY
    void increaseFrequency(Node *node)
    {
        int oldFreq = node->freq;

        // Remove Node from old frequency list
        removeNode(node);

        // If this was the last node of minimum frequency
        if (oldFreq == minFreq)
        {
            Node *head = freqTable[oldFreq].first;
            Node *tail = freqTable[oldFreq].second;

            if (head->next == tail)
            {
                minFreq++;
            }
        }

        // Increase frequency
        node->freq++;

        // Insert into new frequency list
        insertAtFront(node, node->freq);
    }

public:
    // CONSTRUCTOR
    LFUCache(int capacity)
    {
        this->capacity = capacity;
        minFreq = 0;
    }

    // GET
    int get(int key)
    {
        // Key doesn't exist
        if (keyTable.find(key) == keyTable.end())
        {
            return -1;
        }

        Node *node = keyTable[key];

        // Accessing means frequency increases
        increaseFrequency(node);

        return node->value;
    }

    // PUT
    void put(int key, int value)
    {
        // Capacity 0
        if (capacity == 0)
            return;

        // CASE 1: KEY ALREADY EXISTS
        if (keyTable.find(key) != keyTable.end())
        {
            Node *node = keyTable[key];

            node->value = value;

            increaseFrequency(node);

            return;
        }

        // CASE 2: CACHE IS FULL
        if (keyTable.size() == capacity)
        {
            Node *lru = removeLRU(minFreq);

            keyTable.erase(lru->key);

            delete lru;
        }

        // CASE 3: INSERT NEW NODE
        Node *newNode = new Node(key, value);

        keyTable[key] = newNode;

        minFreq = 1;

        insertAtFront(newNode, 1);
    }

    // DISPLAY — ONLY FOR UNDERSTANDING
    void display()
    {
        cout << "\n----------------------\n";

        for (auto &entry : freqTable)
        {
            int freq = entry.first;

            Node *head = entry.second.first;
            Node *tail = entry.second.second;

            if (head->next == tail)
                continue;

            cout << "Freq " << freq << ": ";

            Node *curr = head->next;

            while (curr != tail)
            {
                cout << curr->key
                     << "(" << curr->freq << ") ";

                curr = curr->next;
            }

            cout << endl;
        }

        cout << "minFreq = " << minFreq << endl;
        cout << "----------------------\n";
    }
};

// MAIN

int main()
{
    LFUCache cache(3);

    cache.put(1, 10);
    cache.put(2, 20);
    cache.put(3, 30);

    cout << "After inserting 1, 2, 3:";
    cache.display();

    cout << "\nget(1) = "
         << cache.get(1) << endl;

    cache.display();

    cout << "\nget(1) = "
         << cache.get(1) << endl;

    cache.display();

    cout << "\nget(2) = "
         << cache.get(2) << endl;

    cache.display();

    cout << "\nput(4, 40)" << endl;

    cache.put(4, 40);

    cache.display();

    cout << "\nget(3) = "
         << cache.get(3) << endl;

    cout << "get(4) = "
         << cache.get(4) << endl;

    return 0;
}