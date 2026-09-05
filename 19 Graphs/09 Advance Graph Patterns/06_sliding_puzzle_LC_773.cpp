#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <string>
using namespace std;

class Solution
{
public:
    int slidingPuzzle(vector<vector<int>> &board)
    {
        // Convert 2D board into a string state
        string start = "";

        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                start += char(board[i][j] + '0');
            }
        }

        // Target configuration
        string target = "123450";

        // BFS queue
        queue<string> q;

        // Keep track of already visited board configurations
        unordered_set<string> visited;

        q.push(start);
        visited.insert(start);

        // Every BFS level represents one move
        int moves = 0;

        // Possible movements of 0
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!q.empty())
        {
            int size = q.size();

            // Process one complete BFS level
            while (size--)
            {
                string current = q.front();
                q.pop();

                // If target reached
                if (current == target)
                {
                    return moves;
                }

                // Find position of 0
                int zeroPos = current.find('0');

                // Convert index into row and column
                int row = zeroPos / 3;
                int col = zeroPos % 3;

                // Try all 4 possible directions
                for (int i = 0; i < 4; i++)
                {
                    int newRow = row + dr[i];
                    int newCol = col + dc[i];

                    // Check boundaries
                    if (newRow < 0 || newRow >= 2 || newCol < 0 || newCol >= 3)
                    {
                        continue;
                    }

                    // Convert new position back to string index
                    int newPos = newRow * 3 + newCol;

                    // Create next state by swapping 0
                    string next = current;

                    swap(next[zeroPos], next[newPos]);

                    // If this configuration is new
                    if (visited.find(next) == visited.end())
                    {
                        visited.insert(next);
                        q.push(next);
                    }
                }
            }

            // One BFS level = one move
            moves++;
        }

        // Target cannot be reached
        return -1;
    }
};

int main()
{
    vector<vector<int>> board = {
        {1, 2, 3},
        {4, 0, 5}};

    Solution obj;

    int result = obj.slidingPuzzle(board);

    cout << "Minimum moves: " << result << endl;

    return 0;
}