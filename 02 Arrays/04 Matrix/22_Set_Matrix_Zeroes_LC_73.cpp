#include <iostream>
#include <vector>
using namespace std;

// Problem : 22_Set_Matrix_Zeroes_LC_73.cpp
// Pattern : Matrix Marking
// Approach : Store rows and columns containing zero,
//            then update the matrix.
//
// Time  : O(rows × cols)
// Space : O(rows + cols)
//
// Learning:
// 1. Separate detection from modification.
// 2. Row Marker Array
// 3. Column Marker Array

void setZeroes(vector<vector<int>> &matrix)
{
    int rows = matrix.size();
    int cols = matrix[0].size();

    vector<bool> zeroRow(rows, false);
    vector<bool> zeroCol(cols, false);

    // Pass 1 : Find all original zeros.

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (matrix[i][j] == 0)
            {
                zeroRow[i] = true;
                zeroCol[j] = true;
            }
        }
    }

    // Pass 2 : Update matrix.

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (zeroRow[i] || zeroCol[j])
            {
                matrix[i][j] = 0;
            }
        }
    }
}

// Approach : Use first row and first column as marker arrays.
//
// Time  : O(rows × cols)
// Space : O(1)
//
// Learning:
// 1. Reuse matrix as marker storage.
// 2. Handle first row separately.
// 3. Handle first column separately.

void setZeroes(vector<vector<int>> &matrix)
{
    int rows = matrix.size();
    int cols = matrix[0].size();

    bool firstColZero = false;

    // Pass 1 : Store markers.

    for (int i = 0; i < rows; i++)
    {
        if (matrix[i][0] == 0)
        {
            firstColZero = true;
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

    // Pass 2 : Update remaining cells.

    for (int i = 1; i < rows; i++)
    {
        for (int j = 1; j < cols; j++)
        {
            if (matrix[i][0] == 0 || matrix[0][j] == 0)
            {
                matrix[i][j] = 0;
            }
        }
    }

    // Handle first row.

    if (matrix[0][0] == 0)
    {
        for (int j = 0; j < cols; j++)
        {
            matrix[0][j] = 0;
        }
    }

    // Handle first column.

    if (firstColZero)
    {
        for (int i = 0; i < rows; i++)
        {
            matrix[i][0] = 0;
        }
    }
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

    setZeroes(matrix);

    for (const auto &row : matrix)
    {
        for (int value : row)
        {
            cout << value << " ";
        }

        cout << endl;
    }

    return 0;
}