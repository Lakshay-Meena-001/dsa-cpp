/*
------------------------------------------------------------

Problem : 01_Number_of_Provinces_LC_547

Pattern
-------
Disjoint Set Union (DSU)
+
Connected Components

Time Complexity
---------------
O(N² × α(N))
≈ O(N²)

Space Complexity
----------------
O(N)

------------------------------------------------------------
*/

#include <iostream>
#include <vector>
#include <set>

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
        parent.resize(n);
        size.resize(n, 1);

        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }

    // Finds Ultimate Parent/Leader of node
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

        // Already belongs to same component

        if (leaderU == leaderV)
        {
            return;
        }

        // Attach smaller tree below larger tree

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
    }

    // Counts unique connected components

    int countComponents()
    {
        set<int> uniqueLeaders;

        for (int node = 0; node < parent.size(); node++)
        {
            uniqueLeaders.insert(findParent(node));
        }

        return uniqueLeaders.size();
    }
};

// Returns total number of provinces.

int numberOfProvinces(vector<vector<int>> &isConnected)
{
    int numberOfCities = isConnected.size();

    DisjointSet ds(numberOfCities);

    // Traverse only Upper Triangle
    // Since matrix is symmetric.

    for (int i = 0; i < numberOfCities; i++)
    {
        for (int j = i + 1; j < numberOfCities; j++)
        {
            if (isConnected[i][j] == 1)
            {
                ds.unionBySize(i, j);
            }
        }
    }

    return ds.countComponents();
}

// Main

int main()
{
    vector<vector<int>> isConnected =
        {
            {1, 1, 0},
            {1, 1, 0},
            {0, 0, 1}};

    cout << "Number of Provinces = ";

    cout << numberOfProvinces(isConnected);

    return 0;
}