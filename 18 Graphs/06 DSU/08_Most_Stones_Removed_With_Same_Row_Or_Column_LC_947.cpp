/*
------------------------------------------------------------

Problem : Most_Stones_Removed_With_Same_Row_Or_Column_LC_947

Pattern
-------
Disjoint Set Union (DSU)
+
Connected Components
+
Hidden Graph

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

// Returns maximum stones that can be removed.

int removeStones(vector<vector<int>> &stones)
{
    int numberOfStones = stones.size();

    DisjointSet ds(numberOfStones);

    //---------------------------------------------------
    // Compare every pair of stones
    //---------------------------------------------------

    for (int i = 0; i < numberOfStones; i++)
    {
        for (int j = i + 1; j < numberOfStones; j++)
        {
            int row1 = stones[i][0];
            int col1 = stones[i][1];

            int row2 = stones[j][0];
            int col2 = stones[j][1];

            // Same row OR Same column

            if (row1 == row2 || col1 == col2)
            {
                ds.unionBySize(i, j);
            }
        }
    }

    //---------------------------------------------------
    // Answer
    //---------------------------------------------------

    return numberOfStones - ds.getComponents();
}

// Driver

int main()
{
    vector<vector<int>> stones =
    {
        {0,0},
        {0,1},
        {1,0},
        {2,2}
    };

    cout << "Maximum Stones Removed = ";

    cout << removeStones(stones);

    return 0;
}