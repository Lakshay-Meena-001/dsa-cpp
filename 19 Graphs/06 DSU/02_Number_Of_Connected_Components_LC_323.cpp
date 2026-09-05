/*
------------------------------------------------------------

Problem : Number_Of_Connected_Components_LC_323

Pattern
-------
Disjoint Set Union (DSU)
+
Connected Components
+
Edge List

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

    // Union By Size

    void unionBySize(int u, int v)
    {
        int leaderU = findParent(u);
        int leaderV = findParent(v);

        // Already in same component

        if (leaderU == leaderV)
        {
            return;
        }

        // Merge smaller component into larger component

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

        // Two components became one

        components--;
    }

    int getComponents()
    {
        return components;
    }
};

// Returns total connected components

int countConnectedComponents(int numberOfNodes,vector<vector<int>> &edges)
{
    DisjointSet ds(numberOfNodes);

    // Process every edge

    for (auto edge : edges)
    {
        int u = edge[0];
        int v = edge[1];

        ds.unionBySize(u, v);
    }

    return ds.getComponents();
}

// Driver

int main()
{
    int numberOfNodes = 5;

    vector<vector<int>> edges =
        {
            {0, 1},
            {1, 2},
            {3, 4}};

    cout << "Connected Components = ";

    cout << countConnectedComponents(numberOfNodes, edges);

    return 0;
}