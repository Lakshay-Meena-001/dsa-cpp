/*
------------------------------------------------------------

problem : Dijkstra Algorithm using Set

Pattern
-------
Weighted Graph
+
Greedy
+
Set
+
Relaxation

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
#include <set>
#include <climits>

using namespace std;

// Dijkstra using Set

vector<int> dijkstra(int V, vector<vector<pair<int, int>>> &adj, int source)
{
    // Distance Array

    vector<int> dist(V, INT_MAX);

    // Parent Array

    vector<int> parent(V);

    for (int i = 0; i < V; i++)
    {
        parent[i] = i;
    }

    // ⭐ Set
    // (distance, node)

    set<pair<int, int>> st;

    // Source Initialization

    dist[source] = 0;

    st.insert({0, source});

    // Dijkstra

    while (!st.empty())
    {
        // ⭐ Smallest distance node

        auto it = st.begin();

        int currentDistance = it->first;
        int currentNode = it->second;

        // ⭐ Remove from set

        st.erase(it);

        // Relax neighbours

        for (auto edge : adj[currentNode])
        {
            int neighbour = edge.first;
            int weight = edge.second;

            // Better path found?

            if (dist[currentNode] + weight < dist[neighbour])
            {
                // ⭐ Old entry remove

                if (dist[neighbour] != INT_MAX)
                {
                    st.erase({dist[neighbour], neighbour});
                }

                // Distance Update

                dist[neighbour] = dist[currentNode] + weight;

                // Parent Update

                parent[neighbour] = currentNode;

                // Insert new pair

                st.insert({dist[neighbour], neighbour});
            }
        }
    }

    return dist;
}

//------------------------------------------------------------

int main()
{
    int V = 5;

    vector<vector<pair<int, int>>> adj(V);

    auto addEdge = [&](int u, int v, int w)
    {
        adj[u].push_back({v, w});
    };

    addEdge(0, 1, 4);
    addEdge(0, 2, 1);
    addEdge(2, 1, 2);
    addEdge(1, 3, 1);
    addEdge(2, 4, 5);
    addEdge(4, 3, 3);

    int source = 0;

    vector<int> dist = dijkstra(V, adj, source);

    cout << "Shortest Distance\n\n";

    for (int i = 0; i < V; i++)
    {
        cout << i << " -> ";

        if (dist[i] == INT_MAX)
        {
            cout << "INF";
        }
        else
        {
            cout << dist[i];
        }

        cout << endl;
    }

    return 0;
}