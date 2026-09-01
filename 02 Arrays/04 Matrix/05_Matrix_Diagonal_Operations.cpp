#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

//--------------------------------------------------
// Topic   : Matrix Diagonal Operations
// File    : 05_Matrix_Diagonal_Operations.cpp
//
// Concepts:
// 1. Print Main Diagonal
// 2. Print Secondary Diagonal
// 3. Main Diagonal Sum
// 4. Secondary Diagonal Sum
// 5. Matrix Trace
// 6. Absolute Diagonal Difference
//
// Pattern : Diagonal Observation
//
// Time  : O(n)
// Space : O(1)
//
// Learning:
// - Diagonal indexing
// - Coordinate relationship
// - Square matrix properties
//--------------------------------------------------

//--------------------------------------------------
// Print Main Diagonal.
//
// Condition:
// row == column
//--------------------------------------------------

void printMainDiagonal(const vector<vector<int>> &matrix)
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
// Print Secondary Diagonal.
//
// Condition:
// row + column == n - 1
//--------------------------------------------------
void printSecondaryDiagonal(const vector<vector<int>> &matrix)
{
    int n = matrix.size();

    cout << "\nSecondary Diagonal:\n";

    for (int i = 0; i < n; i++)
    {
        cout << matrix[i][n - 1 - i] << " ";
    }

    cout << endl;
}

//--------------------------------------------------
// Calculate Main Diagonal Sum.
//--------------------------------------------------
int mainDiagonalSum(const vector<vector<int>> &matrix)
{
    int n = matrix.size();

    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += matrix[i][i];
    }

    return sum;
}

//--------------------------------------------------
// Calculate Secondary Diagonal Sum.
//--------------------------------------------------
int secondaryDiagonalSum(const vector<vector<int>> &matrix)
{
    int n = matrix.size();

    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += matrix[i][n - 1 - i];
    }

    return sum;
}

//--------------------------------------------------
// Matrix Trace.
//
// Trace = Sum of Main Diagonal.
//--------------------------------------------------
int matrixTrace(const vector<vector<int>> &matrix)
{
    return mainDiagonalSum(matrix);
}

//--------------------------------------------------
// Absolute Difference Between Diagonal Sums.
//--------------------------------------------------
int diagonalDifference(const vector<vector<int>> &matrix)
{
    int mainSum = mainDiagonalSum(matrix);
    int secondarySum = secondaryDiagonalSum(matrix);

    return abs(mainSum - secondarySum);
}

int main()
{
    int n;

    cout << "Enter size of square matrix: ";
    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n));

    cout << "Enter matrix:\n";

    // Input matrix.
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }

    printMainDiagonal(matrix);

    printSecondaryDiagonal(matrix);

    cout << "\nMain Diagonal Sum      : "
         << mainDiagonalSum(matrix);

    cout << "\nSecondary Diagonal Sum : "
         << secondaryDiagonalSum(matrix);

    cout << "\nMatrix Trace           : "
         << matrixTrace(matrix);

    cout << "\nDiagonal Difference    : "
         << diagonalDifference(matrix);

    return 0;
}