#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int rows, cols;

    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    queue<pair<int, int>> q;

    void dfs(int r, int c, vector<vector<int>> &grid)
    {

        if (r < 0 || r >= rows || c < 0 || c >= cols || grid[r][c] != 1)
        {
            return;
        }

        // First island ko mark kar rahe hain
        grid[r][c] = 2;

        // Multi-source BFS ke liye source queue mein
        q.push({r, c});

        for (int k = 0; k < 4; k++)
        {
            dfs(r + dr[k], c + dc[k], grid);
        }
    }

    int shortestBridge(vector<vector<int>> &grid)
    {

        rows = grid.size();
        cols = grid[0].size();

        // Step 1: First island find karo
        bool found = false;

        for (int r = 0; r < rows && !found; r++)
        {
            for (int c = 0; c < cols; c++)
            {

                if (grid[r][c] == 1)
                {
                    dfs(r, c, grid);
                    found = true;
                    break;
                }
            }
        }

        // Step 2: Multi-source BFS
        int distance = 0;

        while (!q.empty())
        {

            int size = q.size();

            while (size--)
            {
                auto [r, c] = q.front();
                q.pop();

                for (int k = 0; k < 4; k++)
                {
                    int nr = r + dr[k];
                    int nc = c + dc[k];

                    if (nr < 0 || nr >= rows || nc < 0 || nc >= cols)
                    {
                        continue;
                    }

                    // Second island mil gaya
                    if (grid[nr][nc] == 1)
                    {
                        return distance;
                    }

                    // Water ko visit karo
                    if (grid[nr][nc] == 0)
                    {
                        grid[nr][nc] = 2;
                        q.push({nr, nc});
                    }
                }
            }

            distance++;
        }

        return -1;
    }
};