#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//--------------------------------------------------
// Problem: rotate_image_lc_48.cpp
// Pattern : Matrix Rearrangement
// Constraint:
// 1. Matrix is n x n
// 2. Rotate in-place
// Time : O(n²)
// Space: O(1)
//--------------------------------------------------

void rotateImageOptimal(vector<vector<int>> &matrix)
{
    int n = matrix.size();

    // Transpose matrix.
    for (int row = 0; row < n; row++)
    {
        // Start from row+1 to avoid swapping twice.
        for (int col = row + 1; col < n; col++)
        {
            swap(matrix[row][col], matrix[col][row]);
        }
    }

    // Reverse every row.
    for (int row = 0; row < n; row++)
    {
        reverse(matrix[row].begin(), matrix[row].end());
    }
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n));

    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            cin >> matrix[row][col];
        }
    }

    rotateImageOptimal(matrix);

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