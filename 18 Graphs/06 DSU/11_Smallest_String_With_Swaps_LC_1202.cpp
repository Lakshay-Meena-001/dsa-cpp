/*
------------------------------------------------------------

Problem : Smallest_String_With_Swaps (LC 1202)

Pattern
-------
Disjoint Set Union (DSU)
+
Connected Components
+
Sorting
+
String Reconstruction

Time Complexity
---------------
O((N + P) * α(N) + N log N)

N = Length of String
P = Number of Pairs

Space Complexity
----------------
O(N)

------------------------------------------------------------
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class DisjointSet
{
private:
    vector<int> parent;
    vector<int> size;

public:
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

//------------------------------------------------------------

string smallestStringWithSwaps(string s, vector<vector<int>> &pairs)
{
    int n = s.size();

    DisjointSet ds(n);

    // Step 1
    // Merge all indices

    for (auto pair : pairs)
    {
        ds.unionBySize(pair[0], pair[1]);
    }

    // Step 2
    // Leader -> Indices

    unordered_map<int, vector<int>> groups;

    for (int index = 0; index < n; index++)
    {
        int leader = ds.findParent(index);

        groups[leader].push_back(index);
    }

    // Step 3
    // Build Answer

    string answer = s;

    for (auto group : groups)
    {
        vector<int> indices = group.second;

        vector<char> characters;

        // Collect Characters

        for (int index : indices)
        {
            characters.push_back(s[index]);
        }

        // Sort Characters

        sort(characters.begin(), characters.end());

        // Smallest Character
        // -> Smallest Index

        for (int i = 0; i < indices.size(); i++)
        {
            answer[indices[i]] = characters[i];
        }
    }

    return answer;
}

//------------------------------------------------------------

int main()
{
    string s = "dcab";

    vector<vector<int>> pairs =
        {
            {0, 3},
            {1, 2}};

    cout << smallestStringWithSwaps(
        s,
        pairs);

    return 0;
}