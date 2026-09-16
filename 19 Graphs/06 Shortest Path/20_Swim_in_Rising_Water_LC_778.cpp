/*
------------------------------------------------------------

Problem : Swim_in_Rising_Water_LC_778

Pattern
-------
Advanced Dijkstra
+
Grid Graph
+
Minimax Path

Time Complexity
---------------
O((N * N) log(N * N))

Space Complexity
----------------
O(N * N)

------------------------------------------------------------
*/

#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// Returns minimum time required to reach destination.

int swimInWater(vector<vector<int>> &grid)
{
    int n = grid.size();

    // Minimum time required to reach every cell.

    vector<vector<int>> distance(n,vector<int>(n, INT_MAX));

    // Right, Left, Down, Up

    vector<pair<int, int>> directions =
    {
        {0, 1},
        {0, -1},
        {1, 0},
        {-1, 0}
    };

    // Min Heap
    // {time, row, col}

    priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;

    distance[0][0] = grid[0][0];

    pq.push(
    {
        grid[0][0],
        0,
        0
    });

    // Standard Modified Dijkstra.

    while (!pq.empty())
    {
        int currentTime = pq.top()[0];
        int currentRow = pq.top()[1];
        int currentCol = pq.top()[2];

        pq.pop();

        // Ignore outdated entry.

        if (currentTime > distance[currentRow][currentCol])
        {
            continue;
        }

        // Destination reached.

        if (currentRow == n - 1 &&
            currentCol == n - 1)
        {
            return currentTime;
        }

        // Explore all 4 neighbours.

        for (auto direction : directions)
        {
            int newRow =currentRow + direction.first;

            int newCol =currentCol + direction.second;

            // Skip invalid cell.

            if (newRow < 0 ||newCol < 0 ||newRow >= n ||newCol >= n)
            {
                continue;
            }

            // Modified relaxation.

            int newTime = max(currentTime, grid[newRow][newCol]);

            // Better path found.

            if (newTime <distance[newRow][newCol])
            {
                distance[newRow][newCol] = newTime;

                pq.push(
                {
                    newTime,
                    newRow,
                    newCol
                });
            }
        }
    }

    return -1;
}

// Main

int main()
{
    vector<vector<int>> grid =
    {
        {0, 2},
        {1, 3}
    };

    cout << "Minimum Time = ";

    cout << swimInWater(grid);

    return 0;
}