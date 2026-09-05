#include <bits/stdc++.h>

using namespace std;

void dfsIterative(int source, const vector<vector<int>> &adj, vector<bool> &visited)
{
    stack<int> st;

    // Initial State
    st.push(source);

    while (!st.empty())
    {
        int node = st.top();
        st.pop();

        // skip it already visited
        if (visited[node])
        {
            continue;
        }

        // visit current node
        visited[node] = true;

        // process the node
        cout << node << " ";

        // push neighbour in reverse order so traversal matches the dfs
        for (int i = adj[node].size() - 1; i >= 0; i--)
        {
            int neighbour = adj[node][i];

            if (!visited[neighbour])
            {
                st.push(neighbour);
            }
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
            dfsIterative(node, adj, visited);
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