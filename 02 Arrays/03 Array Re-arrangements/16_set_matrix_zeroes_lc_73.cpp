#include <iostream>
#include <vector>
using namespace std;

//--------------------------------------------------
// Problem: set_matrix_zeroes_lc_73.cpp
// Pattern : Matrix Marking
// Time : O(m*n)
// Space: O(m+n)
//--------------------------------------------------

void setZeroesBetter(vector<vector<int>> &matrix)
{
    int rows = matrix.size();
    int cols = matrix[0].size();

    vector<int> row(rows, 0);
    vector<int> col(cols, 0);

    // Mark rows and columns containing zero.
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (matrix[i][j] == 0)
            {
                row[i] = 1;
                col[j] = 1;
            }
        }
    }

    // Update matrix using markers.
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (row[i] || col[j])
            {
                matrix[i][j] = 0;
            }
        }
    }
}

//--------------------------------------------------
// Problem: set_matrix_zeroes_lc_73.cpp
// Pattern : Matrix Marking
// Constraint:
// 1. Modify matrix in-place
// 2. First row & first column are used as markers
// Time : O(m*n)
// Space: O(1)
//--------------------------------------------------

void setZeroesOptimal(vector<vector<int>> &matrix)
{
    int rows = matrix.size();
    int cols = matrix[0].size();

    int col0 = 1;

    // Store markers in first row & first column.
    for (int i = 0; i < rows; i++)
    {
        if (matrix[i][0] == 0)
        {
            col0 = 0;
        }

        for (int j = 1; j < cols; j++)
        {
            if (matrix[i][j] == 0)
            {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    // Traverse backwards so markers are not destroyed early.
    for (int i = rows - 1; i >= 0; i--)
    {
        for (int j = cols - 1; j >= 1; j--)
        {
            if (matrix[i][0] == 0 || matrix[0][j] == 0)
            {
                matrix[i][j] = 0;
            }
        }

        if (col0 == 0)
        {
            matrix[i][0] = 0;
        }
    }
}