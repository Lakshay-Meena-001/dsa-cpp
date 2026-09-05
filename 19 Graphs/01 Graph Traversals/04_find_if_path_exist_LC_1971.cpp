#include <iostream>
#include <vector>
using namespace std;

// LeetCode 1971 - Find if Path Exists in Graph
// Approach : DFS (Recursive)
// Time Complexity  : O(V + E)
// Space Complexity : O(V)

// DFS Helper

void dfs(int node, const vector<vector<int>> &adj, vector<bool> &visited)
{
    visited[node] = true;

    for (int neighbour : adj[node])
    {
        if (!visited[neighbour])
        {
            dfs(neighbour, adj, visited);
        }
    }
}

// Returns true if path exists from source to destination

bool validPath(int n, const vector<vector<int>> &edges, int source, int destination)
{

    // Build Adjacency List

    vector<vector<int>> adj(n);

    for (auto edge : edges)
    {
        int u = edge[0];
        int v = edge[1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // DFS Traversal

    vector<bool> visited(n, false);

    dfs(source, adj, visited);

    return visited[destination];
}

// Driver Code

int main()
{
    int n = 6;

    vector<vector<int>> edges =
        {
            {0, 1},
            {0, 2},
            {3, 5},
            {5, 4},
            {4, 3}};

    int source = 0;
    int destination = 5;

    if (validPath(n, edges, source, destination))
    {
        cout << "Path Exists" << endl;
    }
    else
    {
        cout << "Path Does Not Exist" << endl;
    }

    return 0;
}