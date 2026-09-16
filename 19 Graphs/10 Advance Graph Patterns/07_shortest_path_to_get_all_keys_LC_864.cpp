#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    struct State
    {
        int row;
        int col;
        int mask;
    };

    int shortestPathAllKeys(vector<string> &grid)
    {
        int rows = grid.size();
        int cols = grid[0].size();

        int startRow = -1;
        int startCol = -1;

        int keyCount = 0;

        // Find starting position and count keys
        for (int r = 0; r < rows; r++)
        {
            for (int c = 0; c < cols; c++)
            {
                if (grid[r][c] == '@')
                {
                    startRow = r;
                    startCol = c;
                }

                if (grid[r][c] >= 'a' && grid[r][c] <= 'f')
                {
                    keyCount++;
                }
            }
        }

        // Example:
        // 3 keys -> 111
        int allKeys = (1 << keyCount) - 1;

        // visited[row][col][mask]
        vector<vector<vector<bool>>> visited(rows, vector<vector<bool>>(cols, vector<bool>(1 << keyCount, false)));

        queue<State> q;

        // Start with no keys
        q.push({startRow, startCol, 0});

        visited[startRow][startCol][0] = true;

        int steps = 0;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!q.empty())
        {
            int size = q.size();

            // One BFS level = one step
            while (size--)
            {
                State current = q.front();
                q.pop();

                int r = current.row;
                int c = current.col;
                int mask = current.mask;

                // All keys collected
                if (mask == allKeys)
                {
                    return steps;
                }

                // Try four directions
                for (int i = 0; i < 4; i++)
                {
                    int nr = r + dr[i];
                    int nc = c + dc[i];

                    // Outside grid
                    if (nr < 0 || nr >= rows || nc < 0 || nc >= cols)
                    {
                        continue;
                    }

                    // Wall
                    if (grid[nr][nc] == '#')
                    {
                        continue;
                    }

                    char cell = grid[nr][nc];

                    // Lock
                    if (cell >= 'A' && cell <= 'F')
                    {
                        int requiredKey = cell - 'A';

                        // Key not collected
                        if ((mask & (1 << requiredKey)) == 0)
                        {
                            continue;
                        }
                    }

                    // New mask
                    int newMask = mask;

                    // Key
                    if (cell >= 'a' && cell <= 'f')
                    {
                        int key = cell - 'a';

                        newMask = mask | (1 << key);
                    }

                    // New state already visited?
                    if (visited[nr][nc][newMask])
                    {
                        continue;
                    }

                    visited[nr][nc][newMask] = true;

                    q.push({nr, nc, newMask});
                }
            }

            steps++;
        }

        return -1;
    }
};

int main()
{
    vector<string> grid = {
        "@.a..",
        "###.#",
        "b.A.B"};

    Solution obj;

    int result = obj.shortestPathAllKeys(grid);

    cout << "Minimum steps: "
         << result << endl;

    return 0;
}