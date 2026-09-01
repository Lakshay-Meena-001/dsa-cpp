#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// LeetCode 417 - Pacific Atlantic Water Flow

// Approach : Multi-Source BFS

// Time Complexity : O(rows × cols)
// Space Complexity : O(rows × cols)

// DFS

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

void dfs(int row, int col, vector<vector<int>> &heights, vector<vector<bool>> &visited)
{
    visited[row][col] = true;

    int rows = heights.size();
    int cols = heights[0].size();

    for (int k = 0; k < 4; k++)
    {
        int nr = row + dr[k];
        int nc = col + dc[k];

        if (nr < 0 || nr >= rows || nc < 0 || nc >= cols)
        {
            continue;
        }

        if (visited[nr][nc])
        {
            continue;
        }

        if (heights[nr][nc] < heights[row][col])
        {
            continue;
        }

        dfs(nr, nc, heights, visited);
    }
}

vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
{
    int rows = heights.size();
    int cols = heights[0].size();

    vector<vector<bool>> pacific(rows, vector<bool>(cols, false));

    vector<vector<bool>> atlantic(rows, vector<bool>(cols, false));

    // Pacific
    for (int col = 0; col < cols; col++)
    {
        dfs(0, col, heights, pacific);
    }

    for (int row = 0; row < rows; row++)
    {
        dfs(row, 0, heights, pacific);
    }

    // Atlantic
    for (int col = 0; col < cols; col++)
    {
        dfs(rows - 1, col, heights, atlantic);
    }

    for (int row = 0; row < rows; row++)
    {
        dfs(row, cols - 1, heights, atlantic);
    }

    vector<vector<int>> answer;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (pacific[i][j] && atlantic[i][j])
                answer.push_back({i, j});
        }
    }

    return answer;
}

// Driver Code

int main()
{
    vector<vector<int>> heights =
        {
            {1, 2, 2, 3, 5},
            {3, 2, 3, 4, 4},
            {2, 4, 5, 3, 1},
            {6, 7, 1, 4, 5},
            {5, 1, 1, 2, 4}};

    vector<vector<int>> answer =
        pacificAtlantic(heights);

    cout << "Cells that can reach both oceans:\n\n";

    for (auto cell : answer)
    {
        cout << "("
             << cell[0]
             << ", "
             << cell[1]
             << ")\n";
    }

    return 0;
}

/*
DFS easy one
class Solution
{
public:

    void bfs(queue<pair<int,int>>& q,
         vector<vector<bool>>& visited,
         vector<vector<int>>& heights)
{
    int rows = heights.size();
    int cols = heights[0].size();

    vector<int> dr = {-1, 1, 0, 0};
    vector<int> dc = {0, 0, -1, 1};

    while (!q.empty())
    {
        auto current = q.front();
        q.pop();

        int row = current.first;
        int col = current.second;

        for (int i = 0; i < 4; i++)
        {
            int newRow = row + dr[i];
            int newCol = col + dc[i];

            if (newRow >= 0 &&
                newRow < rows &&
                newCol >= 0 &&
                newCol < cols &&
                !visited[newRow][newCol] &&
                heights[newRow][newCol] >= heights[row][col])
            {
                visited[newRow][newCol] = true;

                q.push({newRow, newCol});
            }
        }
    }
}

//---------------------------------------------------------
// Main Function
//---------------------------------------------------------
vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights)
{
    int rows = heights.size();
    int cols = heights[0].size();

    vector<vector<bool>> pacific(rows,
                                 vector<bool>(cols, false));

    vector<vector<bool>> atlantic(rows,
                                  vector<bool>(cols, false));

    queue<pair<int,int>> pacificQueue;
    queue<pair<int,int>> atlanticQueue;

    //-----------------------------------------------------
    // Pacific Border
    //-----------------------------------------------------

    for (int row = 0; row < rows; row++)
    {
        pacific[row][0] = true;
        pacificQueue.push({row, 0});
    }

    for (int col = 1; col < cols; col++)
    {
        pacific[0][col] = true;
        pacificQueue.push({0, col});
    }

    //-----------------------------------------------------
    // Atlantic Border
    //-----------------------------------------------------

    for (int row = 0; row < rows; row++)
    {
        atlantic[row][cols - 1] = true;
        atlanticQueue.push({row, cols - 1});
    }

    for (int col = 0; col < cols - 1; col++)
    {
        atlantic[rows - 1][col] = true;
        atlanticQueue.push({rows - 1, col});
    }

    //-----------------------------------------------------
    // BFS
    //-----------------------------------------------------

    bfs(pacificQueue, pacific, heights);
    bfs(atlanticQueue, atlantic, heights);

    //-----------------------------------------------------
    // Common Cells
    //-----------------------------------------------------

    vector<vector<int>> answer;

    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {
            if (pacific[row][col] &&
                atlantic[row][col])
            {
                answer.push_back({row, col});
            }
        }
    }

    return answer;
}
};
*/