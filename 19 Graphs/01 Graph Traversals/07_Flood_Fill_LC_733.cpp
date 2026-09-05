#include <iostream>
#include <vector>
using namespace std;

// LeetCode 733 - Flood Fill
// Approach : DFS (Recursive)
// Time Complexity  : O(rows × cols)
// Space Complexity : O(rows × cols)

// DFS Helper

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

void dfs(int row, int col, vector<vector<int>> &image, int originalColor, int newColor)
{
    image[row][col] = newColor;

    int rows = image.size();
    int cols = image[0].size();

    for (int i = 0; i < 4; i++)
    {
        int newRow = row + dr[i];
        int newCol = col + dc[i];

        if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols && image[newRow][newCol] == originalColor)
        {
            dfs(newRow, newCol, image, originalColor, newColor);
        }
    }
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
{
    int originalColor = image[sr][sc];

    // Important Edge Case
    if (originalColor == color)
    {
        return image;
    }

    dfs(sr, sc, image, originalColor, color);

    return image;
}

int main()
{
    vector<vector<int>> image =
    {
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1}
    };

    int sr = 1;
    int sc = 1;
    int newColor = 2;

    vector<vector<int>> ans = floodFill(image, sr, sc, newColor);

    cout << "Flood Filled Image:\n";

    for (const auto &row : ans)
    {
        for (int cell : row)
        {
            cout << cell << " ";
        }
        cout << endl;
    }

    return 0;
}