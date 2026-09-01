#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//--------------------------------------------------
// Topic   : Matrix Modification
// File    : 08_Matrix_Modification.cpp
//
// Concepts:
// 1. Swap Two Rows
// 2. Swap Two Columns
// 3. Reverse Every Row
// 4. Reverse Every Column
// 5. Replace Entire Row
// 6. Replace Entire Column
//
// Pattern : In-place Modification
//
// Time  : O(rows × cols)
// Space : O(1)
//
// Learning:
// - In-place updates
// - Swapping
// - Row modification
// - Column modification
//--------------------------------------------------

//--------------------------------------------------
// Print matrix.
//--------------------------------------------------
void printMatrix(const vector<vector<int>> &matrix)
{
    for (const auto &row : matrix)
    {
        for (int value : row)
        {
            cout << value << " ";
        }
        cout << endl;
    }
}

//--------------------------------------------------
// Swap two rows.
//--------------------------------------------------
void swapRows(vector<vector<int>> &matrix, int row1, int row2)
{
    swap(matrix[row1], matrix[row2]);
}

//--------------------------------------------------
// Swap two columns.
//--------------------------------------------------
void swapColumns(vector<vector<int>> &matrix, int col1, int col2)
{
    int rows = matrix.size();

    for (int i = 0; i < rows; i++)
    {
        swap(matrix[i][col1], matrix[i][col2]);
    }
}

//--------------------------------------------------
// Reverse every row.
//--------------------------------------------------
void reverseRows(vector<vector<int>> &matrix)
{
    for (auto &row : matrix)
    {
        reverse(row.begin(), row.end());
    }
}

//--------------------------------------------------
// Reverse every column.
//--------------------------------------------------
void reverseColumns(vector<vector<int>> &matrix)
{
    int rows = matrix.size();
    int cols = matrix[0].size();

    for (int j = 0; j < cols; j++)
    {
        int top = 0;
        int bottom = rows - 1;

        while (top < bottom)
        {
            swap(matrix[top][j], matrix[bottom][j]);

            top++;
            bottom--;
        }
    }
}

//--------------------------------------------------
// Replace one complete row.
//--------------------------------------------------
void replaceRow(vector<vector<int>> &matrix, int row, const vector<int> &newRow)
{
    matrix[row] = newRow;
}

//--------------------------------------------------
// Replace one complete column.
//--------------------------------------------------
void replaceColumn(vector<vector<int>> &matrix, int col, const vector<int> &newColumn)
{
    int rows = matrix.size();

    for (int i = 0; i < rows; i++)
    {
        matrix[i][col] = newColumn[i];
    }
}

int main()
{
    int rows, cols;

    cout << "Enter rows and columns : ";
    cin >> rows >> cols;

    vector<vector<int>> matrix(rows, vector<int>(cols));

    cout << "Enter matrix:\n";

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cin >> matrix[i][j];
        }
    }

    cout << "\nOriginal Matrix\n";
    printMatrix(matrix);

    //--------------------------------------------------
    // Swap Rows
    //--------------------------------------------------
    swapRows(matrix, 0, rows - 1);

    cout << "\nAfter Swapping First & Last Row\n";
    printMatrix(matrix);

    //--------------------------------------------------
    // Swap Columns
    //--------------------------------------------------
    swapColumns(matrix, 0, cols - 1);

    cout << "\nAfter Swapping First & Last Column\n";
    printMatrix(matrix);

    //--------------------------------------------------
    // Reverse Rows
    //--------------------------------------------------
    reverseRows(matrix);

    cout << "\nAfter Reversing Every Row\n";
    printMatrix(matrix);

    //--------------------------------------------------
    // Reverse Columns
    //--------------------------------------------------
    reverseColumns(matrix);

    cout << "\nAfter Reversing Every Column\n";
    printMatrix(matrix);

    //--------------------------------------------------
    // Replace Row
    //--------------------------------------------------
    vector<int> newRow(cols, 100);

    replaceRow(matrix, 0, newRow);

    cout << "\nAfter Replacing First Row\n";
    printMatrix(matrix);

    //--------------------------------------------------
    // Replace Column
    //--------------------------------------------------
    vector<int> newColumn(rows, 999);

    replaceColumn(matrix, 0, newColumn);

    cout << "\nAfter Replacing First Column\n";
    printMatrix(matrix);

    return 0;
}