#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void dfs(int node, const vector<vector<int>> &adj, vector<bool> &visited, stack<int> &st)
{
    visited[node] = true;

    for (int neighbour : adj[node])
    {
        if (!visited[neighbour])
        {
            dfs(neighbour, adj, visited, st);
        }
    }

    // Push after all children finish
    st.push(node);
}

int main()
{
    int V = 6;

    vector<vector<int>> adj(V);

    adj[5].push_back(2);
    adj[5].push_back(0);

    adj[4].push_back(0);
    adj[4].push_back(1);

    adj[2].push_back(3);

    adj[3].push_back(1);

    vector<bool> visited(V, false);

    stack<int> st;

    // Handle disconnected graph
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            dfs(i, adj, visited, st);
        }
    }

    cout << "Topological Order : ";

    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}