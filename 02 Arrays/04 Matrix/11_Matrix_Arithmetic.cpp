#include <iostream>
#include <vector>
using namespace std;

//--------------------------------------------------
// Topic   : Matrix Arithmetic
// File    : 11_Matrix_Arithmetic.cpp
//
// Concepts:
// 1. Matrix Addition
// 2. Matrix Subtraction
// 3. Scalar Multiplication
// 4. Matrix Multiplication
//
// Pattern : Matrix Arithmetic
//
// Time:
// Addition            : O(rows × cols)
// Subtraction         : O(rows × cols)
// Scalar Multiplication : O(rows × cols)
// Matrix Multiplication : O(r1 × c1 × c2)
//
// Space : O(rows × cols)
//
// Learning:
// - Element-wise operations
// - Matrix multiplication
// - Triple nested loops
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
// Matrix Addition.
//
// Both matrices must have same dimensions.
//--------------------------------------------------
vector<vector<int>> addMatrices(const vector<vector<int>> &A, const vector<vector<int>> &B)
{
    int rows = A.size();
    int cols = A[0].size();

    vector<vector<int>> result(rows, vector<int>(cols));

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result[i][j] = A[i][j] + B[i][j];
        }
    }

    return result;
}

//--------------------------------------------------
// Matrix Subtraction.
//--------------------------------------------------
vector<vector<int>> subtractMatrices(const vector<vector<int>> &A, const vector<vector<int>> &B)
{
    int rows = A.size();
    int cols = A[0].size();

    vector<vector<int>> result(rows, vector<int>(cols));

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result[i][j] = A[i][j] - B[i][j];
        }
    }

    return result;
}

//--------------------------------------------------
// Scalar Multiplication.
//
// Multiply every element by scalar.
//--------------------------------------------------
vector<vector<int>> scalarMultiplication(const vector<vector<int>> &matrix, int scalar)
{
    int rows = matrix.size();
    int cols = matrix[0].size();

    vector<vector<int>> result(rows, vector<int>(cols));

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result[i][j] = matrix[i][j] * scalar;
        }
    }

    return result;
}

//--------------------------------------------------
// Matrix Multiplication.
//
// A = r1 × c1
// B = c1 × c2
//
// Result = r1 × c2
//--------------------------------------------------
vector<vector<int>> multiplyMatrices(const vector<vector<int>> &A, const vector<vector<int>> &B)
{
    int r1 = A.size();
    int c1 = A[0].size();

    int c2 = B[0].size();

    vector<vector<int>> result(r1, vector<int>(c2, 0));

    // Pick one row from A.
    for (int i = 0; i < r1; i++)
    {
        // Pick one column from B.
        for (int j = 0; j < c2; j++)
        {
            // Multiply corresponding elements.
            for (int k = 0; k < c1; k++)
            {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    return result;
}

int main()
{
    int rows, cols;

    cout << "Enter rows and columns : ";
    cin >> rows >> cols;

    vector<vector<int>> A(rows, vector<int>(cols));
    vector<vector<int>> B(rows, vector<int>(cols));

    cout << "Enter Matrix A:\n";

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cin >> A[i][j];
        }
    }

    cout << "Enter Matrix B:\n";

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cin >> B[i][j];
        }
    }

    //--------------------------------------------------
    // Matrix Addition
    //--------------------------------------------------
    cout << "\nAddition\n";

    printMatrix(addMatrices(A, B));

    //--------------------------------------------------
    // Matrix Subtraction
    //--------------------------------------------------
    cout << "\nSubtraction\n";

    printMatrix(subtractMatrices(A, B));

    //--------------------------------------------------
    // Scalar Multiplication
    //--------------------------------------------------
    int scalar;

    cout << "\nEnter scalar : ";
    cin >> scalar;

    cout << "\nScalar Multiplication\n";

    printMatrix(scalarMultiplication(A, scalar));

    //--------------------------------------------------
    // Matrix Multiplication
    //--------------------------------------------------
    if (cols == B.size())
    {
        cout << "\nMatrix Multiplication\n";

        printMatrix(multiplyMatrices(A, B));
    }
    else
    {
        cout << "\nMatrix multiplication not possible.\n";
    }

    return 0;
}