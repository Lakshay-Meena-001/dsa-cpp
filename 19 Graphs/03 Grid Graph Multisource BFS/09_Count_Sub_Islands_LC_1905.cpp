#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool dfs(int r, int c, vector<vector<int>> &grid1, vector<vector<int>> &grid2)
    {

        int rows = grid2.size();
        int cols = grid2[0].size();

        // Boundary
        if (r < 0 || r >= rows || c < 0 || c >= cols)
        {
            return true;
        }

        // Water / already visited in grid2
        if (grid2[r][c] == 0)
        {
            return true;
        }

        // Current cell visit mark
        grid2[r][c] = 0;

        // Agar grid1 mein same position water hai,
        // to poora island invalid ho jayega.
        bool valid = (grid1[r][c] == 1);

        // Still explore complete island
        bool up = dfs(r - 1, c, grid1, grid2);
        bool down = dfs(r + 1, c, grid1, grid2);
        bool left = dfs(r, c - 1, grid1, grid2);
        bool right = dfs(r, c + 1, grid1, grid2);

        return valid && up && down && left && right;
    }

    int countSubIslands(vector<vector<int>> &grid1, vector<vector<int>> &grid2)
    {

        int rows = grid2.size();
        int cols = grid2[0].size();

        int count = 0;

        for (int r = 0; r < rows; r++)
        {
            for (int c = 0; c < cols; c++)
            {

                if (grid2[r][c] == 1)
                {

                    // Complete grid2 island check karo
                    if (dfs(r, c, grid1, grid2))
                    {
                        count++;
                    }
                }
            }
        }

        return count;
    }
};