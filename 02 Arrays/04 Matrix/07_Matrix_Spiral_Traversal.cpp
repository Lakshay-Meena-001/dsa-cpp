#include <iostream>
#include <vector>
using namespace std;

//--------------------------------------------------
// Topic   : Matrix Spiral Traversal
// File    : 07_Matrix_Spiral_Traversal.cpp
//
// Concepts:
// 1. Clockwise Spiral Traversal
// 2. Anti-Clockwise Spiral Traversal
// 3. Boundary Shrinking
//
// Pattern : Simulation
//
// Time  : O(rows × cols)
// Space : O(1)
//
// Learning:
// - Layer by layer traversal
// - Four boundary pointers
// - Simulation thinking
// - Boundary shrinking
//--------------------------------------------------

//--------------------------------------------------
// Print matrix in clockwise spiral order.
//
// Order:
// Top Row
// Right Column
// Bottom Row
// Left Column
//--------------------------------------------------
void clockwiseSpiralTraversal(const vector<vector<int>> &matrix)
{
    int rows = matrix.size();
    int cols = matrix[0].size();

    int top = 0;
    int bottom = rows - 1;
    int left = 0;
    int right = cols - 1;

    cout << "\nClockwise Spiral Traversal:\n";

    // Continue until boundaries overlap.
    while (top <= bottom && left <= right)
    {
        // Traverse top row.
        for (int j = left; j <= right; j++)
        {
            cout << matrix[top][j] << " ";
        }
        top++;

        // Traverse right column.
        for (int i = top; i <= bottom; i++)
        {
            cout << matrix[i][right] << " ";
        }
        right--;

        // Traverse bottom row.
        if (top <= bottom)
        {
            for (int j = right; j >= left; j--)
            {
                cout << matrix[bottom][j] << " ";
            }
            bottom--;
        }

        // Traverse left column.
        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
            {
                cout << matrix[i][left] << " ";
            }
            left++;
        }
    }

    cout << endl;
}

//--------------------------------------------------
// Print matrix in anti-clockwise spiral order.
//
// Order:
// Left Column
// Bottom Row
// Right Column
// Top Row
//--------------------------------------------------
void antiClockwiseSpiralTraversal(const vector<vector<int>> &matrix)
{
    int rows = matrix.size();
    int cols = matrix[0].size();

    int top = 0;
    int bottom = rows - 1;
    int left = 0;
    int right = cols - 1;

    cout << "\nAnti-Clockwise Spiral Traversal:\n";

    while (top <= bottom && left <= right)
    {
        // Traverse left column.
        for (int i = top; i <= bottom; i++)
        {
            cout << matrix[i][left] << " ";
        }
        left++;

        // Traverse bottom row.
        for (int j = left; j <= right; j++)
        {
            cout << matrix[bottom][j] << " ";
        }
        bottom--;

        // Traverse right column.
        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
            {
                cout << matrix[i][right] << " ";
            }
            right--;
        }

        // Traverse top row.
        if (top <= bottom)
        {
            for (int j = right; j >= left; j--)
            {
                cout << matrix[top][j] << " ";
            }
            top++;
        }
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

    // Input matrix.
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cin >> matrix[i][j];
        }
    }

    clockwiseSpiralTraversal(matrix);

    antiClockwiseSpiralTraversal(matrix);

    return 0;
}