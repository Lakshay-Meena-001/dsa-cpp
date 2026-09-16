/*
------------------------------------------------------------

Problem : Number_Of_Operations_To_Make_Network_Connected_LC_1319

Pattern
-------
Disjoint Set Union (DSU)
+
Connected Components
+
Redundant Edges

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

    // Returns true if Union happened
    // Returns false if edge is redundant

    bool unionBySize(int u, int v)
    {
        int leaderU = findParent(u);
        int leaderV = findParent(v);

        // Already Connected

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

// Returns minimum operations required
// to connect the entire network.

int makeConnected(int numberOfComputers, vector<vector<int>> &connections)
{
    // Not enough cables.

    if (connections.size() < numberOfComputers - 1)
    {
        return -1;
    }

    DisjointSet ds(numberOfComputers);

    int extraCables = 0;

    for (auto connection : connections)
    {
        int u = connection[0];
        int v = connection[1];

        // Union failed
        // Extra cable found

        if (!ds.unionBySize(u, v))
        {
            extraCables++;
        }
    }

    int components = ds.getComponents();

    int requiredCables = components - 1;

    if (extraCables >= requiredCables)
    {
        return requiredCables;
    }

    return -1;
}

// Driver

int main()
{
    int numberOfComputers = 6;

    vector<vector<int>> connections =
        {
            {0, 1},
            {0, 2},
            {1, 2},
            {3, 4},
            {2, 5}};

    cout << "Minimum Operations = ";

    cout << makeConnected(numberOfComputers, connections);

    return 0;
}