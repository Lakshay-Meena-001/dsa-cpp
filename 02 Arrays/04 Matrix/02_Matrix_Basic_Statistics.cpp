#include <iostream>
#include <vector>
#include <climits>
using namespace std;

//--------------------------------------------------
// Topic   : Matrix Basic Statistics
// File    : 02_Matrix_Basic_Statistics.cpp
//
// Concepts:
// 1. Largest Element
// 2. Smallest Element
// 3. Sum of Elements
// 4. Average of Elements
// 5. Count Even Elements
// 6. Count Odd Elements
//
// Pattern : Matrix Traversal
//
// Time  : O(rows × cols)
// Space : O(1)
//
// Learning:
// - Complete matrix traversal
// - Updating answer while traversing
// - Running maximum
// - Running minimum
// - Accumulation
//--------------------------------------------------

//--------------------------------------------------
// Find largest element in matrix.
//--------------------------------------------------
int largestElement(const vector<vector<int>> &matrix)
{
    int rows = matrix.size();
    int cols = matrix[0].size();

    int largest = INT_MIN;

    // Visit every cell.
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            // Update largest element.
            if (matrix[i][j] > largest)
            {
                largest = matrix[i][j];
            }
        }
    }

    return largest;
}

//--------------------------------------------------
// Find smallest element in matrix.
//--------------------------------------------------
int smallestElement(const vector<vector<int>> &matrix)
{
    int rows = matrix.size();
    int cols = matrix[0].size();

    int smallest = INT_MAX;

    // Visit every cell.
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            // Update smallest element.
            if (matrix[i][j] < smallest)
            {
                smallest = matrix[i][j];
            }
        }
    }

    return smallest;
}

//--------------------------------------------------
// Calculate sum of all elements.
//--------------------------------------------------
int sumOfElements(const vector<vector<int>> &matrix)
{
    int rows = matrix.size();
    int cols = matrix[0].size();

    int sum = 0;

    // Add every element.
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            sum += matrix[i][j];
        }
    }

    return sum;
}

//--------------------------------------------------
// Calculate average of all elements.
//--------------------------------------------------
double averageOfElements(const vector<vector<int>> &matrix)
{
    int rows = matrix.size();
    int cols = matrix[0].size();

    int totalElements = rows * cols;

    int sum = sumOfElements(matrix);

    return (double)sum / totalElements;
}

//--------------------------------------------------
// Count even numbers.
//--------------------------------------------------
int countEvenElements(const vector<vector<int>> &matrix)
{
    int rows = matrix.size();
    int cols = matrix[0].size();

    int count = 0;

    // Check every element.
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (matrix[i][j] % 2 == 0)
            {
                count++;
            }
        }
    }

    return count;
}

//--------------------------------------------------
// Count odd numbers.
//--------------------------------------------------
int countOddElements(const vector<vector<int>> &matrix)
{
    int rows = matrix.size();
    int cols = matrix[0].size();

    int count = 0;

    // Check every element.
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (matrix[i][j] % 2 != 0)
            {
                count++;
            }
        }
    }

    return count;
}

int main()
{
    int rows, cols;

    cout << "Enter number of rows and columns: ";
    cin >> rows >> cols;

    vector<vector<int>> matrix(rows, vector<int>(cols));

    cout << "Enter matrix elements:\n";

    // Input matrix.
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cin >> matrix[i][j];
        }
    }

    cout << "\nLargest Element : " << largestElement(matrix);
    cout << "\nSmallest Element: " << smallestElement(matrix);
    cout << "\nSum             : " << sumOfElements(matrix);
    cout << "\nAverage         : " << averageOfElements(matrix);
    cout << "\nEven Count      : " << countEvenElements(matrix);
    cout << "\nOdd Count       : " << countOddElements(matrix);

    return 0;
}