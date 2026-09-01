#include <iostream>
#include <vector>
using namespace std;

// Problem : 26_Search_A_2D_Matrix_II_LC_240.cpp
// Pattern : Matrix Elimination
// Approach : Start from the top-right corner.
//            If current > target, move left.
//            If current < target, move down.
//
// Time  : O(rows + cols)
// Space : O(1)
//
// Learning:
// 1. Row & Column Sorted Matrix
// 2. Elimination Strategy
// 3. Top-Right Traversal

bool searchMatrix(const vector<vector<int>> &matrix, int target)
{
    int rows = matrix.size();
    int cols = matrix[0].size();

    // Start from top-right corner.

    int row = 0;
    int col = cols - 1;

    // row because we are moving downwards and col because we are moving leftwards.
    while (row < rows && col >= 0)
    {
        int current = matrix[row][col];

        // Target found.

        if (current == target)
        {
            return true;
        }

        // Current is too large.
        // Remove current column.

        if (current > target)
        {
            col--;
        }

        // Current is too small.
        // Remove current row.

        else
        {
            row++;
        }
    }

    return false;
}

// Driver

int main()
{
    int rows, cols;

    cin >> rows >> cols;

    vector<vector<int>> matrix(rows, vector<int>(cols));

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cin >> matrix[i][j];
        }
    }

    int target;
    cin >> target;

    cout << (searchMatrix(matrix, target) ? "True" : "False");

    return 0;
}