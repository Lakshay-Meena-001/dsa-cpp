/*
------------------------------------------------------------

Problem : Find_the_City_With_the_Smallest_Number_of_Neighbors_LC_1334

Pattern
-------
All Pairs Shortest Path
+
Floyd-Warshall

Time Complexity
---------------
O(V^3)

Space Complexity
----------------
O(V^2)

------------------------------------------------------------
*/

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

const int INF = 1e9;

int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold)
{
    // Distance matrix.

    vector<vector<int>> distance(n, vector<int>(n, INF));

    // Distance to itself.

    for (int i = 0; i < n; i++)
    {
        distance[i][i] = 0;
    }

    // Build graph.

    for (auto edge : edges)
    {
        int u = edge[0];
        int v = edge[1];
        int weight = edge[2];

        distance[u][v] = weight;
        distance[v][u] = weight;
    }

    // Floyd-Warshall.

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (distance[i][k] == INF ||
                    distance[k][j] == INF)
                {
                    continue;
                }

                distance[i][j] = min(distance[i][j], distance[i][k] + distance[k][j]);
            }
        }
    }

    int answer = -1;
    int minimumReachable = INT_MAX;

    // Count reachable cities.

    for (int city = 0; city < n; city++)
    {
        int reachableCities = 0;

        for (int neighbour = 0; neighbour < n; neighbour++)
        {
            if (distance[city][neighbour] <= distanceThreshold)
            {
                reachableCities++;
            }
        }

        // Smaller count OR tie with larger city index.

        if (reachableCities <= minimumReachable)
        {
            minimumReachable = reachableCities;
            answer = city;
        }
    }

    return answer;
}

// Main

int main()
{
    int n = 4;

    vector<vector<int>> edges =
        {
            {0, 1, 3},
            {1, 2, 1},
            {2, 3, 1},
            {0, 3, 4}};

    int threshold = 4;

    cout << "Answer = ";

    cout << findTheCity(
        n,
        edges,
        threshold);

    return 0;
}