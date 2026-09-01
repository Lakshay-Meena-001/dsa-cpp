#include <iostream>
#include <vector>
using namespace std;

// LeetCode 200 - Number of Islands
// Approach : DFS (Recursive)
// Time Complexity  : O(rows × cols)
// Space Complexity : O(rows × cols)

// DFS Helper

void dfs(int row, int col, vector<vector<char>> &grid)
{
    int rows = grid.size();
    int cols = grid[0].size();

    // Boundary Check
    if (row < 0 || row >= rows ||
        col < 0 || col >= cols)
    {
        return;
    }

    // Water or Already Visited
    if (grid[row][col] == '0')
    {
        return;
    }

    // Mark Current Cell as Visited
    grid[row][col] = '0';

    // Visit 4 Directions
    dfs(row - 1, col, grid); // Up
    dfs(row + 1, col, grid); // Down
    dfs(row, col - 1, grid); // Left
    dfs(row, col + 1, grid); // Right
}

// Count Number of Islands

int numIslands(vector<vector<char>> &grid)
{
    int rows = grid.size();
    int cols = grid[0].size();

    int islands = 0;

    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {
            if (grid[row][col] == '1')
            {
                dfs(row, col, grid);
                islands++;
            }
        }
    }

    return islands;
}

// Driver Code

int main()
{
    vector<vector<char>> grid =
        {
            {'1', '1', '0', '0', '0'},
            {'1', '1', '0', '0', '0'},
            {'0', '0', '1', '0', '0'},
            {'0', '0', '0', '1', '1'}};

    cout << "Number of Islands : "
         << numIslands(grid)
         << endl;

    return 0;
}