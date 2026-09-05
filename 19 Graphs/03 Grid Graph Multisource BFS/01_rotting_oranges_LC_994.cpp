#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// LeetCode 994 - Rotting Oranges

// Approach : Multi-Source BFS
// Time Complexity  : O(rows × cols)
// Space Complexity : O(rows × cols)

// Rotting Oranges

int orangesRotting(vector<vector<int>> &grid)
{
    int rows = grid.size();
    int cols = grid[0].size();

    queue<pair<int, int>> q;

    int freshOranges = 0;
    int minutes = 0;

    // Direction Arrays
    vector<int> dr = {-1, 1, 0, 0};
    vector<int> dc = {0, 0, -1, 1};

    // Store all rotten oranges in queue

    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {
            if (grid[row][col] == 2)
            {
                q.push({row, col});
            }
            else if (grid[row][col] == 1)
            {
                freshOranges++;
            }
        }
    }

    if (freshOranges == 0)
    {
        return 0;
    }

    // Multi Source BFS

    while (!q.empty())
    {
        int size = q.size();
        bool rottenThisMinute = false;

        while (size--)
        {
            auto [row,col] = q.front();
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int newRow = row + dr[i];
                int newCol = col + dc[i];

                if (newRow >= 0 &&
                    newRow < rows &&
                    newCol >= 0 &&
                    newCol < cols &&
                    grid[newRow][newCol] == 1)
                {
                    grid[newRow][newCol] = 2;

                    q.push({newRow, newCol});

                    freshOranges--;

                    rottenThisMinute = true;
                }
            }
        }

        if (rottenThisMinute)
        {
            minutes++;
        }
    }

    return (freshOranges == 0) ? minutes : -1;
}

// Driver Code

int main()
{
    vector<vector<int>> grid =
        {
            {2, 1, 1},
            {1, 1, 0},
            {0, 1, 1}};

    cout << "Minimum Minutes : "
         << orangesRotting(grid)
         << endl;

    return 0;
}