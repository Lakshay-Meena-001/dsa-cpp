/*
------------------------------------------------------------

Problem : Graph_Valid_Tree_LC_261

Pattern
-------
Disjoint Set Union (DSU)
+
Cycle Detection
+
Connected Components

Time Complexity
---------------
O(E × α(N))
≈ O(E)

Space Complexity
----------------
O(N)

------------------------------------------------------------
*/

#include <iostream>
#include <vector>

using namespace std;

class DisjointSet
{
private:
    vector<int> parent;
    vector<int> size;
    int components;

public:
    // Constructor

    DisjointSet(int n)
    {
        parent.resize(n);
        size.resize(n, 1);

        components = n;

        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }

    // Find Ultimate Parent
    // Path Compression

    int findParent(int node)
    {
        if (parent[node] == node)
        {
            return node;
        }

        return parent[node] = findParent(parent[node]);
    }

    // Returns false if Cycle detected

    bool unionBySize(int u, int v)
    {
        int leaderU = findParent(u);
        int leaderV = findParent(v);

        // Cycle

        if (leaderU == leaderV)
        {
            return false;
        }

        // Union By Size

        if (size[leaderU] < size[leaderV])
        {
            parent[leaderU] = leaderV;
            size[leaderV] += size[leaderU];
        }
        else
        {
            parent[leaderV] = leaderU;
            size[leaderU] += size[leaderV];
        }

        components--;

        return true;
    }

    int getComponents()
    {
        return components;
    }
};

// Returns true if graph is a valid tree

bool isValidTree(int numberOfNodes,
                 vector<vector<int>> &edges)
{
    // Tree must have exactly (N-1) edges

    if (edges.size() != numberOfNodes - 1)
    {
        return false;
    }

    DisjointSet ds(numberOfNodes);

    for (auto edge : edges)
    {
        int u = edge[0];
        int v = edge[1];

        // Cycle Found

        if (!ds.unionBySize(u, v))
        {
            return false;
        }
    }

    // Must have exactly one component

    return ds.getComponents() == 1;
}

// Driver

int main()
{
    int numberOfNodes = 5;

    vector<vector<int>> edges =
        {
            {0, 1},
            {0, 2},
            {0, 3},
            {1, 4}};

    if (isValidTree(numberOfNodes, edges))
    {
        cout << "Valid Tree";
    }
    else
    {
        cout << "Not a Valid Tree";
    }

    return 0;
}