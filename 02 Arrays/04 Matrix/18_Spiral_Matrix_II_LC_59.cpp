#include <iostream>
#include <vector>
using namespace std;

// Problem : 18_Spiral_Matrix_II_LC_59.cpp
// Pattern : Boundary Shrinking + Simulation
// Approach : Fill the matrix layer by layer while shrinking boundaries.
//
// Time  : O(n²)
// Space : O(1) (Ignoring output matrix)
//
// Learning:
// 1. Boundary Shrinking
// 2. Spiral Filling
// 3. Simulation

vector<vector<int>> generateMatrix(int n)
{
    vector<vector<int>> matrix(n, vector<int>(n));

    int top = 0;
    int bottom = n - 1;
    int left = 0;
    int right = n - 1;

    int value = 1;

    while (top <= bottom && left <= right)
    {
        // Fill Top Row.

        for (int j = left; j <= right; j++)
        {
            matrix[top][j] = value++;
        }

        top++;

        // Fill Right Column.

        for (int i = top; i <= bottom; i++)
        {
            matrix[i][right] = value++;
        }

        right--;

        // Fill Bottom Row.

        if (top <= bottom)
        {
            for (int j = right; j >= left; j--)
            {
                matrix[bottom][j] = value++;
            }

            bottom--;
        }

        // Fill Left Column.

        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
            {
                matrix[i][left] = value++;
            }

            left++;
        }
    }

    return matrix;
}

// Driver

int main()
{
    int n;

    cin >> n;

    vector<vector<int>> answer = generateMatrix(n);

    for (const auto &row : answer)
    {
        for (int value : row)
        {
            cout << value << " ";
        }

        cout << endl;
    }

    return 0;
}