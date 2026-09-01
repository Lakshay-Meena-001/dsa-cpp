#include <iostream>
#include <vector>
using namespace std;

// Problem : 30_Game_Of_Life_LC_289.cpp
// Pattern : Matrix Simulation
// Approach :
// 1. Count alive neighbours using direction vectors.
// 2. Mark temporary states.
//      -1 = Alive -> Dead
//       2 = Dead  -> Alive
// 3. Convert temporary states to final states.
//
// Time  : O(rows × cols)
// Space : O(1)
//
// Learning:
// 1. Direction Vectors
// 2. In-place State Transition
// 3. Simulation

void gameOfLife(vector<vector<int>> &board)
{
    int rows = board.size();
    int cols = board[0].size();

    vector<pair<int, int>> directions =
        {
            {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

    //--------------------------------------------------
    // Pass 1 : Mark temporary states.
    //--------------------------------------------------

    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {
            int aliveNeighbours = 0;

            // Count alive neighbours.

            for (auto direction : directions)
            {
                int newRow = row + direction.first;
                int newCol = col + direction.second;

                if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols)
                {
                    // 1  = Alive
                    // -1 = Was Alive (still count as alive)

                    if (board[newRow][newCol] == 1 || board[newRow][newCol] == -1)
                    {
                        aliveNeighbours++;
                    }
                }
            }

            // Current cell is alive.

            if (board[row][col] == 1)
            {
                if (aliveNeighbours < 2 || aliveNeighbours > 3)
                {
                    board[row][col] = -1;
                }
            }

            // Current cell is dead.

            else
            {
                if (aliveNeighbours == 3)
                {
                    board[row][col] = 2;
                }
            }
        }
    }

    //--------------------------------------------------
    // Pass 2 : Convert temporary states.
    //--------------------------------------------------

    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {
            if (board[row][col] == -1)
            {
                board[row][col] = 0;
            }
            else if (board[row][col] == 2)
            {
                board[row][col] = 1;
            }
        }
    }
}

// Driver

int main()
{
    int rows, cols;

    cin >> rows >> cols;

    vector<vector<int>> board(rows, vector<int>(cols));

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cin >> board[i][j];
        }
    }

    gameOfLife(board);

    for (const auto &row : board)
    {
        for (int cell : row)
        {
            cout << cell << " ";
        }

        cout << endl;
    }

    return 0;
}