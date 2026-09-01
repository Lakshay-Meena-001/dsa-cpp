#include <iostream>
#include <vector>

using namespace std;

// LeetCode 1020 - Number of Enclaves

// Approach : Boundary DFS

// Time Complexity : O(rows × cols)
// Space Complexity : O(rows × cols) (Recursion Stack)

class Solution
{
public:
    vector<int> dr = {-1, 1, 0, 0};
    vector<int> dc = {0, 0, -1, 1};

    // DFS

    void dfs(int row, int col, vector<vector<int>> &grid)
    {
        int rows = grid.size();
        int cols = grid[0].size();

        grid[row][col] = 0;

        for (int i = 0; i < 4; i++)
        {
            int newRow = row + dr[i];
            int newCol = col + dc[i];

            if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols && grid[newRow][newCol] == 1)
            {
                dfs(newRow, newCol, grid);
            }
        }
    }

    // Main Function

    int numEnclaves(vector<vector<int>> &grid)
    {
        int rows = grid.size();
        int cols = grid[0].size();

        // First Row

        for (int col = 0; col < cols; col++)
        {
            if (grid[0][col] == 1)
            {
                dfs(0, col, grid);
            }
        }

        // Last Row

        for (int col = 0; col < cols; col++)
        {
            if (grid[rows - 1][col] == 1)
            {
                dfs(rows - 1, col, grid);
            }
        }

        // First Column

        for (int row = 0; row < rows; row++)
        {
            if (grid[row][0] == 1)
            {
                dfs(row, 0, grid);
            }
        }

        // Last Column

        for (int row = 0; row < rows; row++)
        {
            if (grid[row][cols - 1] == 1)
            {
                dfs(row, cols - 1, grid);
            }
        }

        // Count Remaining Land

        int count = 0;

        for (int row = 0; row < rows; row++)
        {
            for (int col = 0; col < cols; col++)
            {
                if (grid[row][col] == 1)
                {
                    count++;
                }
            }
        }

        return count;
    }
};

// Driver Code

int main()
{
    vector<vector<int>> grid =
        {
            {0, 0, 0, 0},
            {1, 0, 1, 0},
            {0, 1, 1, 0},
            {0, 0, 0, 0}};

    Solution obj;

    cout << "Number of Enclaves = "
         << obj.numEnclaves(grid)
         << endl;

    return 0;
}