#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Edge Structure
struct Edge
{
    int u;
    int v;
    int wt;
};

// DSU

class DSU
{
    vector<int> parent;
    vector<int> size;

public:
    DSU(int n)
    {
        parent.resize(n);
        size.resize(n, 1);

        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }

    int find(int node)
    {
        if (parent[node] == node)
        {
            return node;
        }

        return parent[node] = find(parent[node]);
    }

    void unite(int u, int v)
    {
        u = find(u);
        v = find(v);

        if (u == v)
        {
            return;
        }

        if (size[u] < size[v])
        {
            swap(u, v);
        }

        parent[v] = u;
        size[u] += size[v];
    }
};

// Sort by Weight

bool compare(Edge &a, Edge &b)
{
    return a.wt < b.wt;
}

// Kruskal

int kruskalMST(int V, vector<Edge> &edges)
{
    sort(edges.begin(), edges.end(), compare);

    DSU dsu(V);

    int mstCost = 0;

    for (auto &edge : edges)
    {
        int u = edge.u;
        int v = edge.v;
        int wt = edge.wt;

        if (dsu.find(u) == dsu.find(v))
        {
            continue;
        }

        dsu.unite(u, v);

        mstCost += wt;
    }

    return mstCost;
}

int main()
{
    vector<Edge> edges =
        {
            {0, 1, 4},
            {0, 2, 2},
            {1, 2, 1},
            {1, 3, 1},
            {2, 3, 3}};

    cout << kruskalMST(4, edges);
}