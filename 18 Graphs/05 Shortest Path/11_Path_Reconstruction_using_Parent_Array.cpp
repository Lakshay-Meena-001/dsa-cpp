/*
------------------------------------------------------------

Dijkstra Algorithm
+
Shortest Path Reconstruction

Pattern
-------
Weighted Graph
+
Greedy
+
Priority Queue
+
Relaxation
+
Parent Array

Works For
---------
✔ Positive Weights
✔ Zero Weights

Does NOT Work
-------------
✘ Negative Weights

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
#include <algorithm>
#include <climits>

using namespace std;

// Dijkstra + Parent Array

void dijkstra(int V, vector<vector<pair<int, int>>> &adj, int source, vector<int> &dist, vector<int> &parent)
{
    // Initialize

    dist.assign(V, INT_MAX);
    parent.resize(V);

    for (int i = 0; i < V; i++)
    {
        parent[i] = i;
    }

    // Min Heap
    //
    // (distance,node)

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[source] = 0;

    pq.push({0, source});

    // Dijkstra

    while (!pq.empty())
    {
        int currentDistance = pq.top().first;
        int currentNode = pq.top().second;

        pq.pop();

        // Ignore outdated entry

        if (currentDistance > dist[currentNode])
        {
            continue;
        }

        // Relax all neighbours

        for (auto edge : adj[currentNode])
        {
            int neighbour = edge.first;
            int weight = edge.second;

            if (dist[currentNode] + weight < dist[neighbour])
            {
                // Update shortest distance

                dist[neighbour] = dist[currentNode] + weight;

                // Store parent

                parent[neighbour] = currentNode;

                // Push updated answer

                pq.push({dist[neighbour], neighbour});
            }
        }
    }
}

// Returns actual shortest path

vector<int> getPath(int source, int destination, vector<int> &parent, vector<int> &dist)
{
    vector<int> path;

    // Destination unreachable

    if (dist[destination] == INT_MAX)
     {   return path;}

    // Follow parent chain backwards

    int node = destination;

    while (parent[node] != node)
    {
        path.push_back(node);

        node = parent[node];
    }

    path.push_back(source);

    // Reverse path

    reverse(path.begin(), path.end());

    return path;
}

// Main Function

int main()
{
    int V = 5;

    vector<vector<pair<int, int>>> adj(V);

    auto addEdge = [&](int u, int v, int w)
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

    int destination = 3;

    vector<int> dist;
    vector<int> parent;

    // Run Dijkstra

    dijkstra(V, adj, source, dist, parent);

    // Print Distance

    cout << "Shortest Distance = ";

    cout << dist[destination] << endl;

    // Reconstruct Path

    vector<int> path = getPath(source, destination, parent, dist);

    cout << "Shortest Path : ";

    for (int node : path)
    {
        cout << node << " ";
    }

    cout << endl;

    // Print Parent Array

    cout << "\nParent Array\n";

    for (int i = 0; i < V; i++)
    {
        cout << "Parent[" << i << "] = "
             << parent[i]
             << endl;
    }

    return 0;
}