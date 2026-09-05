/*
------------------------------------------------------------

Dijkstra Algorithm

Pattern
-------
Weighted Graph
+
Greedy
+
Priority Queue
+
Relaxation

Works For
---------
✔ Positive Weights
✔ Zero Weights

Does NOT Work
-------------
✘ Negative Weight Edges

Time Complexity
---------------
O((V + E) log V)

Space Complexity
----------------
O(V + E)

------------------------------------------------------------
*/

#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// Returns shortest distance from source

vector<int> dijkstra(int V, vector<vector<pair<int, int>>> &adj, int source)
{
    // Distance Array

    vector<int> dist(V, INT_MAX);

    // Parent Array
    // (Useful for path reconstruction later)

    vector<int> parent(V);

    for (int i = 0; i < V; i++)
    {
        parent[i] = i;
    }

    // Min Heap
    // (distance,node)

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // Source Initialization

    dist[source] = 0;

    pq.push({0, source});

    // Standard Dijkstra

    while (!pq.empty())
    {

        // Smallest distance node

        int currentDistance = pq.top().first;

        int currentNode = pq.top().second;

        pq.pop();

        // Ignore old entry

        if (currentDistance > dist[currentNode])
        {
            continue;
        }

        // Relax all neighbours

        for (auto edge : adj[currentNode])
        {
            int neighbour = edge.first;

            int weight = edge.second;

            // Relaxation

            if (dist[currentNode] + weight < dist[neighbour])
            {
                dist[neighbour] = dist[currentNode] + weight;

                // Store parent

                parent[neighbour] = currentNode;

                // Push better answer

                pq.push({dist[neighbour], neighbour});
            }
        }
    }

    return dist;
}


int main()
{
    int V = 5;

    vector<vector<pair<int, int>>> adj(V);

    auto addEdge =
        [&](int u, int v, int w)
    {
        adj[u].push_back({v, w});
    };

    // Graph

    addEdge(0, 1, 4);

    addEdge(0, 2, 1);

    addEdge(2, 1, 2);

    addEdge(1, 3, 1);

    addEdge(2, 4, 5);

    addEdge(4, 3, 3);

    int source = 0;

    vector<int> dist =
        dijkstra(V, adj, source);

    cout << "Shortest Distance\n\n";

    for (int i = 0; i < V; i++)
    {
        cout << i << " -> ";

        if (dist[i] == INT_MAX)
            cout << "INF";
        else
            cout << dist[i];

        cout << endl;
    }

    return 0;
}