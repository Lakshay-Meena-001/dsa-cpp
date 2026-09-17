#include <iostream>
#include <vector>

using namespace std;
class Solution
{
public:
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    void dfs(int row, int col, vector<vector<char>> &board)
    {
        int rows = board.size();
        int cols = board[0].size();

        // Grid ke bahar
        if (row < 0 || row >= rows || col < 0 || col >= cols)
        {
            return;
        }

        // Sirf O ko explore karna hai
        if (board[row][col] != 'O')
        {
            return;
        }

        // Boundary-connected O = SAFE
        board[row][col] = 'S';

        // 4 directions
        for (int k = 0; k < 4; k++)
        {
            int nr = row + dr[k];
            int nc = col + dc[k];

            dfs(nr, nc, board);
        }
    }

    void solve(vector<vector<char>> &board)
    {
        int rows = board.size();
        int cols = board[0].size();

        // Top + Bottom boundaries
        for (int col = 0; col < cols; col++)
        {
            dfs(0, col, board);
            dfs(rows - 1, col, board);
        }

        // Left + Right boundaries
        for (int row = 0; row < rows; row++)
        {
            dfs(row, 0, board);
            dfs(row, cols - 1, board);
        }

        // Remaining O = Surrounded
        // S = Safe, so restore it back to O
        for (int row = 0; row < rows; row++)
        {
            for (int col = 0; col < cols; col++)
            {
                if (board[row][col] == 'O')
                {
                    board[row][col] = 'X';
                }
                else if (board[row][col] == 'S')
                {
                    board[row][col] = 'O';
                }
            }
        }
    }
};