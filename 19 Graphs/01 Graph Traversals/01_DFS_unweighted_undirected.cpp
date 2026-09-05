#include <bits/stdc++.h>

using namespace std;

void dfs(int node,const vector<vector<int>> &adj, vector<bool> &visited)
{
    // ark node as visited
    visited[node] = true;

    // process node
    cout << node << " ";

    // visit all unvisited Neighbours
    for (int neighbour : adj[node])
    {
        if (!visited[neighbour])
        {
            dfs(neighbour, adj, visited);
        }
    }
}

void dfsTraversal(const vector<vector<int>> &adj)
{
    int n = adj.size();
    vector<bool> visited(n, false);

    // Visit every connected component
    for (int node = 0; node < n; node++)
    {
        if (!visited[node])
        {
            dfs(node, adj, visited);
        }
    }
    cout << endl;
}

int main()
{
    // Title: DFS Traversal Undirected Unweighted Graph
    int n = 7;

    vector<vector<int>> edges =
        {
            {0, 1},
            {0, 2},
            {1, 3},
            {2, 3},
            {4, 5},
            {5, 6}};

    // Build Undirected Adjacency List

    vector<vector<int>> adj(n);

    for (auto edge : edges)
    {
        int u = edge[0];
        int v = edge[1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // DFS Traversal

    cout << "DFS Traversal : ";

    dfsTraversal(adj);

    return 0;
}