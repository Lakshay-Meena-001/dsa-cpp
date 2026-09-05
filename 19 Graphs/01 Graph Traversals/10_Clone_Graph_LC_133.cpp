#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// LeetCode 133 - Clone Graph
// Approach : DFS + Hash Map
// Time Complexity  : O(V + E)
// Space Complexity : O(V)


// Graph Node

class Node
{
public:
    int val;
    vector<Node*> neighbors;

    Node()
    {
        val = 0;
    }

    Node(int value)
    {
        val = value;
    }
};


// DFS Helper

Node* dfs(Node* node, unordered_map<Node*, Node*> &cloned)
{
    if (node == nullptr)
    {
        return nullptr;
    }

    // Already Cloned
    if (cloned.count(node))
    {
        return cloned[node];
    }

    // Create Clone
    Node* copy = new Node(node->val);

    cloned[node] = copy;

    // Clone Neighbours
    for (Node* neighbour : node->neighbors)
    {
        copy->neighbors.push_back(
            dfs(neighbour, cloned)
        );
    }

    return copy;
}


// Clone Graph

Node* cloneGraph(Node* node)
{
    if (node == nullptr)
    {
        return nullptr;
    }

    unordered_map<Node*, Node*> cloned;

    return dfs(node, cloned);
}


// Print Graph (DFS)

void printGraph(Node* node,unordered_map<Node*, bool> &visited)
{
    if (node == nullptr || visited[node])
    {
        return;
    }

    visited[node] = true;

    cout << "Node " << node->val << " -> ";

    for (Node* neighbour : node->neighbors)
    {
        cout << neighbour->val << " ";
    }

    cout << endl;

    for (Node* neighbour : node->neighbors)
    {
        printGraph(neighbour, visited);
    }
}


// Driver Code

int main()
{

    // Create Graph
    //
    //      1 ----- 2
    //      |       |
    //      |       |
    //      4 ----- 3
    

    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);

    node1->neighbors = {node2, node4};
    node2->neighbors = {node1, node3};
    node3->neighbors = {node2, node4};
    node4->neighbors = {node1, node3};

    // Original Graph

    cout << "Original Graph\n";

    unordered_map<Node*, bool> visited1;

    printGraph(node1, visited1);

    // Clone Graph

    Node* clonedGraph = cloneGraph(node1);

    // Cloned Graph

    cout << "\nCloned Graph\n";

    unordered_map<Node*, bool> visited2;

    printGraph(clonedGraph, visited2);

    return 0;
}