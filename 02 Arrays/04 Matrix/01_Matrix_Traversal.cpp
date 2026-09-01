#include <iostream>
#include <vector>
using namespace std;

//--------------------------------------------------
// Topic   : Matrix Traversal
// File    : 01_Matrix_Traversal.cpp
//
// Concepts:
// 1. Print Matrix
// 2. Row Wise Traversal
// 3. Column Wise Traversal
// 4. Reverse Row Traversal
// 5. Reverse Column Traversal
//
// Pattern : Matrix Traversal
//
// Time  : O(rows × cols)
// Space : O(1)
//
// Learning:
// - Matrix indexing
// - Nested loops
// - Row vs Column traversal
// - Coordinate thinking
//--------------------------------------------------


// Print matrix in normal 2D format.

void printMatrix(const vector<vector<int>> &matrix)
{
    int rows = matrix.size();
    int cols = matrix[0].size();

    cout << "\nMatrix:\n";

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

//--------------------------------------------------
// Traverse matrix row by row.
// Pattern:
// → → →
// → → →
// → → →
//--------------------------------------------------

void rowWiseTraversal(const vector<vector<int>> &matrix)
{
    int rows = matrix.size();
    int cols = matrix[0].size();

    cout << "\nRow Wise Traversal:\n";

    // Visit every row.
    for (int i = 0; i < rows; i++)
    {
        // Visit every column inside current row.
        for (int j = 0; j < cols; j++)
        {
            cout << matrix[i][j] << " ";
        }
    }

    cout << endl;
}

//--------------------------------------------------
// Traverse matrix column by column.
// Pattern:
// ↓ ↓ ↓
// ↓ ↓ ↓
//--------------------------------------------------

void columnWiseTraversal(const vector<vector<int>> &matrix)
{
    int rows = matrix.size();
    int cols = matrix[0].size();

    cout << "\nColumn Wise Traversal:\n";

    // Visit every column.
    for (int j = 0; j < cols; j++)
    {
        // Visit every row inside current column.
        for (int i = 0; i < rows; i++)
        {
            cout << matrix[i][j] << " ";
        }
    }

    cout << endl;
}

//--------------------------------------------------
// Traverse every row from right to left.
// Pattern:
// ← ← ←
// ← ← ←
//--------------------------------------------------

void reverseRowTraversal(const vector<vector<int>> &matrix)
{
    int rows = matrix.size();
    int cols = matrix[0].size();

    cout << "\nReverse Row Traversal:\n";

    // Visit every row.
    for (int i = 0; i < rows; i++)
    {
        // Traverse current row in reverse order.
        for (int j = cols - 1; j >= 0; j--)
        {
            cout << matrix[i][j] << " ";
        }
    }

    cout << endl;
}

//--------------------------------------------------
// Traverse every column from bottom to top.
// Pattern:
// ↑ ↑ ↑
// ↑ ↑ ↑
//--------------------------------------------------

void reverseColumnTraversal(const vector<vector<int>> &matrix)
{
    int rows = matrix.size();
    int cols = matrix[0].size();

    cout << "\nReverse Column Traversal:\n";

    // Visit every column.
    for (int j = 0; j < cols; j++)
    {
        // Traverse current column in reverse order.
        for (int i = rows - 1; i >= 0; i--)
        {
            cout << matrix[i][j] << " ";
        }
    }

    cout << endl;
}

int main()
{
    int rows, cols;

    cout << "Enter number of rows and columns: ";
    cin >> rows >> cols;

    vector<vector<int>> matrix(rows, vector<int>(cols));

    cout << "Enter matrix elements:\n";

    // Input matrix.
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cin >> matrix[i][j];
        }
    }

    printMatrix(matrix);

    rowWiseTraversal(matrix);

    columnWiseTraversal(matrix);

    reverseRowTraversal(matrix);

    reverseColumnTraversal(matrix);

    return 0;
}