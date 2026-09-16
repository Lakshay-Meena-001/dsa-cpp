#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    // Convert square number into board[row][col]
    pair<int, int> getPosition(int square, int n)
    {
        int x = square - 1;

        int row = n - 1 - x / n;
        int col = x % n;

        // Reverse direction on alternate rows
        if ((n - 1 - row) % 2 == 1)
        {
            col = n - 1 - col;
        }

        return {row, col};
    }

    int snakesAndLadders(vector<vector<int>> &board)
    {
        int n = board.size();

        // visited[square]
        vector<bool> visited(n * n + 1, false);

        queue<int> q;

        // Start from square 1
        q.push(1);
        visited[1] = true;

        int moves = 0;

        while (!q.empty())
        {
            int size = q.size();

            // One BFS level = one dice throw
            while (size--)
            {
                int current = q.front();
                q.pop();

                // Try all dice rolls
                for (int dice = 1; dice <= 6; dice++)
                {
                    int next = current + dice;

                    // Cannot go beyond last square
                    if (next > n * n)
                    {
                        continue;
                    }

                    // Convert square number to board coordinates
                    auto [row, col] = getPosition(next, n);

                    // Snake or ladder
                    if (board[row][col] != -1)
                    {
                        next = board[row][col];
                    }

                    // Reached destination
                    if (next == n * n)
                    {
                        return moves + 1;
                    }

                    // Visit this square only once
                    if (!visited[next])
                    {
                        visited[next] = true;
                        q.push(next);
                    }
                }
            }

            // One complete BFS level = one dice throw
            moves++;
        }

        return -1;
    }
};

int main()
{
    vector<vector<int>> board = {
        {-1, -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1, -1},
        {-1, 35, -1, -1, 13, -1},
        {-1, -1, -1, -1, -1, -1},
        {-1, 15, -1, -1, -1, -1}};

    Solution obj;

    int result = obj.snakesAndLadders(board);

    cout << "Minimum dice throws: "
         << result << endl;

    return 0;
}