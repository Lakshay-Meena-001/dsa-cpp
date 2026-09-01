#include <iostream>
#include <vector>
#include <climits>
using namespace std;

//--------------------------------------------------
// Topic   : Matrix Column Operations
// File    : 04_Matrix_Column_Operations.cpp
//
// Concepts:
// 1. Print Every Column
// 2. Column Sum
// 3. Column Average
// 4. Column Maximum Element
// 5. Column Minimum Element
// 6. Column With Maximum Sum
// 7. Column With Minimum Sum
//
// Pattern : Column Observation
//
// Time  : O(rows × cols)
// Space : O(1)
//
// Learning:
// - Process one complete column at a time
// - Running sum
// - Running maximum
// - Running minimum
// - Best column selection
//--------------------------------------------------

//--------------------------------------------------
// Print every column separately.
//--------------------------------------------------
void printColumns(const vector<vector<int>> &matrix)
{
    int rows = matrix.size();
    int cols = matrix[0].size();

    cout << "\nColumns:\n";

    for (int j = 0; j < cols; j++)
    {
        cout << "Column " << j << " : ";

        // Visit every row of current column.
        for (int i = 0; i < rows; i++)
        {
            cout << matrix[i][j] << " ";
        }

        cout << endl;
    }
}

//--------------------------------------------------
// Print sum of every column.
//--------------------------------------------------
void columnSum(const vector<vector<int>> &matrix)
{
    int rows = matrix.size();
    int cols = matrix[0].size();

    cout << "\nColumn Sum:\n";

    for (int j = 0; j < cols; j++)
    {
        int sum = 0;

        // Add all elements of current column.
        for (int i = 0; i < rows; i++)
        {
            sum += matrix[i][j];
        }

        cout << "Column " << j << " = " << sum << endl;
    }
}

//--------------------------------------------------
// Print average of every column.
//--------------------------------------------------
void columnAverage(const vector<vector<int>> &matrix)
{
    int rows = matrix.size();
    int cols = matrix[0].size();

    cout << "\nColumn Average:\n";

    for (int j = 0; j < cols; j++)
    {
        int sum = 0;

        for (int i = 0; i < rows; i++)
        {
            sum += matrix[i][j];
        }

        cout << "Column " << j << " = " << (double)sum / rows << endl;
    }
}

//--------------------------------------------------
// Print maximum element of every column.
//--------------------------------------------------
void columnMaximum(const vector<vector<int>> &matrix)
{
    int rows = matrix.size();
    int cols = matrix[0].size();

    cout << "\nColumn Maximum:\n";

    for (int j = 0; j < cols; j++)
    {
        int maximum = INT_MIN;

        // Find maximum in current column.
        for (int i = 0; i < rows; i++)
        {
            maximum = max(maximum, matrix[i][j]);
        }

        cout << "Column " << j << " = " << maximum << endl;
    }
}

//--------------------------------------------------
// Print minimum element of every column.
//--------------------------------------------------
void columnMinimum(const vector<vector<int>> &matrix)
{
    int rows = matrix.size();
    int cols = matrix[0].size();

    cout << "\nColumn Minimum:\n";

    for (int j = 0; j < cols; j++)
    {
        int minimum = INT_MAX;

        // Find minimum in current column.
        for (int i = 0; i < rows; i++)
        {
            minimum = min(minimum, matrix[i][j]);
        }

        cout << "Column " << j << " = " << minimum << endl;
    }
}

//--------------------------------------------------
// Find column having maximum sum.
//--------------------------------------------------
void columnWithMaximumSum(const vector<vector<int>> &matrix)
{
    int rows = matrix.size();
    int cols = matrix[0].size();

    int bestColumn = -1;
    int bestSum = INT_MIN;

    for (int j = 0; j < cols; j++)
    {
        int currentSum = 0;

        for (int i = 0; i < rows; i++)
        {
            currentSum += matrix[i][j];
        }

        // Better column found.
        if (currentSum > bestSum)
        {
            bestSum = currentSum;
            bestColumn = j;
        }
    }

    cout << "\nColumn With Maximum Sum : " << bestColumn;
    cout << "\nMaximum Sum             : " << bestSum << endl;
}

//--------------------------------------------------
// Find column having minimum sum.
//--------------------------------------------------
void columnWithMinimumSum(const vector<vector<int>> &matrix)
{
    int rows = matrix.size();
    int cols = matrix[0].size();

    int bestColumn = -1;
    int bestSum = INT_MAX;

    for (int j = 0; j < cols; j++)
    {
        int currentSum = 0;

        for (int i = 0; i < rows; i++)
        {
            currentSum += matrix[i][j];
        }

        // Smaller column found.
        if (currentSum < bestSum)
        {
            bestSum = currentSum;
            bestColumn = j;
        }
    }

    cout << "\nColumn With Minimum Sum : " << bestColumn;
    cout << "\nMinimum Sum             : " << bestSum << endl;
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

    printColumns(matrix);

    columnSum(matrix);

    columnAverage(matrix);

    columnMaximum(matrix);

    columnMinimum(matrix);

    columnWithMaximumSum(matrix);

    columnWithMinimumSum(matrix);

    return 0;
}