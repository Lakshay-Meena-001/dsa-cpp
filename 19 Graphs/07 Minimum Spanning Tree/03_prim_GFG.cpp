#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

class Solution
{
public:
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // Min Heap
        // Stores : {Edge Weight, Node}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        // Visited Array
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

            // Explore neighbours
            for (auto &it : adj[node])
            {
                int neighbour = it[0];
                int edgeWeight = it[1];

                if (!visited[neighbour])
                {
                    pq.push({edgeWeight, neighbour});
                }
            }
        }

        return mstCost;
    }
};

int main()
{
    int V = 3;

    // Adjacency List
    vector<vector<int>> adj[V];

    // Edge : 0 - 1 (Weight 5)
    adj[0].push_back({1, 5});
    adj[1].push_back({0, 5});

    // Edge : 0 - 2 (Weight 1)
    adj[0].push_back({2, 1});
    adj[2].push_back({0, 1});

    // Edge : 1 - 2 (Weight 3)
    adj[1].push_back({2, 3});
    adj[2].push_back({1, 3});

    Solution obj;

    cout << "Minimum Spanning Tree Cost = "
         << obj.spanningTree(V, adj);

    return 0;
}