/*
------------------------------------------------------------

Problem : Regions Cut By Slashes (LC 959)

Pattern
-------
Disjoint Set Union (DSU)
+
Grid Transformation
+
Connected Components

Time Complexity
---------------
O(N² * α(N))

Space Complexity
----------------
O(N²)

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

    int findParent(int node)
    {
        if (parent[node] == node)
        {
            return node;
        }

        return parent[node] = findParent(parent[node]);
    }

    void unionBySize(int u, int v)
    {
        int leaderU = findParent(u);
        int leaderV = findParent(v);

        if (leaderU == leaderV)
        {
            return;
        }

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
    }

    int getComponents()
    {
        return components;
    }
};

int regionsBySlashes(vector<string> &grid)
{
    int rows = grid.size();
    int cols = grid[0].size();

    DisjointSet ds(rows * cols * 4);

    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {
            int base = (row * cols + col) * 4;

            char current = grid[row][col];

            // Internal Connections

            if (current == ' ')
            {
                ds.unionBySize(base + 0, base + 1);
                ds.unionBySize(base + 1, base + 2);
                ds.unionBySize(base + 2, base + 3);
            }
            else if (current == '/')
            {
                ds.unionBySize(base + 0, base + 3);
                ds.unionBySize(base + 1, base + 2);
            }
            else if (current == '\\')
            {
                ds.unionBySize(base + 0, base + 1);
                ds.unionBySize(base + 2, base + 3);
            }

            // Right Neighbour

            if (col + 1 < cols)
            {
                int rightBase = base + 4;

                ds.unionBySize(base + 1, rightBase + 3);
            }

            // Bottom Neighbour

            if (row + 1 < rows)
            {
                int bottomBase = ((row + 1) * cols + col) * 4;

                ds.unionBySize(base + 2, bottomBase + 0);
            }
        }
    }

    return ds.getComponents();
}

int main()
{
    vector<string> grid =
        {
            " /",
            "/ "};

    cout << "Regions = ";

    cout << regionsBySlashes(grid);

    return 0;
}