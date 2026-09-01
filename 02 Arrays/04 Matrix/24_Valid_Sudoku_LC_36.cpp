#include <iostream>
#include <vector>
using namespace std;

// Problem : 24_Valid_Sudoku_LC_36.cpp
// Pattern : Matrix Validation
// Approach : Validate every row, every column,
//            and every 3x3 box independently.
//
// Time  : O(9 × 9)
// Space : O(1)
//
// Learning:
// 1. Row Validation
// 2. Column Validation
// 3. 3×3 Box Traversal

bool isValidSudoku(const vector<vector<char>> &board)
{
    //--------------------------------------------------
    // Check every row.
    //--------------------------------------------------

    for (int i = 0; i < 9; i++)
    {
        bool seen[10] = {false};

        for (int j = 0; j < 9; j++)
        {
            if (board[i][j] == '.')
            {
                continue;
            }

            int number = board[i][j] - '0';

            if (seen[number])
            {
                return false;
            }

            seen[number] = true;
        }
    }

    //--------------------------------------------------
    // Check every column.
    //--------------------------------------------------

    for (int j = 0; j < 9; j++)
    {
        bool seen[10] = {false};

        for (int i = 0; i < 9; i++)
        {
            if (board[i][j] == '.')
            {
                continue;
            }

            int number = board[i][j] - '0';

            if (seen[number])
            {
                return false;
            }

            seen[number] = true;
        }
    }

    //--------------------------------------------------
    // Check every 3×3 box.
    //--------------------------------------------------

    for (int boxRow = 0; boxRow < 9; boxRow += 3)
    {
        for (int boxCol = 0; boxCol < 9; boxCol += 3)
        {
            bool seen[10] = {false};

            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    char current =
                        board[boxRow + i][boxCol + j];

                    if (current == '.')
                    {
                        continue;
                    }

                    int number = current - '0';

                    if (seen[number])
                    {
                        return false;
                    }

                    seen[number] = true;
                }
            }
        }
    }

    return true;
}

// Driver

int main()
{
    vector<vector<char>> board(9, vector<char>(9));

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> board[i][j];
        }
    }

    cout << (isValidSudoku(board) ? "True" : "False");

    return 0;
}