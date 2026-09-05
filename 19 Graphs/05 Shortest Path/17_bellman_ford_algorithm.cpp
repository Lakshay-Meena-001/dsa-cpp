/*
------------------------------------------------------------

Algorithm : Bellman_Ford

Pattern
-------
Single Source Shortest Path
+
Weighted Graph
+
Negative Edge
+
Edge Relaxation

Time Complexity
---------------
O(V * E)

Space Complexity
----------------
O(V)

------------------------------------------------------------
*/

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Edge Representation

struct Edge
{
    int source;
    int destination;
    int weight;
};

// Returns shortest distance from source.
// Also detects negative weight cycle.

vector<int> bellmanFord(int V, vector<Edge> &edges, int source)
{
    // Distance array.

    vector<int> distance(V, INT_MAX);

    distance[source] = 0;

    // Relax all edges V-1 times.

    for (int pass = 1; pass <= V - 1; pass++)
    {
        bool updated = false;

        for (auto edge : edges)
        {
            int u = edge.source;
            int v = edge.destination;
            int weight = edge.weight;

            if (distance[u] != INT_MAX && distance[u] + weight < distance[v])
            {
                distance[v] = distance[u] + weight;

                updated = true;
            }
        }

        // No update means answer is finalized.

        if (!updated)
        {
            break;
        }
    }

    // Detect negative weight cycle.

    for (auto edge : edges)
    {
        int u = edge.source;
        int v = edge.destination;
        int weight = edge.weight;

        if (distance[u] != INT_MAX && distance[u] + weight < distance[v])
        {
            cout << "Negative Weight Cycle Detected\n";

            return {};
        }
    }

    return distance;
}

// Main

int main()
{
    int V = 5;

    vector<Edge> edges =
        {
            {0, 1, 6},
            {0, 2, 7},
            {1, 2, 8},
            {1, 3, 5},
            {1, 4, -4},
            {2, 3, -3},
            {2, 4, 9},
            {3, 1, -2},
            {4, 3, 7},
            {4, 0, 2}};

    int source = 0;

    vector<int> distance = bellmanFord(V, edges, source);

    if (distance.empty())
    {
        return 0;
    }

    cout << "Shortest Distance\n\n";

    for (int node = 0; node < V; node++)
    {
        cout << node << " -> ";

        if (distance[node] == INT_MAX)
        {
            cout << "INF";
        }
        else
        {
            cout << distance[node];
        }

        cout << endl;
    }

    return 0;
}