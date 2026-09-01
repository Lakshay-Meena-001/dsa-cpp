#include <iostream>
#include <vector>
using namespace std;

// Problem : 25_Search_A_2D_Matrix_LC_74.cpp
// Pattern : Binary Search on Flattened Matrix
// Approach : Treat the matrix as a sorted 1D array
//            and convert 1D index back to 2D coordinates.
//
// Time  : O(log(rows × cols))
// Space : O(1)
//
// Learning:
// 1. Flatten Matrix Concept
// 2. Index → (Row, Column)
// 3. Binary Search

bool searchMatrix(const vector<vector<int>> &matrix, int target)
{
    int rows = matrix.size();
    int cols = matrix[0].size();

    int low = 0;
    int high = rows * cols - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        // Convert 1D index into 2D coordinates.

        int row = mid / cols;
        int col = mid % cols;

        if (matrix[row][col] == target)
        {
            return true;
        }

        if (matrix[row][col] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return false;
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

    int target;
    cin >> target;

    cout << (searchMatrix(matrix, target) ? "True" : "False");

    return 0;
}