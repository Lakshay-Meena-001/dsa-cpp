/*
------------------------------------------------------------

Shortest Path in DAG

Pattern
-------
Directed Acyclic Graph
+
Topological Sort
+
Relaxation

Time Complexity
---------------
Topological Sort : O(V + E)

Relaxation       : O(E)

Overall          : O(V + E)

Space Complexity
----------------
O(V + E)

------------------------------------------------------------
*/

#include <iostream>
#include <vector>
#include <stack>
#include <climits>

using namespace std;

// DFS used for Topological Sorting

void topoDFS(int node, vector<vector<pair<int, int>>> &adj, vector<bool> &visited, stack<int> &st)
{
    visited[node] = true;

    for (auto neighbour : adj[node])
    {
        int nextNode = neighbour.first;

        if (!visited[nextNode])
        {
            topoDFS(nextNode, adj, visited, st);
        }
    }

    // Push after visiting all children.
    st.push(node);
}

// DAG Shortest Path

vector<int> shortestPathDAG(int V, vector<vector<pair<int, int>>> &adj, int source)
{
    // Step 1
    // Topological Sort

    vector<bool> visited(V, false);

    stack<int> st;

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            topoDFS(i, adj, visited, st);
        }
    }

    // Step 2
    // Distance Array

    vector<int> dist(V, INT_MAX);

    dist[source] = 0;

    // Step 3
    // Process nodes in Topological Order

    while (!st.empty())
    {
        int current = st.top();

        st.pop();

        // Ignore unreachable nodes.

        if (dist[current] == INT_MAX)
        {
            continue;
        }

        // Relax every outgoing edge.

        for (auto edge : adj[current])
        {
            int neighbour = edge.first;

            int weight = edge.second;

            // Relaxation

            if (dist[current] + weight < dist[neighbour])
            {
                dist[neighbour] = dist[current] + weight;
            }
        }
    }

    return dist;
}

// Driver Main

int main()
{
    int V = 6;

    vector<vector<pair<int, int>>> adj(V);

    // Helper function

    auto addEdge = [&](int u, int v, int w)
    {
        adj[u].push_back({v, w});
    };

    addEdge(0, 1, 2);
    addEdge(0, 2, 4);
    addEdge(1, 3, 7);
    addEdge(2, 3, 1);
    addEdge(2, 4, 3);
    addEdge(3, 5, 2);
    addEdge(4, 5, 5);

    int source = 0;

    vector<int> distance = shortestPathDAG(V, adj, source);

    cout << "Shortest Distance\n\n";

    for (int i = 0; i < V; i++)
    {
        cout << i << " -> ";

        if (distance[i] == INT_MAX)
        {
            cout << "INF";
        }
        else
        {
            cout << distance[i];
        }

        cout << endl;
    }

    return 0;
}