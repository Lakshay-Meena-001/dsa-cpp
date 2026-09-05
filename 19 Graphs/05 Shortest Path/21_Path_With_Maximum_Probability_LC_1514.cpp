/*
------------------------------------------------------------

Problem : Path_With_Maximum_Probability_LC_1514

Pattern
-------
Modified Dijkstra
+
Maximum Probability
+
Max Heap

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

using namespace std;

// Returns maximum probability from start to end.

double maxProbability(int n, vector<vector<int>> &edges, vector<double> &successProbability, int start, int end)
{
    // Adjacency List
    // {neighbour, probability}

    vector<vector<pair<int, double>>> adj(n);

    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        double probability = successProbability[i];

        adj[u].push_back({v, probability});
        adj[v].push_back({u, probability});
    }

    // Stores maximum probability to reach every node.

    vector<double> probability(n, 0.0);

    // Max Heap
    // {probability, node}

    priority_queue<pair<double, int>> pq;

    probability[start] = 1.0;

    pq.push({1.0, start});

    // Modified Dijkstra.

    while (!pq.empty())
    {
        double currentProbability = pq.top().first;
        int currentNode = pq.top().second;

        pq.pop();

        // Ignore outdated entry.

        if (currentProbability < probability[currentNode])
        {
            continue;
        }

        // Destination reached.

        if (currentNode == end)
        {
            return currentProbability;
        }

        // Explore neighbours.

        for (auto edge : adj[currentNode])
        {
            int neighbour = edge.first;
            double edgeProbability = edge.second;

            // Modified relaxation.

            double newProbability = currentProbability * edgeProbability;

            // Better path found.

            if (newProbability > probability[neighbour])
            {
                probability[neighbour] = newProbability;

                pq.push({newProbability, neighbour});
            }
        }
    }

    return 0.0;
}

// Main

int main()
{
    int n = 3;

    vector<vector<int>> edges =
        {
            {0, 1},
            {1, 2},
            {0, 2}};

    vector<double> successProbability =
        {
            0.5,
            0.5,
            0.2};

    int start = 0;
    int end = 2;

    cout << "Maximum Probability = ";

    cout << maxProbability(
        n,
        edges,
        successProbability,
        start,
        end);

    return 0;
}