#include <iostream>
#include <vector>
#include <climits>
using namespace std;

//--------------------------------------------------
// Topic   : Matrix Row Operations
// File    : 03_Matrix_Row_Operations.cpp
//
// Concepts:
// 1. Print Every Row
// 2. Row Sum
// 3. Row Average
// 4. Row Maximum Element
// 5. Row Minimum Element
// 6. Row With Maximum Sum
// 7. Row With Minimum Sum
//
// Pattern : Row Observation
//
// Time  : O(rows × cols)
// Space : O(1)
//
// Learning:
// - Process one complete row at a time
// - Running sum
// - Running maximum
// - Running minimum
// - Best row selection
//--------------------------------------------------

//--------------------------------------------------
// Print every row separately.
//--------------------------------------------------
void printRows(const vector<vector<int>> &matrix)
{
    int rows = matrix.size();
    int cols = matrix[0].size();

    cout << "\nRows:\n";

    for (int i = 0; i < rows; i++)
    {
        cout << "Row " << i << " : ";

        for (int j = 0; j < cols; j++)
        {
            cout << matrix[i][j] << " ";
        }

        cout << endl;
    }
}

//--------------------------------------------------
// Print sum of every row.
//--------------------------------------------------
void rowSum(const vector<vector<int>> &matrix)
{
    int rows = matrix.size();
    int cols = matrix[0].size();

    cout << "\nRow Sum:\n";

    for (int i = 0; i < rows; i++)
    {
        int sum = 0;

        // Add all elements of current row.
        for (int j = 0; j < cols; j++)
        {
            sum += matrix[i][j];
        }

        cout << "Row " << i << " = " << sum << endl;
    }
}

//--------------------------------------------------
// Print average of every row.
//--------------------------------------------------
void rowAverage(const vector<vector<int>> &matrix)
{
    int rows = matrix.size();
    int cols = matrix[0].size();

    cout << "\nRow Average:\n";

    for (int i = 0; i < rows; i++)
    {
        int sum = 0;

        for (int j = 0; j < cols; j++)
        {
            sum += matrix[i][j];
        }

        cout << "Row " << i << " = " << (double)sum / cols << endl;
    }
}

//--------------------------------------------------
// Print maximum element of every row.
//--------------------------------------------------
void rowMaximum(const vector<vector<int>> &matrix)
{
    int rows = matrix.size();
    int cols = matrix[0].size();

    cout << "\nRow Maximum:\n";

    for (int i = 0; i < rows; i++)
    {
        int maximum = INT_MIN;

        // Find maximum in current row.
        for (int j = 0; j < cols; j++)
        {
            maximum = max(maximum, matrix[i][j]);
        }

        cout << "Row " << i << " = " << maximum << endl;
    }
}

//--------------------------------------------------
// Print minimum element of every row.
//--------------------------------------------------
void rowMinimum(const vector<vector<int>> &matrix)
{
    int rows = matrix.size();
    int cols = matrix[0].size();

    cout << "\nRow Minimum:\n";

    for (int i = 0; i < rows; i++)
    {
        int minimum = INT_MAX;

        // Find minimum in current row.
        for (int j = 0; j < cols; j++)
        {
            minimum = min(minimum, matrix[i][j]);
        }

        cout << "Row " << i << " = " << minimum << endl;
    }
}

//--------------------------------------------------
// Find row having maximum sum.
//--------------------------------------------------
void rowWithMaximumSum(const vector<vector<int>> &matrix)
{
    int rows = matrix.size();
    int cols = matrix[0].size();

    int bestRow = -1;
    int bestSum = INT_MIN;

    for (int i = 0; i < rows; i++)
    {
        int currentSum = 0;

        for (int j = 0; j < cols; j++)
        {
            currentSum += matrix[i][j];
        }

        // Better row found.
        if (currentSum > bestSum)
        {
            bestSum = currentSum;
            bestRow = i;
        }
    }

    cout << "\nRow With Maximum Sum : " << bestRow;
    cout << "\nMaximum Sum          : " << bestSum << endl;
}

//--------------------------------------------------
// Find row having minimum sum.
//--------------------------------------------------
void rowWithMinimumSum(const vector<vector<int>> &matrix)
{
    int rows = matrix.size();
    int cols = matrix[0].size();

    int bestRow = -1;
    int bestSum = INT_MAX;

    for (int i = 0; i < rows; i++)
    {
        int currentSum = 0;

        for (int j = 0; j < cols; j++)
        {
            currentSum += matrix[i][j];
        }

        // Smaller row found.
        if (currentSum < bestSum)
        {
            bestSum = currentSum;
            bestRow = i;
        }
    }

    cout << "\nRow With Minimum Sum : " << bestRow;
    cout << "\nMinimum Sum          : " << bestSum << endl;
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

    printRows(matrix);

    rowSum(matrix);

    rowAverage(matrix);

    rowMaximum(matrix);

    rowMinimum(matrix);

    rowWithMaximumSum(matrix);

    rowWithMinimumSum(matrix);

    return 0;
}