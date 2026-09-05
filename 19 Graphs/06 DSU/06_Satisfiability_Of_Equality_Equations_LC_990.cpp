/*
------------------------------------------------------------

Problem : Satisfiability_Of_Equality_Equations_LC_990

Pattern
-------
Disjoint Set Union (DSU)
+
Equality Constraints
+
Character Grouping

Time Complexity
---------------
O(N × α(26))
≈ O(N)

Space Complexity
----------------
O(26)

------------------------------------------------------------
*/

#include <iostream>
#include <vector>
#include <string>

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
    }
};

// Returns true if all equations can be satisfied.

bool equationsPossible(vector<string> &equations)
{
    // Only lowercase letters
    // a -> 0
    // b -> 1
    // ...
    // z -> 25

    DisjointSet ds(26);

    //--------------------------------------------------
    // Pass 1
    // Merge all equal variables
    //--------------------------------------------------

    for (string equation : equations)
    {
        if (equation[1] == '=')
        {
            int u = equation[0] - 'a';
            int v = equation[3] - 'a';

            ds.unionBySize(u, v);
        }
    }

    //--------------------------------------------------
    // Pass 2
    // Check all inequalities
    //--------------------------------------------------

    for (string equation : equations)
    {
        if (equation[1] == '!')
        {
            int u = equation[0] - 'a';
            int v = equation[3] - 'a';

            if (ds.findParent(u) == ds.findParent(v))
            {
                return false;
            }
        }
    }

    return true;
}

// Driver

int main()
{
    vector<string> equations =
        {
            "a==b",
            "b==c",
            "a!=c"};

    if (equationsPossible(equations))
    {
        cout << "All equations are possible.";
    }
    else
    {
        cout << "Equations cannot be satisfied.";
    }

    return 0;
}