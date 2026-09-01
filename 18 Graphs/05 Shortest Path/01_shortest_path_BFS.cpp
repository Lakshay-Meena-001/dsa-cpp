#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// BFS Shortest Path in Unweighted Graph
// Time Complexity : O(V + E)
// Space Complexity: O(V)

void shortestPathBFS(int source, vector<vector<int>> &adj)
{
    int n = adj.size();

    // Distance array
    // Initially sabhi nodes unreachable hain.
    vector<int> dist(n, -1);

    // Parent array
    // Actual shortest path reconstruct karne ke liye.
    vector<int> parent(n, -1);

    // Visited array
    // Ek node ko sirf ek hi baar process karenge.
    vector<bool> visited(n, false);

    queue<int> q;

    // Source initialize
    q.push(source);
    visited[source] = true;
    dist[source] = 0;

    while (!q.empty())
    {
        int current = q.front();
        q.pop();

        // Current node ke saare neighbours dekho
        for (int neighbour : adj[current])
        {
            // Agar pehli baar mila hai
            if (!visited[neighbour])
            {
                visited[neighbour] = true;

                // Distance update
                dist[neighbour] = dist[current] + 1;

                // Parent update
                parent[neighbour] = current;

                q.push(neighbour);
            }
        }
    }

    cout << "Shortest Distance From Source\n";

    for (int i = 0; i < n; i++)
    {
        cout << i << " -> " << dist[i] << endl;
    }

    cout << "\nParent Array\n";

    for (int i = 0; i < n; i++)
    {
        cout << i << " -> " << parent[i] << endl;
    }
}

// ---------------------------------------------

int main()
{
    int n = 7;

    vector<vector<int>> adj(n);

    auto addEdge = [&](int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    };

    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 3);
    addEdge(1, 4);
    addEdge(2, 5);
    addEdge(4, 6);
    addEdge(5, 6);

    shortestPathBFS(0, adj);

    return 0;
}