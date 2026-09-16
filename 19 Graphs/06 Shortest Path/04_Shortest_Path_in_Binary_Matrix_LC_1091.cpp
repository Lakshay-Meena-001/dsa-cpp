#include <iostream>
#include <vector>
#include <queue>

using namespace std;
// LeetCode 1091 - Shortest Path in Binary Matrix
//
// Approach : BFS (Shortest Path in Grid)
//
// Time Complexity : O(n²)
// Space Complexity : O(n²

int shortestPathBinaryMatrix(vector<vector<int>> &grid)
{
    int n = grid.size();

    // Start or Destination Blocked

    if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
    {
        return -1;
    }

    // Single Cell Grid

    if (n == 1)
    {
        return 1;
    }

    // 8 Directions

    vector<pair<int, int>> directions = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

    // Distance Matrix

    vector<vector<int>> dist(n, vector<int>(n, -1));

    queue<pair<int, int>> q;

    q.push({0, 0});

    dist[0][0] = 1;

    // BFS

    while (!q.empty())
    {
        auto current = q.front();
        q.pop();

        int row = current.first;
        int col = current.second;

        // Destination Reached

        if (row == n - 1 && col == n - 1)
        {
            return dist[row][col];
        }
        // Visit Neighbour

        for (auto direction : directions)
        {
            int newRow = row + direction.first;
            int newCol = col + direction.second;

            if (newRow < 0 || newCol < 0 || newRow >= n || newCol >= n)
            {
                continue;
            }

            if (grid[newRow][newCol] == 1)
            {
                continue;
            }

            if (dist[newRow][newCol] != -1)
            {
                continue;
            }

            dist[newRow][newCol] =
                dist[row][col] + 1;

            q.push({newRow, newCol});
        }
    }

    return -1;
}

// Driver Code

int main()
{
    vector<vector<int>> grid = {{0, 1}, {1, 0}};

    cout << "Shortest Path Length = "
         << shortestPathBinaryMatrix(grid)
         << endl;

    return 0;
}