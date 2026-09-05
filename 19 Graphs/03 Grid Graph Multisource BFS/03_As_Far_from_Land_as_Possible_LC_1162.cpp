#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// LeetCode 1162 - As Far from Land as Possible

// Approach : Multi Source BFS

// Time Complexity : O(rows × cols)
// Space Complexity : O(rows × cols)

// Maximum Distance

int maxDistance(vector<vector<int>> &grid)
{
    int rows = grid.size();
    int cols = grid[0].size();

    queue<pair<int, int>> q;

    vector<int> dr = {-1, 1, 0, 0};
    vector<int> dc = {0, 0, -1, 1};

    int waterCells = 0;

    vector<vector<int>> distance(rows, vector<int>(cols, -1));

    // Push all Land Cells into Queue

    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {
            if (grid[row][col] == 1)
            {
                q.push({row, col});
                distance[row][col] = 0;
            }
            else
            {
                waterCells++;
            }
        }
    }

    // All Water OR All Land
    if (q.empty() || waterCells == 0)
    {
        return -1;
    }

    int answer = -1;

    // Multi Source BFS

    while (!q.empty())
    {
        auto current = q.front();
        q.pop();

        int row = current.first;
        int col = current.second;

        for (int i = 0; i < 4; i++)
        {
            int newRow = row + dr[i];
            int newCol = col + dc[i];

            if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols && distance[newRow][newCol] == -1)
            {
                distance[newRow][newCol] = distance[row][col] + 1;

                answer = max(answer, distance[newRow][newCol]);

                q.push({newRow, newCol});
            }
        }
    }

    return answer;
}

// Driver Code

int main()
{
    vector<vector<int>> grid =
        {
            {1, 0, 1},
            {0, 0, 0},
            {1, 0, 1}};

    cout << "Maximum Distance : "
         << maxDistance(grid)
         << endl;

    return 0;
}