/*
------------------------------------------------------------

Problem : Network_Delay_Time_LC_743

Pattern
-------
Dijkstra
+
Single Source Shortest Path
+
Weighted Graph

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

// Returns the time required for the signal to reach all nodes.

int networkDelayTime(vector<vector<int>> &times, int n, int source)
{
    // Build adjacency list.
    // pair = (neighbour, weight)

    vector<vector<pair<int, int>>> adj(n + 1);

    for (auto edge : times)
    {
        int u = edge[0];
        int v = edge[1];
        int weight = edge[2];

        adj[u].push_back({v, weight});
    }

    // Distance array.

    vector<int> distance(n + 1, INT_MAX);

    // Min Heap.
    // pair = (distance, node)

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    distance[source] = 0;

    pq.push({0, source});

    // Standard Dijkstra.

    while (!pq.empty())
    {
        int currentDistance = pq.top().first;
        int currentNode = pq.top().second;

        pq.pop();

        // Ignore outdated entry.

        if (currentDistance > distance[currentNode])
        {
            continue;
        }

        // Relax all neighbours.

        for (auto edge : adj[currentNode])
        {
            int neighbour = edge.first;
            int weight = edge.second;

            // Better path found.

            if (distance[currentNode] + weight < distance[neighbour])
            {
                distance[neighbour] = distance[currentNode] + weight;

                pq.push({distance[neighbour],neighbour});
            }
        }
    }

    // Find the maximum distance.

    int answer = 0;

    for (int node = 1; node <= n; node++)
    {
        // Unreachable node.

        if (distance[node] == INT_MAX)
        {
            return -1;
        }

        answer = max(answer, distance[node]);
    }

    return answer;
}

// Main

int main()
{
    vector<vector<int>> times =
        {
            {2, 1, 1},
            {2, 3, 1},
            {3, 4, 1}};

    int n = 4;

    int source = 2;

    cout << "Network Delay Time = ";

    cout << networkDelayTime(times, n, source);

    return 0;
}