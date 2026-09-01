#include <iostream>
#include <vector>
using namespace std;

//--------------------------------------------------
// Topic   : Matrix Validation
// File    : 10_Matrix_Validation.cpp
//
// Concepts:
// 1. Matrix Equality
// 2. Identity Matrix
// 3. Symmetric Matrix
// 4. Upper Triangular Matrix
// 5. Lower Triangular Matrix
// 6. Toeplitz Matrix
//
// Pattern : Matrix Validation
//
// Time  : O(rows × cols)
// Space : O(1)
//
// Learning:
// - Matrix comparison
// - Matrix properties
// - Coordinate relationships
// - Observation based validation
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
}

//--------------------------------------------------
// Check whether two matrices are equal.
//
// Every corresponding element must be equal.
//--------------------------------------------------
bool areMatricesEqual(const vector<vector<int>> &matrix1,
                      const vector<vector<int>> &matrix2)
{
    int rows = matrix1.size();
    int cols = matrix1[0].size();

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (matrix1[i][j] != matrix2[i][j])
            {
                return false;
            }
        }
    }

    return true;
}

//--------------------------------------------------
// Identity Matrix
//
// Main diagonal -> 1
// Remaining cells -> 0
//--------------------------------------------------
bool isIdentityMatrix(const vector<vector<int>> &matrix)
{
    int n = matrix.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                if (matrix[i][j] != 1)
                    return false;
            }
            else
            {
                if (matrix[i][j] != 0)
                    return false;
            }
        }
    }

    return true;
}

//--------------------------------------------------
// Symmetric Matrix
//
// matrix[i][j] == matrix[j][i]
//--------------------------------------------------
bool isSymmetricMatrix(const vector<vector<int>> &matrix)
{
    int n = matrix.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (matrix[i][j] != matrix[j][i])
            {
                return false;
            }
        }
    }

    return true;
}

//--------------------------------------------------
// Upper Triangular Matrix
//
// Elements below main diagonal must be zero.
//--------------------------------------------------
bool isUpperTriangular(const vector<vector<int>> &matrix)
{
    int n = matrix.size();

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (matrix[i][j] != 0)
            {
                return false;
            }
        }
    }

    return true;
}

//--------------------------------------------------
// Lower Triangular Matrix
//
// Elements above main diagonal must be zero.
//--------------------------------------------------
bool isLowerTriangular(const vector<vector<int>> &matrix)
{
    int n = matrix.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (matrix[i][j] != 0)
            {
                return false;
            }
        }
    }

    return true;
}

//--------------------------------------------------
// Toeplitz Matrix
//
// Every diagonal should contain same value.
//
// matrix[i][j] == matrix[i-1][j-1]
//--------------------------------------------------
bool isToeplitzMatrix(const vector<vector<int>> &matrix)
{
    int rows = matrix.size();
    int cols = matrix[0].size();

    for (int i = 1; i < rows; i++)
    {
        for (int j = 1; j < cols; j++)
        {
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

    cout << "Enter rows and columns : ";
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

    cout << "\nMatrix\n";
    printMatrix(matrix);

    //--------------------------------------------------
    // Equality Check
    //--------------------------------------------------
    cout << "\nMatrix Equal To Itself : "
         << (areMatricesEqual(matrix, matrix) ? "Yes" : "No");

    //--------------------------------------------------
    // Square Matrix Validations
    //--------------------------------------------------
    if (rows == cols)
    {
        cout << "\nIdentity Matrix        : "
             << (isIdentityMatrix(matrix) ? "Yes" : "No");

        cout << "\nSymmetric Matrix       : "
             << (isSymmetricMatrix(matrix) ? "Yes" : "No");

        cout << "\nUpper Triangular       : "
             << (isUpperTriangular(matrix) ? "Yes" : "No");

        cout << "\nLower Triangular       : "
             << (isLowerTriangular(matrix) ? "Yes" : "No");
    }
    else
    {
        cout << "\nSquare matrix validations skipped.";
    }

    //--------------------------------------------------
    // Toeplitz Check
    //--------------------------------------------------
    cout << "\nToeplitz Matrix        : "
         << (isToeplitzMatrix(matrix) ? "Yes" : "No");

    return 0;
}