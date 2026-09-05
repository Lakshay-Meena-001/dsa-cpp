/*
------------------------------------------------------------

Problem : Cheapest_Flights_Within_K_Stops_LC_787

Pattern
-------
Modified Shortest Path
+
State Space Graph
+
BFS + Relaxation

Time Complexity
---------------
O(K * E)

Space Complexity
----------------
O(V)

------------------------------------------------------------
*/

#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// Returns minimum flight cost within K stops.

int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
{

    vector<vector<pair<int, int>>> adj(n);

    for (auto &edge : flights)
    {
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];

        adj[u].push_back({v, w});
    }

    vector<int> distance(n, INT_MAX);

    queue<vector<int>> q;
    q.push({0, src, 0});

    distance[src] = 0;

    while (!q.empty())
    {

        auto curr = q.front();
        q.pop();

        int stops = curr[0];
        int node = curr[1];
        int cost = curr[2];

        if (stops > k)
            {continue;}

        for (auto &edge : adj[node])
        {

            int next = edge.first;
            int wt = edge.second;

            if (cost + wt < distance[next])
            {

                distance[next] = cost + wt;

                q.push({stops + 1, next, cost + wt});
            }
        }
    }

    if (distance[dst] == INT_MAX)
        return -1;

    return distance[dst];
}

// Main

int main()
{
    int n = 3;

    vector<vector<int>> flights =
        {
            {0, 1, 100},
            {1, 2, 100},
            {0, 2, 500}};

    int source = 0;
    int destination = 2;
    int maxStops = 1;

    cout << "Minimum Cost = ";

    cout << findCheapestPrice(
        n,
        flights,
        source,
        destination,
        maxStops);

    return 0;
}