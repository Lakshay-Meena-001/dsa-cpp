/*
------------------------------------------------------------

Problem : Redundant_Connection_LC_684

Pattern
-------
Disjoint Set Union (DSU)
+
Cycle Detection

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

public:
    // Constructor

    DisjointSet(int n)
    {
        parent.resize(n + 1);
        size.resize(n + 1, 1);

        // Nodes are 1-indexed

        for (int i = 1; i <= n; i++)
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

    // Returns true if Union happened
    // Returns false if both nodes were already connected

    bool unionBySize(int u, int v)
    {
        int leaderU = findParent(u);
        int leaderV = findParent(v);

        // Cycle Found

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

        return true;
    }
};

// Returns redundant edge

vector<int> findRedundantConnection(vector<vector<int>> &edges)
{
    int numberOfNodes = edges.size();

    DisjointSet ds(numberOfNodes);

    for (auto edge : edges)
    {
        int u = edge[0];
        int v = edge[1];

        // If Union fails,
        // this edge creates a cycle.

        if (!ds.unionBySize(u, v))
        {
            return edge;
        }
    }

    return {};
}

// Driver

int main()
{
    vector<vector<int>> edges =
        {
            {1, 2},
            {1, 3},
            {2, 3}};

    vector<int> redundantEdge = findRedundantConnection(edges);

    cout << "Redundant Edge = ";

    cout << "[" << redundantEdge[0]
         << ", "
         << redundantEdge[1]
         << "]";

    return 0;
}