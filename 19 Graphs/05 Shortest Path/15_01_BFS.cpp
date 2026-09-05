/*
------------------------------------------------------------

Algorithm : 0-1 BFS

Pattern
-------
Shortest Path
+
Graph
+
Edge Weight = 0 or 1
+
Deque

Time Complexity
---------------
O(V + E)

Space Complexity
----------------
O(V)

------------------------------------------------------------
*/

#include <iostream>
#include <vector>
#include <deque>
#include <climits>

using namespace std;

// Returns shortest distance from source.

vector<int> zeroOneBFS(int V,vector<vector<pair<int, int>>> &adj,int source)
{
    // Distance array.

    vector<int> distance(V, INT_MAX);

    // Deque.

    deque<int> dq;

    distance[source] = 0;

    dq.push_front(source);

    // Standard 0-1 BFS.

    while (!dq.empty())
    {
        int currentNode = dq.front();

        dq.pop_front();

        // Relax neighbours.

        for (auto edge : adj[currentNode])
        {
            int neighbour = edge.first;
            int weight = edge.second;

            if (distance[currentNode] + weight < distance[neighbour])
            {
                distance[neighbour] = distance[currentNode] + weight;

                // Weight = 0

                if (weight == 0)
                {
                    dq.push_front(neighbour);
                }

                // Weight = 1

                else
                {
                    dq.push_back(neighbour);
                }
            }
        }
    }

    return distance;
}

// Main

int main()
{
    int V = 5;

    vector<vector<pair<int, int>>> adj(V);

    auto addEdge =
        [&](int u, int v, int weight)
        {
            adj[u].push_back({v, weight});
        };

    addEdge(0, 1, 0);
    addEdge(0, 2, 1);
    addEdge(1, 3, 1);
    addEdge(2, 3, 0);
    addEdge(3, 4, 1);

    vector<int> distance = zeroOneBFS(V, adj, 0);

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