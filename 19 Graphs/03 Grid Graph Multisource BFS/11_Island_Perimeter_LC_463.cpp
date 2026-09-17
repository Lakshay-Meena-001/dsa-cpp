#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int islandPerimeter(vector<vector<int>> &grid)
    {

        int rows = grid.size();
        int cols = grid[0].size();

        int perimeter = 0;

        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};

        for (int r = 0; r < rows; r++)
        {
            for (int c = 0; c < cols; c++)
            {

                if (grid[r][c] != 1)
                {
                    continue;
                }

                // Har land cell ki 4 sides check karo
                for (int k = 0; k < 4; k++)
                {

                    int nr = r + dr[k];
                    int nc = c + dc[k];

                    // Grid ke bahar = perimeter
                    if (nr < 0 || nr >= rows || nc < 0 || nc >= cols)
                    {
                        perimeter++;
                    }

                    // Water = perimeter
                    else if (grid[nr][nc] == 0)
                    {
                        perimeter++;
                    }
                }
            }
        }

        return perimeter;
    }
};