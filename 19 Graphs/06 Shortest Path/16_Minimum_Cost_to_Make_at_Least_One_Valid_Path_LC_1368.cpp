/*
------------------------------------------------------------

Problem : Minimum_Cost_to_Make_at_Least_One_Valid_Path_LC_1368

Pattern
-------
0-1 BFS
+
Grid Graph
+
Deque

Time Complexity
---------------
O(N * M)

Space Complexity
----------------
O(N * M)

------------------------------------------------------------
*/

#include <iostream>
#include <vector>
#include <deque>
#include <climits>

using namespace std;

// Returns minimum cost to reach bottom-right cell.

int minCost(vector<vector<int>> &grid)
{
    int rows = grid.size();
    int cols = grid[0].size();

    // Distance array.

    vector<vector<int>> distance(
        rows,
        vector<int>(cols, INT_MAX));

    // Right, Left, Down, Up

    vector<pair<int, int>> directions =
    {
        {0, 1},
        {0, -1},
        {1, 0},
        {-1, 0}
    };

    // Deque stores:
    // {row, col}

    deque<pair<int, int>> dq;

    distance[0][0] = 0;

    dq.push_front({0, 0});

    // Standard 0-1 BFS.

    while (!dq.empty())
    {
        int currentRow = dq.front().first;
        int currentCol = dq.front().second;

        dq.pop_front();

        // Explore all four directions.

        for (int direction = 0; direction < 4; direction++)
        {
            int newRow =
                currentRow + directions[direction].first;

            int newCol =
                currentCol + directions[direction].second;

            // Skip invalid cell.

            if (newRow < 0 ||
                newCol < 0 ||
                newRow >= rows ||
                newCol >= cols)
            {
                continue;
            }

            // Cost = 0 if following arrow.
            // Cost = 1 if changing arrow.

            int edgeWeight =
                (grid[currentRow][currentCol] == direction + 1)
                    ? 0
                    : 1;

            int newDistance =
                distance[currentRow][currentCol] + edgeWeight;

            // Better path found.

            if (newDistance < distance[newRow][newCol])
            {
                distance[newRow][newCol] =
                    newDistance;

                if (edgeWeight == 0)
                {
                    dq.push_front(
                    {
                        newRow,
                        newCol
                    });
                }
                else
                {
                    dq.push_back(
                    {
                        newRow,
                        newCol
                    });
                }
            }
        }
    }

    return distance[rows - 1][cols - 1];
}

// Main

int main()
{
    vector<vector<int>> grid =
    {
        {1, 1, 3},
        {3, 2, 2},
        {1, 1, 4}
    };

    cout << "Minimum Cost = ";

    cout << minCost(grid);

    return 0;
}