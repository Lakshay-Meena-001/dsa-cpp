#include <iostream>
#include <vector>

using namespace std;
class Solution
{
public:
    bool dfs(int row, int col, vector<vector<int>> &grid)
    {
        int rows = grid.size();
        int cols = grid[0].size();

        // Grid ke bahar = boundary touch ho gayi
        if (row < 0 || row >= rows || col < 0 || col >= cols)
        {
            return false;
        }

        // Water / already visited
        if (grid[row][col] == 1)
        {
            return true;
        }

        // Mark land as visited
        grid[row][col] = 1;

        bool up = dfs(row - 1, col, grid);
        bool down = dfs(row + 1, col, grid);
        bool left = dfs(row, col - 1, grid);
        bool right = dfs(row, col + 1, grid);

        // Every direction must remain inside
        return up && down && left && right;
    }

    int closedIsland(vector<vector<int>> &grid)
    {
        int rows = grid.size();
        int cols = grid[0].size();

        int count = 0;

        for (int row = 0; row < rows; row++)
        {
            for (int col = 0; col < cols; col++)
            {
                if (grid[row][col] == 0)
                {
                    if (dfs(row, col, grid))
                    {
                        count++;
                    }
                }
            }
        }

        return count;
    }
};