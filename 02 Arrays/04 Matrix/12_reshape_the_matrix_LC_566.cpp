#include <iostream>
#include <vector>
using namespace std;

//--------------------------------------------------
// Problem : Reshape the Matrix (LC 566)
// Pattern : Coordinate Mapping
//
// Time  : O(rows × cols)
// Space : O(r × c)
//
// Learning:
// 1. Linear Index
// 2. Coordinate Mapping
// 3. Matrix Traversal
//--------------------------------------------------

vector<vector<int>> matrixReshape(const vector<vector<int>> &matrix, int r, int c)
{
    int rows = matrix.size();
    int cols = matrix[0].size();

    // Reshape not possible.
    if (rows * cols != r * c)
    {
        return matrix;
    }

    vector<vector<int>> result(r, vector<int>(c));

    // Visit every element of original matrix.
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            // Convert current coordinate into linear index.
            int index = i * cols + j;

            // Find new coordinate.
            int newRow = index / c;
            int newCol = index % c;

            result[newRow][newCol] = matrix[i][j];
        }
    }

    return result;
}

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

    int newRows, newCols;

    cin >> newRows >> newCols;

    vector<vector<int>> answer =
        matrixReshape(matrix, newRows, newCols);

    printMatrix(answer);

    return 0;
}