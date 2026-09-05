#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int primMST(int V, vector<vector<pair<int, int>>> &adj)
{
    // Pair kis cheez ka weight ka and node ka (weight, node)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    vector<bool> visited(V, false);

    int mstCost = 0;

    // Start from node 0
    pq.push({0, 0});

    while (!pq.empty())
    {
        auto [weight, node] = pq.top();
        pq.pop();

        // Already included in MST
        if (visited[node])
        {
            continue;
        }

        visited[node] = true;

        mstCost += weight;

        for (auto &[neighbour, edgeWeight] : adj[node])
        {
            if (!visited[neighbour])
            {
                pq.push({edgeWeight, neighbour});
            }
        }
    }

    return mstCost;
}

int main()
{
    int V = 4;

    vector<vector<pair<int, int>>> adj(V);

    auto addEdge = [&](int u, int v, int w)
    {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    };

    addEdge(0, 1, 4);
    addEdge(0, 2, 2);
    addEdge(1, 2, 1);
    addEdge(1, 3, 1);
    addEdge(2, 3, 3);

    cout << "Minimum Spanning Tree Cost = "
         << primMST(V, adj);

    return 0;
}