#include <bits/stdc++.h>

using namespace std;

int main()
{
    // Title: Graph conversion -> edge List to Adjacency list

    int n = 4;

    vector<vector<int>> unweightedEdges = {
        {0, 1}, {0, 2}, {1, 2}, {2, 3}
    };

    // Un-directed + Un-weighted Graph

    vector<vector<int>> undirectedAdj(n);

    for (const auto &edge : unweightedEdges)
    {
        int u = edge[0];
        int v = edge[1];

        undirectedAdj[u].push_back(v);
        undirectedAdj[v].push_back(u);
    }

    // Directed + Un-weighted Graph

    vector<vector<int>> directedAdj(n);

    for (const auto &edge : unweightedEdges)
    {
        int u = edge[0];
        int v = edge[1];

        directedAdj[u].push_back(v);
    }

    // undirected + Weighted
    // pair = {Neighbour, Weight}

    vector<vector<int>> weightedEdges = {
        {0, 1, 5},
        {0, 2, 2},
        {1, 3, 8},
        {2, 3, 1}};

    vector<vector<pair<int, int>>> weightedUndirectedAdj(n);

    for (const auto &edge : weightedEdges)
    {
        int u = edge[0];
        int v = edge[1];
        int wt = edge[2];

        weightedUndirectedAdj[u].push_back({v, wt});
        weightedUndirectedAdj[v].push_back({u, wt});
    }

    // directed + Weighted
    // pair = {Neighbour, Weight}

    vector<vector<int>> weightedEdges = {
        {0, 1, 5},
        {0, 2, 2},
        {1, 3, 8},
        {2, 3, 1}};

    vector<vector<pair<int, int>>> weightedDirectedAdj(n);

    for (const auto &edge : weightedEdges)
    {
        int u = edge[0];
        int v = edge[1];
        int wt = edge[2];

        weightedDirectedAdj[u].push_back({v, wt});
    }

    return 0;
}
