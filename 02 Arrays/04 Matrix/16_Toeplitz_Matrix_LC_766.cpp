#include <iostream>
#include <vector>
using namespace std;

//--------------------------------------------------
// Problem : Toeplitz Matrix (LC 766)
// Pattern : Matrix Validation
//
// Time  : O(rows × cols)
// Space : O(1)
//
// Learning:
// 1. Diagonal Validation
// 2. Compare with Top Left
//--------------------------------------------------

bool isToeplitzMatrix(const vector<vector<int>> &matrix)
{
    int rows = matrix.size();
    int cols = matrix[0].size();

    // Skip first row and first column.
    for (int i = 1; i < rows; i++)
    {
        for (int j = 1; j < cols; j++)
        {
            // Current cell must match
            // its top-left neighbour.
            if (matrix[i][j] != matrix[i - 1][j - 1])
            {
                return false;
            }
        }
    }

    return true;
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

    cout << (isToeplitzMatrix(matrix) ? "True" : "False");

    return 0;
}