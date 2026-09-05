#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// LeetCode 695 - Max Area of Island
// Approach : DFS (Recursive)
// Time Complexity  : O(rows × cols)
// Space Complexity : O(rows × cols)

// DFS Helper
// Returns area of current island

int dfs(int row, int col, vector<vector<int>> &grid)
{
    int rows = grid.size();
    int cols = grid[0].size();

    // Boundary Check
    if (row < 0 || row >= rows || col < 0 || col >= cols)
    {
        return 0;
    }

    // Water or Already Visited
    if (grid[row][col] == 0)
    {
        return 0;
    }

    // Mark Current Cell as Visited
    grid[row][col] = 0;

    int area = 1;

    // Visit 4 Directions
    area += dfs(row - 1, col, grid); // Up
    area += dfs(row + 1, col, grid); // Down
    area += dfs(row, col - 1, grid); // Left
    area += dfs(row, col + 1, grid); // Right

    return area;
}

// Find Maximum Area

int maxAreaOfIsland(vector<vector<int>> &grid)
{
    int rows = grid.size();
    int cols = grid[0].size();

    int maxArea = 0;

    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {
            if (grid[row][col] == 1)
            {
                maxArea = max(maxArea, dfs(row, col, grid));
            }
        }
    }

    return maxArea;
}

// Driver Code

int main()
{
    vector<vector<int>> grid =
        {
            {0, 0, 1, 0, 0},
            {1, 1, 1, 0, 1},
            {0, 1, 0, 0, 1},
            {0, 0, 0, 1, 1}};

    cout << "Maximum Area of Island : " << maxAreaOfIsland(grid) << endl;

    return 0;
}

/*
class Solution {
public:
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    int dfs(int row, int col, vector<vector<int>>& grid) {

        grid[row][col] = '0';

        int rows = grid.size();
        int cols = grid[0].size();

        int area = 1;

        for (int i = 0; i < 4; i++) {
            int newRow = row + dr[i];
            int newCol = col + dc[i];

            if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols &&
                grid[newRow][newCol] == 1) {
                area += dfs(newRow, newCol, grid);
            }
        }

        return area;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {

        int rows = grid.size();
        int cols = grid[0].size();

        int maxArea = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) {
                    maxArea = max(maxArea, dfs(i, j, grid));
                }
            }
        }
        return maxArea;
    }
};
*/