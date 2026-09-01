#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//--------------------------------------------------
// Topic   : Matrix Transformations
// File    : 09_Matrix_Transformations.cpp
//
// Concepts:
// 1. Transpose Matrix
// 2. Horizontal Flip
// 3. Vertical Flip
// 4. Rotate 90° Clockwise
// 5. Rotate 90° Anti-Clockwise
// 6. Rotate 180°
//
// Pattern : Coordinate Transformation
//
// Time  : O(n²)
// Space : O(1)
//
// Learning:
// - Coordinate mapping
// - In-place transformation
// - Reverse operations
// - Rotation intuition
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

    cout << endl;
}

//--------------------------------------------------
// Transpose Square Matrix.
//
// (i,j) -> (j,i)
//
// Swap only upper triangle.
//--------------------------------------------------
void transpose(vector<vector<int>> &matrix)
{
    int n = matrix.size();

    for (int i = 0; i < n; i++)
    {
        // Start from i+1 to avoid double swapping.
        for (int j = i + 1; j < n; j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
}

//--------------------------------------------------
// Reverse order of rows.
//
// Top <-> Bottom
//--------------------------------------------------
void horizontalFlip(vector<vector<int>> &matrix)
{
    int top = 0;
    int bottom = matrix.size() - 1;

    while (top < bottom)
    {
        swap(matrix[top], matrix[bottom]);

        top++;
        bottom--;
    }
}

//--------------------------------------------------
// Reverse every row.
//
// Left <-> Right
//--------------------------------------------------
void verticalFlip(vector<vector<int>> &matrix)
{
    for (auto &row : matrix)
    {
        reverse(row.begin(), row.end());
    }
}

//--------------------------------------------------
// Rotate 90 Degree Clockwise.
//
// Step 1 : Transpose
// Step 2 : Reverse every row
//--------------------------------------------------
void rotate90Clockwise(vector<vector<int>> &matrix)
{
    transpose(matrix);

    verticalFlip(matrix);
}

//--------------------------------------------------
// Rotate 90 Degree Anti-Clockwise.
//
// Step 1 : Transpose
// Step 2 : Reverse every column
//--------------------------------------------------
void rotate90AntiClockwise(vector<vector<int>> &matrix)
{
    transpose(matrix);

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
// Rotate 180 Degree.
//
// Reverse rows
// +
// Reverse columns
//--------------------------------------------------
void rotate180(vector<vector<int>> &matrix)
{
    horizontalFlip(matrix);

    verticalFlip(matrix);
}

int main()
{
    int n;

    cout << "Enter size of square matrix : ";
    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n));

    cout << "Enter matrix:\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }

    cout << "\nOriginal Matrix\n";
    printMatrix(matrix);

    //--------------------------------------------------
    // Transpose
    //--------------------------------------------------
    auto transposeMatrix = matrix;

    transpose(transposeMatrix);

    cout << "Transpose\n";
    printMatrix(transposeMatrix);

    //--------------------------------------------------
    // Horizontal Flip
    //--------------------------------------------------
    auto horizontalMatrix = matrix;

    horizontalFlip(horizontalMatrix);

    cout << "Horizontal Flip\n";
    printMatrix(horizontalMatrix);

    //--------------------------------------------------
    // Vertical Flip
    //--------------------------------------------------
    auto verticalMatrix = matrix;

    verticalFlip(verticalMatrix);

    cout << "Vertical Flip\n";
    printMatrix(verticalMatrix);

    //--------------------------------------------------
    // Rotate 90 Clockwise
    //--------------------------------------------------
    auto clockwiseMatrix = matrix;

    rotate90Clockwise(clockwiseMatrix);

    cout << "Rotate 90 Clockwise\n";
    printMatrix(clockwiseMatrix);

    //--------------------------------------------------
    // Rotate 90 Anti-Clockwise
    //--------------------------------------------------
    auto antiClockwiseMatrix = matrix;

    rotate90AntiClockwise(antiClockwiseMatrix);

    cout << "Rotate 90 Anti-Clockwise\n";
    printMatrix(antiClockwiseMatrix);

    //--------------------------------------------------
    // Rotate 180
    //--------------------------------------------------
    auto rotate180Matrix = matrix;

    rotate180(rotate180Matrix);

    cout << "Rotate 180 Degree\n";
    printMatrix(rotate180Matrix);

    return 0;
}