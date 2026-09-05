#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

void printShortestPath(int source, int destination, vector<int> &parent, vector<int> &dist)
{
    // Destination unreachable
    if (dist[destination] == -1)
    {
        cout << "\nNo Path Exists!\n";
        return;
    }

    vector<int> path;

    int current = destination;

    // Keep moving to parent until source is reached
    while (current != -1)
    {
        path.push_back(current);
        current = parent[current];
    }

    // Currently path is:
    // Destination -> Source
    // Reverse it.
    reverse(path.begin(), path.end());

    cout << "\nShortest Path : ";

    for (int node : path)
    {
        cout << node << " ";
    }

    cout << endl;
}

// BFS Shortest Path

void shortestPathBFS(int source, vector<vector<int>> &adj)
{
    int n = adj.size();

    // Distance of every node from source.
    // -1 means unreachable.
    vector<int> dist(n, -1);

    // Parent of every node.
    // Used to reconstruct shortest path.
    vector<int> parent(n, -1);

    // Prevent revisiting nodes.
    vector<bool> visited(n, false);

    queue<int> q;

    // Source Initialization

    q.push(source);

    visited[source] = true;

    dist[source] = 0;

    // Standard BFS

    while (!q.empty())
    {
        int current = q.front();
        q.pop();

        // Traverse every neighbour
        for (int neighbour : adj[current])
        {
            // Process only first time discovered nodes
            if (!visited[neighbour])
            {
                visited[neighbour] = true;

                // One edge farther than current node
                dist[neighbour] = dist[current] + 1;

                // Store route information
                parent[neighbour] = current;

                q.push(neighbour);
            }
        }
    }

    // Print Distance Array

    cout << "Distance Array\n";

    for (int i = 0; i < n; i++)
    {
        cout << i << " -> " << dist[i] << endl;
    }

    // Print Parent Array

    cout << "\nParent Array\n";

    for (int i = 0; i < n; i++)
    {
        cout << i << " -> " << parent[i] << endl;
    }

    // Example:
    // Print shortest path from Source to Node 6

    printShortestPath(source, 6, parent, dist);
}

int main()
{
    int n = 7;

    vector<vector<int>> adj(n);

    // Undirected Graph
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