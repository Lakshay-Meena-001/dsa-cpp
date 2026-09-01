#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Problem : 21_Rotate_Image_LC_48.cpp
// Pattern : Matrix Transformation
// Approach : Transpose the matrix, then reverse every row.
//
// Time  : O(n²)
// Space : O(1)
//
// Learning:
// 1. In-place Transpose
// 2. Reverse Every Row
// 3. 90° Clockwise Rotation

void rotate(vector<vector<int>> &matrix)
{
    int n = matrix.size();

    // Transpose the matrix.

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    // Reverse every row.

    for (int i = 0; i < n; i++)
    {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}

// Driver

int main()
{
    int n;

    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }

    rotate(matrix);

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