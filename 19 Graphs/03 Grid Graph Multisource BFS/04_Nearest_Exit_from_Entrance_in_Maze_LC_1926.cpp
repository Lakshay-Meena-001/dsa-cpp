#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// LeetCode 1926 - Nearest Exit from Entrance in Maze

// Approach : BFS (Shortest Path)

// Time Complexity : O(rows × cols)
// Space Complexity : O(rows × cols)

int nearestExit(vector<vector<char>> &maze, vector<int> &entrance)
{
    int rows = maze.size();
    int cols = maze[0].size();

    queue<pair<int, int>> q;

    vector<vector<bool>> visited(rows, vector<bool>(cols, false));

    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    // Put entrance into queue
    q.push({entrance[0], entrance[1]});

    visited[entrance[0]][entrance[1]] = true;

    int steps = 0;

    while (!q.empty())
    {
        int size = q.size();

        for (int i = 0; i < size; i++)
        {
            int row = q.front().first;
            int col = q.front().second;

            q.pop();

            for (int k = 0; k < 4; k++)
            {
                int nr = row + dr[k];
                int nc = col + dc[k];

                // Boundary Check
                if (nr < 0 || nr >= rows || nc < 0 || nc >= cols)
                    continue;

                // Wall
                if (maze[nr][nc] == '+')
                    continue;

                // Already Visited
                if (visited[nr][nc])
                    continue;

                // Exit Found
                if (nr == 0 || nr == rows - 1 ||
                    nc == 0 || nc == cols - 1)
                {
                    return steps + 1;
                }

                visited[nr][nc] = true;

                q.push({nr, nc});
            }
        }

        steps++;
    }

    return -1;
}

// Driver Code

int main()
{
    vector<vector<char>> maze =
        {
            {'+', '+', '.', '+'},
            {'.', '.', '.', '+'},
            {'+', '+', '+', '.'}};

    vector<int> entrance = {1, 2};

    cout << "Nearest Exit Steps = "
         << nearestExit(maze, entrance)
         << endl;

    return 0;
}