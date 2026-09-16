#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

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

struct Edge
{
    int u;
    int v;
    int weight;
};

bool compare(Edge &a, Edge &b)
{
    return a.weight < b.weight;
}

int kruskalMST(int V, vector<Edge> &edges)
{
    sort(edges.begin(), edges.end(), compare);

    DSU dsu(V);

    int mstCost = 0;

    for (auto &edge : edges)
    {
        int parentU = dsu.find(edge.u);
        int parentV = dsu.find(edge.v);

        if (parentU == parentV)
        {
            continue;
        }

        dsu.unite(parentU, parentV);

        mstCost += edge.weight;
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

    cout << "MST Cost = " << kruskalMST(4, edges);

    return 0;
}