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

    // Push Entrance

    q.push({entrance[0], entrance[1]});

    // Mark as Visited

    maze[entrance[0]][entrance[1]] = '+';

    vector<int> dr = {-1, 1, 0, 0};
    vector<int> dc = {0, 0, -1, 1};

    int steps = 0;

    // BFS

    while (!q.empty())
    {
        int size = q.size();

        while (size--)
        {
            auto current = q.front();
            q.pop();

            int row = current.first;
            int col = current.second;

            // Check Exit

            if (!(row == entrance[0] && col == entrance[1]) &&
                (row == 0 || row == rows - 1 || col == 0 || col == cols - 1))
            {
                return steps;
            }

            // Visit Neighbours

            for (int i = 0; i < 4; i++)
            {
                int newRow = row + dr[i];
                int newCol = col + dc[i];

                if (newRow >= 0 &&
                    newRow < rows &&
                    newCol >= 0 &&
                    newCol < cols &&
                    maze[newRow][newCol] == '.')
                {
                    maze[newRow][newCol] = '+';

                    q.push({newRow, newCol});
                }
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