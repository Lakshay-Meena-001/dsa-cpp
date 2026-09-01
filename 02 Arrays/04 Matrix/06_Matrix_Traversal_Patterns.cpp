#include <iostream>
#include <vector>
using namespace std;

//--------------------------------------------------
// Topic   : Matrix Traversal Patterns
// File    : 06_Matrix_Traversal_Patterns.cpp
//
// Concepts:
// 1. Boundary Traversal
// 2. Wave Traversal
// 3. Zigzag Traversal
// 4. Main Diagonal Traversal
// 5. Anti-Diagonal Traversal
//
// Pattern : Matrix Traversal
//
// Time  : O(rows × cols)
// Space : O(1)
//
// Learning:
// - Fixed traversal paths
// - Direction changes
// - Boundary observation
// - Diagonal grouping
//--------------------------------------------------

//--------------------------------------------------
// Print boundary elements.
//
// Order:
// Top
// Right
// Bottom
// Left
//--------------------------------------------------
void boundaryTraversal(const vector<vector<int>> &matrix)
{
    int rows = matrix.size();
    int cols = matrix[0].size();

    cout << "\nBoundary Traversal:\n";

    // Single row.
    if (rows == 1)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << matrix[0][j] << " ";
        }

        cout << endl;
        return;
    }

    // Single column.
    if (cols == 1)
    {
        for (int i = 0; i < rows; i++)
        {
            cout << matrix[i][0] << " ";
        }

        cout << endl;
        return;
    }

    // Top row.
    for (int j = 0; j < cols; j++)
    {
        cout << matrix[0][j] << " ";
    }

    // Right column.
    for (int i = 1; i < rows; i++)
    {
        cout << matrix[i][cols - 1] << " ";
    }

    // Bottom row.
    for (int j = cols - 2; j >= 0; j--)
    {
        cout << matrix[rows - 1][j] << " ";
    }

    // Left column.
    for (int i = rows - 2; i >= 1; i--)
    {
        cout << matrix[i][0] << " ";
    }

    cout << endl;
}

//--------------------------------------------------
// Print matrix in wave form.
//
// Even column  : Top -> Bottom
// Odd column   : Bottom -> Top
//--------------------------------------------------
void waveTraversal(const vector<vector<int>> &matrix)
{
    int rows = matrix.size();
    int cols = matrix[0].size();

    cout << "\nWave Traversal:\n";

    for (int j = 0; j < cols; j++)
    {
        if (j % 2 == 0)
        {
            for (int i = 0; i < rows; i++)
            {
                cout << matrix[i][j] << " ";
            }
        }
        else
        {
            for (int i = rows - 1; i >= 0; i--)
            {
                cout << matrix[i][j] << " ";
            }
        }
    }

    cout << endl;
}

//--------------------------------------------------
// Print matrix in zigzag form.
//
// Even row : Left -> Right
// Odd row  : Right -> Left
//--------------------------------------------------
void zigzagTraversal(const vector<vector<int>> &matrix)
{
    int rows = matrix.size();
    int cols = matrix[0].size();

    cout << "\nZigzag Traversal:\n";

    for (int i = 0; i < rows; i++)
    {
        if (i % 2 == 0)
        {
            for (int j = 0; j < cols; j++)
            {
                cout << matrix[i][j] << " ";
            }
        }
        else
        {
            for (int j = cols - 1; j >= 0; j--)
            {
                cout << matrix[i][j] << " ";
            }
        }
    }

    cout << endl;
}

//--------------------------------------------------
// Print main diagonal.
//
// Condition:
// row == column
//--------------------------------------------------
void mainDiagonalTraversal(const vector<vector<int>> &matrix)
{
    int n = matrix.size();

    cout << "\nMain Diagonal:\n";

    for (int i = 0; i < n; i++)
    {
        cout << matrix[i][i] << " ";
    }

    cout << endl;
}

//--------------------------------------------------
// Print anti-diagonal.
//
// Condition:
// row + column = n - 1
//--------------------------------------------------
void antiDiagonalTraversal(const vector<vector<int>> &matrix)
{
    int n = matrix.size();

    cout << "\nAnti Diagonal:\n";

    for (int i = 0; i < n; i++)
    {
        cout << matrix[i][n - 1 - i] << " ";
    }

    cout << endl;
}

int main()
{
    int rows, cols;

    cout << "Enter rows and columns: ";
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

    boundaryTraversal(matrix);

    waveTraversal(matrix);

    zigzagTraversal(matrix);

    if (rows == cols)
    {
        mainDiagonalTraversal(matrix);
        antiDiagonalTraversal(matrix);
    }
    else
    {
        cout << "\nDiagonal traversal requires a square matrix.\n";
    }

    return 0;
}