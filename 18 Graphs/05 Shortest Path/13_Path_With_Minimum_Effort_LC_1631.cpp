/*
------------------------------------------------------------

Problem : Path_With_Minimum_Effort_LC_1631

Pattern
-------
Modified Dijkstra
+
Grid Graph
+
Weighted Graph

Time Complexity
---------------
O((N * M) log(N * M))

Space Complexity
----------------
O(N * M)

------------------------------------------------------------
*/

#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// Returns minimum effort required to reach destination.

int minimumEffortPath(vector<vector<int>> &heights)
{
    int rows = heights.size();
    int cols = heights[0].size();

    // Distance array stores minimum effort.

    vector<vector<int>> distance(rows, vector<int>(cols, INT_MAX));

    // Directions

    vector<pair<int, int>> directions =
        {{-1, 0},
         {1, 0},
         {0, -1},
         {0, 1}};

    // Min Heap
    // {effort, row, col}

    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

    distance[0][0] = 0;

    pq.push({0, 0, 0});

    // Standard Modified Dijkstra.

    while (!pq.empty())
    {
        int currentEffort = pq.top()[0];
        int currentRow = pq.top()[1];
        int currentCol = pq.top()[2];

        pq.pop();

        // Destination reached.

        if (currentRow == rows - 1 && currentCol == cols - 1)
        {
            return currentEffort;
        }

        // Ignore outdated entry.

        if (currentEffort > distance[currentRow][currentCol])
        {
            continue;
        }

        // Explore all 4 neighbours.

        for (auto direction : directions)
        {
            int newRow = currentRow + direction.first;
            int newCol = currentCol + direction.second;

            // Skip invalid cell.

            if (newRow < 0 || newCol < 0 || newRow >= rows || newCol >= cols)
            {
                continue;
            }

            // Current edge weight.

            int edgeWeight = abs(heights[currentRow][currentCol] - heights[newRow][newCol]);

            // Modified relaxation.

            int newEffort = max(currentEffort, edgeWeight);

            // Better path found.

            if (newEffort < distance[newRow][newCol])
            {
                distance[newRow][newCol] = newEffort;

                pq.push({newEffort, newRow, newCol});
            }
        }
    }

    return 0;
}

// Main

int main()
{
    vector<vector<int>> heights =
        {
            {1, 2, 2},
            {3, 8, 2},
            {5, 3, 5}};

    cout << "Minimum Effort = ";

    cout << minimumEffortPath(heights);

    return 0;
}