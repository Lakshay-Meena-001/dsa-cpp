#include <iostream>
#include <vector>
using namespace std;

// Problem : 27_Count_Negative_Numbers_In_A_Sorted_Matrix_LC_1351.cpp
// Pattern : Matrix Elimination
// Approach : Start from bottom-left.
//            If current is negative,
//            count remaining elements in the row.
//            Otherwise move right.
//
// Time  : O(rows + cols)
// Space : O(1)
//
// Learning:
// 1. Bottom-Left Traversal
// 2. Elimination Strategy
// 3. Count Multiple Cells Together

int countNegatives(const vector<vector<int>> &grid)
{
    int rows = grid.size();
    int cols = grid[0].size();

    int row = rows - 1;
    int col = 0;

    int count = 0;

    while (row >= 0 && col < cols)
    {
        int current = grid[row][col];

        // Current is negative.

        if (current < 0)
        {
            // Every element on the right
            // is also negative.

            count += cols - col;

            // Move upward.

            row--;
        }

        // Current is positive.

        else
        {
            // Search on the right.

            col++;
        }
    }

    return count;
}

// Driver

int main()
{
    int rows, cols;

    cin >> rows >> cols;

    vector<vector<int>> grid(rows, vector<int>(cols));

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cin >> grid[i][j];
        }
    }

    cout << countNegatives(grid);

    return 0;
}